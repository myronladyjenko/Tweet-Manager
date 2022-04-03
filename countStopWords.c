#include "headerHelperA3.h"

/******
countStopWords: For this function, the program will
traverse the entire linked list and calculate the number of stop words that are present across all tweets, outputting the
summation of all tweets. For this program, only the top 25 stop words will be considered:
"a","an","and","are","as","at","be","by","for","from","has","he","in","is","it","its",
"of","on","that","the","to","was","were","will","with"
In: tweet * tweetList
Out: void
Post: prints how many tweets were searched and how many stop words were found
*******/
void countStopWords(tweet * tweetList)
{
    char listOfWords[25][10];
    char textLower[142];
    int count = 0;
    tweet * temp = tweetList;
    int sumStopWords = 0;
    int numberOfTweets = 0;

    strcpy(listOfWords[0], "a");
    strcpy(listOfWords[1], "an");
    strcpy(listOfWords[2], "and");
    strcpy(listOfWords[3], "are");
    strcpy(listOfWords[4], "as");
    strcpy(listOfWords[5], "at");
    strcpy(listOfWords[6], "be");
    strcpy(listOfWords[7], "by");
    strcpy(listOfWords[8], "for");
    strcpy(listOfWords[9], "from");
    strcpy(listOfWords[10], "has");
    strcpy(listOfWords[11], "he");
    strcpy(listOfWords[12], "in");
    strcpy(listOfWords[13], "is");
    strcpy(listOfWords[14], "it");
    strcpy(listOfWords[15], "its");
    strcpy(listOfWords[16], "of");
    strcpy(listOfWords[17], "on");
    strcpy(listOfWords[18], "that");
    strcpy(listOfWords[19], "the");
    strcpy(listOfWords[20], "to");
    strcpy(listOfWords[21], "was");
    strcpy(listOfWords[22], "were");
    strcpy(listOfWords[23], "will");
    strcpy(listOfWords[24], "with");
    
    while (temp != NULL)
    {
        numberOfTweets++;
        strcpy(textLower, temp -> text);
        
        // lowercase each letter in the tweet
        for (count = 0; temp -> text[count] != '\0';)
        {
            textLower[count] = tolower(temp -> text[count]);
            count++;
        }

        textLower[count] = '\0';

        for (int i = 0; i < 25; i++)
        {
            // call function that looks for a stop word
            sumStopWords += numStopWords(textLower, listOfWords[i]);
        }
        // printf("%d\n", sumStopWords);
        temp = temp -> next;
    }

    printf("Across %d tweets, %d stop words were found.\n", numberOfTweets, sumStopWords);
}