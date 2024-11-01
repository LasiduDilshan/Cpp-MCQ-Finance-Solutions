
#include <iostream>
using namespace std;


class CustomerDataAccess
{
public:
    string getCustomerName(int id) {
        return "Customer Name Derived from DB"; 
    }
};

class CustomerBusinessLogic
{
    CustomerDataAccess dataAccess;
public:
    string getCustomerName(int id)
    {
        return dataAccess.getCustomerName(id);
    }
};


int main()
{
    CustomerBusinessLogic customer;
    string name = customer.getCustomerName(1);
    cout << name << endl;
    
}
