Sure! Below is a comprehensive C++ tutorial that covers the basics from the beginning to the use of `struct`. This should give you a solid foundation in C++ programming. Let's start step by step.

---

## **C++ Basics to Struct Tutorial**

### 1. **Introduction to C++**

C++ is a powerful, high-level programming language developed as an extension of C. It supports both procedural and object-oriented programming.

#### Why C++?
- Combines the power of low-level languages with high-level features.
- Rich standard library.
- Used for system programming, game development, embedded systems, etc.

### 2. **Hello, World! Program**

A simple program that outputs "Hello, World!" to the console.

```cpp
#include <iostream>  // Library for input/output

int main() {
    std::cout << "Hello, World!" << std::endl;  // Output
    return 0;  // End of program
}
```

#### Key Points:
- `#include <iostream>`: Includes the input/output stream library.
- `std::cout`: Outputs text to the console.
- `<<`: Output operator.
- `std::endl`: Adds a new line.

### 3. **Variables and Data Types**

Variables store data in memory. Common C++ data types include:
- `int`: Integer numbers.
- `float`: Floating-point numbers.
- `double`: Double precision floating-point numbers.
- `char`: Single characters.
- `bool`: Boolean values (true/false).

#### Example:

```cpp
#include <iostream>

int main() {
    int age = 25;  // Integer
    double weight = 70.5;  // Double (float with more precision)
    char grade = 'A';  // Character
    bool is_passed = true;  // Boolean

    std::cout << "Age: " << age << std::endl;
    std::cout << "Weight: " << weight << std::endl;
    std::cout << "Grade: " << grade << std::endl;
    std::cout << "Passed: " << is_passed << std::endl;

    return 0;
}
```

#### Key Points:
- `=`: Assignment operator.
- Variables must be declared with their type before use.

### 4. **Input and Output**

To read data from the user, use `std::cin`.

#### Example:

```cpp
#include <iostream>

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;  // Taking input from user

    std::cout << "You entered: " << number << std::endl;
    return 0;
}
```

### 5. **Operators**

C++ supports various operators, such as:
- Arithmetic: `+`, `-`, `*`, `/`, `%`
- Relational: `==`, `!=`, `>`, `<`, `>=`, `<=`
- Logical: `&&`, `||`, `!`

#### Example:

```cpp
#include <iostream>

int main() {
    int a = 10, b = 20;

    std::cout << "Sum: " << a + b << std::endl;
    std::cout << "Difference: " << a - b << std::endl;
    std::cout << "Product: " << a * b << std::endl;
    std::cout << "Quotient: " << b / a << std::endl;

    return 0;
}
```

### 6. **Control Structures**

Control structures help in decision-making and looping.

#### a. **If-Else**

```cpp
#include <iostream>

int main() {
    int num = 5;

    if (num > 0) {
        std::cout << "Positive number" << std::endl;
    } else {
        std::cout << "Non-positive number" << std::endl;
    }

    return 0;
}
```

#### b. **For Loop**

```cpp
#include <iostream>

int main() {
    for (int i = 0; i < 5; i++) {
        std::cout << "i: " << i << std::endl;
    }

    return 0;
}
```

#### c. **While Loop**

```cpp
#include <iostream>

int main() {
    int i = 0;

    while (i < 5) {
        std::cout << "i: " << i << std::endl;
        i++;
    }

    return 0;
}
```

### 7. **Functions**

A function is a reusable block of code.

#### Defining a Function:

```cpp
#include <iostream>

void greet() {  // Function definition
    std::cout << "Hello!" << std::endl;
}

int main() {
    greet();  // Function call
    return 0;
}
```

#### Functions with Parameters:

```cpp
#include <iostream>

void printSum(int a, int b) {  // Function with parameters
    std::cout << "Sum: " << a + b << std::endl;
}

int main() {
    printSum(5, 10);  // Pass arguments to the function
    return 0;
}
```

### 8. **Arrays**

Arrays store multiple values of the same type.

#### Example:

```cpp
#include <iostream>

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};

    for (int i = 0; i < 5; i++) {
        std::cout << numbers[i] << std::endl;
    }

    return 0;
}
```

### 9. **Pointers**

Pointers store the memory address of a variable.

#### Example:

```cpp
#include <iostream>

int main() {
    int num = 10;
    int* ptr = &num;  // Pointer to num

    std::cout << "Value of num: " << num << std::endl;
    std::cout << "Address of num: " << ptr << std::endl;
    std::cout << "Value at ptr: " << *ptr << std::endl;  // Dereferencing the pointer

    return 0;
}
```

### 10. **Structures (Struct)**

A `struct` is used to group different types of data together.

#### Defining a `struct`:

```cpp
#include <iostream>

// Define a structure
struct Person {
    std::string name;
    int age;
    double height;
};

int main() {
    // Declare and initialize a structure
    Person person1 = {"John", 30, 5.9};

    // Accessing structure members
    std::cout << "Name: " << person1.name << std::endl;
    std::cout << "Age: " << person1.age << std::endl;
    std::cout << "Height: " << person1.height << std::endl;

    return 0;
}
```

#### Key Points:
- `struct` allows grouping of different types of data under one name.
- Members of a structure are accessed using the `.` operator.

### **Conclusion**

By following this tutorial, you've learned the basics of C++ and how to use structures (`struct`). You now know how to:
- Write a basic C++ program.
- Declare variables and perform input/output.
- Use operators, control structures, and loops.
- Define and use functions.
- Work with arrays and pointers.
- Define and manipulate structures.

Next, you can explore more advanced topics like classes, inheritance, and polymorphism to continue your C++ journey!

--- 

Feel free to ask for more information if needed or if you'd like to explore a specific topic in more detail!