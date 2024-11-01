#include <iostream>

struct Person {
    std::string name;
    int age;

    // Constructor
    Person(std::string personName, int personAge) {
        name = personName;
        age = personAge;
    }

    // Member function
    void printDetails() {
        std::cout << "Name: " << name << ", Age: " << age << std::endl;
    }
};

int main() {
    // Creating a struct instance using a constructor
    Person person1("Alice", 30);
    person1.printDetails();

    return 0;
}