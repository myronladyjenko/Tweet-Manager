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
   char * user = NULL;
   char * text = NULL;
   userName = malloc(sizeof(char) * 102);
   userText = malloc(sizeof(char) * 102);
   user = malloc(sizeof(char) * 52);
   text = malloc(sizeof(char) * 142);
   int flag = 0;
   srand(time(NULL));

   int sum = 0;
   tweet * ptr;
   ptr = malloc (sizeof(tweet));
   ptr -> next = NULL;
   
   // prompt for the username
   do {
      // clear input
      while (flag == 1)
      {
          // printf("string: %s\n", userName);
          fgets(userName, 102, stdin);

          if (userName[strlen(userName) - 1] == '\n')
          {
              break;
          }
      }

      flag = 0;
      printf("Enter a username (<= 50 characters): ");
      fgets(user, 52, stdin);

      // printf("String: %s\n", user);
      // printf("Char: %c\n", user[strlen(user) - 1]);

      if (user[strlen(user) - 1] == '\n')
      {
         user[strlen(user) - 1] = '\0';
      } 

      if (strlen(user) > 50 && user[50] != '\n')
      {
          flag = 1;
      }
      // printf("length: %d\n", strlen( user));

   } while (strlen(user) > 50 && user[50] != '\n');
    
   strcpy(ptr -> user, user); 
   flag = 0;
   
   // prompt for the tweet
   do {
      // clear stdin
      while (flag == 1)
      {
          fgets(userText, 102, stdin);
          if (userText[strlen(userText) - 1] == '\n')
          {
              break;
          } 
      }

      flag = 0;

      printf("Enter a text for a tweet (<= 140 characters): ");
      fgets(text, 142, stdin);

      if (text[strlen(text) - 1] == '\n')
      {
         text[strlen(text) - 1] = '\0';
      } 

      if (strlen(text) > 140 && text[140] != '\n')
      {
          flag = 1;
      }

   } while (strlen(text) > 140 && text[140] != '\n');
   
   strcpy(ptr -> text, text); 
   
   free(userName);
   free(userText);
   free(user);
   free(text);
   
   // generate the user id
   for (int i = 0; ptr -> user[i] != '\0'; i++)
   {
       sum += (int) (ptr -> user[i]);
   }

   sum += strlen(ptr -> text);
   
   // generate a unique user id, if the it already exists
   while (searchTweet(tweetList, sum) != NULL)
   {
      sum = sum + (rand() % 1000);
   }

   ptr -> id = sum;
   printf("Your computer generated id is: %d\n", ptr -> id);

   return ptr;
}