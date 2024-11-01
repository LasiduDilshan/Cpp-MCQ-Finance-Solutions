

#include <iostream>
using namespace std;

class  MultiFunctionMachine
{
public:
    virtual void photocopy() = 0;
    virtual void scan() = 0;
    virtual void print() = 0;
};

class MultiFunctionPhotocopyMachine : public MultiFunctionMachine
{
public:
    virtual void photocopy()
    {
        cout << "MultiFunction Photocopy Success" << endl;
    }
    virtual void scan()
    {
        cout << "MultiFunction Scan Success" << endl;
    }
    virtual void print()
    {
        cout << "MultiFunction Print Success" << endl;
    }
};

class Printer : public MultiFunctionMachine
{
public:
    virtual void photocopy()
    {
        cout << "Printer : Photocopy Not Implemented" << endl;
    }
    virtual void scan()
    {
        cout << "Printer : Scan Not Implemented" << endl;
    }
    virtual void print()
    {
        cout << "Printer Print Success" << endl;
    }
};

class PrintAndCopyMachine : public MultiFunctionMachine
{
public:
    virtual void photocopy()
    {
        cout << "PrintAndCopyMachine Photocopy Success" << endl;
    }

    virtual void scan()
    {
        cout << "PrintAndCopyMachine : Scan Not Implemented" << endl;
    }
    virtual void print()
    {
        cout << "PrintAndCopyMachine Print Success" << endl;
    }
};
int main()
{
    MultiFunctionMachine* m1 = new MultiFunctionPhotocopyMachine();
    m1->print();
    m1->scan();
    MultiFunctionMachine* m2 = new PrintAndCopyMachine();
    m2->print();
    m2->scan();
    MultiFunctionMachine* m3 = new Printer();
    m3->print();
    m3->scan();
    
}
