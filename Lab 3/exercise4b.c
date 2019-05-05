/*
	Xiaoshuai Geng
	104845608
	Lab exercise 4

*/
#include <stdio.h>
#define MAX 20
void Swap(int *Ptr_a, int *Ptr_b);		//Prototype

void Triple(int *Ptr);					//Prototype

void BubbleSort(int *Ptr, int size, int sort_order); //Prototype

void PopulateArray(int *Ptr, int size);

void PrintArray(int *Ptr, int size);

int main(void){

	int NumList[MAX];			//declare single dimensional array with 20 elements

	int *Ptr_main = NumList;	//Use for pass-by-reference into the function

	int *Ptr_count = NumList;	//Use in the for loop for counting

	int order;								//receive the user input for sorting order

	printf("\n%s","Populate the array with increasing even numbers:" );

	PopulateArray(Ptr_main,MAX);

	PrintArray(Ptr_main,MAX);

	for(int i = 0; i < MAX; i++, Ptr_count++){

		Triple(Ptr_count);

	}

	PrintArray(Ptr_main,MAX);

	printf("\nHow do you like to sort the array:\n");

	printf("\t1.Ascending\n\t-1.Descending\n");

	scanf("%d",&order);

	BubbleSort(Ptr_main, MAX, order);

	PrintArray(Ptr_main,MAX);

	return 0;
}


	//Swap:					swap the pointed value between two pointers
	//INPUT:				two pointers that pointed to two variables
	//OUTPUT:				two pointers which their pointed values been changed
	void Swap(int *Ptr_a, int *Ptr_b){

		int swap;

		swap = *Ptr_a;

		*Ptr_a = *Ptr_b;

		*Ptr_b = swap;

	}


	//Triple:				Triple the values of the original input
	//INPUT:				a single pointer
	//OUTPUT:				triple that value that the pointer point to
	void Triple(int *Ptr){

		*Ptr = *Ptr * *Ptr * *Ptr;

	}





	//BubbleSort:			Sort the array in either ascending or descending order
	//INPUT:				a pointer point to a array, size of array and a flag determine ascending or descending
	//OUTPUT:				am array which its elements are being sorted properly
	void BubbleSort(int *Ptr, const int size,const int sort_order){

		int done = 0;		//a flag to determine when to stop bubble sort

		if(sort_order == 1){

			for(int i = 0; i < size - 1 && !done; i++){
										//Improved Bubble sort process
				done = 1;

				for(int n = size - 1; n > i; n-- ){

					if( Ptr[n] < Ptr[n - 1] ){

						Swap(&Ptr[n], &Ptr[n - 1] );

						done = 0;

					}

				}

			}



		}else if(sort_order == -1){

			for(int i = 0; i < size - 1 && !done; i++){
										//Improved Bubble sort process
				done = 1;

				for(int n = size - 1; n > i; n-- ){

					if( Ptr[n] > Ptr[n - 1] ){

						Swap(&Ptr[n], &Ptr[n - 1] );

						done = 0;

					}

				}

			}

		}
	}



	//PopulateArray:			Populate increasing even numbers into PopulateArray
	//INPUT:							array address and size of the array
	//OUTPUT:							Array with increasing even number elements
	void PopulateArray(int *Ptr, int size){

		int start = 4;

		for(int i = 0; i < size; ++i, start+=2){

			*Ptr = start;

			Ptr++;

		}
		printf("\n");
	}


	//PrintArray:					Print all the elements of the array
	//INPUT:							a single dimensional array
	//OUTPUT:							print the array to the screen
	void PrintArray(int *Ptr, int size){

		printf("\n");

		for(int i = 0; i < size; ++i, Ptr++){

			printf("%d ", *Ptr);

		}
		printf("\n");
	}
