#ifndef SORTING_H
#define SORTING_H

#define uint unsigned int

template <typename T>
bool asc(const T&, const T&);

template <typename T>
bool desc(const T&, const T&);

template <typename T>
bool abs_asc(const T&, const T&);

template <typename T>
bool abs_desc(const T&, const T&);

template <typename T>
void bubbleSort(T arr[], uint size, bool comp(const T&, const T&) = asc);

template <typename T>
void selectionSort(T arr[], uint size, bool comp(const T&, const T&) = asc);

template <typename T>
void insertionSort(T arr[], uint size, bool comp(const T&, const T&) = asc);

template <typename T>
void cocktailSort(T arr[], uint size, bool comp(const T&, const T&) = asc);

template <typename T>
void quickSort(T arr[], uint left, uint right, bool comp(const T&, const T&) = asc); // Hoare Sorting

template <typename T>
void quickSort(T arr[], uint size, bool comp(const T&, const T&) = asc);

#include "sorting.tpp"

#endif //SORTING_H