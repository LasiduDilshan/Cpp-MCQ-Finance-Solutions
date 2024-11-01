#include <iostream>
#include <iomanip> // for std::setprecision

using namespace std;

void showMenu() {
    cout << "Basic Calculator" << endl;
    cout << "-----------------" << endl;
    cout << "1. Addition" << endl;
    cout << "2. Subtraction" << endl;
    cout << "3. Multiplication" << endl;
    cout << "4. Division" << endl;
    cout << "5. Exit" << endl;
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        throw invalid_argument("Division by zero is not allowed.");
    }
    return a / b;
}

int main() {
    int choice;
    double num1, num2, result;

    do {
        showMenu();
        cout << "Enter your choice (1-5): ";
        cin >> choice;

        if (choice == 5) {
            cout << "Exiting calculator. Goodbye!" << endl;
            break;
        }

        if (choice < 1 || choice > 5) {
            cout << "Invalid choice. Please select a number between 1 and 5." << endl;
            continue;
        }

        cout << "Enter first number: ";
        cin >> num1;
        cout << "Enter second number: ";
        cin >> num2;

        try {
            switch (choice) {
                case 1:
                    result = add(num1, num2);
                    cout << "Result: " << fixed << setprecision(2) << result << endl;
                    break;
                case 2:
                    result = subtract(num1, num2);
                    cout << "Result: " << fixed << setprecision(2) << result << endl;
                    break;
                case 3:
                    result = multiply(num1, num2);
                    cout << "Result: " << fixed << setprecision(2) << result << endl;
                    break;
                case 4:
                    result = divide(num1, num2);
                    cout << "Result: " << fixed << setprecision(2) << result << endl;
                    break;
                default:
                    cout << "Invalid choice. Please select a number between 1 and 5." << endl;
                    break;
            }
        } catch (const invalid_argument& e) {
            cout << "Error: " << e.what() << endl;
        }

    } while (true);

    return 0;
}
