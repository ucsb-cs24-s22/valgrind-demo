# Valgrind Demo

The [Valgrind website](https://valgrind.org/docs/manual/quick-start.html) says, "The Valgrind tool suite provides a number of **debugging and profiling tools** that help you make your programs faster and more correct. The most popular of these tools is called **Memcheck**. It can detect many **memory-related errors** that are common in C and C++ programs and that can lead to crashes and unpredictable behaviour." 

Memory-related errors are **runtime errors**, not compile-time errors; therefore, your compiler won't (and sometimes *can't*; see below) tell you when your code has memory-related errors. 

For those of you who are interested, an **undecidable problem** is a "decision problem for which it is proved to be impossible to construct an algorithm that always leads to a correct yes-or-no answer" ([Wikipedia](https://en.wikipedia.org/wiki/Undecidable_problem)). Even a seemingly innocent question about a runtime behavior can be undecidable, meaning no compiler can always answer it correctly. For example, "Will this C++ program terminate on this input, or will it get stuck in an infinite loop?" is more formally known as the **halting problem**, a canonical undecidable problem. The only way to "answer" this question is to run the program on the input and check if it terminates within some threshold (like 10 seconds).

## Examples

This repo contains C++ examples of common memory-related errors, including
- using uninitialized memory
- using memory after it has been freed on the heap
- using memory off the end of a block on the heap
- memory leaks
- mismatched or redundant deletes
- overlapping src and dst pointers in C library functions

## Running the Examples

### Step 1. Compile a Program
```
g++ copy_overlap.cpp
```

### Step 2. Run Valgrind
```
valgrind --tool=memcheck --leak-check=full ./a.out
```

### Step 3 (Optional but Useful): Save Valgrind Output in a File
```
valgrind --tool=memcheck --leak-check=full ./a.out 2> FILENAME.txt
```

## Other Resources

There are many valgrind tutorials and examples online, such as
- http://cs.ecs.baylor.edu/~donahoo/tools/valgrind/,
- https://pages.cs.wisc.edu/~bart/537/valgrind.html,
- https://web.stanford.edu/class/archive/cs/cs107/cs107.1222/resources/valgrind.html,
- https://ucsb-cs32.github.io/topics/tools_valgrind/ (from CS32)