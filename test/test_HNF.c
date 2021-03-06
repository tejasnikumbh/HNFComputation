int
test_HNF(size_t N, size_t M, int** A){

	int i,j;
	int isHNF=1;

	for(i=0;i<N;i++){

		for(j=0;j<M;j++){
			
			//Check for lower triangular ness
			// Upper triangular entry
			if(j>i){

				// If the upper triangular entry is nonzero, matrix is not HNF
				if(A[i][j]!=0){
					isHNF = 0;
					break;	
				}

			// Diagonal entry
			}else if(j==i){

				//Check if diagonal entry is positive
				if(A[i][j]<0){
					isHNF = 0;
					break;
				}

			// Lower triangular entry
			}else{

				//Check if lower triangular entry is less than corresponding diagonal
				// Also check if entry is negative(No seperate negativity check needed
				// for above two as it is checked by the conditions defined)
				if(A[i][j]>A[i][i] || A[i][j]<0){
					isHNF = 0;
					break;
				}
			
			}

		}//End of column looping

	}// End of row looping

	return isHNF;

}//End of function
