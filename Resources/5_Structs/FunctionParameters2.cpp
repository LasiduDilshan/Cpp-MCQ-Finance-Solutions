#include <iostream>

// Pass by reference

struct Person {
    std::string name;
    int age;
};

void printPerson(const Person& p) {  // Passed by reference
    std::cout << p.name << " is " << p.age << " years old." << std::endl;
}

int main() {
    Person person1 = {"Alice", 25};
    printPerson(person1);  // Pass by reference
    return 0;
}
