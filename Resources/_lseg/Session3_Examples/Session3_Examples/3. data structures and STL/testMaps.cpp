#include <iostream>
#include <algorithm>
#include <map>

void printMap(std::map<int,int>& myMap)
{
    std::cout << "Key,Values pairs in Map = "; 
    for (auto& pair : myMap)
    {
        std::cout << "(" << pair.first << "," << pair.second << ") ";
    }
    std::cout << "\n";
}

void testMaps()
{
    std::map<int, int> myMap;

    myMap[10] = 10;
    myMap.insert(myMap.begin(), std::pair<int,int>(2,2));
    myMap.insert(std::pair<int,int>(8,8));
    myMap[1] = 1;

    printMap(myMap);

    int valToFind = 2;
    auto iter = myMap.find(valToFind);
    if (iter != myMap.end())
    {
        std::cout << "myMap contains " << valToFind << std::endl;
        myMap.erase(iter);
        std::cout << "After removing " << valToFind << " from map"<< std::endl;
        printMap(myMap);
    }
    else
    {
        std::cout << "map does not contain " << valToFind << std::endl;
    } 

    // std::find_if
    auto isNegative = [](auto& pair) { return pair.second < 0; };
    auto iter2 = std::find_if(std::begin(myMap), std::end(myMap), isNegative);
    if (iter2 != std::end(myMap))
    {
        std::cout << "map contain/s negative number/s" << std::endl;
    }
	else
    {
        std::cout << "map does not contain negative numbers " << std::endl;
    }
}

int main()
{
    std::cout << "\nTesting with Maps...\n\n";
    testMaps();

	std::cin.get();
}

// Output


/*
Testing with Maps...

Key,Values pairs in Map = (1,1) (2,2) (8,8) (10,10) 
myMap contains 2
After removing 2 from map
Key,Values pairs in Map = (1,1) (8,8) (10,10) 
map does not contain negative numbers

*/