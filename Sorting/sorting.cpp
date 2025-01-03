#include <iostream>
#define uint unsigned int

template <typename T>
void bubbleSort(T arr[], int size) {
    bool isSorted = false;
    for (uint iter = 1; iter < size && !isSorted; ++iter) {
        isSorted = true;
        for (uint i = 0; i < size - iter; ++i) {
            if (arr[i] > arr[i+1]) {
                std::swap(arr[i], arr[i+1]);
                isSorted = false;
            }
        }
    }
}
