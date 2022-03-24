#include "headerHelperA3.h"

tweet * searchTweet(tweet * tweetList, int sum)
{
    tweet * temp = tweetList;

    while (temp != NULL)
    {
        if (temp -> id == sum)
        {
            return temp;
        }

        temp = temp -> next;
    }

    return NULL; 
}