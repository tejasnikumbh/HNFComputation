/*=============================================================================

This file is sample code for the FLINT GSoC proposal. No parts of this
file may be copied and used without the author's permission. FLINT is a 
Fast Library for Number Theory. I hope to contribute to FLINT via GSoC
this year.

=============================================================================*/
/******************************************************************************

Copyright (C) 2014 Tejas Nikumbh
Special Thanks : Bill Hart

******************************************************************************/

/* ======================================================================== *
 * File : main.c 		                                            *
 * ======================================================================== *
 * Description : Program to compute the Hermite Normal Form for a given     *
 * matrix.Consists of the main program and the core function which is       *
 * compute_HNF.                                                             *
 * Concept : A HNF or Hermite Normal Form of a matrix A is a matrix         *
 * obtained by performing the following 3 column operations on A : -        *
 * 									    *	 
 *   1.Multiplication by -1                                                 *
 *   2.Exchanging two columns                                               *
 *   3.Add an integral multiple of a column to another.                     *
 * 								            * 
 * It is simply a reduced column echelon form of the given matrix. More     *
 * generally, we can represent the relationship between A and its           *
 * Hermite form using the following relation.                               *
 *    									    *							
 *      			AU = H					    *		
 *  									    *			
 * where U is the Unitary transform matrix applied to A to get H.           *
 * A full rank square matrix is said to be in Hermite Normal form if        *
 *   1. It is lower triangular                                              *
 *   2. It has positive diagonal entries                                    * 
 *   3. All entries to the left of a diagonal entry are strictly less than  *
 *      the diagonal entry.                                                 *
 * 									    * 
 * To give an example, given a matrix                                       *  
 *   A = [  9  -36   30                                                     *
 *        -36  192 -180                                                     *
 *         30 -180  180]                                                    *
 * if transformed to Hermite Matrix would give, : -                         *
 *   H = [  3  0  0                                                         *
 *          0 12  0                                                         *
 *         30  0 60]                                                        *
 * ======================================================================== *
 * Copyrights : Tejas Nikumbh                                               *
 * ======================================================================== *
 */

/* Including standard libraries */
#include <stdio.h>
#include <math.h>
#include "interface.h"
#include "implementation.h"

/* Defining constants */
#define ROWS 4
#define COLS 4

/* The main program */
main(){

  // Introduction
  printf("This program computes the Hermite Normal Form for a given matrix\n");    

  // Initializing the matrix
  int matrix[ROWS][COLS];
  matrix[0][0] = 3;  matrix[0][1] = 3;  matrix[0][2] = 1; matrix[0][3] = 4;  
  matrix[1][0] = 0;  matrix[1][1] = 1; matrix[1][2] = 0 ; matrix[1][3] = 0;
  matrix[2][0] = 0;  matrix[2][1] = 0;  matrix[2][2] = 19; matrix[2][3] =16;
  matrix[3][0] = 0;  matrix[3][1] = 0;  matrix[3][2] = 0; matrix[3][3] =3;
  
  //Displaying the matrix before computing HNF
  display_matrix(ROWS,COLS,matrix);

  // Calling the compute_HNF program, passing it the pointer to the matrix
  compute_HNF(ROWS,COLS,matrix); 

  //Displaying the matrix after computing HNF
  display_matrix(ROWS,COLS,matrix);

}


