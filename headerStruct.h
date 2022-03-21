#ifndef HEADER_STRUCT_A3_H
#define HEADER_STRUCT_A3_H

typedef struct microtweet {
    int id; 				  //unique integer value	
    char user[51]; 			  // the userid / username of the person who wrote the tweet
    char text[141]; 		  // the text of the tweet
   
    struct microtweet *next;  //dynamic connection to the next tweet
} tweet;

#endif