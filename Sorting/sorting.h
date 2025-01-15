#ifndef SORTING_H
#define SORTING_H


#define uint unsigned int

template <typename T>
bool asc(const T&, const T&);

template <typename T>
bool desc(const T &, const T &);

template <typename T>
bool abs_asc(const T&, const T&);

template <typename T>
bool abs_desc(const T &, const T &);

template <typename T>
void bubbleSort(T [], uint , bool (const T&, const T&));

template <typename T>
void selectionSort(T [], uint, bool (const T&, const T&));

template <typename T>
void insertionSort(T [], uint, bool (const T&, const T&));

template <typename T>
void cocktailSort(T [], uint, bool (const T&, const T&));

template <typename T>
void quickSort(T [], uint, uint, bool (const T&, const T&));

template <typename T>
void quickSort(T [], uint, bool (const T&, const T&));


#endif //SORTING_H