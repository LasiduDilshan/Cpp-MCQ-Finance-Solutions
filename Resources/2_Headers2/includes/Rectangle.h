#pragma once  //Ensure that a header file is included only once in a single compilation

// Rectangle.h
#ifndef RECTANGLE_H
#define RECTANGLE_H

class Rectangle {
private:
    double width;
    double height;

public:
    // Constructor
    Rectangle(double w, double h);

    // Methods
    double getWidth() const;
    double getHeight() const;
    double area() const;
    double perimeter() const;

    // Mutators
    void setWidth(double w);
    void setHeight(double h);
};

#endif // RECTANGLE_H
