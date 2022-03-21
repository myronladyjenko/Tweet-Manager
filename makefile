CC=gcc
CFLAGS=-Wall -std=c99

ladyjenkoMyronA3: addNodeToList.o sortID.o loadTweetsFromFile.o saveTweetsToFile.o deleteTweet.o countStopWords.o searchTweetsByKeyword.o displayTweets.o createTweet.o searchTweet.o numWordsInLine.o mainA3.o
	$(CC) $(CFLAGS) addNodeToList.o sortID.o loadTweetsFromFile.o saveTweetsToFile.o deleteTweet.o countStopWords.o searchTweetsByKeyword.o displayTweets.o createTweet.o searchTweet.o numWordsInLine.o mainA3.o -o ladyjenkoMyronA3

addNodeToList.o: addNodeToList.c headerA3.h headerHelperA3.h
	$(CC) $(CFLAGS) -c addNodeToList.c

sortID.o: sortID.c headerA3.h
	$(CC) $(CFLAGS) -c sortID.c

loadTweetsFromFile.o: loadTweetsFromFile.c headerA3.h
	$(CC) $(CFLAGS) -c loadTweetsFromFile.c

saveTweetsToFile.o: saveTweetsToFile.c headerA3.h
	$(CC) $(CFLAGS) -c saveTweetsToFile.c

deleteTweet.o: deleteTweet.c headerA3.h
	$(CC) $(CFLAGS) -c deleteTweet.c	

countStopWords.o: countStopWords.c headerA3.h headerHelperA3.h
	$(CC) $(CFLAGS) -c countStopWords.c

searchTweetsByKeyword.o: searchTweetsByKeyword.c headerA3.h headerHelperA3.h
	$(CC) $(CFLAGS) -c searchTweetsByKeyword.c

displayTweets.o: displayTweets.c headerA3.h
	$(CC) $(CFLAGS) -c displayTweets.c

createTweet.o: createTweet.c headerA3.h headerHelperA3.h
	$(CC) $(CFLAGS) -c createTweet.c

searchTweet.o: searchTweet.c headerA3.h headerHelperA3.h
	$(CC) $(CFLAGS) -c searchTweet.c 

numWordsInLine.o: numWordsInLine.c headerA3.h headerHelperA3.h
	$(CC) $(CFLAGS) -c numWordsInLine.c	

mainA3.o: mainA3.c headerA3.h
	$(CC) $(CFLAGS) -c mainA3.c
	
clean: 
	rm *.o ladyjenkoMyronA3
