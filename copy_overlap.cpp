#include <cstring>
#include <iostream>

using namespace std;

char* a_cstring = "a c-string";

int main() {
    // allocate space on the heap
    char* arr = new char[11];

    // put the c-string in the buffer
    strcpy(arr, a_cstring);

    cout << arr << endl;

    // replace " " with "\0" to turn
    // the c-string into two c-strings
    // in the same buffer
    arr[1] = '\0';

    char* a = arr;           // ptr to "a"
    char* cstring = arr + 2; // ptr to "c"

    // copy "c-string" into the beginning
    // of the buffer, overwriting "a"
    strcpy(a, cstring);

    cout << arr << endl;

    delete[] arr;

    // question for you: where is the
    // "overlap"?
}