#include <iostream>

struct Example {
    char a;
    int b;
    char c;
};

int main() {
    std::cout << "Size of struct Example: " << sizeof(Example) << " bytes" << std::endl;
    return 0;
}
