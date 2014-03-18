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

