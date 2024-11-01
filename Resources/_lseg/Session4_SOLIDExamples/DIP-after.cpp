

#include <iostream>
using namespace std;

class ICustomerDataAccess
{
public:
    virtual string getCustomerName(int id) = 0;
};

class CustomerDataAccess : public ICustomerDataAccess
{
public:
    virtual string getCustomerName(int id) {
        return "Customer Name Derived from DB";
    }
};


class CustomerBusinessLogic
{
    ICustomerDataAccess* dataAccess = new CustomerDataAccess();
public:
    string getCustomerName(int id)
    {
        return dataAccess->getCustomerName(id);
    }
};


int main()
{
    CustomerBusinessLogic customer;
    string name = customer.getCustomerName(1);
    cout << name << endl;
    
}

