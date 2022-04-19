#include <iostream>

using namespace std;

int main() {
    // allocate space on the heap
    // do not initialize the int
    int* ptr = new int(42);
    
    // dereference the pointer to the
    // uninitialized int
    cout << *ptr << endl;
    
    // free space on the heap
    delete ptr;

    // dereference the pointer to the
    // int that has since been freed
    cout << *ptr << endl;
}