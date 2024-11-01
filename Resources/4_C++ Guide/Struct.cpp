#include <iostream>

// Define a structure
struct Person {
    std::string name;
    int age;
    double height;
};

int main() {
    // Declare and initialize a structure
    Person person1 = {"John", 30, 5.9};

    // Accessing structure members
    std::cout << "Name: " << person1.name << std::endl;
    std::cout << "Age: " << person1.age << std::endl;
    std::cout << "Height: " << person1.height << "\n" << std::endl;

    // Declare and initialize a structure 2
    Person person2 = {"Tim", 22, 6.1};

    // Accessing structure members
    std::cout << "Name: " << person2.name << std::endl;
    std::cout << "Age: " << person2.age << std::endl;
    std::cout << "Height: " << person2.height << std::endl;

    return 0;
}
