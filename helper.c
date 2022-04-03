#include "headerHelperA3.h"

/******
splitList: This function splits the given list into two halfes (if odd, then uneven halfes)
In: tweet * head, tweet ** firstList, tweet ** secondList
Out: void
Post: nothing
*******/
void splitList(tweet * head, tweet ** firstList, tweet ** secondList)
{
    // create two temp pointers
    tweet * ptr = head;
    tweet * ptrNew = head;
    int numNodes = 0;
    int halfNodes = 0;
    int count = 1;
    
    // count the number of nodes
    while (ptr != NULL)
    {
       numNodes++;
       ptr = ptr -> next; 
    }

    halfNodes = numNodes / 2;
    
    // loop to the half nodes
    while (count < halfNodes)
    {
        count++;
        ptrNew = ptrNew -> next;
    }
    
    // assign second half of the list (first node in second half) to the secondList
    *secondList = ptrNew -> next;
    ptrNew -> next = NULL;
    // assign first half of the list (first node in first half) to the firstList
    *firstList = head;
}

/******
combineLists: This function takes two linked lists and combines them in an acsending order of userids'
In: tweet * headFirst, tweet * headSecond
Out: tweet *
Post: retunrs final (combined) list
*******/
tweet * combineLists(tweet * headFirst, tweet * headSecond)
{
    tweet * finalList = NULL;
    
    // base case
    if (headFirst == NULL)
    {
        return headSecond;
    }
    
    // base case
    if (headSecond == NULL)
    {
        return headFirst;
    }
    

    // merging lists in ascending order
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

/******
numStopWords: This function searches the tweet for the stop word passed and count them.
In: char arr[141], char word[10]
Out: int
Post: retunrs the number of stop words found in the tweet
*******/
int numStopWords(char arr[141], char word[10])
{
    char * token = NULL;

    // create a copy of the array
    char arrCopy[141];
    strcpy(arrCopy, arr);
    // printf("arr: %s; word: %s\n", arr, word);

    int count = 0;
    token = strtok(arrCopy, " ");
    
    // loop for through every word (separated by space)
    while (token != NULL)
    {
        // compare words
        if (strcmp(token, word) == 0)
        {
            // printf("%s %s ", word, token);
            count++;
        }

        token = strtok(NULL, " ");
    }

    return count;
}

/******
searchTweet: This function searches the tweet for the id same as passed id (sum).
In: tweet * tweetList, int sum
Out: tweet *
Post: retunrs the node if it was found, otherwise NULL.
*******/
tweet * searchTweet(tweet * tweetList, int sum)
{
    tweet * temp = tweetList;
    
    // searches if the sum(id) exists in the list 
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

/******
addNodeToList: This function takes a list of all tweets and add a new one to the end of the list
In: tweet** tweetList, tweet * node
Out: void
Post: nothing
*******/
void addNodeToList(tweet** tweetList, tweet * node)
{
    tweet *temp = *tweetList;
    // printf("Id: %d\n", node -> id);
     
    if (*tweetList == NULL)
    {
        *tweetList = node;
        return;
    }
    
    // loop to the second last node
    while (temp -> next != NULL)
    {
        temp = temp -> next;
    }
    
    // insert node
    temp -> next = node;
    return;
}