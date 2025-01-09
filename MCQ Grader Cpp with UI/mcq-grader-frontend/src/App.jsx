import React, { useState } from 'react';
import axios from 'axios';
import { CSVLink } from 'react-csv';
import { Bar } from 'react-chartjs-2';
import 'chart.js/auto';
import './App.css';

function App() {
    const [answersFile, setAnswersFile] = useState(null);
    const [studentsFile, setStudentsFile] = useState(null);
    const [results, setResults] = useState([]);
    const [downloadData, setDownloadData] = useState([]);
    const [chartData, setChartData] = useState({});
    const [statistics, setStatistics] = useState({});
    const [isProcessing, setIsProcessing] = useState(false);

    const handleFileChange = (e) => {
        const { name, files } = e.target;
        if (name === 'answers') setAnswersFile(files[0]);
        else if (name === 'students') setStudentsFile(files[0]);
    };

    const handleSubmit = async (e) => {
        e.preventDefault();
        setIsProcessing(true); // Set processing state to true
        const formData = new FormData();
        formData.append('answers', answersFile);
        formData.append('students', studentsFile);

        try {
            const response = await axios.post('http://localhost:5000/upload', formData, {
                responseType: 'json',
            });

            const { results, statistics } = response.data;
            setResults(results);

            const headers = Object.keys(results[0]);
            const csvData = [headers, ...results.map(row => headers.map(header => row[header]))];
            setDownloadData(csvData);

            setStatistics(statistics);
            setChartData({
                labels: Object.keys(statistics.correctAnswerCounts),
                datasets: [
                    {
                        label: 'Number of Students',
                        data: Object.values(statistics.correctAnswerCounts),
                        backgroundColor: 'rgba(75, 192, 192, 0.6)',
                        borderColor: 'rgba(75, 192, 192, 1)',
                        borderWidth: 1
                    },
                ],
            });
        } catch (error) {
            console.error('Error processing files:', error);
        } finally {
            setIsProcessing(false); // Reset processing state
        }
    };

    return (
        <div className="App">
            <div className="navbar">
                <h1>MCQ Grader</h1>
            </div>
            <form onSubmit={handleSubmit}>
                <div>
                    <label>Answers CSV:</label>
                    <input type="file" name="answers" onChange={handleFileChange} />
                </div>
                <div>
                    <label>Students CSV:</label>
                    <input type="file" name="students" onChange={handleFileChange} />
                </div>
                <button type="submit" disabled={isProcessing}>
                    {isProcessing ? 'Processing...' : 'Process'}
                </button>
            </form>

            {results.length > 0 && (
                <>
                    <h2>Results</h2>
                    <table>
                        <thead>
                            <tr>
                                {Object.keys(results[0]).map((header, index) => (
                                    <th key={index}>{header}</th>
                                ))}
                            </tr>
                        </thead>
                        <tbody>
                            {results.map((row, index) => (
                                <tr key={index}>
                                    {Object.values(row).map((cell, cellIndex) => (
                                        <td key={cellIndex}>{cell}</td>
                                    ))}
                                </tr>
                            ))}
                        </tbody>
                    </table>
                    <CSVLink data={downloadData} filename="results.csv">
                        <button>Download CSV</button>
                    </CSVLink>
                    <h2>Statistics</h2>
                    <p>Total Students: {statistics.totalStudents}</p>
                    <p>Average Percentage: {statistics.averagePercentage}%</p>
                    <p>Standard Deviation: {statistics.stdDev}</p>
                    <h2>Statistics Visualization</h2>
                    <Bar data={chartData} />
                </>
            )}
        </div>
    );
}

export default App;