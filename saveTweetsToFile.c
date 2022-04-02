#include "headerHelperA3.h"

/******
saveTweetsToFile: For this function the user first gets prompted for the filename to output their tweets to.
Unless chosen by the user through the menu (Option 6), the tweet data will not be output to file; that is, if the user
chooses Exit before saving, then the data that they input is lost. Tweet storage should follow the CSV format of the
input file, such that the file can be reloaded using the load menu option. The format of the CSV is as follows: id,
user, text.
In: tweet * tweetList
Out: void
Post: prints if the output was succesful, or the file couldn't open
*******/
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