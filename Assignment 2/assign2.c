/*
	Xiaoshuai Geng
	104845608
	assignment 2

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define COL 20

#define ROW 20

void PopulateArray2DUnique(int A[][COL], unsigned int rowsize, unsigned int colsize, int min, int max);

void DisplayArray2D(int A[][COL], unsigned int rowsize, unsigned int colsize);

int FindLargest(int A[][COL], unsigned int rowsize, unsigned int colsize);

int FindColSum(int A[][COL], unsigned int rowsize, unsigned int colsize, unsigned int col_to_sum);

int Sort2Darray(int A[][COL], unsigned int rowsize, unsigned int colsize);

int CopyArray2D(int A[][COL], int B[][COL], unsigned int rowsize,unsigned int colsize);

int CopyArray2DSpiral(int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize);

int main(void){
	
	int A[ROW][COL];	
	
	int B[ROW][COL];
	
	int input_row;			//how many rows being displayed
	
	int input_col;			//how many cols being displayed
	
	do{
		
		printf("Testing an array of size: ");		
	
		scanf("%d%d",&input_row, &input_col);
		
	}while(input_row > 20 && input_col > 20);
	
	
	
	printf("\n");
	
	PopulateArray2DUnique(A, input_row,input_col,1,99);
	
	printf("Populate Array with unique random integers between 1 and 99:\n");
	
	DisplayArray2D(A, input_row, input_col);
	
	printf("\nFindLargest: %d\n", FindLargest(A, input_row,input_col));
	
	printf("\nFindColSum of col 0: %d\n", FindColSum(A, input_row,input_row, 0));
	
	Sort2Darray(A,input_row,input_col);
	
	printf("\nSort2Darray followed by DisplayArray2D:\n");
	
	DisplayArray2D(A, input_row,input_col);
	
	CopyArray2D(A,B,input_row,input_col);
	
	printf("Copy2Darray from A to B, then Display B:\n");
	
	DisplayArray2D(B, input_row,input_col);
	
	CopyArray2DSpiral(A,B,input_row,input_col);
	
	printf("CopyArray2DSpiral from A to B, then Display B: \n");
	
	DisplayArray2D(B, input_row,input_col);
	
	printf("\n*********END*********\n");
	
	return 0; 
	
}


	//PopulateArray2DUnique:		Populate the 2D of sizes rowsize x colsize with random
									//integers ranging between min and max inclusive
	//INPUT:						A 2D array, row and col size , the range from min to max
	//OUTPUT:						a 2d array being populated by the values bewteen min and max
	//include <time.h>
	void PopulateArray2DUnique(int A[][COL], unsigned int rowsize, unsigned int colsize, int min, int max){
		
		srand((unsigned)time(NULL));
		
		int i;				//Use for count in for-loop
		
		int n;
		
		for(i = 0; i < rowsize ; i++){
			
			for(n = 0; n < colsize; n++){
				
				A[i][n] = rand() % (max + 1 - min) + min;
				
			}
			
		}
		
	}
	
	
	//DisplayArray2D:			Display all the elements in the 2d array
	//INPUT:					A 2d array with give rowsize and colsize
	//OUTPUT:					All the values in 2d array will be print to screen
	void DisplayArray2D(int A[][COL], unsigned int rowsize, unsigned int colsize){
		
		int i;				//Use for count in for-loop
		
		int n;				//use in the loop
		
		for(i = 0; i < rowsize ; i++){
			
			for(n = 0; n < colsize; n++){
				
				printf("%2d ", A[i][n]);
				
			}
			
			printf("\n");
			
		}
		
	}
	
	
	
	//FindLargest:				Find the largest value in an array
	//INPUT:					A 2D array address, rowsize and colsize
	//OUTPUT:					the largest value in the array
	int FindLargest(int A[][COL], unsigned int rowsize, unsigned int colsize){
		
		int max = A[0][0];		//store the the current largest value
		//temporally let the first element in the array be the largest value
		
		int i;				//Use in the loop for counting
		
		int n; 				//use in the loop for counting
		
		for(i = 0; i < rowsize; i++){
			
			for(n = 0; n < colsize; n++){
				
				if( max < A[i][n] ){
					
					max = A[i][n];
					
				}
				
			}
			
		}
		
		
		return max;
		
	}
	
	
	//FindColSum:				Calculate the sum of a given column col of a 2D array of size rowsize x colsize.
	//INPUT:					address of 2d array, rowsize and colsize,and which column need to be calculated
	//OUTPUT:					the sum of all element in that column
	int FindColSum(int A[][COL], unsigned int rowsize, unsigned int colsize, unsigned int col_to_sum){
		
		int sum = 0;			//store the total sum of the column sum
		
		int i;					//Use in the loop for counting
		
		for(i = 0; i < rowsize; i++){
			
			sum += A[i][col_to_sum];
			
		}
		
		
		return sum;
	}
	
	//Sort2Darray:				Sort the 2D array in ascending order
	//INPUT:					a 2D array address with rowsize and colsize
	//OUTPUT:					all the elements in 2d array are sorted in ascending order
	int Sort2Darray(int A[][COL], unsigned int rowsize, unsigned int colsize){
		
		int copy = 0, paste = 0;		//from 0 to final element of 1D array 
		
		int done = 0;					//test if there is no swap in bubble sort
		
		int swap;						//Swap the values in array
		
		int i;							//use for counting in loop
		
		int n;							//use for counting in loop
		
		int copy_array[rowsize * colsize];
		
		for(i = 0; i < rowsize; ++i){		//Copy from 2D to 1D
			
			for( n = 0; n < colsize ; ++n, copy++){
				
				copy_array[copy] = A[i][n];		
				
			}
		
		}
		
		for( i = 0; i < copy - 1 && !done; i++){
										//Improved Bubble sort process
			done = 1;
			
			for(n = copy - 1; n > i; n-- ){
				
				if(copy_array[n] < copy_array[n - 1]){
					
					swap = copy_array[n];
					
					copy_array[n] = copy_array[n - 1];
					
					copy_array[n - 1] = swap;
					
					done = 0;
					
				}
				
			}
			
		}
		
		for(i = 0; i < rowsize; ++i){		//copy from 1D back to 2D
			
			for(n = 0; n < colsize ; ++n, paste++){
				
				A[i][n] = copy_array[paste] ;		
			}
		
		}
		
		return 0;
	}
	
	
	//CopyArray2D:					Copy the contents of array A into array B of the same size such that
									//the contents of B would be exactly the contents of A
	//INPUT:						original 2d array A and 2d array B with rowsize and colsize
	//OUTPUT:						the elements in B are the exact copy in A
	int CopyArray2D(int A[][COL], int B[][COL], unsigned int rowsize,unsigned int colsize){
		
		int i;						//Use for counting in loop
		
		int n; 						//Use for counting in loop
		
		for(i = 0; i < rowsize; i++){
			
			for(n = 0; n < colsize; n++){
				
				B[i][n] = A[i][n];
				
			}
			
		}
		
		return 0;
		
	}
	
	//CopyArray2DSpiral:			Copy the contents of array A into array B of the same size such that
									//the contents of B would be exactly the contents of A except they will
									//be in a clockwise spiral sorted order.
	//INPUT:						original 2D array A and a 2D array B with rowsize and colsize
	//OUTPUT:						the element in B are the copyed from A by clockwise sprial sorted order					
	int CopyArray2DSpiral(int A[][COL], int B[][COL], unsigned int rowsize, unsigned int colsize){
		//Direction:  R D L U
		
		int row =0, col = 0;//use to count the current row and col in B
		
		char direction = 'R';
		
		for(int i = 0; i < rowsize; i++){
			
			for(int n = 0; n < colsize; n++){
				
				B[i][n] = 0;
				
			}
		
		}
  
        for(int i = 0; i < rowsize; i++){
            
            for(int n = 0; n < colsize; n++){
                
                switch(direction){
                    
                    case 'R':
                        
                        
                            
                        if(B[row][col + 1] != 0 ){
                            
                            direction = 'D';
                            
                            B[row][col] = A[i][n];
                            
                            row++;   
							
                        }else{
                            
                            B[row][col] = A[i][n];
                            
                            col++;
                            
                        }
                        
                        if( col >= colsize ){
                            
                            col--;
                            
                            row++;
                            
                            direction = 'D';
                        }    
                            
                            
                        break;
                        
                    case 'D':
                        
                        if(B[row + 1][col] != 0){
                            
                            direction = 'L';
                            
                            B[row][col] = A[i][n];
                            
                            col--;
                            
                            
                        }else{
                            
                            B[row][col] = A[i][n];
                            
                            row++;
                            
                        }
                        
                        if( row >= rowsize ){
                            
                            row--;
                            
                            col--;
                            
                            direction = 'L';
                            
                        }
                        
                        break;
                        
                    case 'L':
                        
                        if(B[row][col - 1] != 0){
                            
                            direction = 'U';
                            
                            B[row][col] = A[i][n];
                        
                            row--;
                            
                        }else{
                            
                            B[row][col] = A[i][n];
                            
                            col--;
                        
                        }
                        if( col < 0 ){
                            
                            col++;
                            
                            row--;
                            
                            direction = 'U';
                        }
                        break;
                        
                    case 'U':
                        
                        if(B[row - 1][col] != 0){

                            direction = 'R';
                            
                            B[row][col] = A[i][n];
                            
                            col++;
                            
                            
                            
                        }else{
                            
                            B[row][col] = A[i][n];
                            
                            row--;
                            
                        }
                        if( row < 0 ){
                            
                            row++;
                            
                            col++;
                            
                            direction = 'R';
                        }
                        break;
                
				}
				
			}
			
		}
		
		
		return 0;
		
	}
	
	
	
	
	