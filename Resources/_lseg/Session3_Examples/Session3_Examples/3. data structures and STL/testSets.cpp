#include <iostream>
#include <algorithm>
#include <set>

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

void testSets() 
{
    std::set<int> mySet;

    mySet.insert(10);
    mySet.insert(20);
    mySet.insert(30);
    mySet.insert(40);
    mySet.insert(50);

    // Find an element in the set
    int keyToFind = 30;
    auto itr = mySet.find(keyToFind);
    if (itr != mySet.end()) 
    {
        std::cout << "Element " << keyToFind << " found in the set." << std::endl;
        
        // Atempt to insert duplicates
        mySet.insert(keyToFind);
        
        printContainer<std::set<int>, int>(mySet);
    } 
    else 
    {
        std::cout << "Element " << keyToFind << " not found in the set." << std::endl;
    }
    
    if (itr != mySet.end())
    {
        mySet.insert(itr, 35); // insert elements with help of iterator
    }

    // Iterate over the set and print elements
    printContainer<std::set<int>, int>(mySet);

    // Delete an element from the set
    int keyToDelete = 20;
    size_t erasedCount = mySet.erase(keyToDelete);
    if (erasedCount > 0) 
    {
        std::cout << "Element " << keyToDelete << " deleted from the set." << std::endl;
    } 
    else 
    {
        std::cout << "Element " << keyToDelete << " not found to delete." << std::endl;
    }

    // Iterate over the set after deletion
    std::cout << "Elements in the set after deletion: \n";
    printContainer<std::set<int>, int>(mySet);
}

int main() 
{
    std::cout << "\nTesting with Sets...\n\n";
    testSets();

	std::cin.get();
}

// Output

/*
Testing with Sets...

Element 30 found in the set.
Elements in Container = 10 20 30 40 50 
Elements in Container = 10 20 30 35 40 50 
Element 20 deleted from the set.
Elements in the set after deletion: 
Elements in Container = 10 30 35 40 50 

*/
