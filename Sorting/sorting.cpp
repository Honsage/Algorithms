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

template <typename T>
void selectionSort(T arr[], int size) {
    uint idxOfMin;
    for(uint i = 0; i < size-1; ++i) {
        idxOfMin = i;
        for(uint k = i + 1; k < size; ++k) {
            if(arr[k] < arr[idxOfMin]) {
                idxOfMin = k;
            }
        }
        std::swap(arr[i], arr[idxOfMin]);
    }
}
