#include "headerHelperA3.h"

tweet * createTweet(tweet * tweetList)
{
   srand(time(NULL));

   int sum = 0;
   tweet * ptr;
   ptr = malloc (sizeof(tweet));
   ptr -> next = NULL;
   
   printf("Enter a username: ");
   fgets(ptr -> user, 51, stdin);
   ptr -> user[strlen(ptr -> user) - 1] = '\0'; 

   printf("Enter the user’s tweet: ");
   fgets(ptr -> text, 141, stdin);
   ptr -> text[strlen(ptr -> text) - 1] = '\0';

   for (int i = 0; ptr -> user[i] != '\0'; i++)
   {
       sum += (int) (ptr -> user[i]);
   }

   // printf("Sum1: %d\n", sum);
   sum += strlen(ptr -> text);
   // printf("Sum2: %d\n", sum);

   while (searchTweet(tweetList, sum) != NULL)
   {
      // printf("ENTERS?\n");
      sum = sum + (rand() % 1000);
   }

   ptr -> id = sum;
   // printf("Sum: %d\n", ptr -> id);

   return ptr;
}