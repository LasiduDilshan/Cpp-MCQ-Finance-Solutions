
#include <iostream>
using namespace std;

class  IPhotocopy
{
public:
    virtual void photocopy() = 0;
};
class IPrint
{
public:
    virtual void print() = 0;
};
class IScan
{
public:
    virtual void scan() = 0;
};

class MultiFunctionPhotocopyMachine : public IPhotocopy,IPrint, IScan
{
public:
    
    virtual void photocopy() override
    {
        cout << "MultiFunction Photocopy Success" << endl;
    }
    virtual void scan() override
    {
        cout << "MultiFunction Scan Success" << endl;
    }
    virtual void print() override
    {
        cout << "MultiFunction Print Success" << endl;
    }
};

class Printer : public IPrint
{
public:
    virtual void print() override
    {
        cout << "Printer Print Success" << endl;
    }
};

class PrintAndCopyMachine : public IPhotocopy, IPrint
{
public:
    virtual void photocopy() override
    {
        cout << "PrintAndCopyMachine Photocopy Success" << endl;
    }

    
    virtual void print() override
    {
        cout << "PrintAndCopyMachine Print Success" << endl;
    }
};
int main()
{
    MultiFunctionPhotocopyMachine m1;
    m1.print();
    m1.scan();
    PrintAndCopyMachine m2;
    m2.print();
    //m2.scan();
    Printer m3;
    m3.print();
    //m3.scan();
    
}
