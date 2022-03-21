#include "headerA3.h"
#include "headerHelperA3.h"

int searchTweetsByKeyword(tweet * tweetList)
{
    tweet * temp = tweetList;
    int count = 0; 
    int count1 = 0;
    int flag = 0;
    char * match = NULL;
    char word[50];
    char wordLower[50];
    char textLower[141];

    wordLower[0] = '0';
    textLower[0] = '0';

    printf("Enter a keyword to search: ");
    scanf("%s", word);

    for (int i = 0; word[i] != '\0'; i++)
    {
        wordLower[i] = tolower(word[i]);
        count1++;
    }

    wordLower[count1] = '\0'; 

    while (temp != NULL)
    {
        for (count = 0; temp -> text[count] != '\0';)
        {
            textLower[count] = tolower(temp -> text[count]);
            count++;
        }

        textLower[count] = '\0';
        match = strstr(textLower, wordLower);

        if (match != NULL)
        {
            flag = 1; 
            printf("Mathc found for '%s': uogsocis wrote: \"%s\"\n", word, temp -> text);
        }
        
        temp = temp -> next;
        count = 0;
    }

    if (flag == 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}