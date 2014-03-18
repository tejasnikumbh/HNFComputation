Implementation of Naive HNF Algorithm for Computing HNF
========================================================

Coding samples for the flint project, in Matlab and C programming language.

I have a habit of prototyping first and then impleneting. I've observed that 
this makes the coding process more productive for me.
I used Octave to prototype the HNF algorithm first, and then implemented it 
using C.

Curret code in the Repository

* C implementation of HNL using Euclidean Algorithm.
  - Compiling instructions
      type 'gcc main.c -lm -o main' to compile the example implementation.
      then type ./main to run the program
  - Trying different matrices.
      The code is sufficiently modularised to try finding different HNF of different matrices.
      Just change the matrix definition in the generate_matrix method found in the implementations.h file in the root folder. Also, define rows and cols in the main program accordingly.

* main.c
 - This is the main test program for the computation of HNF, which utilises interface.h and implementa
   -tion.h.

* interface.h
  - The interface.h file contains a definition of all the algorithm related functions that we need to
    compute the HNF of a given matrix.

* implementation.h
  - This file contains the implementations of the functions described in the interface and as used by 
    the main program.

* Docs Folder
  - The Docs folder contains the documentation for all the algorithm functions descirbed in the interface
    and implementation files.

* Test Folder
  - The test folder contains the tests to verify whether a given matrix is in Hermite Normal Form or not. The tests are       based on the following definition of HNF for a non-singular matrix given on Page 2 of this reference         
    https://www.math.uwaterloo.ca/~wgilbert/Research/GilbertBricklaying.pdf

* Research Folder
  - This folder contains the research I did prior to GSoC about the various algorithms that need to be studied and implemented as a part of the project.
