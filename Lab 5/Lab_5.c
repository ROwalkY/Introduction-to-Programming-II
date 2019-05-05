#include <stdio.h>
#include <string.h>

void ParseSentence(char *S);

int main(){

	char a[50]="hello world, how are you today.";

	ParseSentence(a);

	return 0;


}


//ParseSentence:	takes as an input parameter a  null-terminated string S
			//get rid of the punctuation and spaces then re-prints the words
			//in alphabetical order
//INPUT:		a  null-ternimated string S
//OUTPUT:		the words in string S will re-print in alphabetical order
			//without punctuation and spaces
//delimiters are assumed as space, comma, semicolon, and period
void ParseSentence(char *S){

	char limit[]=" ,;.";

	char *token = strtok(S,limit);

	char temp[20][20];	//store a word in each line

	int wordcount = 0;//count how many words

	int done = 0;

	char swap[20];	//use to swap the words

	while( token != NULL ){

		strcpy(temp[wordcount], token);

		wordcount++;

		token = strtok(NULL, limit);

	}


	for(int i = 0; i < wordcount - 1 && !done; i++){

		done = 1;

		for(int n = wordcount - 1; n > i; n--){

			if(strcmp(temp[n], temp[n-1]) < 0){

				strcpy(swap, temp[n]);

				strcpy(temp[n], temp[n-1]);

				strcpy(temp[n-1], swap);

				done = 0;

			}

		}

	}


	for(int j = 0; j < wordcount; j++){

		printf("%s\n", temp[j]);

	}
}
