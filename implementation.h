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

/* 									     *			
 * File : implementation.h						     *
 * ==========================================================================*
 * This file contains the implementation for the interface to the module     * 
 * involving computation of HNF using Naive Algorithm. The documentation for *
 * each of these functions can be found in the docs folder of the module     * 
 * ==========================================================================*/


void 
display_matrix(size_t N,size_t M, int matrix[N][M]){

  	int i,j;
  	printf("\n");

  	for(i=0;i<N;i++){
   		for(j=0;j<M;j++){
    			printf("%5d",matrix[i][j]);
    		}
    		printf("\n");
  	}

}


void
compute_HNF(size_t N,size_t M, int A[N][M]){
	// Setting the lower bound on the rank of A.
	int c = 0;
	int i,j,r,k; 

	for(r=0;r<N;r++){

		//Ensuring that A[r][c+1,m] is not a zero array.
    		int allZero = is_all_zero(r,c,N,M,A); 

    		// If it is not a zero array then proceed to do reduction.
    		// Also check if reduction is not done already by checking c.
    		if(allZero==0){
       			c = c + 1;
       			//Make the partial row non-negative
       			for(i=(c-1);i<M;i++){
        	 		int sign;
        	 		if(A[r][i]>0)
       		    			sign = 1;
       		  		else if(A[r][i]<0)
         	  			sign = -1;
         			else
         	  			sign =0;
         			for(k=0;k<N;k++){
        	   			A[k][i] = A[k][i]*sign;
        	 		} 
       			}

       			while(allZero!=1){

        	 		// Finding the index of the min term in the current row.
        	 		int index = c-1;
        	 		int minVal = A[r][c-1];
        	 		for(k=c;k<M;k++){
       		    			if((A[r][k]<minVal && A[r][k]!=0)||(minVal==0 && A[r][k]!=0)){
       		      				index = k;
        	     				minVal = A[r][k]; 
        	   			}
        	 		} 

        	 		//Swapping column c-1 with index if c-1 != index
       		  		if((c-1)!=index){ 
        	  			for(k=0;k<N;k++){
        	     				int temp = A[k][c-1];
        	     				A[k][c-1] = A[k][index];
        	     				A[k][index] = temp;
        	   			}
        	 		}   
            
        	 		// Main Euclidean step   
        	 		for(j=c;j<M;j++){
        		 		int constant = floor((1.0*A[r][j])/A[r][c-1]);
        		   		for(k=0;k<N;k++){
        		     			A[k][j] = A[k][j] - constant*A[k][c-1];
        		   		}
        		 	}
         
        		 	// Block to test the partial Zero condition.
			 	allZero = is_all_zero(r,c,N,M,A);
	
       			}// End of while loop
	
       			// Row clean up
       			for(j=0;j<(c-1);j++){
       				int constant = floor((1.0*A[r][j])/A[r][c-1]);  
        	 		for(k=0;k<N;k++){
        	   			A[k][j] = A[k][j] - constant*A[k][c-1];
        	 		}
       			}
        
    		}//End of if statement 
      
	}//End of outermost for loop

}// End of function


int
is_all_zero(int r,int c, size_t N, size_t M, int A[N][M]){

	int k;
	int allZero = 1;
    	for(k=c;k<M;k++){
		if(A[r][k]!=0){
        		allZero = 0; 
        		break;
      		}
    	}

	return allZero;

}
