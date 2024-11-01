// main.cpp
#include <iostream>
#include "includes/Rectangle.h"

int main() {
    // Create a Rectangle object
    Rectangle rect(5.0, 3.0);

    // Display initial dimensions
    std::cout << "Width: " << rect.getWidth() << std::endl;
    std::cout << "Height: " << rect.getHeight() << std::endl;
    std::cout << "Area: " << rect.area() << std::endl;
    std::cout << "Perimeter: " << rect.perimeter() << std::endl;

    // Modify dimensions
    rect.setWidth(7.0);
    rect.setHeight(4.0);

    // Display updated dimensions
    std::cout << "Updated Width: " << rect.getWidth() << std::endl;
    std::cout << "Updated Height: " << rect.getHeight() << std::endl;
    std::cout << "Updated Area: " << rect.area() << std::endl;
    std::cout << "Updated Perimeter: " << rect.perimeter() << std::endl;

    return 0;
}
