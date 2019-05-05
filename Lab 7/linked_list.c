
struct student
{
   int id;        /* stores a unique student id number */
   char name[40];    /* stores a student's full name */
   struct student * pNext; /* self referencial pointer */
            /* used to point to the next student record in the linked list */ };


struct student *pFirst = NULL;

struct student *pLast = NULL;

int main()
{
   int done = 0;        /* done used as a flag to exit the interactive loop (-1) and as an ID input */
   struct student * pNew = NULL; /* pNew is used as a temporary pointer to refer to the newly created record */

   /* interactive repeat and ask for the user's input, -1 to quit */
   /* this is used to illustrate that the user may enter as many records as he/she wishes */
   /* arrays cannot be used to do this properly, since we do not know in advance how many records are being entered */
   do
   {
      /* prompt the user for an id, or -1 to quit */
      printf("Enter an id (-1 to quit): ");
      scanf("%d", &done);

      if (done == -1)
         break;   /* use break and NOT return because in the case when we have already created a number of 
               records then we should free these records before we exit the program to avoid a memory
               leak 
             */

      /* create a new record, note the cast used for compliance with strict typing in C */
      pNew = (struct student *) (malloc( sizeof( struct student)) );

      /* check if the memory space was actually allocated */
      if (pNew == NULL)
         break;   /* again, we may still need to clear already allocated records */

      /* store the id in the newly created student record */
      pNew->id = done;

      /* prompt for the name and store it */
      printf("Enter a name: ");
      scanf("%s", pNew->name);

      /* we are adding the new nodes to the end of the list, so the newly created node will have 
        its pNext (pointer to the next record) as NULL to indicate the end of the list */
      pNew->pNext = NULL;

      /* special case: if this is the first record, then make pFirst point to it */
      if (pFirst == NULL)
         pFirst = pNew;

      /* special case: if this is the first record then do not increment the pLast pointer */
      /* which by the way was the problem causing the "segmentation fault" in class */
      /* you really have to draw this and trace it manually to see why! */
      if (pLast != NULL)
         pLast->pNext = pNew;

      /* update the last pointer, ie: make the new node the last one */
      pLast = pNew;

   } while(done != -1);


   /* display what we have in that list, we only need to supply the pointer to the first element in the list */
   PrintList(pFirst);

   /* WE MUST FREE ALL DYNAMICALLY ALLOCATED RECORDS!!!! Rule: for every malloc there is a free */
   /* again, we only need to supply the function the first node, it can find the remaining nodes easily */
   ClearList(pFirst);


   /* we can safely exit the program now provided we freed all dynamically allocated records */
   return 0;
}
