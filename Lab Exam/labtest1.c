#include <stdio.h>
#define ROWS 20
#define COLS 20

void Print(float A[ROWS][COLS],int rows,int cols);		//Function Prototype

void MaxMerge(float A[ROWS][COLS],float B[ROWS][COLS],float C[ROWS][COLS],int rows, int cols);

void main(){

	int p,q;

	int rows, cols;

	float A[ROWS][COLS], B[ROWS][COLS], C[ROWS][COLS];

	printf("Enter # of rows, # of cols: ");

	scanf("%d%d", &rows, &cols);

	for(p = 0; p < rows; p++)
	{

		printf("Enter %d column values for row %d: \n",cols,p+1);

		for(q = 0; q < cols; q++)
		{
		
			scanf("%f", &A[p][q]);

		}//TODO: REPEAT this loop to obtain the contents of B[][]

	}

	for(p = 0; p < rows; p++)
	{

		printf("Enter %d column values for row %d: \n", cols,p+1);
		
		for(q = 0; q < cols; q++){

			scanf("%f", &B[p][q]);	
	
		}
	}

		printf("\n");	

		Print(A, rows, cols);
		
		printf("\n");

		Print(B, rows, cols);
		
		printf("\n");
		
		MaxMerge(A,B,C,rows,cols);

		Print(C,rows,cols);

			

}
	//Print:		print out all the elements in the array
	//input:		a float array, number of rows and cols
	//output:		lines of values of the elements in the array 
	void Print(float A[ROWS][COLS],int rows,int cols){

		for(int i = 0; i < rows; i++){

			for(int n = 0; n < cols; n++){
			
				printf("%.2f ", A[i][n]);

			}
			
			printf("\n");			

		}

	}


	//MaxMerge:		Compare the value of every element in the array and get the maximum value
				//then merge into the other array
	//input:		//Two arrays for comparing and one for merging. number of rows and cols
	//output:		array that has all the maximum values in two of the arrays
	void MaxMerge(float A[ROWS][COLS],float B[ROWS][COLS],float C[ROWS][COLS],int rows, int cols){
		
		float temp; 	//use to swap the values
		
		for(int i = 0; i < rows; i++){

			for(int n = 0; n < cols; n++){

				C[i][n] = A[i][n] > B[i][n] ? A[i][n]: B[i][n];
				//Merge the arrays
				//determine which one is the maximum value
			}	
		
		}

	}

