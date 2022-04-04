#include "headerHelperA3.h"


/******
deleteTweet: If this function is called, he user is prompted to give a value between 1 and the total number of tweets your linked list has –
note that this number must be equal to the total number of tweets at that time.
In: tweet ** tweetList
Out: void
Post: the id of the tweet that got deleted
*******/
void deleteTweet(tweet ** tweetList)
{
    int currNumTweets = 0;
    int tweetToDelete = 0;
    int id = 0;
    tweet * temp1 = *tweetList;
    tweet * temp2 = *tweetList;
    char * number = NULL;
    number = malloc(sizeof(char) * 102);
    
    // count number of words in the tweet
    while (temp1 != NULL)
    {
        currNumTweets++;
        temp1 = temp1 -> next;
    } 

    printf("Currently there are %d tweets\n", currNumTweets);

    if (currNumTweets == 0)
    {
        printf("IMPORTANT: The list has no tweets to delete!\n");
        free(number);
        return;
    }

    printf("Which twwet you wish to delete - enter a value between 1 and %d (enter -1 if you want to exit the function): ", currNumTweets);
     
    fgets(number, 102, stdin);
    // re-prompt the user for the proper input
    while ( (atoi(number) == 0 || atoi(number) > currNumTweets || atoi(number) < 1) && atoi(number) != -1)
    {
        printf("PLease, enter a correct number - enter a value between 1 and %d (enter -1 if you want to exit the function): ", currNumTweets);
        fgets(number, 100, stdin); 
    }

    tweetToDelete = atoi(number);

    if (tweetToDelete == -1)
    {
        printf("Exiting fucntion...\n");
        free(number);
        return;
    }

    // delete node 
    if (tweetToDelete == 1)
    {
        id = (*tweetList) -> id;
        *tweetList = (*tweetList) -> next;
        temp2 -> next = NULL;
        free(temp2);
    }
    else
    {
        for (int i = 1; i < tweetToDelete - 1; i++)
        {
            temp2 = temp2 -> next;
        }
        
        tweet * delete = temp2 -> next;
        // preserve the id of the deleted node
        id = delete -> id;
        temp2 -> next = temp2 -> next -> next;
        delete -> next = NULL;
        free(delete);
    }
    
    free(number);
    printf("\nTweet %d (id: %d) deleted. There are now %d tweets left.", tweetToDelete, id, currNumTweets - 1);
}