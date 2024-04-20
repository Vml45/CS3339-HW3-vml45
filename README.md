# CS3339-HW3-vml45
# Cache Simulator

### Overview
This project implements a simple cache simulator in C++ designed to help understand and analyze cache behavior with varying memory references. The simulator models a cache's operation including the processes of hits, misses, and cache line replacement based on the Least Recently Used (LRU) algorithm. This tool can be used for educational purposes or to enhance understanding of computer architecture concepts related to cache memory.

### Bug Description
Upon thorough testing and review of the cache_simulator program, no bugs were identified. The application executed smoothly across various test scenarios including different cache sizes, associativity levels, and input memory reference patterns. All functions behaved as expected, accurately simulating cache behavior with consistent and correct handling of cache hits and misses.
   
### Usage
Here are the steps to clone and run a repository:

Open a terminal and on your Linux machine we will be using zeus/capi to run the program:
``` 
- ssh NET_ID@zeus.cs.txstate.edu
- ssh capi.cs.txstate.edu 
```
  - Replace NET_ID with your NET_ID

Clone the GitHub repository using the git clone command followed by the repository URL. For example:
- ``` git clone https://git.txstate.edu/vml45/CS3339-HW3-vml45.git ```
  - The git clone command is used to create a copy of a Git repository from a remote source

Change directory into the cloned repository:
- ``` cd CS3339-HW3-vml45 ```
  - The command cd CS3339-HW3-vml45 changes the current directory to a directory named "CS3339-HW3-vml45"

Compile the source code files using g++. For example, to compile "HW3.cpp" and generate an executable named "HW3"
- ```g++ -o HW3 HW3.cpp ```
  - The command g++ -o HW3 HW3.cpp is a compilation command in C++. 
  - It compiles the source code file "HW3.cpp" and generates an executable file named "HW3". 
  - This assumes that "HW3.cpp" is a C++ source code file containing the main program logic.

Run the ./HW# with the num_entries, associativity, and memory_reference_file to compile a C++ program that simulates the behavior of a cache memory.
-  ```./HW3 num_entries associativity memory_reference_file```
- The simulator will output each memory address followed by HIT or MISS to indicate whether the cache access was successful or not.


