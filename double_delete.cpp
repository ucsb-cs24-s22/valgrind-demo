#include <iostream>

using namespace std;

int main() {
    // allocate space on the heap
    int* arr = new int[5];
    
    // free space on the heap
    delete[] arr;

    // free space on the heap (again)
    delete[] arr;
}