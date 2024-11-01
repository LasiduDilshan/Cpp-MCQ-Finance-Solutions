#include <iostream>

int main() {
    int num = 10;
    int* ptr = &num;  // Pointer to an int = int*
    int** ptr2 = &ptr;  // Pointer to an int* = int**
    int*** ptr3 = &ptr2;  // Pointer to an int** = int***

    std::cout << "Value of num: " << num << std::endl;
    std::cout << "Address of num: " << ptr << std::endl;
    std::cout << "Value at ptr: " << *ptr << std::endl;  // Dereferencing the pointer
    //*ptr is used to access the value at the address stored in ptr. Since ptr points to num, *ptr gives the value of num, which is 10.

    std::cout << "Address of ptr: " << ptr2 << std::endl;
    std::cout << "Address of ptr2: " << ptr3 << std::endl;

    return 0;
}

//Simply a pointer is just an address of someone