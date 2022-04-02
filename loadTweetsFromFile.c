#include "headerHelperA3.h"

/******
loadTweetsFromFile: This function load the contents for each tweet into the node, and them adds it into the linked list.
In: tweet ** tweetList
Out: void
Post: prints a succes message if the tweets were imported, and not otherwise.
*******/
void loadTweetsFromFile(tweet ** tweetList)
{
    srand(time(NULL));
    FILE *fptr = NULL;   
    tweet * ptr;

    char fileName[50];
    char string[300];
    char * tweetStr = NULL;
    printf("Enter a filename to load from: ");
    scanf("%s", fileName);

    fptr = fopen(fileName, "r");
 
    if (fptr == NULL) 
    {
        printf("Can't open file\n");
        return;
    }
    else
    {
        while (fgets(string, 300, fptr) != NULL)
        {
            ptr = calloc (1, sizeof(tweet));
            tweetStr = malloc (sizeof(char) * 10000);
            ptr -> next = NULL;

            if (string[strlen(string) - 1] == '\n' || string[strlen(string) - 2] == '\n')
            {
                string[strlen(string) - 1] = '\0';
            }

            // delete all trailing spaces
            int length = strlen(string) - 1;
            int countSpaces = 0;
            while (isspace(string[length]) != 0)
            {
                // printf("%c\n", string[length]);
                countSpaces++;
                length--;
            }
            
            // printf("Spaces: %d\n", countSpaces);
            string[strlen(string) - countSpaces] = '\0';
            // printf("String: %s\n", string);

            char * token = NULL;
            token = strtok(string, ",");


            if (token != NULL && token[0] != 13)
            {
                ptr -> id = atoi(token);
                // printf("Token: %d \n", ptr -> id);
            }
            
            token = strtok(NULL, ",");

            if (token != NULL && token[0] != 13)
            {
                // printf("Token: %s\n", ptr -> user);
                strcpy(ptr -> user, token);
            } 
            
            /*
            token = strtok(NULL, ",");
            strcpy(tweetStr, token);

            token = strtok(NULL, ",");
            // printf("token: %s\n", token);
            while (token != NULL && token[0] != 13)
            {
                strcat(tweetStr, ",");
                strcat(tweetStr, token);
                token = strtok(NULL, ",");
            }

            strcpy(ptr -> text, tweetStr); 
            */

            token = strtok(NULL, "");
            token[strlen(token) - 1] = '\0';
            strcpy(ptr -> text, token); 

            int sum = ptr -> id;

            while (searchTweet(*tweetList, sum) != NULL)
            {
                sum = sum + (rand() % 1000);
            }

            addNodeToList(tweetList, ptr);
            free(tweetStr);
        }
    }
    
    printf("Tweets imported!\n");
    fclose(fptr);
}