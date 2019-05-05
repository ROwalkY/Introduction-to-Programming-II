#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//struct definition
struct point{
	
	int x;
	
	int y;
	
	char label[21];
	
	struct point *ptrNext;	//self referential pointer
};


//Prototype
int isEmptyList(struct point *ptrF);

void PrintList(struct point *ptrF);

void ResetList(struct point *ptrF, struct point *ptrL);

void AddToBeginning(struct point *ptrF, struct point *ptrL);

void AddToEnd(struct point *ptrF, struct point *ptrL);

void InputRecord(struct point *ptrNew);
//used by Add to interactively get the values from the user

void SaveRecord(struct point *ptrF);

void ReadRecord(struct point *ptrF);

struct point *ptrFirst = NULL;

struct point *ptrLast = NULL;

void main(){
	
	
	
	int input;		//get user input
	
	do{
		
		printf("\n1. Add a point at the END of the list\n");
		printf("2. Add a point at the BEGINNING of the list\n");
		printf("3. Is the list empty?\n");
		printf("4. Erase all points from the list (reset)\n");
		printf("5. Display the list\n");
		printf("6. Save the list to a sequential file (reset/replace file contents)\n");
		printf("7. Read the list back from a sequential file (reset/replace current memory content)\n");
		printf("0. Exit\n");
	
	
		printf(">> ");
		scanf("%d", &input);	//get the input
		
		switch(input){
			
			case 0:

				printf("Exit Successfully\n");
				
				if(isEmptyList(ptrFirst) != 1){
					
					ResetList(ptrFirst, ptrLast);
					
				}
				
				break;
				
			case 1:
				
				AddToEnd(ptrFirst, ptrLast);
				
				printf("Added to the end of the list\n");
				
				break;
				
			case 2:
				
				AddToBeginning(ptrFirst, ptrLast);
				
				printf("Added to the beginning of the list\n");
				
				break;
			
			case 3:
			
				if(isEmptyList(ptrFirst) == 1){
					
					printf("The list is empty\n");
					
				}else{
					
					printf("The list is not empty\n");
					
				}
				
				break;
			
			case 4:
			
				ResetList(ptrFirst, ptrLast);
				
				printf("The list reset\n");
			
				break;
			
			case 5:
			
				PrintList(ptrFirst);
				
				break;
			
			case 6:
			
				SaveRecord(ptrFirst);
				
				break;
			
			case 7:
			
				ReadRecord(ptrFirst);
				
				break;
			
			default:
				
				printf("Invalid choice\n");
				
				break;
		}
	
	
	}while(input != 0);
	
	
}


//InputRecord:		get the user input and store in the memory
//INPUT:			the value of x, y and the label of the object
//OUTPUT:			the value will be stored in ptrNew
void InputRecord(struct point *ptrNew){
	
	printf("Please enter the value for x: ");
	
	scanf("%d",&ptrNew->x);
	
	printf("Please enter the value for y: ");
	
	scanf("%d%*c",&ptrNew->y);
	
	printf("Please enter the label: ");
	
	fgets(ptrNew->label,20,stdin);
	
	ptrNew->ptrNext = NULL;
}


//AddToBeginning: 	add the record to the beginning of the memory list
//INPUT:			two pointers point to the beginning of the list and the end of the list
//OUTPUT:			the record will be insert to the beginning of the list 
void AddToBeginning(struct point *ptrF, struct point *ptrL){
	
	struct point *ptr_temp = (struct point*)malloc(sizeof(struct point));
	
	if(ptr_temp != NULL){
		
		InputRecord(ptr_temp);
		
		if(ptrF == NULL){
			
			ptrFirst = ptr_temp;
			
		}else{
			
			ptr_temp->ptrNext = ptrFirst;
			
			ptrFirst = ptr_temp;
			/*
			if(ptrFirst->ptrNext == NULL){
				
				printf("The next one is NULL\n");
				
			}*/
		}
	}
}



//AddToEnd:			add the record to the end of the memory list
//INPUT:			two pointers point to the beginning of the list and the end of the list
//OUTPUT:			the record will be insert to the end of the list 
void AddToEnd(struct point *ptrF, struct point *ptrL){
	
	struct point *ptr_temp = (struct point*)malloc(sizeof(struct point));
	
	if(ptr_temp != NULL){
		
		InputRecord(ptr_temp);
		
		struct point *ptr_current = ptrF;	//a pointer indicate the current pointer location
		
		if(ptr_current == NULL){
			
			ptrFirst = ptr_temp;
			
			
		}else{
			
			while(ptr_current->ptrNext != NULL){
			
				ptr_current = ptr_current->ptrNext;
			
			}
		
			ptr_current->ptrNext = ptr_temp;	//store the record the the very end of the memory list
			
		}
		
	}
	
}


//PrintList			print all the content in the memory list
//INPUT:			the pointer point to the first record of the list
//OUTPUT:			print all the content in the list to screen
void PrintList(struct point *ptrF){
	
	struct point *ptr_current = ptrF;
	
	if(ptr_current == NULL){
		
		return;
		
	}else{
		
		while(ptr_current != NULL){
		
			printf("\nx: %d\n", ptr_current->x);
		
			printf("y: %d\n", ptr_current->y);
		
			printf("Label: %s", ptr_current->label);
		
			ptr_current = ptr_current->ptrNext;
		
		
		}
		
		
	}
	
	
	
}


//ResetList:		reset the list and get rid of the content in the list
//INPUT:			two pointers point to the beginning of the list and the end of the list
//OUTPUT:			reset the list and free the allocated memory
void ResetList(struct point *ptrF, struct point *ptrL){
	
	struct point *ptr_current = ptrF;
	
	if(ptr_current == NULL){
		
		return;
		
	}else{
		
		while(ptr_current != NULL){
		
			ptr_current = ptr_current->ptrNext;
		
			free(ptrFirst);
		
			ptrFirst = ptr_current;
		
		}
		
	}
}



//isEmptyList:		check if the list is empty or not
//INPUT:			a single pointer point to the first element of the list
//OUTPUT:			return 1 if it is empty else return 0
int isEmptyList(struct point *ptrF){
	
	if(ptrF == NULL){
		
		return 1;
		
	}else{
		
		return 0;
		
	}
	
}



//SaveRecord:		save the record into a sequential file(replace the existing content in the file)
//INPUT:			the pointer point to the first element of the list
//OUTPUT:			the content in the list will be saved into file
void SaveRecord(struct point *ptrF){
	
	FILE *fp;
	fp = fopen("data.txt","w");
	
	if(fp != NULL){
		
		if(isEmptyList(ptrFirst) != 1){
			
			struct point *ptr_current = ptrF;
			
			while(ptr_current != NULL){
				
				if(ptr_current->ptrNext == NULL){
					
					fprintf(fp,"%d\n%d\n%s",ptr_current->x, ptr_current->y,strtok(ptr_current->label,"\n"));
					
				}else{
					
					fprintf(fp,"%d\n%d\n%s",ptr_current->x, ptr_current->y,ptr_current->label);
					
				}
				
				ptr_current = ptr_current->ptrNext;
			
				
					
			}
			
			printf("Record saved in \"data.txt\"\n");
			
		}else{
			
			printf("The list is not empty\n");
			
			return;
		}
		
	}
	
	fclose(fp);
}



//ReadRecord:		read the record from a sequential file(replace the current content in the list)
//INPUT:			a pointer that point to the first element of the linked list
//OUTPUT:			the content from the file will be saved into linked list
void ReadRecord(struct point *ptrF){
	
	char check;		//check if EOF
	
	FILE *fn;
	
	fn = fopen("data.txt","r");
	
	if(fn != NULL){
		
		if(isEmptyList(ptrFirst) != 1){			//check if the list is empty
			//if the list empty, reset the list first
			
			ResetList(ptrFirst,ptrLast);
		}	
		while(!feof(fn)){
				
			struct point *ptr_temp = (struct point*)malloc(sizeof(struct point));
				
			if(ptr_temp != NULL){
	
				fscanf(fn,"%d",&ptr_temp->x);
	
				fscanf(fn,"%d%*c",&ptr_temp->y);
	
				fgets(ptr_temp->label,20,fn);
	
				ptr_temp->ptrNext = NULL;
					
				struct point *ptr_current = ptrFirst;	//a pointer indicate the current pointer location
					
					
				//check whether the current list location
				//if it it null, let temp be the first element 
				//otherwise check the last element in the list and place temp there
				if(ptr_current == NULL){
			
					ptrFirst = ptr_temp;
			
			
				}else{
			
					while(ptr_current->ptrNext != NULL){
			
						ptr_current = ptr_current->ptrNext;
			
					}
		
					ptr_current->ptrNext = ptr_temp;	//store the record the the very end of the memory list
			
				}
				
			}
				
		}
		
		printf("Record loaded from file \"data.txt\"\n");
		
	}else{
		
		printf("There's something wrong with the file \"data.txt\"\n");
		
	}
	
	fclose(fn);
}