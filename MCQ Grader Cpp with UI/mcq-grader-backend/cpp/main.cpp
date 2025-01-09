#include "MCQGrader.h"

int main() {
    // Initialize MCQGrader with CSV file paths for correct answers and student answers
    MCQGrader grader("answers.csv", "students.csv");

    // Grade students
    grader.gradeStudents();

    // Write results to an output CSV
    grader.writeResultsToCSV("results.csv");

    // Optional: Generate statistics in PDF format (requires implementation)
    // grader.generateStatisticsPDF("statistics.pdf");

    std::cout << "Grading complete. Results saved to 'results.csv'.\n";

    return 0;
}
