#include <iostream>

#pragma pack(1)  // Disable padding
struct Example {
    char a;
    int b;
    char c;
};

int main() {
    std::cout << "Size of struct Example: " << sizeof(Example) << " bytes" << std::endl;
    return 0;
}
//Pragma will stop padding so, the size will be reduced.
//However this is difficult to access to the cpu. So, takes some time.