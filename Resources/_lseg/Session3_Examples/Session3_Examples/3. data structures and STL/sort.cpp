#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main()
{
	std::vector<int> vec = { 3, 2, 1, 5, 4 };
	std::cout << "Before sort: ";
	for (int val : vec)
	{
		std::cout << " " << val;
	}
	std::cout << std::endl;

	std::sort(vec.begin(), vec.end());
	std::cout << "ASC: ";
	for (int val : vec)
	{
		std::cout << " " << val;
	}
	std::cout << std::endl;

	std::sort(vec.begin(), vec.end(), std::greater<int>());
	std::cout << "DES: ";
	for (int val : vec)
	{
		std::cout << " " << val;
	}
	std::cout << std::endl;
	
	std::cin.get();
}

// Output

/*
Before sort:  3 2 1 5 4
ASC:  1 2 3 4 5
DES:  5 4 3 2 1

*/