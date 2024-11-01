#include <iostream>

//Passing by Value

struct Person {
    std::string name;
    int age;
};

void printPerson(Person p) {  // Passed by value
    std::cout << p.name << " is " << p.age << " years old." << std::endl;
}

int main() {
    Person person1 = {"Alice", 25};
    printPerson(person1);  // Pass by value
    return 0;
}
