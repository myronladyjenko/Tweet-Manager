## Tweet Manager

Tweet Manager is a simple application that allow the user to do the simple Twitter functionality. This application was completed in **C**. 

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
    git clone https://github.com/myronladyjenko/Tweet-Manager.git

##### cd to the Tweet-Manager directory the program; compile the program using makefile:    
    make    

##### run the executable (ladyjenkoMyronA3):   
    ./ladyjenkoMyronA3

##### clean all object files (.o) and the executable:
    make clean    

## Completed Components

Tweet Manager has a full range of functionality. The user is able to any of the proposed functionality. Users are able to create tweets, display tweets, search tweets based on a keyword or mention, save and load tweets from a local file, and calculate the number of stop words are
present across all of the tweets.

##### Main Functionality

<details><summary>Create new tweet</summary>
This function prompts the user for the username and the tweet. Then it automatically creates a unique id for every tweet.  
</details>

<details><summary>Display tweets</summary>
This function displays all the stored tweets. 
</details>

<details><summary>Search a tweet (by keyword)</summary>
This function takes prompts the user to enter a keyword and then searches for this keyword in all of the tweets. 
</details>

<details><summary>Find how many words are “stop words” (stop words are explained in a later section)</summary>
This function takes counts how many stop words all across all the stored tweets.  
</details>

<details><summary>Delete the nth tweet</summary>
This function deletes nth tweet from all the stored tweets and prints the id of it. 
</details>

<details><summary>Save tweets to a file</summary>
This function saves all the stored tweets to the .csv file.
</details>

<details><summary>Load tweets from a file</summary>
This function load tweets from the .csv file into the memory (linked list form).
</details>

<details><summary>Sort the given linked list on userid.</summary>
This function sorts all the tweets by the user id. 
</details>

In addition, since this is a menu-driven program, there are several input streams for the tweets. The first input
stream is from the command line itself (Menu Option 1). Alternatively, the user can use the seventh option to load a
CSV file of tweets into the program. A sample CSV file has been provided for you to test your programs with. Both
of these inputs will feed into the same linked list structure, as defined above.

#### **IMPORTANT NOTE**
If the user decides to exit the program with saving the tweets (option 6), then all the information will be lost.

## Limitations of the program

The program covers the full scope of the assignment listed in the instructions and has no limitations. 

## Improvements

#### Completed Improvements:
1. Added an error checking for a wrong input for "Delete the nth tweet" function. Plus, was given an option to exit the function if the user doesn't want to delete any nodes. 

#### Future Improvements:
1. Check for the uniqueness of the id when loading from a .csv file.
2. Error checking for the wrong file format when loading tweets from a .csv file. 
