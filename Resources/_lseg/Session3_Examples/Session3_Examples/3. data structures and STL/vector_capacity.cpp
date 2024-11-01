#include <iostream>
#include <vector>

void printVectorDetails(const std::vector<int>& vec) {
    std::cout << "Size: " << vec.size() << ", Capacity: " << vec.capacity() << std::endl;
}

int main() {
    std::vector<int> vec;

    // Print initial capacity and size
    std::cout << "Initial vector:" << std::endl;
    printVectorDetails(vec);

    // Insert elements and observe capacity
    std::cout << "Inserting elements..." << std::endl;
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
        printVectorDetails(vec);
    }

    // Remove elements and observe capacity
    std::cout << "Removing elements..." << std::endl;
    for (int i = 0; i < 5; ++i) {
        vec.pop_back();
        printVectorDetails(vec);
    }

    // Reserve more space and observe capacity
    std::cout << "Reserving more space..." << std::endl;
    vec.reserve(20);
    printVectorDetails(vec);

    // Shrink to fit
    std::cout << "Shrinking to fit..." << std::endl;
    vec.shrink_to_fit();
    printVectorDetails(vec);
    
    // Insert elements again and observe capacity
    std::cout << "Inserting elements again..." << std::endl;
    for (int i = 0; i < 10; ++i) {
        vec.push_back(i);
        printVectorDetails(vec);
    }
    
    return 0;
}
// Output

/*
Initial vector:
Size: 0, Capacity: 0
Inserting elements...
Size: 1, Capacity: 1
Size: 2, Capacity: 2
Size: 3, Capacity: 4
Size: 4, Capacity: 4
Size: 5, Capacity: 8
Size: 6, Capacity: 8
Size: 7, Capacity: 8
Size: 8, Capacity: 8
Size: 9, Capacity: 16
Size: 10, Capacity: 16
Removing elements...
Size: 9, Capacity: 16
Size: 8, Capacity: 16
Size: 7, Capacity: 16
Size: 6, Capacity: 16
Size: 5, Capacity: 16
Reserving more space...
Size: 5, Capacity: 20
Shrinking to fit...
Size: 5, Capacity: 5
Inserting elements again...
Size: 6, Capacity: 10
Size: 7, Capacity: 10
Size: 8, Capacity: 10
Size: 9, Capacity: 10
Size: 10, Capacity: 10
Size: 11, Capacity: 20
Size: 12, Capacity: 20
Size: 13, Capacity: 20
Size: 14, Capacity: 20
Size: 15, Capacity: 20
*/