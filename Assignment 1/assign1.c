/*
	Xiaoshuai Geng
	104845608
	I acknowledge that this is my own work and did not receive any unauthorized help with it

*/

#include <stdio.h>
#include <stdlib.h>

unsigned reverseInteger(unsigned value);			//Function prototype

void generateMagicNumber(unsigned num);				//Function prototype

int main(void){
	
	int how_many;									//determine how many numbers will be entered
	
	unsigned origin_in;								//store the original input numbers
	
	unsigned reverse_num;							//store the answer from reverseInteger Function
	
	unsigned magic_num;								//store the answer from Magic Number function
	
	unsigned largeABS = 0;							//store the biggest absolute value
	
	unsigned compare;								//compare the biggest absolute values
	
	do{					//make sure at least 1 input
		
		printf("Please enter the number of inputs: ");
		
		scanf("%d", &how_many);					
		
	}while(how_many < 1);					
	
	printf("Please enter the whole sequence of numbers here: ");
	
	for(int i = 0; i < how_many; i++){
		
		scanf("%u", &origin_in);
		
		reverse_num = reverseInteger(origin_in);	//get the reversed num after function ends
			
		compare = abs(reverse_num - origin_in);		//calculate the absolute values
			
		largeABS = compare > largeABS? compare : largeABS;//determine the biggest absolute values
		
		generateMagicNumber(compare);				//generate the magic numbers
		
	}
		
		printf("\n%u\n", largeABS);					//print the largest absolute value 
		
	return 0;
	
}

	/***********************************reverseInteger Function***********************************/
	//reverseInteger:						reverse the input numbers
	//INPUT:								non-negative integers
	//OUTPUT:								reversed integers
	unsigned reverseInteger(unsigned value){
		
		unsigned reverse = 0; 				//store the current reverse value
		
		if(value < 10){
			
			return value;
			
		}else{
			
			while(value > 0){
				
				reverse *= 10;
				
				reverse += value % 10;
				
				value /= 10;
				
			}
			
			return reverse;
			
		}
		
	}
	/***********************************reverseInteger Function***********************************/
	
	
	
	
	
	/***********************************generateMagicNumber Function******************************/
	//generateMagicNumber:					take the absolute difference and inverse it
	//INPUT:								non-negative integers
	//OUTPUT:								reversed absolute difference values
	void generateMagicNumber(unsigned num){
		
		unsigned reverse = 0; 				//store the current reverse value
		
		if(num < 10){
			
			printf("%u ",num);
			
		}else{
			
			while(num > 0){
				
				reverse *= 10;
				
				reverse += num % 10;
				
				num /= 10;
				
			}
			
			printf("%u ",reverse);
			
		}
		
	}
	/***********************************generateMagicNumber Function******************************/
	