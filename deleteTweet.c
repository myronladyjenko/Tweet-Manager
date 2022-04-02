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

    while (temp1 != NULL)
    {
        currNumTweets++;
        temp1 = temp1 -> next;
    } 

    printf("Currently there are %d tweets\n", currNumTweets);
    printf("Which twwet you wish to delete - enter a value between 1 and %d: ", currNumTweets);
    scanf("%d", &tweetToDelete);
    
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
        id = delete -> id;
        temp2 -> next = temp2 -> next -> next;
        delete -> next = NULL;
        free(delete);
    }

    printf("\nTweet %d (id: %d) deleted. There are now %d tweets left.", tweetToDelete, id, currNumTweets - 1);
}