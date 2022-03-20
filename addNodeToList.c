#include "headerA3.h"

void addNodeToList(tweet** tweetList, tweet * node)
{
    tweet *temp = *tweetList;
    // printf("Id: %d\n", node -> id);

    if (*tweetList == NULL)
    {
        *tweetList = node;
        return;
    }

    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }

    temp -> next = node;
    return;
}