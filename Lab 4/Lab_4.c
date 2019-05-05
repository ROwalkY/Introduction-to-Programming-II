/*
	Xiaoshuai Geng
	104845608
	Lab exercise #4


*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define SIZE 80

void Reverse(char *A);

void RecursiveReverse(char *A, int size);

int main(void){

	int end;		//determine whether input end or not
	
	char Buffer1[] = {'t','h','i','s',' ','i','s',' ',
    't','h','e',' ','f','i','r','s','t',' ','b','u','f','f','e','r','\0'};


	char Buffer2[] = "this is the second buffer";
	
	char Buffer3[80];
	
	//unsigned int length;
	
	char *Ptr_temp = Buffer3;	//temporally point to the end the the string input
	
	
	printf("Please initialize for Buffer3 here:\n");

/*
	
	get the first string input and get a single char from stdin to check
	if there is a whitespace. If so and the strlen is less than 79(save one space for '\0'), 
	get another string input. Using length to indicate the string length and add a space between 2 string inputs
	Using the pointer *Ptr_temp to point the end of the string in order to store the next string input 
	after the string being stored, initialize the pointer and go to next loop
	
*/
/*
	scanf("%s", Buffer3);
	
	scanf("%c", &end);
	
	while(end ==' ' && strlen(Buffer3)<=79){
		
		length = strlen(Buffer3);		//get the length of the current string length
		
		Buffer3[length] = ' ';
		
		scanf("%s", Ptr_temp+length+1);
		
		scanf("%c", &end);
		
		Ptr_temp = &Buffer3[0];
		
	}
	
	Buffer3[strlen(Buffer3)] = '\0';

*/

	fgets(Buffer3,79,stdin);
	
	printf("%s\n", Buffer1);//output: this is the first buffer
	
	printf("%s\n", Buffer2);//output: this is the second buffer
	
	printf("%s\n", Buffer3);//output: this is  the third buffer
	
	/*-----------------Part II---------------------*/
	
	printf("-------------PART II---------------\n");
	
	char *pBuffer = Buffer3;
	
	while( *pBuffer!= '\0'){
		
		printf("%c",*pBuffer);
		
		pBuffer++;
		
	}
	
	printf("\n-------------PART III---------------\n");
	
	printf("Before:\n%s\n", Buffer3);
	
	Reverse(Buffer3);
	
	printf("After:%s\n", Buffer3);
	
	RecursiveReverse(Buffer3, strlen(Buffer3));
	
	printf("After:\n%s", Buffer3);
	
	return 0;
}

	//Reverse:			reverse all the elements in an array
	//INPUT:			an array name or a pointer point to an array
	//OUTPUT:			the elements in the array are reversed e.g:first element become last element
	void Reverse(char *A){
		
		char temp;
		
		int length = strlen(A) - 1;
		
		int count = 0;
		
		while(count < length){
			
			temp = A[count];
			
			A[count] = A[length];
			
			A[length] = temp;
			
			count++;
			
			length--;
			
		}
		
	}
	
	
	
	//RecursiveReverse:		reverse all the elements in an array recursively
	//INPUT:				an array name or a pointer point to an array
	//OUTPUT:				the elements in the array are reversed e.g:first element become last element
	void RecursiveReverse(char A[], int size){
		
		//int length = strlen(A) - 1;
		
		//printf("%d ",length);
		
		char temp;
		
		if(size >1){
		
			temp = A[0];
			
			A[0] = A[size - 1];
			
			A[size - 1] = temp;
		
			RecursiveReverse(&A[1], size - 2);
		}
		
		
		
		
		/*
		
			if(strlen(A) > 1){
				
				
			
				RecursiveReverse(A++);
				
			}
			*/
			
	}

	
	
	
	
	
