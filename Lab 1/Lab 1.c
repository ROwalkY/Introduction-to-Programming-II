/*
	Geng, Xiaoshuai
	ID: 104845608
	Lab Exercise #1
	Date: January 17, 2018
	Purpose: This is a sample C program used for practice
*/
#include <stdio.h>
//Non-Recursion Part
void SumNumbers();		 				//Declaration of Function #1 

void SquareNumbers(); 					//Declaration of Function #2 

void Fibonacci();						//Declaration of Function #3 

void GCD_Function();					//Declaration of Function #4 

void Power();							//Declaration of Function #5 

void PrintInteger();					//Declaration of Function #6 

void DrawTriange();						//Declaration of Function #7 

void DrawTriange_2();					//Declaration of Function #8 


//Recursion Part

int ReSumNumbers(int input); 			//Declaration of Function #9  

int ReSquareNumbers(int input); 		//Declaration of Function #10  

int ReFibonacci(int input);				//Declaration of Function #11  

int ReGCD_Function(int x, int y);		//Declaration of Function #12 

int RePower(int input_a, int input_b);	//Declaration of Function #13 

int RePrintInteger(int input);			//Declaration of Function #14 

char ReDrawTriange(int input);			//Declaration of Function #15 

void ReDrawTriange_2(int input);		//Declaration of Function #16 


	/*Main Program*/
int main(void){
	
		// Used in Interactive main menu 
		// Variable Location
		int getNumber;						//To store what the input number is
											//in order to determine which number should be called
										
		char onemoretime;					//Determine if User want to back to the main page again	
		
	do{										//do_while structure to determine when to terminal the program
	
		int input;							//Used for get the input for Function
		
		int x;								//Store the values used in GCD Function
											//As well as in Power Function
		int y;
		
		// Interactive main menu
	
		printf("--------------------------Lab 1 Program--------------------------\n");
		
		printf("-        0. Exit                                                -\n");
		
		printf("-        1. The sum of the numbers from 1 to n                  -\n");
	
		printf("-        2. The sum of the numbers from (1+1)^2 to (n+1)^2      -\n");
	
		printf("-        3. Fibonacci Function                                  -\n");
	
		printf("-        4. GCD Function                                        -\n");
		
		printf("-        5. Power Function                                      -\n");
	
		printf("-        6. Display the positive integers from n to 1           -\n");
	
		printf("-        7. DrawTriange #1                                      -\n");
	
		printf("-        8. DrawTriange #2                                      -\n");
		
		printf("-        9. The sum of the numbers from 1 to n (Recursion)      -\n");
	
		printf("-        10. The sum  from (1+1)^2 to (n+1)^2(Recursion)        -\n");
	
		printf("-        11. Fibonacci Function (Recursion)                     -\n");
	
		printf("-        12. GCD Function (Recursion)                           -\n");
		
		printf("-        13. Power Function (Recursion)                         -\n");
	
		printf("-        14. Display the positive integers from n to 1 (Re)     -\n");
	
		printf("-        15. DrawTriange #1 (Recursion)                         -\n");

		printf("-        16. DrawTriange #2 (Recursion)                         -\n");
	
		printf("-----------------------------------------------------------------\n");
	
		printf("   Enter numbers to call the function directly (0 to Exit):  \n");
											//Print to the screen and let User to enter the number
		
	
		scanf("%d", &getNumber);			//Get the input and stored
		
		
			switch(getNumber){				//To make the function call
				
				case 0:						//If number is 0, then jump out of the switch statement 
					
					break;
				
				case 1:						//Go to Function #1
				
					SumNumbers();
				
					break;					//Jump out of the switch statement
				
				case 2:
				
					SquareNumbers();		//Go to Function #2	
					
					break;
				
				case 3:
				
					Fibonacci();			//Go to Function #3
					
					break;
				
				case 4:
				
					GCD_Function();			//Go to Function #4
					
					break;
				
				case 5:
					
					Power();				//Go to Function #5
					
					break;
				
				case 6:
				
					PrintInteger();			//Go to Function #6
					
					break;
				
				case 7:
				
					DrawTriange();			//Go to Function #7
					
					break;
					
				case 8:
					
					DrawTriange_2();		//Go to Function #8
					
					break;
				
				case 9:
					
					printf("Call The Function #9:  The sum of the numbers from 1 to n (Recursion)\n\n");
					
					printf("*******************Positive Integers Only*******************\n\n");
					
					do{
						
						printf("Please enter a positive integer: ");
					
						scanf("%d",&input);
						
					}while(input<1);
					
					printf("The answer is: %d\n",ReSumNumbers(input));			
											//Go to Function #9
					
					break;
				
				case 10:
					
					printf("Call The Function #10:  The sum  from (1+1)^2 to (n+1)^2(Recursion)\n\n");
					
					printf("*******************Positive Integers Only*******************\n\n");
					
					do{
						
						printf("Please enter a positive integer: ");
					
						scanf("%d",&input);
						
					}while(input<1);
					
					printf("The answer is: %d\n",ReSquareNumbers(input));						
											//Go to Function #10
					break;
				
				case 11:
					
					printf("Call The Function #11:  Fibonacci Function (Recursion)\n\n");
					
					printf("*******************Positive Integers Only*******************\n\n");
					
					do{
						
						printf("Please enter a positive integer: ");
					
						scanf("%d",&input);
						
					}while(input<1);
					
					printf("The Fibonacci(%d) is: %d\n",input, ReFibonacci(input));			
											//Go to Function #11	
					
					break;
					
				case 12:
				
					printf("Call The Function #12:  GCD Function (Recursion)\n\n");
					
					printf("*******************Non-negative Integers Only*******************\n\n");
					
					do{
						printf("Please enter two non-negative integer: ");
					
						scanf("%d%d",&x , &y);
					
					}while(x < 0 || y < 0);
						
					printf("The greatest common divisor is: %d\n",ReGCD_Function(x , y));			
											//Go to Function #12
				
					break;
				
				case 13:
				
					printf("Call The Function #13:  Power Function (Recursion)\n\n");
					
					printf("*******************Positive Integers Only*******************\n\n");
					
					do{
					
						printf("Please enter Two positive integer: ");
					
						scanf("%d%d",&x , &y);
					
					}while( x < 1 || y < 1 );
					
					printf("The answer is: %d\n",RePower(x , y));			
											//Go to Function #13
				
					break;
				
				case 14:
					
					printf("Call The Function #14:  PrintInteger Function (Recursion)\n\n");
					
					printf("*******************Positive Integers Only*******************\n\n");
					
					do{
						
						printf("Please enter a positive integer: ");
					
						scanf("%d",&input);
						
					}while(input<1);
					
					printf("%d \n",RePrintInteger(input) );	
											//Go to Function #14	
					
					break;
				
				case 15:
					
					printf("Call The Function #15:  DrawTriange #1 (Recursion)\n\n");
					
					printf("*******************Positive Integers Only*******************\n\n");
					
					do{
						
						printf("Please enter a positive integer: ");
					
						scanf("%d",&input);
						
					}while(input<1);
					
					printf("%c \n",ReDrawTriange(input) );	
											//Go to Function #15	
					
					break;
				
				case 16:
					
					printf("Call The Function #16:  DrawTriange #2 (Recursion)\n\n");
					
					printf("*******************Positive Integers Only*******************\n\n");
					
					do{
						
						printf("Please enter a positive integer: ");
					
						scanf("%d",&input);
						
					}while(input<1);
					
					ReDrawTriange_2(input);	
											//Go to Function #16	
					
					break;
				
				default:					//If the input is not correct, then exit the program
			
					printf("-------------Error(From Main Menu): No such Function-------------\n");
				
					break;
			}
			
			if(getNumber!=0){				//If the original input is not 0,
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
			
	}while( getNumber != 0 );
	
	printf("**************Program Exit Successfully**************");
	
	
	
	return 0;
	
}
	/*-------------------------Function #1: SumNumbers-------------------------*/
	//SumNumbers: 	Add all the numbers from 1 to n  (n is entered by the user)
	//INPUT: 		a positive integer n, test n if it is a positive integer or not
	//OUTPUT: 		return the sum of the numbers from 1 to n
	void SumNumbers(){
		int input_1;						//Will be used to store the input number and use in the function
		
		int sum = 0;						//Store the total sum of the numbers being added
		
		printf("Call The Function #1:  The sum of the numbers from 1 to n\n\n");	
											//Showing what function has been called
			
		printf("Please enter a positive integer n (n>0):\n");
											//Print on the screen and let User enter the number n
					
		scanf("%d",&input_1);				//Get the input number
				
		if(input_1>0){						//"if" statement to determine if it is a positive number
				
			while(input_1>0){				//While loops to add numbers from n to 1
			
				sum+=input_1;				//Add current value of n to sum 
			
				input_1--;					// n minus 1 until n=1
			
			}
		
		}
		
		printf("The sum of the numbers from 1 to %d is: %d\n\n", input_1, sum);
		
	}
	/*-------------------------Function #1: SumNumbers-------------------------*/
	
	
	
	
	
	/*-------------------------Function #2: SquareNumbers----------------------*/
	//SquareNumbers: 	To get the sum of (1+1)^2 to (n+1)^2
	//INPUT:			A positive integer, test the input if it is a positive integer
	//OUTPUT			The sum of (1+1)^2 to (n+1)^2
	void SquareNumbers(){
		
		int input;							//Shown in the final answer
		
		int input_2;						//To store the user input
		
		int sum_2=0;						//Store the sum of all numbers added together
			
		printf("Call the Function #2: The sum of the numbers from (1+1)^2 to (n+1)^2\n\n");
											//Showing the function has been called successfully
		
		do{									//Determine whether it is positive
			printf("Please enter a positive integer: \n");
											//Ask for entering a new input
		
			scanf("%d", &input);
			
			if(input<= 0){				
			
				printf("Invalid Input\n");	//Print invalid input if number is not positive
				
			}
		
		}while(input <= 0);
			
		input_2 = input;
		
		if(input_2>0){						//determine if it is positive
			
			while(input_2>0){
				
				sum_2 += ( (input_2+1)*(input_2+1) );
				
				input_2--;					//End until input_2 = 0
			}
			
			printf("The sum from (1+1)^2 to (%d+1)^2 is: %d\n\n", input, sum_2);
		}
			
			
			
	}
	
	/*-------------------------Function #2: SquareNumbers----------------------*/
	
	
	
	
	
	
	/*-------------------------Function #3: Fibonacci Function----------------------*/
	
	//Fibonacci: 			To get the exact Fibonacci Number depend on what input is
	//INPUT: 				A non-negative number, test it if positive or not
	//OUTPUT: 				The Fibonacci number is the sum of the previous two numbers
	void Fibonacci(){
		
		int input_3;						//To store the input which should be >= 0
		
		long start_1=0;						//The previous first fibonacci number, start at 0
		
		long start_2=1;						//The previous second fibonacci number, start at 1
		
		long sum=0; 						//Use this to collect the sum of previous two fibonacci numbers
		
		printf("Call the Function #3: Fibonacci Function\n\n");
											//Show the function has been called successfully
		do{									//do_while loop to make sure get a valid input
				
			printf("Please enter a non-negative number: \n");
											//print to the screen and ask for input
			scanf("%d", &input_3);			//store the input into variable "input_3"
				
			if(input_3<0){					//if statement to warning that if the input is invalid
				
				printf("Invalid Input\n");
				
			}
				
		}while( input_3 <0 );
		
		if(input_3 == 0){					//if input is 0 or 1, write the answer directly
				
			printf("The Fibonacci number is: 0\n");
				
		}else if(input_3 == 1){
			
			printf("The Fibonacci number is: 1\n");
			
		}else{
			
			printf("The Fibonacci numbers are: ");
			
			for(int i=0; i < input_3; ++i){	//for loop to add fibonacci numbers all together
				
				printf("%ld ", start_1);	//print the fibonacci number here
				
				sum = start_1 + start_2;	//the sum of the previous two numbers
				
				start_1 = start_2;			//give value of start_2 to start_1
				
				start_2 = sum;				
				
			}
			
			printf("\n\n*************************The Function runs successfully*************************\n\n");
											//Print out the function has done here
			
		}
		
	}
	

	/*-------------------------Function #3: Fibonacci Function----------------------*/
	
	
	
	
	
	
	
	
	/*-------------------------Function #4: GCD Function----------------------------*/
	//GCD_Function: 			To find the greatest common divisor
	//INPUT:					Two non-negative integers
	//OUTPUT:					An integer that is the greatest common divisor of the two input numbers
	void GCD_Function(){
		
		int get_1,get_2; 			//Get the input numbers, will be used in printing the final answers
		int x,y;					//the value will be used in the loop to find the GCD
		int swap;					//swap the values between x and y
		
		printf("Call the Function #4: GCD Function\n\n");
		
		do{							//do_while loop to get correct input for the function
		
			printf("Please enter two non-negative integers x and y: \n");
		
			scanf("%d%d", &get_1,&get_2);	//store the input numbers into variables
			
			if( (get_1<0) || (get_2<0) ){
				
				printf("\n\n---------Error: The input is not correct---------\n\n");
									//When the input is not correct, print this on the screen
			}
		
		}while( (get_1<0) && (get_2<0) );
		
		x = get_1;
		
		y = get_2;
		
			
		while(y>0){					//To find the GCD
			
			swap = x;				// get the value of x
			
			x = y;					//Give the value of y to x  e.g: y is 16 and give to x
			
			y = swap % y;			// y's value now is x%y   e.g 4%16 = 4
		}
		
		if(y==0){					//if y=0, give the answer immediately
		
			printf("The greatest common divisor of the numbers %d and %d is: %d",get_1,get_2,x);
			
		}
		
		printf("\n\n*************************The Function runs successfully*************************\n\n");
											//Print out the function has done here
		
	}
	/*-------------------------Function #4: GCD Function----------------------------*/
	
	
	
	
	
	
	/*-------------------------Function #5: Power Function--------------------------*/
	//Power: 					To get the specific power of the number
	//INPUT:					Two non-negative integers
	//OUTPUT:					Positive integers which is the specific power  of the input number
	void Power(){
		
		int a;						//The number need to be powered
		
		int b;						//To what power of the number
		
		int sum=1;					//Showing the final answer
		
		printf("Call the Function #5: Power Function\n\n");
		
		do{
		
		printf("*******************Positive Integers Only*******************\n\n");
		
		printf("Please enter the base number and the exponential number: \n");
		
		scanf("%d%d",&a,&b);
		
		if(a<1){
			
			printf("\n\n-----------------Error: Number Undefined-----------------\n\n");
			
		}
		
		}while(a<1);
		
		if(a == 1){
			
			printf("The answer is: 1\n");
			
		}else{
			
			for(int i = 0; i < b; ++i){		
									
				sum *= a;
				
			}
			
			printf("The answer is: %d", sum);
			
		}
		
		printf("\n\n*************************The Function runs successfully*************************\n\n");
											//Print out the function has done here
		
	}
	
	
	/*-------------------------Function #5: Power Function--------------------------*/
	
	
	
	
	
	
	
	/*-------------------------Function #6: PrintInteger Function-------------------------*/
	//PrintInteger:					Print positive integers from n to 1
	//INPUT:						A positive integer
	//OUTPUT:						Display the positive integers from n to 1
	void PrintInteger(){
		
		int get_input;				//To get user input, get n value
		
		int printnumber;			//How many numbers being displayed	
		
		
		printf("Call the Function #6: PrintInteger Function\n\n");
		
		do{							//do_while loop to get valid input
		
			printf("Please enter a positive integer: \n");
			
			scanf("%d",&get_input);	//get user input and store it in get_input
			
			if(get_input < 1){
				
				printf("\n\n***********************Error: The number is not positive***********************\n\n");
				
			}
			
			
		}while(get_input < 1);
		
		printnumber = get_input;	//give the value of get_input to printnumber
		
		printf("Print(%d): ",get_input);
		
		for(; printnumber>0; --printnumber ){
									//print the positive integers from n to 1 by using for loop
				printf("%d ",printnumber);
			
		}
		
		printf("\n\n*************************The Function runs successfully*************************\n\n");
											//Print out the function has done here
	}
	
	/*-------------------------Function #6: PrintInteger Function-------------------------*/
	
	
	
	
	
	
	
	/*-------------------------Function #7: DrawTriange Function--------------------------*/
	//DrawTriange: 					Display n number of *'s first line	
									//and one less each line until there's only a single *
	//INPUT:						A positive integer
	//OUTPUT:						A triangle composed by *s and one less * with each line
	void DrawTriange(){
		
		int get_input;				//get user input and store it
									//determine how many stars and lines being print
									
		int printlines;				//How many lines being printed
		
		printf("Call the Function #7: DrawTriange Function\n\n");
		
		do{							//do_while loop to get valid input
		
			printf("Please enter a positive integer: ");
			
			scanf("%d",&get_input);	//get user input and store it in get_input
			
			printf("\n");
			
			if(get_input < 1){
				
				printf("\n\n***********************Error: The number is not positive***********************\n\n");
				
			}
			
			
		}while(get_input < 1);
		
		printlines = get_input;		//convert input values to printlines
		
		for(;printlines>0; --printlines ){
									//print n lines
			for(int i = 0; i < printlines; i++ ){
									//print n stars every line
				printf("*");
				
			}
			
			printf("\n");
			
		}
		
		printf("\n\n*************************The Function runs successfully*************************\n\n");
											//Print out the function has done here
		
	}
	
	
	/*-------------------------Function #7: DrawTriange Function--------------------------*/
	
	
	
	
	
	
	
	/*-------------------------Function #8: DrawTriange_2 Function------------------------*/
	//DrawTriange_2:				Print a triangle composed by n line of stars, the first with 1 star
									//and with one more each line
	//INPUT:						A positive integers
	//OUTPUT:						A triangle composed by *s and one more * with each line
	void DrawTriange_2(){
		
		int get_input;				//get user input and store it
									//determine how many stars and lines being print
									
		int printlines;				//How many lines being printed
		
		do{							//do_while loop to get valid input
		
			printf("Please enter a positive integer: ");
			
			scanf("%d",&get_input);	//get user input and store it in get_input
			
			printf("\n");
			
			if(get_input < 1){
				
				printf("\n\n***********************Error: The number is not positive***********************\n\n");
				
			}
			
			
		}while(get_input < 1);
		
		printlines = get_input;		//convert input values to printlines
		
		for(int i = 0; i < printlines; i++){
									//How many lines being printed
			for(int stars = 0; stars <= i; stars++){
									//How many stars a line being printed
				printf("*");
				
			}
			
			printf("\n");			//To next line
		}
		
		printf("\n\n*************************The Function runs successfully*************************\n\n");
											//Print out the function has done here
		
	}
	
	/*-------------------------Function #8: DrawTriange_2 Function------------------------*/
	
	
	
	
	
	
	/*-------------------------Function #9: ReSumNumbers Function-------------------------*/
	//ReSumNumbers: 				Add all the numbers from 1 to n  (n is entered by the user)
	//INPUT: 						a positive integer n, test n if it is a positive integer or not
	//OUTPUT: 						return the sum of the numbers from 1 to n
	int ReSumNumbers(int input){
		
		
		if(input == 1){
			
			return 1;
			
		}else{
			
			return input+ReSumNumbers(input-1);
			
		}
	}
	/*-------------------------Function #9: ReSumNumbers Function-------------------------*/
	
	
	
	
	
	/*-------------------------Function #10: ReSquareNumbers Function---------------------*/
	//ReSquareNumbers:				To get the sum of (1+1)^2 to (n+1)^2
	//INPUT:						A positive integer, test the input if it is a positive integer
	//OUTPUT						The sum of (1+1)^2 to (n+1)^2
	int ReSquareNumbers(int input){
		
		
		if(input == 1){
			
			return  ((1+1)*(1+1));
			
		}else{
			
			
			return (((input+1)*(input+1))+ ReSquareNumbers(input - 1) );
			
		}
		
	}
	
	
	/*-------------------------Function #10: ReSquareNumbers Function---------------------*/
	
	
	
	
	
	
	
	
	/*-------------------------Function #11: ReFibonacci Function-------------------------*/
	//ReFibonacci:					To get the exact Fibonacci Number depend on what input is
	//INPUT: 						A non-negative number, test it if positive or not
	//OUTPUT: 						The Fibonacci number is the sum of the previous two numbers
	int ReFibonacci(int input){
		
									//2 Base case: 0 and 1
		if(input == 0){			//if input = 0, return 0, otherwise return 1

			return 0;
				
				
		}else if(input == 1){
				
			return 1;
					
		}else{
			
			return  ReFibonacci(input - 1) + ReFibonacci(input - 2) ;
			
		}
		
	}
	
	/*-------------------------Function #11: ReFibonacci Function-------------------------*/
	
	
	
	
	
	
	
	/*-------------------------Function #12: ReGCD_Function ------------------------------*/
	//ReGCD_Function: 			To find the greatest common divisor
	//INPUT:					Two non-negative integers
	//OUTPUT:					An integer that is the greatest common divisor of the two input numbers
	int ReGCD_Function(int x , int y){
		
		if(y == 0){
			
			return x;
			
		}else{
			
			return ReGCD_Function( y , x%y );
			
		}
		
	}
	/*-------------------------Function #12: ReGCD_Function ------------------------------*/
	
	
	
	
	
	
	
	
	/*-------------------------Function #13: RePower Function-----------------------------*/
	//RePower: 					To get the specific power of the number
	//INPUT:					Two non-negative integers
	//OUTPUT:					Positive integers which is the specific power  of the input number
	int RePower(int a, int b){
		
		if(b == 1){
			
			return a;
		
		}else{
			
			return a*RePower(a,b-1);
			
		}
		
	}
	/*-------------------------Function #13: RePower Function-----------------------------*/
	
	
	
	
	
	
	/*-------------------------Function #14: RePrintInteger Function----------------------*/
	//RePrintInteger:				Print positive integers from n to 1
	//INPUT:						A positive integer
	//OUTPUT:						Display the positive integers from n to 1
	int RePrintInteger(int input){
		
		
		if(input == 1){				//Base Case when input ==1
			
			return 1;
		
		}else{
			
			printf("%d ",input );
			
			return RePrintInteger(input - 1);
			
		}
	}
	
	
	
	/*-------------------------Function #14: RePrintInteger Function----------------------*/
	
	
	
	
	
	
	
	
	
	/*-------------------------Function #15: ReDrawTriange Function-------------------------*/
	//ReDrawTriange: 				Display n number of *'s first line	
									//and one less each line until there's only a single *
	//INPUT:						A positive integer
	//OUTPUT:						A triangle composed by *s and one less * with each line
	char ReDrawTriange(int input){
		
		if(input == 1){				//Base case will print a single * to the bottom
				
			return '*';
			
		}else{
			
			for(int i = 0; i < input ; i++){
				
				printf("*");
				
			}
			printf("\n");
			
			return ReDrawTriange(input - 1);
		}
		
	}
	
	
	
	/*-------------------------Function #15: ReDrawTriange Function-------------------------*/
	
	
	
	
	
	
	
	
	
	/*-------------------------Function #16: ReDrawTriange_2 Function-----------------------*/
	//DrawTriange_2:				Print a triangle composed by n line of stars, the first with 1 star
									//and with one more each line
	//INPUT:						A positive integers
	//OUTPUT:						A triangle composed by *s and one more * with each line
	void ReDrawTriange_2(int input){
		
		if(input == 1){
			
			printf("*\n");
			
		}else{
			
			ReDrawTriange_2(input - 1);
			
			for(int i = 0; i < input ; i++){
				
				printf("*");
				
			}
			printf("\n");
			
		}
		
		
	}
	
	/*-------------------------Function #16: ReDrawTriange_2 Function-----------------------*/
	
	
	
	
	
	
	