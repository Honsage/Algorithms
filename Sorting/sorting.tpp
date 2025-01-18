#ifndef SORTING_TPP
#define SORTING_TPP

template <typename T>
bool asc(const T& lhs, const T& rhs) {
    return lhs < rhs;
}

template <typename T>
bool desc(const T &lhs, const T &rhs) {
    return lhs > rhs;
}

template <typename T>
bool abs_asc(const T& lhs, const T& rhs) {
    return abs(lhs) < abs(rhs);
}

template <typename T>
bool abs_desc(const T &lhs, const T &rhs) {
    return abs(lhs) > abs(rhs);
}

template <typename T>
void bubbleSort(T arr[], const uint size, bool comp(const T&, const T&)) {
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
void selectionSort(T arr[], const uint size, bool comp(const T&, const T&)) {
    uint idxOfExtr;
    for (uint i = 0; i < size-1; ++i) {
        idxOfExtr = i;
        for (uint k = i + 1; k < size; ++k) {
            if (comp(arr[k], arr[idxOfExtr])) {
                idxOfExtr = k;
            }
        }
        std::swap(arr[i], arr[idxOfExtr]);
    }
}

template <typename T>
void insertionSort(T arr[], const uint size, bool comp(const T&, const T&)) {
    T key;
    int j;
    for (uint i = 1; i < size; ++i) {
        key = arr[i];
        j = i-1;
        while (j >= 0 && !comp(arr[j], key)) {
            arr[j+1] = arr[j];
            --j;
        }
        arr[j+1] = key;
    }
}

template <typename T>
void cocktailSort(T arr[], const uint size, bool comp(const T&, const T&)) {
    bool isSwapped = true;
    uint start = 0;
    uint end = size - 1;
    while (isSwapped) {
        isSwapped = false;
        for (uint i = start; i < end; ++i) {
            if (!comp(arr[i], arr[i+1])) {
                std::swap(arr[i], arr[i+1]);
                isSwapped = true;
            }
        }
        if (!isSwapped) break;
        --end;

        for (uint i = end - 1; (int)i >= (int)start; --i) {
            if (!comp(arr[i], arr[i+1])) {
                std::swap(arr[i], arr[i+1]);
                isSwapped = true;
            }
        }
        ++start;
    }
}

template <typename T>
void quickSort(T arr[], uint left, uint right, bool comp(const T&, const T&)) {
    if (left >= right) return;
    uint i = left;
    uint j = right;
    T midValue = arr[(left + right) / 2];
    do {
        while(comp(arr[i], midValue)) i++;
        while(comp(midValue, arr[j])) j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            if (j != 0) j--;
        }
    } while (i <= j);
    if(j > left) quickSort(arr, left, j, comp);
    if (i < right) quickSort(arr, i, right, comp);
}

template <typename T>
void quickSort(T arr[], uint size, bool comp(const T&, const T&)) {
    quickSort(arr, 0, size-1, comp);
}

#endif //SORTING_TPP