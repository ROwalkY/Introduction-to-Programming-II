#include <stdio.h>

  struct employee{

    char firstname[40];

    char lastname[40];

    int id;

  };

  typedef struct employee Employee;

/*Input the employee data interactively from the keyboard*/

void InputEmployeeRecord(Employee *ptrEmp);

/*Display the contents of a given Employee record*/
void PrintEmployeeRecord(const Employee e);

/*Save the contents of the employee record list to the newly created
text file specified by FileName
*/

void SaveEmployeeRecord(const Employee e[], const char *FileName);

void main(){

	Employee e1;//todo: modify to input and save an array of 3 employee records

	Employee array[3];	//store the 3 employee records
	
	Employee *ptr_a;	//point to array;
	
	ptr_a = array;
	
	int record_num;		//get the record number
  
	for(int i = 0; i < 3; i++){
		
		printf("Please enter the record: ");
		
		InputEmployeeRecord(ptr_a);
		
		ptr_a++;
		
	}
  
	for(int n = 0; n < 3; n++ ){
		
		PrintEmployeeRecord(array[n]);
		
	}
	
	
	SaveEmployeeRecord(array,"employee.dat");

}


//InputEmployeeRecord:	get the user input and store it in object variable
//INPUT:				the object pointer will be filled with record
//OUTPUT:				the record will be stored to the pointer point to 
void InputEmployeeRecord(Employee *ptrEmp){
		
	
	scanf("%d%*c%s%*c%[^\n]s", &(ptrEmp)->id,ptrEmp->firstname, ptrEmp->lastname);
		
	
}

//PrintEmployeeRecord:	print the results in given struct type variable
//INPUT:				A struct type variable
//OUTPUT:				All the content in the variable will be shown on screen
void PrintEmployeeRecord(const Employee e){
	
	printf("%d %s %s\n", e.id, e.firstname, e.lastname);
	
}


//
void SaveEmployeeRecord(const Employee e[], const char *FileName){
	
	FILE *fp;
	
	fp = fopen(FileName,"w");
	
	if(fp != NULL){
		
		fprintf(fp,"ID FIRSTNAME LASTNAME\n");
		
		for(int i = 0; i < 3; i++){
			
			fprintf(fp,"%d %s %s\n", e[i].id, e[i].firstname, e[i].lastname);
			
		}
		
		fclose(fp);
		
	}else{
		
		printf("There's something wrong with the file\n");
		
	}
	
}


