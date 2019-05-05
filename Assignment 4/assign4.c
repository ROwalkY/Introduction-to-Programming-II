#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct tweet{		
	
	int id;
	
	char created_at[51];	
	
	char text[141];			
	
	char user[21];			
	
	struct tweet *ptrNext;	
	
};

typedef struct tweet Tweet;

Tweet *ptrFirst = NULL;

Tweet *ptrLast = NULL;

//Function Prototype

int isEmptyList(struct tweet *ptrF);

void PrintList(struct tweet *ptrF);

void SaveToFile(struct tweet *ptrF);

void ResetList(struct tweet *ptrF);

int main(){
	
	FILE *fp;
	
	fp = fopen("tweet.txt","r");
		
	if(fp!=NULL){
		
		while(!feof(fp)){
		
			Tweet *ptrNew = (Tweet*)malloc(sizeof(Tweet));
		
			fscanf(fp,"%d",&ptrNew->id);
			
			fscanf(fp,"%*c");
			
			fscanf(fp,"%24[^\n]s",ptrNew->created_at);
			
			fscanf(fp,"%*c");
			
			fscanf(fp,"%20[^\n]s%*c",ptrNew->user);
			
			fscanf(fp,"%*c");
				
			fscanf(fp,"%140[^\n]s",ptrNew->text);
		
			ptrNew->ptrNext = NULL;
		
			
		
			
			if(isEmptyList(ptrFirst) != 0){
			
				ptrFirst = ptrNew;		
									
				ptrLast = ptrNew;
			
			}else{
			
				if(strcmp(ptrFirst->user,ptrNew->user)>=0){
				
					ptrNew->ptrNext = ptrFirst;
				
					ptrFirst = ptrNew;
				
				}else if(strcmp(ptrLast->user,ptrNew->user)<=0){
				
					ptrLast->ptrNext = ptrNew;
			
					ptrLast = ptrNew;
				
				}else{
				
					Tweet *ptrPrevious = ptrFirst;		
				
					while(strcmp(ptrPrevious->ptrNext->user,ptrNew->user)<0){
						
						ptrPrevious = ptrPrevious->ptrNext;
					
					}
				
					ptrNew->ptrNext = ptrPrevious->ptrNext;
					
					ptrPrevious->ptrNext = ptrNew; 
				
				}
			
			
			
			}
			
		}
		
	}else{
		
		puts("There's something wrong with the file");
		
	}
	
	fclose(fp);
	
	SaveToFile(ptrFirst);
	
	ResetList(ptrFirst);
	
	return 0;
}


//isEmptyList:		check if the list is empty or not
//INPUT:			a single pointer point to the first element of the list
//OUTPUT:			return 1 if it is empty else return 0
int isEmptyList(struct tweet *ptrF){
	
	if(ptrF == NULL){
		
		return 1;
		
	}else{
		
		return 0;
		
	}
	
}



//SaveToFile:		save the linked list into file
//INPUT:			a struct tweet type pointer point to the beginning of the list
//OUTPUT:			The linked list will be saved into file named "tweet.txt"
void SaveToFile(struct tweet *ptrF){
	
	if(isEmptyList(ptrF) != 0 ){
		
		return;
		
	}else{
		
		struct tweet *ptrcurrent = ptrF;
		
		FILE *fp;
		
		fp = fopen("tweet.txt","w");
		
		while(ptrcurrent != NULL){
		
			if(ptrcurrent->ptrNext != NULL){		//check if it is the end(last element) of the list
			
				fprintf(fp,"%d\n",ptrcurrent->id);
			
				fprintf(fp,"%s\n",ptrcurrent->created_at);
		
				fprintf(fp,"%s\n",ptrcurrent->user);
			
				fprintf(fp,"%s\n",ptrcurrent->text);
			
			}else{
			
				fprintf(fp,"%d\n",ptrcurrent->id);
			
				fprintf(fp,"%s\n",ptrcurrent->created_at);
		
				fprintf(fp,"%s\n",ptrcurrent->user);
			
				fprintf(fp,"%s",ptrcurrent->text);
			
			}
		
			ptrcurrent = ptrcurrent->ptrNext;
		
		}
		
		fclose(fp);
		
		
	}
	
}


//ResetList:		reset the list and get rid of the content in the list
//INPUT:			two pointers point to the beginning of the list and the end of the list
//OUTPUT:			reset the list and free the allocated memory
void ResetList(struct tweet *ptrF){
	
	struct tweet *ptr_current = ptrF;
	
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