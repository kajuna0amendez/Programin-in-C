# Binary Search Tree Insertion

This is an answer that solve the problem of inserting middle elements of an array by the following 
process:

1) Read a File with integers in increasing order by row
2) Put them in an array
3) Create a Iterator to find the middle of each possible segment i.e.

    + [1 2 3 4 5] -> 3

    + [1 2] -> 1

    + [4 5] -> 4

4) Insert these middle elements in the binary search tree
5) Use a inorder walk to test that the result is correct

## Execute the Makefile
1) cd into the root of the project
2) run "export LD_LIBRARY_PATH=lib:$LD_LIBRARY_PATH" you need that for the linkage
3) You can build the project by making the libraries and the main 

  + make lib
  + make main

Appart from those commands, you have the following:

+ Make all lib and main executable: make all
+ Clean all the build elements: make clean  

## Run the executable "main" 
./bin/main
