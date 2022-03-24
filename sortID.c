#include "headerHelperA3.h"

void sortID (tweet ** head)
{
    tweet * ptr = * head; 
    tweet * firstHead = NULL;
    tweet * secondHead = NULL; 

    if ( (ptr == NULL) || (ptr -> next == NULL) )
    {
        return;
    }

    splitList(ptr, &firstHead, &secondHead);

    sortID(&firstHead);
    sortID(&secondHead);

    *head = combineLists(firstHead, secondHead); 
}