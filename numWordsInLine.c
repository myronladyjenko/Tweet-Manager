#include "headerHelperA3.h"

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