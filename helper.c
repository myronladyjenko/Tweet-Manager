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

int numWordsInLine(char arr[141], char word[10])
{
    char * token = NULL;
    char arrCopy[141];
    strcpy(arrCopy, arr);
    // printf("arr: %s; word: %s\n", arr, word);

    int count = 0;
    token = strtok(arrCopy, ", ");

    while (token != NULL)
    {
        if (strcmp(token, word) == 0)
        {
            // printf("HERE\n");
            count++;
        }

        token = strtok(NULL, ", ");
    }

    return count;
}

int numStopWords(char arr[141], char word[10])
{
    char * token = NULL;
    char arrCopy[141];
    strcpy(arrCopy, arr);
    // printf("arr: %s; word: %s\n", arr, word);

    int count = 0;
    token = strtok(arrCopy, " ");

    while (token != NULL)
    {
        if (strcmp(token, word) == 0)
        {
            // printf("%s %s ", word, token);
            count++;
        }

        token = strtok(NULL, " ");
    }

    return count;
}

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