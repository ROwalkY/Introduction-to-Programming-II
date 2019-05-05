/*
	Xiaoshuai Geng
	104845608
	Class Section: 01
	Lab Section: 55
	7 Mar 2018
	lab exam 2
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ROWS 9
#define COLS 10

int InitializeA(char A[][COLS]);

int ParseSentence(char A[][COLS], char *S);

void PrintWordList(char A[][COLS]);


void main(){

  char A[ROWS][COLS];
  char S[100];

  gets(S);
  InitializeA(A);
  ParseSentence(A,S); //todo: code these functions
  PrintWordList(A);

}

//InitializeA: initialize all the contents of A
//INPUT:    A 2d array that need to be initialized
//OUTPUT:   all the contents in A will be initialized to '\0'
int InitializeA(char A[][COLS]){

  for(int i = 0; i < ROWS; ++i){

    for(int n = 0; n < COLS; ++n){

      A[i][n] = '\0';

    }

  }
  return 0;
}

//ParseSentence:    Extracts the words from the sentence and stores them in the 2D array and each row holds one words
//INPUT:    a 2D array to store the wordlist and the sentence S that contains the words to be tokenized
//OUTPUT:   each word from the sentence S will be copyed to 2d array in the corresponding row
int ParseSentence(char A[][COLS], char *S){

  int row = 0;

  int count;  //use to count the current cell number

  char temp[ROWS][COLS];

  char limit[]=" ";
/*----------TOkenize the sentence S------------------*/
  char *token = strtok(S,limit);

  while( token != NULL ){

    strcpy(temp[row], token);

    row++;

		token = strtok(NULL, limit);

	}

/*----------TOkenize the sentence S------------------*/

  for(int n = 0;n < 9; n++ ){

    switch (temp[n][0]) {
      case 'a':
      case 'b':
      case 'c':
        if(A[0][0] == '\0'){

          strcpy(A[0], temp[n]);

        }else{

          count = 0;

          count++;

          while(A[count][0] !='\0'){

            count++;

            if(count > 8){

              count = 0;

            }

          }

          strcpy(A[count], temp[n]);

        }
        break;

      case 'd':
      case 'e':
      case 'f':
        if(A[1][0] == '\0'){

            strcpy(A[1], temp[n]);

        }else{

          count = 1;

          count++;
          while(A[count][0] !='\0'){

            count++;

            if(count > 8){

              count = 0;

            }

          }

          strcpy(A[count], temp[n]);

        }
        break;

        case 'g':
        case 'h':
        case 'i':
          if(A[2][0] == '\0'){

              strcpy(A[2], temp[n]);

          }else{

            count = 2;

            count++;
            while(A[count][0] !='\0'){

              count++;

              if(count > 8){

                count = 0;

              }

            }

            strcpy(A[count], temp[n]);

          }
          break;

          case 'j':
          case 'k':
          case 'l':
            if(A[3][0] == '\0'){

                strcpy(A[3], temp[n]);

            }else{

              count = 3;

              count++;
              while(A[count][0] !='\0'){

                count++;

                if(count > 8){

                  count = 0;

                }

              }

              strcpy(A[count], temp[n]);

            }
            break;

            case 'm':
            case 'n':
            case 'o':
              if(A[4][0] == '\0'){

                  strcpy(A[4], temp[n]);

              }else{

                count = 4;

                count++;
                while(A[count][0] !='\0'){

                  count++;

                  if(count > 8){

                    count = 0;

                  }

                }

                strcpy(A[count], temp[n]);

              }
              break;

              case 'p':
              case 'q':
              case 'r':
                if(A[5][0] == '\0'){

                    strcpy(A[5], temp[n]);

                }else{

                  count = 5;

                  count++;
                  while(A[count][0] !='\0'){

                    count++;

                    if(count > 8){

                      count = 0;

                    }

                  }

                  strcpy(A[count], temp[n]);

                }
                break;

                case 's':
                case 't':
                case 'u':
                  if(A[6][0] == '\0'){

                      strcpy(A[6], temp[n]);

                  }else{

                    count = 6;

                    count++;
                    while(A[count][0] !='\0'){

                      count++;

                      if(count > 8){

                        count = 0;

                      }

                    }

                    strcpy(A[count], temp[n]);

                  }
                  break;

                case 'v':
                case 'w':
                case 'x':
                  if(A[7][0] == '\0'){

                    strcpy(A[7], temp[n]);

                  }else{

                      count = 7;

                      count++;
                      while(A[count][0] !='\0'){

                        count++;

                        if(count > 8){

                          count = 0;

                        }

                      }

                      strcpy(A[count], temp[n]);

                    }
                    break;

                    case 'y':
                    case 'z':
                      if(A[8][0] == '\0'){

                          strcpy(A[8], temp[n]);

                      }else{

                        count = 8;

                        count++;
                        while(A[count][0] !='\0'){

                          count++;

                          if(count > 8){

                            count = 0;

                          }

                        }

                        strcpy(A[count], temp[n]);

                      }
                      break;
    }

  }



  return 0;
}


//PrintWordList:  print every element in the list
//input:  a 2d array need to be printed
//output: all the element being print to the array
void PrintWordList(char A[][COLS]){

  for(int i =0; i < 9; ++i){

    printf("%s\n", A[i]);

  }

}
