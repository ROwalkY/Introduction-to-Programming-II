#include <stdio.h>
#include <ctype.h>
#include <string.h>

//struct definition: 2 char array with length of 40 
//and an integer type indicate record id
  struct employee{

    char firstname[40];

    char lastname[40];

    int id;

  };

  typedef struct employee Employee;

//Prototype:
void WordCap(char *name);  
  
int main(){
	
	Employee EmployeeList[3];
	
	FILE *fp;
	
	fp = fopen("employee.dat","r");
	
	
	int i = 0;
	
	char list[40];
	
	if(fp != NULL){
		
		
		
		for(i = 0; i < 3; i++){
			
			if(i == 0){
				
				fscanf(fp,"%[^\n]s",list);
				
				//printf("%s ",list);
			}	
				
			fscanf(fp,"%*c%d",&EmployeeList[i].id);
			
			//printf("%d ",EmployeeList[i].id);
			
			fscanf(fp,"%*c%39[^ ]s",EmployeeList[i].firstname);
			
			WordCap(EmployeeList[i].firstname);
			//printf("%s ",EmployeeList[i].firstname);
			
			fscanf(fp,"%*c%39[^\n]s%*c",EmployeeList[i].lastname);
			
			WordCap(EmployeeList[i].lastname);
			//printf("%s ",EmployeeList[i].lastname);	
				
		}
			
			
		fclose(fp);
		
		FILE *fn;
	
		fn = fopen("employee.dat","w");
		
		fprintf(fn,"%s\n",list);
		
		for(int n = 0; n < 3; n++){
			
			fprintf(fn,"%d %s %s\n",EmployeeList[n].id,EmployeeList[n].firstname,EmployeeList[n].lastname);
			
		}
		
		fclose(fn);
		
	}else{
		
		puts("There's something wrong with the file");
		
	}
	
	return 0;
}

//WordCap:		get a string and capitalize the first element
//INPUT:		takes a char pointer
//OUTPUT:		capitalize the first character and remain the rest lower case
void WordCap(char *name){
	
	int length = strlen(name);
	
	name[0] = toupper(name[0]);
	
	for(int i = 1; i < length; i++){
		
		name[i] = tolower(name[i]);
		
	}
}