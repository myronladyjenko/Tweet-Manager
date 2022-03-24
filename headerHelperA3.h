#define  _POSIX_C_SOURCE 200809L

#include <ctype.h>
#include <time.h>
#include "headerA3.h"

tweet * searchTweet(tweet * tweetList, int sum);

int numWordsInLine(char arr[], char word[]);

tweet * combineLists(tweet * headFirst, tweet * headSecond);
void splitList(tweet * head, tweet ** firstList, tweet ** secondList);
