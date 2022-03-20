#include "headerA3.h"
#include "headerHelperA3.h"

int main()
{
    int checkCurr = 0;
    char choiceStr[101]; 
    int choice = 0; 

    tweet * head = NULL;

    do {
            printf ("\n1. Create a new tweet\n");
            printf ("2. Display tweets\n");
            printf ("3. Search a tweet (by keyword)\n");
            printf ("4. Find how many words are “stop words” (stop words are explained in a later section)\n");
            printf ("5. Delete the nth tweet\n");
            printf ("6. Save tweets to a file\n");
            printf ("7. Load tweets from a file\n");
            printf ("8. Sort the given linked list on userid\n");
            printf ("9. Exit\n");
            
            // user input for the options provided in the menu (chekcs for invalid type input
            while (checkCurr < 1) 
            {
               printf ("Choose a menu option. Please choose from 1 to 9: ");
               fgets(choiceStr, 100, stdin);
             
               for (int i = 0; choiceStr[i] != '\n'; i++)
               {
                  
                  if ( isdigit(choiceStr[i]) ) 
                  {  
                    checkCurr = 1;
                  }
                  else
                  {
                     checkCurr = 0;
                     break;
                  }     
               }
            }

            checkCurr = 0;
            choice = atoi(choiceStr);
            
            // swithc statement for each of the options provided in the menu
            switch (choice) 
            {
                case 1:
                  printf("\nCalls: createTweet.c\n");
                  head = createTweet(head);
                  printf("%s\n%s\n%d\n", head -> user, head -> text, head -> id);
                  if (head -> next != NULL)
                  printf("%s\n%s\n%d\n", (head -> next) -> user, (head -> next) -> text, (head -> next) -> id);
                  
                  break;

                case 2:
                    printf("Calls: displayTweets.c\n");
                    break;

                case 3:
                    printf("Calls: searchTweetsByKeyword.c\n");
                    break;

                case 4:
                    printf("Calls: countStopWords.c\n");
                    break;

                case 5:
                    printf("Calls: deleteTweet.c\n");
                    break;

                case 6:
                    printf("Calls: saveTweetsToFile.c\n");
                    break;

                case 7:
                    printf("Calls: loadTweetsFromFile.c\n");
                    break;

                case 8:
                    printf("Calls: sortID.c\n");
                    break;

                case 9:
                    printf("Exiting...\n");
                    break;

                // validity check for the input for the choice variable 
               default: printf ("That is an invalid choice. Please choose from 1 to 9\n");
          
            }
      
      checkCurr = 0;
    } while (choice != 9);
    
}