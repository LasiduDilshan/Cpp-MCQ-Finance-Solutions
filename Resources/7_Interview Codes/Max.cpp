#include <iostream>

int findMax(int arr[], int size) {
    if (size == 0) return 0; // Handle empty array case

    int max = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int arr[] = {3, 1, 4, 1, 5, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    int max = findMax(arr, size);
    std::cout << "Maximum value in the array: " << max << std::endl;

    return 0;
}
