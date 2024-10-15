#include "MCQGrader.h"
#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>

// Helper function to split strings by delimiter
std::vector<std::string> split(const std::string &str, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(str);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// Load correct answers from CSV
void MCQGrader::loadCorrectAnswers(const std::string& filepath) {
    std::ifstream file(filepath);
    std::string line;
    if (file.is_open()) {
        std::getline(file, line); // Skip the first line (header)
        if (std::getline(file, line)) { // Read the second line
            std::vector<std::string> tokens = split(line, ',');
            for (const auto& ans : tokens) {
                correctAnswers.push_back(ans[0]); // Store correct answers as characters
            }
        }
    }
    file.close();
}

// Load student answers from CSV
void MCQGrader::loadStudentAnswers(const std::string& filepath) {
    std::ifstream file(filepath);
    std::string line;
    if (file.is_open()) {
        std::getline(file, line); // Skip header line
        while (std::getline(file, line)) {
            std::vector<std::string> tokens = split(line, ',');
            Student student;
            student.name = tokens[0];  // Student name
            student.id = tokens[1];    // Student ID
            for (int i = 2; i < tokens.size(); ++i) {
                student.answers.push_back(tokens[i][0]); // Store each answer as a character
            }
            students.push_back(student);  // Add the student object to the list

            /*// Print the student's name, ID, and answers for verification
            std::cout << "Loaded Student: " << student.name << " (ID: " << student.id << ")\n";
            std::cout << "Answers: ";
            for (const auto& ans : student.answers) {
                std::cout << ans << " ";
            }
            std::cout << std::endl;*/
        }
    }
    file.close();
}

// Grade students based on correct answers
void MCQGrader::gradeStudents() {
    for (auto& student : students) {
        int correctCount = 0;
        int wrongCount = 0;
        // Compare student's answers with correct answers
        for (size_t i = 0; i < correctAnswers.size(); ++i) {
            if (student.answers[i] == correctAnswers[i]) {
                correctCount++;
            } else {
                wrongCount++;
                /*std::cout << "Question " << i + 1 << ": Student Answer = " << student.answers[i]
                  << ", Correct Answer = " << correctAnswers[i] << std::endl;*/
            }
        }
        student.correctAnswers = correctCount;
        student.wrongAnswers = wrongCount;
        student.percentage = (correctCount / static_cast<double>(correctAnswers.size())) * 100;
    }
}

// Rank students based on percentage
void MCQGrader::rankStudents() {
    // Sort students in descending order based on their percentage
    std::sort(students.begin(), students.end(), [](const Student& a, const Student& b) {
        return a.percentage > b.percentage;
    });

    int rank = 1; // Start ranking from 1
    for (size_t i = 0; i < students.size(); ++i) {
        // If it's the first student or the percentage is different from the previous student
        if (i == 0 || students[i].percentage < students[i - 1].percentage) {
            students[i].rank = rank; // Assign current rank
        } else {
            students[i].rank = students[i - 1].rank; // Same rank as the previous student
        }
        rank++; // Move to the next rank
    }
}


// Write results to CSV file
void MCQGrader::writeResultsToCSV(const std::string& outputFile) {
    std::ofstream file(outputFile);
    file << "Name,ID,Correct Answers,Wrong Answers,Percentage,Rank\n";
    rankStudents(); // Ensure students are ranked before writing to CSV
    for (const auto& student : students) {
        file << student.name << "," << student.id << ","
             << student.correctAnswers << "," << student.wrongAnswers << ","
             << std::fixed << std::setprecision(2) << student.percentage << "," << student.rank << "\n";
    }
    file.close();
}


// Constructor to load data from the input files
MCQGrader::MCQGrader(const std::string& correctAnswersFile, const std::string& studentsFile) {
    loadCorrectAnswers(correctAnswersFile);
    loadStudentAnswers(studentsFile);
}
