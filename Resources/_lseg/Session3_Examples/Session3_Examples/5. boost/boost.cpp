#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/optional.hpp>
#include <boost/filesystem.hpp>
#include <boost/regex.hpp>

using namespace boost::multiprecision;
using namespace boost::filesystem;

template <typename T>
T getProduct(T num1, T num2)
{
	T val = num1 * num2;
	return val;
}

boost::optional<double> getAverage(int sum, int count)
{
    if (count > 0)
    {
        return (double)sum/count;
    }
    return {};
}

void testBoostMultiPrecision()
{
    std::cout << "\nTEST - testBoostMultiPrecision\n\n";
    // boost::multiprecision
    // support big integer data types like int128_t, int256_t, int512_t, int1024_t
    long long num1 = 123456789123456789;
	long long num2 = 111111111111111111;
	std::cout << num1 << " * " << num2 << " = " << getProduct<int128_t>((int128_t)num1, (int128_t)num2) << std::endl;  
    
    // multiprecision - can get higher preceisions like 50, 100
    // check the precision of product of 2 values with different data types & with boost precision
    std::cout << "Double Precision : " << std::setprecision(std::numeric_limits<double>::digits10) << getProduct<double>(1.23456789, 9.87654321) << std::endl;
    std::cout << "Float Precision : " << std::setprecision(std::numeric_limits<float>::digits10) << getProduct<float>(1.23456789, 9.87654321) << std::endl;
    std::cout << "Boost MulitPrecision : " << std::setprecision(std::numeric_limits<cpp_dec_float_50>::digits10) << getProduct<cpp_dec_float_50>(1.23456789, 9.87654321) << std::endl;  
}

void testBoostOptional()
{
    std::cout << "\nTEST - testBoostOptional\n\n";
    // define a boost optional object which can hold a double value
    boost::optional<double> optAvg;

    // check if the optional contains a value
    if (!optAvg) {
        std::cout << "optAvg is empty." << std::endl;
    }
    
    optAvg = getAverage(100,0); // optAvg should still remain empty
    if (!optAvg) {
        std::cout << "optAvg is empty." << std::endl;
    }
    
    // still we can try to get the optional value with a default value
    double avg = optAvg.value_or(0.0);
    std::cout << "avg = " << avg << std::endl;

    optAvg = getAverage(100,11); // optAvg should have a valid value now
    if (optAvg) {
        std::cout << "optAvg is not empty: " << std::endl;
        // we can get the optional value in below ways
        
        //avg = optAvg.value_or(0.0);
        //avg = *optAvg;
        avg = optAvg.get();
        std::cout << "avg = " << avg << std::endl;
    }

    // reset the optional (clear its value)
    optAvg.reset();

    // check if the optional is empty again
    if (!optAvg) {
        std::cout << "optAvg is empty after reset." << std::endl;
    }
}


void testBoostFileSystem() 
{
    std::cout << "\nTEST - testBoostFileSystem\n\n";
    // boost::filesystem
    // define a directory path
    path dirPath(".");

    // check if the path exists and is a directory
    if (exists(dirPath) && is_directory(dirPath)) 
    {
        std::cout << "Directory exists with below files in it : " << dirPath << std::endl;
        
        // list the files in the directory
        for (directory_iterator itr(dirPath), end; itr != end; ++itr) 
        {
            path filePath = itr->path();
            std::cout << (is_directory(filePath) ? "\t[DIR] " : "\t[FILE] ") << filePath.filename().string() << std::endl;
        }
    } 
    else 
    {
        std::cout << "Directory does not exist or is not a Directory." << std::endl;
    }

    // define a file path
    path filePath("myTest.txt");

    // check if the file exists
    if (exists(filePath)) 
    {
        std::cout << "File exists : " << filePath << std::endl;
    }
    else 
    {
        std::cout << "File does not exist : " << filePath << std::endl;
    }

}

void testBoostRegex()
{
    std::cout << "\nTEST - testBoostRegex\n\n";

    // regex to find a given pattern in a string
    std::string myText = "Hello World";
    boost::regex myPattern1("Hello");

    if (boost::regex_search(myText, myPattern1))
    {
        std::cout << "Pattern found in the text" << std::endl;
    } 
    else 
    {
        std::cout << "Pattern NOT found in the text" << std::endl;
    }

    // regex to find a given pattern in a string - ignore case
    boost::regex myPattern2("HELLO", boost::regex::icase);  // pattern with ignore case
    if (boost::regex_search(myText, myPattern2))
    {
        std::cout << "Pattern found (ignore case) in the text" << std::endl;
    } 
    else 
    {
        std::cout << "Pattern NOT found in the text" << std::endl;
    }

    // regex to do basic input validations
    boost::regex myPattern3("^[^@\\s]+@[^@\\s]+\\.[^@\\s]+$");
    std::string myEmail = "janeDoe@gmail.com";
    
    if (boost::regex_match(myEmail, myPattern3))
    {
        std::cout << "Valid Email Address" << std::endl;
    }
    else
    {
        std::cout << "Invalid Email Address" << std::endl;
    }

    // regex to extract values from a string
    std::string myInfoText = "Name: John Doe, Age: 20, Height: 5.2 ft";
    boost::regex myPattern4(R"(Name:\s*([A-Za-z\s]+),\s*Age:\s*(\d+),\s*Height:\s*([\d.]+\s*ft))");    // regex to capture name, age, and height
    boost::smatch myInfo;

    if (boost::regex_search(myInfoText, myInfo, myPattern4))
    {
        std::cout << "Extracted Information:\n";
        std::cout << "\tName: " << myInfo[1] << std::endl;
        std::cout << "\tAge: " << myInfo[2] << std::endl;
        std::cout << "\tHeight: " << myInfo[3] << std::endl;
    }
    else
    {
        std::cout << "Not found" << std::endl;
    }

    // reference - https://cplusplus.com/reference/regex/
}


int main()
{
    testBoostMultiPrecision();
    testBoostOptional();
    testBoostFileSystem();
    testBoostRegex();
	return 0;
}
