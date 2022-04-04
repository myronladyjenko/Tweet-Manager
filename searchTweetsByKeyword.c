#include "headerHelperA3.h"

/******
searchTweetsByKeyword: Searching for tweets in this assignment will be done by keyword. To search for tweets, the linked list
should be traversed to find all tweets that have the user-provided substring inside them. If a match is found, that
tweet should be printed to console along with its associated user value. Search is case-insensitive.
In: tweet * tweetList
Out: int
Post: outputs how the tweets where the word was found
*******/
int searchTweetsByKeyword(tweet * tweetList)
{
    tweet * temp = tweetList;
    int count = 0; 
    int count1 = 0;
    int flag = 0;
    char word[50];
    char wordLower[50];
    char textLower[141];

    wordLower[0] = '0';
    textLower[0] = '0';
    
    do {
        printf("Enter a keyword to search (non-zero length): ");
        fgets(word, 50, stdin);
        word[strlen(word) - 1] = '\0';
    } while (strlen(word) == 0);
    
    // make the letters in the word be lowercase
    for (int i = 0; word[i] != '\0'; i++)
    {
        wordLower[i] = tolower(word[i]);
        count1++;
    }

    wordLower[count1] = '\0'; 

    while (temp != NULL)
    {
        // make the letters in the tweet be lowercase
        for (count = 0; temp -> text[count] != '\0';)
        {
            textLower[count] = tolower(temp -> text[count]);
            count++;
        }

        textLower[count] = '\0';

        // count if the keyword is in the tweet 
        if (strstr(textLower, wordLower) != NULL)
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