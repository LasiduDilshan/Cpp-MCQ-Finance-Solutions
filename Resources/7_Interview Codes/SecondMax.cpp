#include <iostream>

int findSecondMax(int arr[], int size) {
    if (size < 2) return -1; // Not enough elements

    int max = arr[0];
    int secondMax = -1;

    for (int i = 1; i < size; ++i) {
        if (arr[i] > max) {
            secondMax = max;
            max = arr[i];
        } else if (arr[i] > secondMax && arr[i] < max) {
            secondMax = arr[i];
        }
    }

    return secondMax;
}

int main() {
    int arr[] = {3, 1, 4, 1, 5, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    int secondMax = findSecondMax(arr, size);
    if (secondMax == -1) {
        std::cout << "There is no second maximum value in the array." << std::endl;
    } else {
        std::cout << "Second maximum value in the array: " << secondMax << std::endl;
    }

    return 0;
}
