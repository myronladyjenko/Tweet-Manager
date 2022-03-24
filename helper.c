#include "headerHelperA3.h"

void splitList(tweet * head, tweet ** firstList, tweet ** secondList)
{
    tweet * ptr = head;
    tweet * ptrNew = head;
    int numNodes = 0;
    int halfNodes = 0;
    int count = 1;

    while (ptr != NULL)
    {
       numNodes++;
       ptr = ptr -> next; 
    }

    halfNodes = numNodes / 2;

    while (count < halfNodes)
    {
        count++;
        ptrNew = ptrNew -> next;
    }

    *secondList = ptrNew -> next;
    ptrNew -> next = NULL;
    *firstList = head;
}

tweet * combineLists(tweet * headFirst, tweet * headSecond)
{
    tweet * finalList = NULL;
    
    if (headFirst == NULL)
    {
        return headSecond;
    }

    if (headSecond == NULL)
    {
        return headFirst;
    }

    if (headFirst -> id < headSecond -> id)
    {
        finalList = headFirst;
        finalList -> next = combineLists(headFirst -> next, headSecond);
    }
    else
    {
        finalList = headSecond;
        finalList -> next = combineLists(headFirst, headSecond -> next);
    }

    return finalList;
    
}