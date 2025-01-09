#ifndef MCQGRADER_H
#define MCQGRADER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

struct Student {
    std::string name;
    std::string id;
    std::vector<char> answers;
    int correctAnswers;
    int wrongAnswers;
    double percentage;
    int rank;
};

class MCQGrader {
private:
    std::vector<char> correctAnswers;
    std::vector<Student> students;
    void loadCorrectAnswers(const std::string& filepath);
    void loadStudentAnswers(const std::string& filepath);
    void rankStudents();
public:
    MCQGrader(const std::string& correctAnswersFile, const std::string& studentsFile);
    void gradeStudents();
    void writeResultsToCSV(const std::string& outputFile);
    void generateStatisticsPDF(const std::string& pdfFile);
};

#endif
