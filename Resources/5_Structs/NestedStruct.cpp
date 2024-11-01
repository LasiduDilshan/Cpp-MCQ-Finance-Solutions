#include <iostream>
#include <string>

struct Address {
    std::string city;
    std::string country;
};

struct Person {
    std::string name;
    int age;
    Address address;  // Nested struct
};

int main() {
    // Create a person with an address
    Person person1 = {"John", 28, {"New York", "USA"}};

    // Accessing nested struct members
    std::cout << "Name: " << person1.name << std::endl;
    std::cout << "City: " << person1.address.city << std::endl;
    std::cout << "Country: " << person1.address.country << std::endl;

    return 0;
}