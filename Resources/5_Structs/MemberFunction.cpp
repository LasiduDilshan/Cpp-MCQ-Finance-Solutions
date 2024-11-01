#include <iostream>

struct Person {
    std::string name;
    int age;

    // Member function to print details
    void printDetails() {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Age: " << age << std::endl;
    }

    // Member function to change the age
    void changeAge(int newAge) {
        age = newAge;
    }
};

int main() {
    Person person1 = {"Alice", 25};
    
    person1.printDetails();  // Call the member function
    person1.changeAge(30);   // Update age using a member function
    person1.printDetails();  // See the updated details

    return 0;
}
