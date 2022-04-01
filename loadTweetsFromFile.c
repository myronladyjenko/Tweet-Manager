#include "headerHelperA3.h"

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
            ptr = malloc (sizeof(tweet));
            tweetStr = malloc (sizeof(char) * 10000);
            ptr -> next = NULL;
            
            // fgets(string, 300, fptr);

            string[strlen(string) - 1] = '\0';

            char * token = NULL;
            token = strtok(string, ",");

            if (token != NULL)
            {
                ptr -> id = atoi(token);
                // printf("Token: %d ", ptr -> id);
            }

            token = strtok(NULL, ",");

            if (token != NULL)
            {
                strcpy(ptr -> user, token);
                // printf("Token: %s\n", ptr -> user);
            } 
            
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