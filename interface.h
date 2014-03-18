/*=============================================================================

This file is part of FLINT.

FLINT is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

FLINT is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with FLINT; if not, write to the Free Software
Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

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
