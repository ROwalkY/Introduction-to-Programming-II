#include <stdio.h>
int main(){

	int a = 7;
	
	int *aPtr;
	
	aPtr = &a;
	
	printf("%p\n",&a);	//function: the address of variable "a"
						//output: 0xffffcbfc
	
	printf("%p\n",aPtr);//function: the address that the pointer variable stored
						//output: 0xffffcbfc
	
	printf("%p\n",&aPtr);//function: the address of "aPtr" pointer variable
						//output: 0xffffcbf0
	
	printf("%d\n",a);//function: the value of variable "a"
						//output: 7
	
	printf("%d\n",*aPtr);//function: to the variable value that the pointer variable point to
						//output: 7
	
	printf("%p\n",*&aPtr);//function: the value inside the address of the pointer variable
						//output: 0xffffcbfc
	
	printf("%p\n",&*aPtr);//function: the address of the variable that the pointer point to
						//output: 0xffffcbfc
	
	printf("%d\n", *&a);//function: the value inside the address of variable "a"
						//output: 7
	
	//printf("%d", &*a);//error: the value does not have a address, 
						//therefore the address of the address of a specific value cannot be shown 

	return 0;
}
