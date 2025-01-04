const express = require('express');
const bodyParser = require('body-parser');
const cors = require('cors');
const { exec } = require('child_process');
const fs = require('fs');
const path = require('path');

const app = express();
const port = 5000;

const cppDir = path.resolve(__dirname);

app.use(cors());
app.use(bodyParser.json());

app.post('/set-data', (req, res) => {
    const { budgets, expenses } = req.body;

    // Write budgets to budgets.csv
    const budgetData = budgets.map(b => `${b.month},${b.amount}`).join('\n');
    fs.writeFileSync(path.join(cppDir, 'budgets.csv'), budgetData);

    // Write expenses to expenses.csv
    const expenseData = expenses.map(e => `${e.month},${e.category},${e.amount}`).join('\n');
    fs.writeFileSync(path.join(cppDir, 'expenses.csv'), expenseData);

    res.send({ message: 'Data saved successfully' });
});

app.get('/process', (req, res) => {
    const compileCommand = `g++ -std=c++11 -pthread "${path.join(cppDir, 'main.cpp')}" "${path.join(cppDir, 'FinanceManager.cpp')}" "${path.join(cppDir, 'Budget.cpp')}" "${path.join(cppDir, 'Expense.cpp')}" "${path.join(cppDir, 'Category.cpp')}" -o "${path.join(cppDir, 'finance_manager')}"`;

    console.log(`Running compile command: ${compileCommand}`);
    exec(compileCommand, { cwd: cppDir, shell: true }, (compileError, compileStdout, compileStderr) => {
        if (compileError) {
            console.error(`Error during compilation: ${compileError.message}`);
            console.error(`stderr: ${compileStderr}`);
            return res.status(500).json({ error: 'Failed to compile C++ code', details: compileStderr });
        }

        console.log('Compilation successful. Running execution command:');
        
        // Run the compiled C++ program
        const executeCommand = `"${path.join(cppDir, 'finance_manager')}"`;
        console.log(`Executing command: ${executeCommand}`);
        exec(executeCommand, { cwd: cppDir, shell: true }, (execError, execStdout, execStderr) => {
            if (execError) {
                console.error(`Error during execution: ${execError.message}`);
                console.error(`stderr: ${execStderr}`);
                return res.status(500).json({ error: 'Failed to execute C++ code', details: execStderr });
            }

            // Log stdout and stderr from the C++ program
            console.log('C++ program output stdout:', execStdout);
            console.log('C++ program output stderr:', execStderr);

            // Check if the output file exists in the cpp directory
            const outputPath = path.resolve(cppDir, 'output.csv');
            if (!fs.existsSync(outputPath)) {
                console.error('Output file not found at:', outputPath);
                return res.status(500).json({ error: 'Output file not found' });
            }

            console.log('C++ program executed successfully.');
            // Read and send the output file content
            const outputContent = fs.readFileSync(outputPath, 'utf8');
            res.json({ message: 'Processing complete', output: outputContent });
        });
    });
});

// Start server
app.listen(port, () => {
    console.log(`Server running at http://localhost:${port}`);
});