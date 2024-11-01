#include <iostream>

using namespace std;

template<typename T>
void swapValues(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    cout << "\nSwap int variables\n";
    int a = 5, b = 10;
    cout << "Before Swap: a = " << a << " | b = " << b << endl;
    swapValues<int>(a,b);
    cout << "After Swap: a = " << a << " | b = " << b << endl;

    cout << "\nSwap double variables\n";
    double c = 1.25, d = 4.75;
    cout << "Before Swap: c = " << c << " | d = " << d << endl;
    swapValues<double>(c,d);
    cout << "After Swap: c = " << c << " | d = " << d << endl;

    cout << "\nSwap string variables\n";
    string e = "First", f = "Second";
    cout << "Before Swap: e = " << e.c_str() << " | f = " << f.c_str() << endl;
    swapValues<string>(e,f);
    cout << "After Swap: e = " << e.c_str() << " | f = " << f.c_str() << endl;

    return 0;
}

// Output

/*
Swap int variables
Before Swap: a = 5 | b = 10
After Swap: a = 10 | b = 5

Swap double variables
Before Swap: c = 1.25 | d = 4.75
After Swap: c = 4.75 | d = 1.25

Swap string variables
Before Swap: e = First | f = Second
After Swap: e = Second | f = First
*/