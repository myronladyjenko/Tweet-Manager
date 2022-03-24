#include "headerHelperA3.h"

void saveTweetsToFile(tweet * tweetList)
{
    FILE *fptr = NULL;
    tweet * temp = tweetList;

    char fileName[50];
    printf("Enter the filename where you would like to store your tweets: ");
    scanf("%s", fileName);

    fptr = fopen(fileName, "w");
 
    if (fptr == NULL) 
    {
        printf("Can't open file\n");
        return;
    }
    else
    {
        while (temp != NULL)
        {
            if (temp -> next == NULL)
            {
                fprintf(fptr, "%d,%s,%s", temp -> id, temp -> user, temp -> text);
            }
            else
            {
                fprintf(fptr, "%d,%s,%s\n", temp -> id, temp -> user, temp -> text);
            }
        
            temp = temp -> next;
        }
    }

    printf("Output successful!\n");
    fclose(fptr);
}