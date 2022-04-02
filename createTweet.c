#include "headerHelperA3.h"

tweet * createTweet(tweet * tweetList)
{
   char * userName = NULL;
   char * userText = NULL;
   userName = malloc(sizeof(char) * 10000);
   userText = malloc(sizeof(char) * 10000);
   srand(time(NULL));

   int sum = 0;
   tweet * ptr;
   ptr = malloc (sizeof(tweet));
   ptr -> next = NULL;
   
   do {
      printf("Enter a username (<= 50 characters): ");
      fgets(userName, 51, stdin);
      userName[strlen(userName) - 1] = '\0';
   } while (strlen(userName) > 50 || strlen(userName) <= 0);

   strcpy(ptr -> user, userName);
   
   do {
      printf("PLease, enter the user’s tweet (<=140 characters): ");
      fgets(userText, 10000, stdin);
      userText[strlen(userText) - 1] = '\0';
   } while (strlen(userText) > 140 || strlen(userText) <= 0);

   strcpy(ptr -> text, userText);
   
   free(userName);
   free(userText);

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