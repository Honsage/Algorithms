# Algorithms and Data Structures


# Brief description
This repository contains solutions of common data processing algorithms and data structures.

## Detailed description
Repository has several directories with solutions for certain algorithm classes. These directories are:
* ### Sorting
  Directory contains header file with the definition of several sorting algorithms. Templated implementation is in .tpp file. There are sorting:
    * bubble
    * selection
    * insertion
    * cocktail
    * quick (Hoare)
  
  And some comparators to set the sorting order.
* ### Graphs
   There are common algorithms, based on Graphs. Algorithms implemented:
    * Dijkstra method of finding shortest paths.
* ### HashTables
* ...

## Interaction with the solutions
You can use these solutions in several ways:
1. Just copy the source code of needed methods.
2. Clone the whole repo to your computer:
    ```bash
      git clone https://github.com/MatheMateCS/Algorithms
    ```
   Create main.cpp in root directory, include in it appropriate headers from directories:

   ```C++
   #include "Sorting/sorting.h"
   
   int main() {
       bubbleSort();
   }
   ``` 
   And then build the project with cmake builder, for example create CMakeLists.txt:

   ```cmake
    cmake_minimum_required(VERSION 3.29)
    project(Algorithms)
    
    set(CMAKE_CXX_STANDARD 14)
    
    add_executable(Algorithms
        Sorting/sorting.h
        Sorting/sorting.tpp
        main.cpp
    )
    ```