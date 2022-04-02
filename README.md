## Tweet Manager

Tweet Manager is a simple application that allow the user to do the simple Twitter functionality. Tweet Manager for the 
**Assignment 3**, course **CIS*2500** was completed in **C** by **Myron Ladyjenko** (username: **mladyjen**, id: **1172255**). 

The application has the following functionality: 

    1. Create a new tweet
    2. Display tweets
    3. Search a tweet (by keyword)
    4. Find how many words are “stop words” (stop words are explained in a later section)
    5. Delete the nth tweet
    6. Save tweets to a file
    7. Load tweets from a file
    8. Sort the given linked list on userid.
    9. Exit

Date of Last Revision: **2022/04/03**.    

## Setup + Compile & Run

##### Clone the repo:
    git clone https://git.socs.uoguelph.ca/2500W22/mladyjen/A3.git

##### cd to the A3 directory the program:
    cd A3

##### compile the program using makefile:    
    make

##### run the executable:    
    ./ladyjenkoMyronA3

## Completed Components

Tweet Manager has a full range of functionality. The user is able to any of the proposed functionality. Users are able to create tweets, display tweets, search tweets based on a keyword or mention, save and load tweets from a local file, and calculate the number of stop words are
present across all of the tweets.

In addition, since this is a menu-driven program, there are several input streams for the tweets. The first input
stream is from the command line itself (Menu Option 1). Alternatively, the user can use the seventh option to load a
CSV file of tweets into the program. A sample CSV file has been provided for you to test your programs with. Both
of these inputs will feed into the same linked list structure, as defined above.

## Limitations of the program

N/A

## Improvements

N/A
