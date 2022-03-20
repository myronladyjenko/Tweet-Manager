CC=gcc
CFLAGS=-Wall -std=c99

ladyjenkoMyronA3: addNodeToList.o sortID.o loadTweetsFromFile.o saveTweetsToFile.o deleteTweet.o countStopWords.o searchTweetsByKeyword.o displayTweets.o createTweet.o searchTweet.o mainA3.o
	$(CC) $(CFLAGS) addNodeToList.o sortID.o loadTweetsFromFile.o saveTweetsToFile.o deleteTweet.o countStopWords.o searchTweetsByKeyword.o displayTweets.o createTweet.o searchTweet.c mainA3.o -o ladyjenkoMyronA3

addNodeToList.o: addNodeToList.c
	$(CC) $(CFLAGS) -c addNodeToList.c

sortID.o: sortID.c
	$(CC) $(CFLAGS) -c sortID.c

loadTweetsFromFile.o: loadTweetsFromFile.c
	$(CC) $(CFLAGS) -c loadTweetsFromFile.c

saveTweetsToFile.o: saveTweetsToFile.c
	$(CC) $(CFLAGS) -c saveTweetsToFile.c

deleteTweet.o: deleteTweet.c
	$(CC) $(CFLAGS) -c deleteTweet.c	

countStopWords.o: countStopWords.c
	$(CC) $(CFLAGS) -c countStopWords.c

searchTweetsByKeyword.o: searchTweetsByKeyword.c
	$(CC) $(CFLAGS) -c searchTweetsByKeyword.c

displayTweets.o: displayTweets.c
	$(CC) $(CFLAGS) -c displayTweets.c

createTweet.o: createTweet.c
	$(CC) $(CFLAGS) -c createTweet.c

searchTweet.o: searchTweet.c
	$(CC) $(CFLAGS) -c searchTweet.c

mainA3.o: mainA3.c
	$(CC) $(CFLAGS) -c mainA3.c
	
clean: 
	rm *.o ladyjenkoMyronA3
