#include <iostream>
#define uint unsigned int

template <typename T>
bool asc(const T& lhs, const T& rhs) {
    return lhs < rhs;
}

template <typename T>
bool desc(const T &lhs, const T &rhs) {
    return lhs > rhs;
}

template <typename T>
void bubbleSort(T arr[], const uint size, bool comp(const T&, const T&) = asc) {
    bool isSorted = false;
    for (uint iter = 1; iter < size && !isSorted; ++iter) {
        isSorted = true;
        for (uint i = 0; i < size - iter; ++i) {
            if (!comp(arr[i], arr[i+1])) {
                std::swap(arr[i], arr[i+1]);
                isSorted = false;
            }
        }
    }
}

template <typename T>
void selectionSort(T arr[], uint size) {
    uint idxOfMin;
    for (uint i = 0; i < size-1; ++i) {
        idxOfMin = i;
        for (uint k = i + 1; k < size; ++k) {
            if (arr[k] < arr[idxOfMin]) {
                idxOfMin = k;
            }
        }
        std::swap(arr[i], arr[idxOfMin]);
    }
}

template <typename T>
void insertionSort(T arr[], uint size) {
    T key;
    int j;
    for (uint i = 1; i < size; ++i) {
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
}

template <typename T>
void cocktailSort(T arr[], uint size) {
    bool isSwapped = true;
    uint start = 0;
    uint end = size - 1;
    while (isSwapped) {
        std::cout << start << " " << end << "\n";
        isSwapped = false;
        for (uint i = start; i < end; ++i) {
            if (arr[i] > arr[i+1]) {
                std::swap(arr[i], arr[i+1]);
                isSwapped = true;
            }
        }
        if (!isSwapped) break;
        --end;

        for (uint i = end - 1; (int)i >= (int)start; --i) {
            if (arr[i] > arr[i+1]) {
                std::swap(arr[i], arr[i+1]);
                isSwapped = true;
            }
        }
        ++start;
    }
}

template <typename T>
void quickSort(T arr[], uint left, uint right) { // Hoare Sorting
    if (left >= right) return;
    uint i = left;
    uint j = right;
    T midValue = arr[(left + right) / 2];
    do {
        while(arr[i] < midValue) i++;
        while(arr[j] > midValue) j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++, j--;
        }
    } while (i <= j);
    if(j > left) quickSort(arr, left, j);
    if (i < right) quickSort(arr, i, right);
}

template <typename T>
void quickSort(T arr[], uint size) {
    quickSort(arr, 0, size-1);
}
