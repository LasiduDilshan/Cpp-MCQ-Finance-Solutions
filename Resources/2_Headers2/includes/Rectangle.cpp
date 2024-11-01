// Rectangle.cpp
#include "Rectangle.h"

// Constructor
Rectangle::Rectangle(double w, double h) : width(w), height(h) {}

// Getters
double Rectangle::getWidth() const {
    return width;
}

double Rectangle::getHeight() const {
    return height;
}

// Calculate area
double Rectangle::area() const {
    return width * height;
}

// Calculate perimeter
double Rectangle::perimeter() const {
    return 2 * (width + height);
}

// Setters
void Rectangle::setWidth(double w) {
    width = w;
}

void Rectangle::setHeight(double h) {
    height = h;
}
