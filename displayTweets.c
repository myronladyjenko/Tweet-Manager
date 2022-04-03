#include "headerHelperA3.h"

/******
displayTweet: all of the tweets that are currently in memory (ie. in the linked list) will be displayed
to the user.
In: tweet * tweetList
Out: void
Post: All the static contents of every tweet
*******/
void displayTweets(tweet * tweetList)
{
    tweet * temp = tweetList;
    
    // loop through each element and print its' contents
    while (temp != NULL)
    {
        printf("%d: Created by %s: %s\n", temp -> id, temp -> user, temp -> text);
        temp = temp -> next;
    }
}