#include <iostream>

void printSum(int a, int b) {  // Function with parameters
    std::cout << "Sum: " << a + b << std::endl;
}

int main() {
    printSum(5, 10);  // Pass arguments to the function
    return 0;
}
