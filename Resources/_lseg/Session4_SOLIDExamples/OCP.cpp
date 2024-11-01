
#include <iostream>
using namespace std;

enum ShapeType
{
    Circle,
    Square,
    Pentagon
};
class ShapeDrawer
{
    void drawCircle() { cout << "Draw Circle" << endl; }
    void drawSquare(){ cout << "Draw Square" << endl; }
    void drawPentagon(){ cout << "Draw Pentagon" << endl; }
public:
    void draw(ShapeType s)
    {
        if (s == Circle)
        {
            drawCircle();
        }
        else if (s = Square)
        {
            drawSquare();
        }
        else if (s = Pentagon)
        {
            drawPentagon();
        }
    }
};


int main()
{
    ShapeDrawer shapedrawer;
    shapedrawer.draw(Circle);
    shapedrawer.draw(Pentagon);
    
}

