#include <iostream>

template <typename T, int size=10>
class MyArray
{
public:
    void setValueAt(int index, T value) { m_array[index] = value; }
    T getValueAt(int index) { return m_array[index]; }  

private:
    T m_array[size];
};

int main()
{
	MyArray<int,5> intArray;
    intArray.setValueAt(2,20);
    std::cout << "Value at index = " << intArray.getValueAt(2) << std::endl;

    MyArray<std::string> stringArray;
    stringArray.setValueAt(1,"ONE");
    std::cout << "Value at index = " << stringArray.getValueAt(1) << std::endl;

	std::cin.get();
}

// Output

/*
Value at index = 20
Value at index = ONE
*/