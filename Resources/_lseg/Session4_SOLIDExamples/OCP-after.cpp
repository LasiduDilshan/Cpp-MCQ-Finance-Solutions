
#include <iostream>
using namespace std;


class Shape
{
public:
    virtual void draw() = 0;
};

class Circle : public Shape
{
public:
    virtual void draw()
    {
        cout << "Draw Circle" << endl;
    }
};

class Square : public Shape
{
public:
    virtual void draw()
    {
        cout << "Draw Square" << endl;
    }
};

class Pentagon : public Shape
{
public:
    virtual void draw()
    {
        cout << "Draw Pentagon" << endl;
    }
};


int main()
{
    Shape* s = new Circle();
    s->draw();
    s = new Square();
    s->draw();
    s = new Pentagon();
    s->draw();
}

