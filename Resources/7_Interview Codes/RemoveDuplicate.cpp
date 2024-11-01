#include <iostream>

void removeDuplicates(int arr[], int& size) {
    int newSize = 0;
    for (int i = 0; i < size; ++i) {
        bool isDuplicate = false;
        for (int j = 0; j < newSize; ++j) {
            if (arr[i] == arr[j]) {
                isDuplicate = true;
                break;
            }
        }
        if (!isDuplicate) {
            arr[newSize++] = arr[i];
        }
    }
    size = newSize;
}

int main() {
    int arr[] = {1, 2, 3, 2, 4, 1, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    removeDuplicates(arr, size);

    std::cout << "Array after removing duplicates: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    std::cout << sizeof(arr) << std::endl;

    return 0;
}
