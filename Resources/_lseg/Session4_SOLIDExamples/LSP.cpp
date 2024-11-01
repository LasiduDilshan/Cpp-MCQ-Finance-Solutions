
#include <iostream>
using namespace std;

class Bird
{

public: 
    virtual void fly() =0;
};

class Parrot: public Bird
{
 //this is okay
    void fly()
    {
        cout << "Bird flies" << endl;
    }
};

class Ostrich : public Bird
{
//this is wrong. Ostrich cant fly :(.
    void fly()
    {
        cerr << "Ostrich cannot fly" << endl;
    }
};

int main()
{
    Bird* b = new Parrot();
    b->fly();
    b = new Ostrich();
    b->fly();
}

