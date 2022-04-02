#include "headerHelperA3.h"

void displayTweets(tweet * tweetList)
{
    tweet * temp = tweetList;

    while (temp != NULL)
    {
        printf("%d: Created by %s: %s\n", temp -> id, temp -> user, temp -> text);
        temp = temp -> next;
    }
}