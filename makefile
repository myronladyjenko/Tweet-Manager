CC=gcc
CFLAGS=-Wall -std=c99

ladyjenkoMyronA3: sortID.o loadTweetsFromFile.o saveTweetsToFile.o deleteTweet.o countStopWords.o searchTweetsByKeyword.o displayTweets.o createTweet.o helper.o mainA3.o
	$(CC) $(CFLAGS) sortID.o loadTweetsFromFile.o saveTweetsToFile.o deleteTweet.o countStopWords.o searchTweetsByKeyword.o displayTweets.o createTweet.o helper.c mainA3.o -o ladyjenkoMyronA3

sortID.o: sortID.c headerA3.h headerHelperA3.h
	$(CC) $(CFLAGS) -c sortID.c

loadTweetsFromFile.o: loadTweetsFromFile.c headerA3.h headerHelperA3.h
	$(CC) $(CFLAGS) -c loadTweetsFromFile.c

saveTweetsToFile.o: saveTweetsToFile.c headerA3.h headerHelperA3.h
	$(CC) $(CFLAGS) -c saveTweetsToFile.c

deleteTweet.o: deleteTweet.c headerA3.h headerHelperA3.h
	$(CC) $(CFLAGS) -c deleteTweet.c	

countStopWords.o: countStopWords.c headerA3.h headerHelperA3.h
	$(CC) $(CFLAGS) -c countStopWords.c

searchTweetsByKeyword.o: searchTweetsByKeyword.c headerA3.h headerHelperA3.h
	$(CC) $(CFLAGS) -c searchTweetsByKeyword.c

displayTweets.o: displayTweets.c headerA3.h headerHelperA3.h
	$(CC) $(CFLAGS) -c displayTweets.c

createTweet.o: createTweet.c headerA3.h headerHelperA3.h
	$(CC) $(CFLAGS) -c createTweet.c

helper.o: helper.c headerA3.h headerHelperA3.h
	$(CC) $(CFLAGS) -c helper.c	

mainA3.o: mainA3.c headerA3.h headerHelperA3.h
	$(CC) $(CFLAGS) -c mainA3.c
	
clean: 
	rm *.o ladyjenkoMyronA3
