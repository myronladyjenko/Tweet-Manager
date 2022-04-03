#include "headerHelperA3.h"

/******
sortID: Sort the tweets in the linked list in an ascending order of userids. Calls helper functions: splitList() and sortID().
In: tweet ** head
Out: void
Post: nothing
*******/
void sortID (tweet ** head)
{
    tweet * ptr = * head; 
    tweet * firstHead = NULL;
    tweet * secondHead = NULL; 

    if ( (ptr == NULL) || (ptr -> next == NULL) )
    {
        return;
    }
    
    // recursively split the linked list into two halves
    splitList(ptr, &firstHead, &secondHead);
    
    sortID(&firstHead);
    sortID(&secondHead);
    
    // combine lists
    *head = combineLists(firstHead, secondHead); 
}