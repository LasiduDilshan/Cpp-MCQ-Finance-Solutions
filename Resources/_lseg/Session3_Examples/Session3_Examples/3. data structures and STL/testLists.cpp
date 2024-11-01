#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

// helper function for std::for_each
template<typename T>
void print(T a)
{
    std::cout << a << " ";
}

template<typename ContainerType, typename ElementType>
void printContainer(ContainerType& container)
{
    std::cout << "Elements in Container = "; 
    
    // std::for_each
    std::for_each(container.begin(), container.end(), print<ElementType>);

    std::cout << "\n";
}

void testLists()
{
    std::list<std::string> lst = { "e1", "e2", "e3"};

    lst.push_back("e4");
    lst.push_back("e2"); // duplicate value insert

    lst.push_front("e0");

    std::string valToFind = "e2";
    // std::find
    auto iter = std::find(lst.begin(), lst.end(), valToFind);
    if (iter != lst.end())
    {
        std::cout << "list contains " << valToFind << std::endl;
        iter = lst.erase(iter);
        std::cout << "After removing element [" << valToFind.c_str() << "] from List: \n";
        printContainer<std::list<std::string>, std::string>(lst);
    }
    else
    {
        std::cout << "list does not contain " << valToFind.c_str() << std::endl;
    }
    
    std::string valToInsert = "e9";
    lst.insert(iter, valToInsert);  // insert at current iter
    std::cout << "After inserting element [" << valToInsert.c_str() << "] to List: \n";
    printContainer<std::list<std::string>, std::string>(lst);

    // std::find_if_not
    auto isZeroLength = [](std::string s) { return s.length() == 0; };
    auto iter2 = std::find_if_not(std::begin(lst), std::end(lst), isZeroLength);
    if (iter2 != std::end(lst))
    {
        std::cout << "list contain/s non zero length element/s" << std::endl;
    }
	else
    {
        std::cout << "list does not contain non zero length element/s" << std::endl;
    }
}

int main()
{
    std::cout << "\nTesting with Lists...\n\n";
    testLists();

	std::cin.get();
}

// Output

/*
Testing with Lists...

list contains e2
After removing element [e2] from List: 
Elements in Container = e0 e1 e3 e4 e2 
After inserting element [e9] to List: 
Elements in Container = e0 e1 e9 e3 e4 e2 
list contain/s non zero length element/s
*/