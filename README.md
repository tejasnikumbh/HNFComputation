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
      type 'gcc compute_HNF.c -lm -o compute_HNF' to compile and run the example implementation.
  - Trying different matrices.
      The code is sufficiently modularised to try finding different HNF of different matrices.
      Just change the matrix definition in the main program and define ROWS and COLS accordingly.

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

