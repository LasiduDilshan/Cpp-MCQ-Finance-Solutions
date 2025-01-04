import React, { useState } from 'react';
import axios from 'axios';
import { useTable } from 'react-table';
import './App.css';

// Define months
const months = [
    'January', 'February', 'March', 'April', 'May', 'June',
    'July', 'August', 'September', 'October', 'November', 'December'
];

// Table component
const DataTable = ({ columns, data }) => {
    const { getTableProps, getTableBodyProps, headerGroups, rows, prepareRow } = useTable({
        columns,
        data,
    });

    return (
        <table {...getTableProps()} className="data-table">
            <thead>
                {headerGroups.map(headerGroup => (
                    <tr {...headerGroup.getHeaderGroupProps()}>
                        {headerGroup.headers.map(column => (
                            <th {...column.getHeaderProps()}>{column.render('Header')}</th>
                        ))}
                    </tr>
                ))}
            </thead>
            <tbody {...getTableBodyProps()}>
                {rows.map(row => {
                    prepareRow(row);
                    return (
                        <tr {...row.getRowProps()}>
                            {row.cells.map(cell => (
                                <td {...cell.getCellProps()}>{cell.render('Cell')}</td>
                            ))}
                        </tr>
                    );
                })}
            </tbody>
        </table>
    );
};

function App() {
    const [budgets, setBudgets] = useState(
        months.map(month => ({ month, amount: 0 }))
    );
    const [expenses, setExpenses] = useState(
        months.reduce((acc, month) => {
            acc[month] = [{ category: 'Groceries', amount: 0 }];
            return acc;
        }, {})
    );
    const [output, setOutput] = useState('');
    const [outputData, setOutputData] = useState([]);

    const handleBudgetChange = (index, value) => {
        const newBudgets = [...budgets];
        newBudgets[index].amount = value;
        setBudgets(newBudgets);
    };

    const handleExpenseChange = (month, index, field, value) => {
        const newExpenses = { ...expenses };
        newExpenses[month][index][field] = value;
        setExpenses(newExpenses);
    };

    const addExpense = (month) => {
        const newExpenses = { ...expenses };
        newExpenses[month].push({ category: '', amount: 0 });
        setExpenses(newExpenses);
    };

    const removeExpense = (month, index) => {
        const newExpenses = { ...expenses };
        newExpenses[month].splice(index, 1);
        setExpenses(newExpenses);
    };

    const processBudget = async () => {
        try {
            const formattedExpenses = Object.entries(expenses).flatMap(([month, expenseList]) =>
                expenseList.map(expense => ({ month, ...expense }))
            );
            await axios.post('http://localhost:5000/set-data', { budgets, expenses: formattedExpenses });
            const response = await axios.get('http://localhost:5000/process');
            setOutput(response.data.output);

            // Process CSV output into a table format
            const lines = response.data.output.trim().split('\n');
            const headers = lines[0].split(',');
            const rows = lines.slice(1).map(line => line.split(','));
            setOutputData({ headers, rows });
        } catch (error) {
            console.error('Error processing budget:', error);
        }
    };

    const columns = React.useMemo(
        () => outputData.headers ? outputData.headers.map(header => ({ Header: header, accessor: header })) : [],
        [outputData.headers]
    );

    const data = React.useMemo(
        () => outputData.rows ? outputData.rows.map((row, index) => {
            const rowData = {};
            outputData.headers.forEach((header, i) => {
                rowData[header] = row[i];
            });
            return rowData;
        }) : [],
        [outputData.rows, outputData.headers]
    );

    return (
        <div className="app-container">
            <div className="section-container">
                <div className="budget-section">
                    <h2>Budgets</h2>
                    {budgets.map((budget, index) => (
                        <div key={index} className="input-group">
                            <input
                                type="text"
                                value={budget.month}
                                readOnly
                                className="month-input"
                            />
                            <input
                                type="number"
                                value={budget.amount}
                                onChange={(e) => handleBudgetChange(index, e.target.value)}
                                placeholder="Amount"
                                className="amount-input"
                            />
                        </div>
                    ))}
                </div>
                <div className="expense-section">
                    <h2>Expenses</h2>
                    {months.map((month) => (
                        <div key={month} className="month-section">
                            <h3>{month}</h3>
                            {expenses[month].map((expense, index) => (
                                <div key={index} className="input-group">
                                    <input
                                        type="text"
                                        value={expense.category}
                                        onChange={(e) => handleExpenseChange(month, index, 'category', e.target.value)}
                                        placeholder="Category"
                                        className="category-input"
                                    />
                                    <input
                                        type="number"
                                        value={expense.amount}
                                        onChange={(e) => handleExpenseChange(month, index, 'amount', e.target.value)}
                                        placeholder="Amount"
                                        className="amount-input"
                                    />
                                    <button onClick={() => removeExpense(month, index)} className="remove-expense-button">Remove</button>
                                </div>
                            ))}
                            <button onClick={() => addExpense(month)} className="add-expense-button">Add Expense</button>
                        </div>
                    ))}
                </div>
                <div className="output-section">
                    <button onClick={processBudget} className="process-button">Process</button>
                    <h2>Output</h2>
                    <div className="output-table">
                        <DataTable columns={columns} data={data} />
                    </div>
                </div>
            </div>
        </div>
    );
}

export default App;