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

## Understanding Memory Leaks

According to this [tutorial from Stanford](https://web.stanford.edu/class/archive/cs/cs107/cs107.1222/resources/valgrind.html), Valgrind categorizes leaks using these terms (found in the LEAK SUMMARY):
- *definitely lost*: heap-allocated memory that was never freed to which the program no longer has a pointer. Valgrind knows that you once had the pointer, but have since lost track of it. This memory is definitely orphaned.
- *indirectly lost*: heap-allocated memory that was never freed to which the only pointers to it also are lost. For example, if you orphan a linked list, the first node would be definitely lost, the subsequent nodes would be indirectly lost.
- *possibly lost*: heap-allocated memory that was never freed to which valgrind cannot be sure whether there is a pointer or not.
- *still reachable*: heap-allocated memory that was never freed to which the program still has a pointer at exit.

## Other Resources

There are many valgrind tutorials and examples online, such as
- http://cs.ecs.baylor.edu/~donahoo/tools/valgrind/,
- https://pages.cs.wisc.edu/~bart/537/valgrind.html,
- https://web.stanford.edu/class/archive/cs/cs107/cs107.1222/resources/valgrind.html,
- https://ucsb-cs32.github.io/topics/tools_valgrind/ (from CS32)
