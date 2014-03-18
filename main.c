/*=============================================================================

This file is a coding sample for the GSoC application for FLINT. 

No reproduction or plagiarism of the contents of this file is permitted 
without the prior written permission of the author.

=============================================================================*/

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
#include <stdlib.h>
#include <math.h>
#include "interface.h"
#include "implementation.c"
#include "test/test_HNF.c"

/* Defining constants */
#define ROWS 4
#define COLS 4

/* The main program */
main(){

	// Introduction
	printf("This program computes the Hermite Normal Form for a given matrix\n");    

	// Allocating memory for 2D array using malloc
  	int **matrix;
  	matrix = malloc(ROWS * sizeof(int *));
        int i;
  	for (i = 0; i < ROWS; i++)
  		matrix[i] = malloc(COLS * sizeof(int));

	// Generating the matrix entries 
  	generate_matrix(ROWS,COLS,matrix);

  	//Displaying the matrix before computing HNF
	printf("\n ========= Test Matrix =========\n");
  	display_matrix(ROWS,COLS,matrix);

  	// Calling the compute_HNF program, passing it the pointer to the matrix
  	compute_HNF(ROWS,COLS,matrix); 

  	//Displaying the matrix after computing HNF
	printf("\n ===== Hermite Normal Form =====\n");	
  	display_matrix(ROWS,COLS,matrix);

	// Testing whether the matrix is in Hermite normal form or not.
	printf("\n ======== Test Results =========");
	int isHNF = test_HNF(ROWS,COLS,matrix);
	if(isHNF == 1)
		printf("\nGiven matrix is in HNF\n\n");
	else
		printf("\nGiven matrix is not in HNF\n\n");

	// Deallocating or freeing memory for 2D array using free
	for(i=0; i<ROWS;i++){
        	free(matrix[i]);
    	}
    	free(matrix);

}


