#include <iostream>

// Overloaded operators allow customizing how operators like + and == work with this type.
// This enables intuitive and meaningful operations specific to this class or struct.

struct Point {
    int x, y;

    // Overload + operator to add two points
    Point operator + (const Point& p) {
        Point temp;
        temp.x = x + p.x;
        temp.y = y + p.y;
        return temp;
    }

    // Overload == operator to compare two points
    bool operator == (const Point& p) {
        return (x == p.x && y == p.y);
    }
};

int main() {
    Point p1 {2, 3};
    Point p2 {4, 5};

    // Adding two points
    Point p3 = p1 + p2;  // p3.x will be 6, p3.y will be 8

    // Comparing two points
    bool areEqual = (p1 == p2);  // areEqual will be false

    std::cout << "p3: (" << p3.x << ", " << p3.y << ")" << std::endl;
    std::cout << "p1 == p2: " << (areEqual ? "true" : "false") << std::endl;

    return 0;
}
