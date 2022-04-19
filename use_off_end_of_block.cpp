#include <iostream>

using namespace std;

int main() {
    // allocate space on the heap
    int* arr = new int[5];
    
    // write to each index in arr.
    // note that the last index
    // should be 4, not 5!
    for(int i = 0; i <= 5; i++) {
        arr[i] = i;
    }

    // read from each index in arr.
    // note that the last index
    // should be 4, not 5!
    for(int i = 0; i <= 5; i++) {
        cout << arr[i] << endl;
    }
    
    // free space on the heap
    delete[] arr;
}