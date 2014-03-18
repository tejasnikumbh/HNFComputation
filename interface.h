/*=============================================================================

This file is a coding sample for the GSoC application for FLINT. 

No reproduction or plagiarism of the contents of this file is permitted 
without the prior written permission of the author.

=============================================================================*/
/******************************************************************************

Copyright (C) 2014 Tejas Nikumbh
Special Thanks : Bill Hart

******************************************************************************/

/*
 * ==========================================================================*
 * File : Interface for Naive HNF Computation Algorithm			     *
 * ==========================================================================*
 * This file is an interface for the functions that are a part of the Naive  * 
 * HNF computation Algorithm. You can find the implementation of the interfac*
 * within the file implementations.h. The documentation for each of these    *
 * functions can be found in the docs folder of the module		     *
 * ========================================================================= */

extern void display_matrix(size_t N,size_t M,int matrix[N][M]); 
extern void compute_HNF(size_t N,size_t M,int A[N][M]);
extern int is_all_zero(int r,int c, size_t N, size_t M, int A[N][M]);
extern void generate_matrix(size_t N,size_t M, int** matrix);
