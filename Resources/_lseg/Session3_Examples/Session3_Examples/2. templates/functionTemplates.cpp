#include <iostream>

template <typename T>
T add(T a, T b)
{
	return (a + b);
}

// int add(int a, int b)
// {
// 	return (a + b);
// }

// double add(double a, double b)
// {
// 	return (a + b);
// }

// char add(char a, char b)
// {
// 	return (a + b);
// }

int main()
{
	std::cout << add<int>(20, 30) << std::endl;
	std::cout << add<double>(5.4, 9.7) << std::endl;
	std::cout << add<char>('1', '2') << std::endl;	// addition of decimal values of '1' -> 49, '2' -> 50 => 49+50 = 99 -> 'c'
	
	std::cin.get();
}

// Output
/*
50
15.1
c
*/