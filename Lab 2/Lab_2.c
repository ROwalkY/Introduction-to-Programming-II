/*
	Geng, Xiaoshuai
	ID: 104845608
	Lab Exercise #2
	Date: January 24, 2018
	Purpose:Understand array fundamentals and multidimensional arrays.
			Pass Arrays as function parameters.
			Basic manipulation of arrays using: Bubble Sort and Binary Search techniques.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define M 10
#define N 5

void InitializeArray2D(int value);		//Function Prototype

void PrintArray2D();					//Function Prototype

void PopulateRandomValues2D();			//Function Prototype

void Sort2D();							//Function Prototype

void LinearSearch2D();					//Function Prototype

void LeftShift2D();						//Function Prototype

int array2D[M][N];						//Store the random values and being printed

int main(void){
	
	int RunFunction;					//Get the user input to run the corresponding function
	
	char onemoretime;					//Determine if User want to back to the main page again	
	
	
	
	do{
		
		int input;						//determine what value that to initialize into the array
		
		// Interactive main menu
	
		printf("\n**************************Lab 2 Program**************************\n");
		
		printf("*                  0. Exit                                      *\n");
		
		printf("*                  1. InitializeArray2D                         *\n");
		
		printf("*                  2. PrintArray2D                              *\n");
		
		printf("*                  3. PopulateRandomValues2D                    *\n");
		
		printf("*                  4. Sort2D                                    *\n");
		
		printf("*                  5. LinearSearch2D                            *\n");
		
		printf("*                  6. LeftShift2D                               *\n");
		
		printf("*****************************************************************\n");
		
		printf("\n   Enter numbers to call the function directly (0 to Exit):  \n");
										//Print to the screen and let User to enter the number
		
	
		scanf("%d", &RunFunction);		//Get the input and stored
		
		switch(RunFunction){			//Determine which function needed to run
			
			case 0: 					//if the input is 0, exit the program
			
				break;
			
			case 1:						//InitializeArray2D Function
			
				printf("Please enter the value to be initialized: ");
				
				scanf("%d", &input);
				
				InitializeArray2D(input);
			
				break;
			
			case 2:						//PrintArray2D Function
			
				PrintArray2D();
				
				break;
			
			case 3:						//PopulateRandomValues2D Function
			
				PopulateRandomValues2D();
				
				break;
			
			case 4:
			
				Sort2D();
				
				break;
			
			case 5:
			
				LinearSearch2D();
				
				break;
			
			case 6:
			
				LeftShift2D();
				
				break;
			
			default:					//If the input is not correct, then exit the program
			
				printf("*************Error(From Main Menu): No such Function*************\n");
				
				break;
		}
		
		if(RunFunction!=0){				//If the original input is not 0,
										//Then print the following part on the screen
				printf("Back to main menu? (y/n)\n");	
											//Ask user if they want to continue or not
				getchar();					//get the previous character '\n' 
											//in order to make the scanf below get valid input
				scanf("%c", &onemoretime);	//Get the character and stored in "onemoretime"
				
				if(onemoretime != 'y'){		//If the answer is n, exit the program right away
				
					printf("**************Program Exit Successfully**************");
				
					return 0;				//Exit the Program
				}
		
		}
		
	}while(RunFunction != 0);
	
	printf("\n**************Program Exit Successfully**************\n");
	
	return 0;
	
}


	/*-------------------------InitializeArray2D Function----------------------*/
	//InitializeArray2D:				Initialize the 2D Array
	//INPUT:							Any integers
	//OUTPUT:							Every values in array will be equal to the input integer
	void InitializeArray2D(int value){
		
		
		for(int i = 0; i < M; ++i){
			
			for( int n = 0; n < N ; ++n){
				
				array2D[i][n] = value;
				
			
			}			
		
		}

		printf("\n******************The array has been initialized******************\n\n");
		
	}

	/*-------------------------InitializeArray2D Function----------------------*/
	
	
	
	
	
	
	/*-------------------------PrintArray2D Function---------------------------*/
	//PrintArray2D:						Print every element in the array
	//INPUT:							No input is necessary
	//OUTPUT:							Every value of the elements in the array is being printed
	void PrintArray2D(){
		
		printf("\nThe elements in the array are now: \n");
		
		for(int i = 0; i < M; ++i){
			
			for( int n = 0; n < N ; ++n){
				
				printf("%3d ",array2D[i][n]);
				
				
			}			
			
			printf("\n");
			
		}
		
	}
	/*-------------------------PrintArray2D Function---------------------------*/
	
	
	
	
	
	
	
	/*-------------------------PopulateRandomValues2D Function-----------------*/
	//PopulateRandomValues2D:			Random the values in the array
	//INPUT:							NO necessary input needed
	//OUTPUT:							Every value in the array will be randomized
	void PopulateRandomValues2D(){
		
		srand((unsigned)time(NULL));	//initialize the random numbers every time
		
		for(int i = 0; i < M; ++i){
			
			for( int n = 0; n < N ; ++n){
				
				int random = rand()%100 + 1;
										//generate random numbers from 1 to 100
				array2D[i][n]= random;	//assign the random value to current element
				
				
			}
		
		}
		
		printf("\n********************The elements has been randomized********************\n\n");
		
	}
	/*-------------------------PopulateRandomValues2D Function-----------------*/
	
	
	
	
	
	
	/*-------------------------Sort2D Function---------------------------------*/
	//Sort2D:							Sort the array in ascending order by Bubble sort
	//INPUT:							No necessary input
	//OUTPUT:							place the elements of the array in ascending order
	void Sort2D(){
		
		int dimension_num = M * N;		//define the length of 1D array
		
		int copy_array[dimension_num];	//claim a 1D array and copy the values from 2D array
		
		int copy = 0, paste = 0;		//from 0 to final element of 1D array 
		
		int done = 0;					//test if there is no swap in bubble sort
		
		int row,col;					//Use in bubble sort to run the loop
		
		int swap;						//Swap the values in array
		
		for(int i = 0; i < M; ++i){		//Copy from 2D to 1D
			
			for( int n = 0; n < N ; ++n, copy++){
				
				copy_array[copy] = array2D[i][n];		
				
			}
		
		}
		
		for(row = 0; row < copy - 1 && !done; row++){
										//Improved Bubble sort process
			done = 1;
			
			for(col = copy - 1; col > row; col-- ){
				
				if(copy_array[col] < copy_array[col - 1]){
					
					swap = copy_array[col];
					
					copy_array[col] = copy_array[col - 1];
					
					copy_array[col - 1] = swap;
					
					done = 0;
					
				}
				
			}
			
		}
		
		for(int i = 0; i < M; ++i){		//copy from 1D back to 2D
			
			for( int n = 0; n < N ; ++n, paste++){
				
				array2D[i][n] = copy_array[paste] ;		
				
			}
		
		}
		
		printf("\n******************The array has been sorted in ascending order******************\n\n");
		
	}
	/*-------------------------Sort2D Function---------------------------------*/
	
	
	
	
	
	
	
	/*-------------------------LinearSearch2D Function-------------------------*/
	//LinearSearch2D:					Search the values' position
	//INPUT:							Values needed to be found
	//OUTPUT:							Location of the element being found or return not being found
	void LinearSearch2D(){
		
		int search_num;					//determine what number that is being searched
		
		int found = 0;					//determine if the number is being found or not
		
		int count = 0;					//count how many times the 					
		
		printf("\nPlease enter the number being searched: ");
		
		scanf("%d", &search_num);		//store the value into variable
		
		for(int i = 0; i < M; ++i){		//for loop for searching the element
			
			for( int n = 0; n < N ; ++n){
				
				if(array2D[i][n] == search_num){
				
					printf("\nNumber has being found at position: row[%d] column[%d]\n", i+1, n+1);
				
					found = 1;
				
					count++;
				}
				
			}
		
		}
		if(found == 0){
			
			printf("\n%d was not found\n",search_num);
			
		}else{
			
			printf("\nThe number %d was found %d time(s)\n", search_num, count);
			
		}
		
	}
	/*-------------------------LinearSearch2D Function-------------------------*/
	
	
	
	
	
	
	/*-------------------------LeftShift2D Function----------------------------*/
	//LeftShift2D:						Move every element one position left
	//INPUT:							an array with different values being assigned to every element
	//OUTPUT:							Every element move one position left
	void LeftShift2D(){
		
		int dimension_num = M * N;		//define the length of 1D array
		
		int copy_array[dimension_num];	//claim a 1D array and copy the values from 2D array
		
		int copy = 0;					//from 0 to final element of 1D array
		
		int paste = 1;		 			//from 1 to final element of 1D array
		
		for(int i = 0; i < M; ++i){		//Copy from 2D to 1D
			
			for( int n = 0; n < N ; ++n, copy++){
				
				copy_array[copy] = array2D[i][n];		
				
			}

		}	

		for(int i = 0; i < M; ++i){		//copy from 1D back to 2D
			
			for( int n = 0; n < N ; ++n, paste++){
				
				array2D[i][n] = copy_array[paste] ;		
				
			}
		
		}
		
		array2D[M - 1][N - 1] = copy_array[0];
		
		printf("\n*********The elements has been shifted one position left*********\n\n");
		
	}
	/*-------------------------LeftShift2D Function----------------------------*/




