#include <iostream>
#include <vector>

int main() {
    std::vector<int> myVector = {1, 2, 3, 4, 5};

    // Modify elements of the vector
    myVector[2] = 10; // Change the value at index 2 to 10

    // Add more elements
    myVector.push_back(6);
    myVector.push_back(7);

    // Print the vector before popping
    std::cout << "Vector before pop_back operation: ";
    for (int i = 0; i < myVector.size(); ++i) {
        std::cout << myVector[i] << " ";
    }
    std::cout << std::endl;

    // Remove the last element
    myVector.pop_back();

    // Print the vector after popping
    std::cout << "Vector after pop_back operation: ";
    for (int i = 0; i < myVector.size(); ++i) {
        std::cout << myVector[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}

/*In usual arrays we can change the elements of the array.
But cannot change the size. Here we can even change the size. 
That is the concept of dynamic arrays.*/
