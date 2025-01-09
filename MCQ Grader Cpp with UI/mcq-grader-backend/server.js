const express = require('express');
const cors = require('cors');
const multer = require('multer');
const { exec } = require('child_process');
const fs = require('fs');
const path = require('path');
const csvParser = require('csv-parser');

const app = express();
const port = 5000;

const cppDir = path.resolve(__dirname, 'cpp');
const uploadDir = path.resolve(__dirname, 'uploads');

app.use(cors());
app.use(express.static('public'));

const upload = multer({ dest: uploadDir });

app.post('/upload', upload.fields([{ name: 'answers' }, { name: 'students' }]), (req, res) => {
    const answersFile = req.files['answers'][0].path;
    const studentsFile = req.files['students'][0].path;

    // Ensure the cpp directory exists
    if (!fs.existsSync(cppDir)) {
        fs.mkdirSync(cppDir, { recursive: true });
    }

    // Move and rename the uploaded files to the cpp directory
    const newAnswersPath = path.join(cppDir, 'answers.csv');
    const newStudentsPath = path.join(cppDir, 'students.csv');
    fs.renameSync(answersFile, newAnswersPath);
    fs.renameSync(studentsFile, newStudentsPath);

    // Compile the C++ code
    const compileCommand = `g++ -o "${path.join(cppDir, 'MCQGrader')}" "${path.join(cppDir, 'main.cpp')}" "${path.join(cppDir, 'MCQGrader.cpp')}"`;
    exec(compileCommand, { cwd: cppDir, shell: true }, (compileError, compileStdout, compileStderr) => {
        if (compileError) {
            console.error(`C++ Compilation Error: ${compileStderr}`);
            return res.status(500).send(`C++ Compilation Error: ${compileStderr}`);
        }

        // Run the compiled C++ program
        const executeCommand = `"${path.join(cppDir, 'MCQGrader')}"`;
        exec(executeCommand, { cwd: cppDir, shell: true }, (execError, execStdout, execStderr) => {
            if (execError) {
                console.error(`C++ Execution Error: ${execStderr}`);
                return res.status(500).send(`C++ Execution Error: ${execStderr}`);
            }

            // Read and process the results.csv file
            const resultsPath = path.join(cppDir, 'results.csv');
            if (!fs.existsSync(resultsPath)) {
                console.error('Results file not found');
                return res.status(500).send('Results file not found');
            }

            const results = [];
            fs.createReadStream(resultsPath)
                .pipe(csvParser())
                .on('data', (row) => {
                    results.push(row);
                })
                .on('end', () => {
                    // Calculate statistics
                    const totalStudents = results.length;
                    const percentages = results.map(r => parseFloat(r.Percentage));
                    const averagePercentage = (percentages.reduce((a, b) => a + b, 0) / totalStudents).toFixed(2);
                    const stdDev = (Math.sqrt(percentages.map(p => Math.pow(p - averagePercentage, 2)).reduce((a, b) => a + b) / totalStudents)).toFixed(2);
                    const correctAnswerCounts = results.reduce((acc, row) => {
                        const count = parseInt(row['Correct Answers'], 10);
                        acc[count] = (acc[count] || 0) + 1;
                        return acc;
                    }, {});

                    // Send results and statistics to the frontend
                    res.json({
                        message: 'Processing complete',
                        results,
                        statistics: {
                            totalStudents,
                            averagePercentage,
                            stdDev,
                            correctAnswerCounts
                        }
                    });
                });
        });
    });
});

app.listen(port, () => {
    console.log(`Server running at http://localhost:${port}`);
});