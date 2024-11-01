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

void testVectors()
{
    std::vector<int> vec = { 1, 2, 3 };
    
    std::cout << "Size of vec = " << vec.size() << std::endl;
    vec.push_back(4);
    std::cout << "Size of vec = " << vec.size() << std::endl;
    vec.resize(5);
    std::cout << "Size of vec = " << vec.size() << std::endl;
    printContainer<std::vector<int>, int>(vec);

    vec[4] = 5;
    printContainer<std::vector<int>, int>(vec);

	int valToFind = 3;
    // std::find
    // std::vector<int>::iterator itr1 = std::find(std::begin(vec), std::end(vec), valToFind);
	auto itr1 = std::find(std::begin(vec), std::end(vec), valToFind);
	if (itr1 != std::end(vec))
    {
        std::cout << "vector contains " << valToFind << std::endl;
        
        vec.erase(itr1);
        std::cout << "After removing element " << valToFind << " from vector: \n";
        printContainer<std::vector<int>, int>(vec);
    }
	else
    {
        std::cout << "vector does not contain " << valToFind << std::endl;
    }

    // erase by position
    int indexToDelete = 1;
    vec.erase(vec.begin() + indexToDelete);
    std::cout << "After removing vector element at index " << indexToDelete << "\n";
    printContainer<std::vector<int>, int>(vec);

    // std::find_if
    auto isEven = [](int i) { return i % 2 == 0; };
    auto itr2 = std::find_if(std::begin(vec), std::end(vec), isEven);
    if (itr2 != std::end(vec))
    {
        std::cout << "vector contain/s even number/s" << std::endl;
    }
	else
    {
        std::cout << "vector does not contain even numbers " << std::endl;
    }
}

int main()
{
    std::cout << "\nTesting with Vectors...\n\n";
	testVectors();

	std::cin.get();
}

// Output


/*
Testing with Vectors...

Size of vec = 3
Size of vec = 4
Size of vec = 5
Elements in Container = 1 2 3 4 0 
Elements in Container = 1 2 3 4 5 
vector contains 3
After removing element 3 from vector: 
Elements in Container = 1 2 4 5 
After removing vector element at index 1
Elements in Container = 1 4 5 
vector contain/s even number/s

*/