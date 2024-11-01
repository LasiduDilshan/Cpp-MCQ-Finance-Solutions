#include <iostream>

int main() {
    int num = -12;

    if (num > 0) {
        std::cout << "Positive number" << std::endl;
    } else if (num == 0)
    {
        std::cout << "Zero" << std::endl;
    } else {
        std::cout << "Non-positive number" << std::endl;
    }

    return 0;
}
