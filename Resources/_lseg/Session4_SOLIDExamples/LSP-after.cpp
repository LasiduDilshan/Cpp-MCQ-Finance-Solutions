
#include <iostream>
using namespace std;

class Bird
{

public: 
    
};

class FlyingBird : public Bird
{
public:
    void fly()
    {
        cout << "Bird flies" << endl;
    }
};

class Parrot: public FlyingBird
{
 //this is okay
};

class Ostrich : public Bird
{
//this is wrong. Ostrich cant fly :(.
};

int main()
{
    FlyingBird* b = new Parrot();
    b->fly();
    Bird* nb = new Ostrich();
    //nb->fly();
}
