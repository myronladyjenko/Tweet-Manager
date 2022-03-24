#include "headerHelperA3.h"

void loadTweetsFromFile(tweet ** tweetList)
{
    srand(time(NULL));
    FILE *fptr = NULL;

    char fileName[50];
    char string[300];
    int count = 0;
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
        while (!feof(fptr))
        {
            tweet * ptr;
            ptr = malloc (sizeof(tweet));
            ptr -> next = NULL;
            fgets(string, 300, fptr);
            // string[strlen(string) - 1] = '\0';

            char * token = NULL;
            token = strtok(string, ",");

            while (count != 3 && token != NULL)
            {
                if (count == 2)
                {
                    strcpy(ptr -> text, token);
                    break;
                }

                if (count == 0)
                {
                    printf("Id: %d\n", atoi(token));
                    ptr -> id = atoi(token);
                }

                if (count == 1)
                {
                    strcpy(ptr -> user, token);
                }

                if (count != 1)
                {
                    token = strtok(NULL, ",");
                }
                else
                {
                    token = strtok(NULL, "\n");
                }

                count++;
            }
            
            count = 0;

            int sum = ptr -> id;

            while (searchTweet(*tweetList, sum) != NULL)
            {
                // printf("ENTERS?\n");
                sum = sum + (rand() % 1000);
            }

            addNodeToList(tweetList, ptr);
        }
    }

    printf("Tweets imported!\n");
    fclose(fptr);
}