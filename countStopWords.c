#include "headerHelperA3.h"

void countStopWords(tweet * tweetList)
{
    char listOfWords[25][10];
    char tweetLine[141];
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
        strcpy(tweetLine, temp -> text);

        for (int i = 0; i < 25; i++)
        {
            sumStopWords += numWordsInLine(tweetLine, listOfWords[i]);
        }
        temp = temp -> next;
    }

    printf("Across %d tweets, %d stop words were found.\n", numberOfTweets, sumStopWords);
}