#include <iostream>
#include <stdexcept>

void validateInput(std::string id, int age, float height)
{
    try {
        if (id.length() >= 6)
            throw(id);

        if (age < 18)
            throw(age);

        if (height < 1.50)
            throw(height);

        std::cout << "Input validations passed for id:" << id << ", age:" << age << ", height:" << height << "\n";      
    } 
    catch (std::string str) {
        std::cout << "Invalid Id : "<< str << "\n";
    }
    catch (int i) {
        std::cout << "Invalid Age : " << i << "\n";
    }
    catch(...) {
        std::cout << "Default Exception fired...!\n";
    }
}

void getAverage(int sum, int count)
{
    try {
        if (count == 0)
            throw std::runtime_error("Div by Zero\n");

        std::cout << "Average = " << (sum/count) << std::endl;
    } 
    catch (std::runtime_error &e) {
        std::cout << "Exception fired. " << e.what() << std::endl;
    }
}

int main()
{
    // validateInput("Jane", 20, 1.59);
    // validateInput("Jane Doe", 20, 1.59);
    // validateInput("Jane", 17, 1.59);
    // validateInput("Jane", 19, 1.49);

    getAverage(10,3);
    getAverage(10,0);

    return 0;
}