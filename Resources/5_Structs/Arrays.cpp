#include <iostream>

struct Person {
    std::string name;
    int age;
};

int main() {
    // Array of structs
    Person people[3] = {
        {"Alice", 25},
        {"Bob", 30},
        {"Charlie", 35}
    };

    // Loop through the array and print details
    for (int i = 0; i < 3; i++) {
        std::cout << "Person " << i + 1 << ": " << people[i].name << ", " << people[i].age << std::endl;
    }

    return 0;
}
