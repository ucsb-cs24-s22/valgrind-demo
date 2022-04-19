#include <iostream>

using namespace std;

int main() {
    // allocate space on the heap
    // and initialize values
    int *ptr = new int(42), 
        **ptr_to_ptr = new int*(ptr);

    cout << *ptr << endl;
    cout << **ptr_to_ptr << endl;
    
    // free space on the heap
    delete ptr_to_ptr;

    // question for you: why is there
    // a memory leak?
}