#include <stdlib.h>
#include <string.h>	
#include <stdio.h>
#include "headerStruct.h"

// menu functions 
tweet * createTweet( tweet * tweetList);

void displayTweets(tweet * tweetList);

int searchTweetsByKeyword(tweet * tweetList);

void countStopWords(tweet * tweetList);

void deleteTweet(tweet ** tweetList);

void saveTweetsToFile(tweet * tweetList);

void loadTweetsFromFile(tweet ** tweetList);

void sortID (tweet ** head);

// linked list function - required after you create a tweet or load tweets from a file
void addNodeToList(tweet ** tweetList, tweet * node);
