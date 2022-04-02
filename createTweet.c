#include "headerHelperA3.h"

/******
createTweet: If this function is called, through the menu, the user should have the option to create a new tweet and fill in some of the parameters for the
struct manually (namely, the username and user’s tweet). Userid is automatically generated using the following rule:
userid = (sum of ascii values of characters in the username) + (length of the user’s tweet). For example, for the
sample given above, the generated userid = (117 + 103 + 111) + 44 = 375. If this userid already exists in the current
linked list, then add random numbers between 1 and 999, repeatedly, until a unique id is generated.
In: tweet * tweetList
Out: tweet *
Post: the user fill out the cntents for the tweet, and that tweet gets returned.
*******/
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