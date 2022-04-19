#include <iostream>

using namespace std;

int main() {
    // allocate space on the heap
    int* arr = new int[5];
    
    // free space on the heap.
    // note that we should be
    // using delete[] because 
    // arr points to an array
    delete arr;
}