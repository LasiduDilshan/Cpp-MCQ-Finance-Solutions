#include <iostream>

struct Person {
    std::string name;
    int age;
};

int main() {
    // Dynamically allocate memory for a struct
    Person* personPtr = new Person{"Bob", 40};

    // Accessing members using pointer
    std::cout << "Name: " << personPtr->name << std::endl;
    std::cout << "Age: " << personPtr->age << std::endl;

    // Clean up the allocated memory
    delete personPtr;

    return 0;
}
