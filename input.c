
/* CS2211a 2020 */
/* Assignment 04 */
/* Jessica Yang */
/* 251083596 */
/* jyang762 */
/* November 21, 2020 */ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definitions.h"
#include "header.h"

int numline =0; // keeps track of the sentence number
int numChars =0; // keeps track of the char number
char inputString[100]; // stores the users input
struct list *linkedList; // linked list will store a pointer to the first sentence

/* Continues to prompt user input and stores it in the sentence structure */
struct list* userInput()
{
    do{ 
        // prompts for user input and stores it in input string
        printf("Enter a string: ");
        fgets(inputString, sizeof inputString, stdin);
        // terminates if user inputs an empty string.
        if (strlen(inputString) == 1) break;
        
        // if it is the first sentence
        if (numline == 0) {
            linkedList = (struct list*) malloc (sizeof(struct list)); // allocates memory for linked list
            struct sentence *sentencePtr = newSentence(inputString, numline); // creates a new sentence
            linkedList->firstSentence = sentencePtr; // points linked list to first sentence
        }
        else { // if it is not the first sentence
            newSentence(inputString, numline); // creates new sentence
        }
        numline++; // moves onto the next line
        

    }while (strlen(inputString)!=0); // continues to loop until user inputs a null sentence
    
    linkedList->numSentences = numline; // will set the number of sentences in linked list
    return linkedList;
}

/* Frees the memory allocated for sentence Ptr*/
void freeStrutures(){
    free(linkedList);
}

/* Creates a new word*/
struct word* newWord(struct word *firstWord, char *charPtr, int numChars, int posWord){
    struct word *currentWord = firstWord; // will set the current word as the first word in the sentence
    while(currentWord->nextWord){ // moves through the sentence until the last word
        currentWord = currentWord->nextWord;
    }
    struct word *newWord = (struct word*) malloc (sizeof(struct word)); // allocates memory for a new word structure 
    char *newChar = (char*)malloc(numChars*sizeof(char)); // allocates memory for the char pointer 
    strcpy(newChar, charPtr); // puts the word into the char pointer
    // sets the information for the new word
    newWord->charPtr = newChar;
    newWord->numChars = numChars;
    newWord->posWord = posWord+1;
    // points the last word to the new word
    currentWord->nextWord = newWord;
    
    return newWord;
}

struct sentence* newSentence(char *inputString, int line){ // struct word *wordPtr, int line, int numWords
    struct sentence *currentSentence = linkedList->firstSentence; // sets current sentence as the first sentence 
    while(currentSentence && currentSentence->nextSentence){ // moves through all the sentences until the last sentence is reached
        currentSentence = currentSentence->nextSentence;
    }
    struct sentence *newSentence = (struct sentence*) malloc (sizeof(struct sentence)); // allocates memory for a new sentence
    struct word *firstWord = (struct word*) malloc (sizeof(struct word)); // allocates memory for the first word
    
    // chops off the first word from the sentence 
    char * currentWord = strtok(inputString, " "); 
    int posWord = 0;
    while( currentWord != NULL ) { // loops through every word
        numChars = strlen(currentWord); // collects the number of chars
        if(currentWord[numChars-1] == '\n'){ // chops off new line char if it is at the end of the sentence
            currentWord[numChars-1] = '\0';
            numChars--;
        }
        if(posWord == 0) { // if we are on the first word then create the first word of the sentence
            char *newChar = (char*)malloc(numChars*sizeof(char)); // allocate memory for the char pointer 
            strcpy(newChar, currentWord); // puts the current word in the char pointer
            // sets the information for the first word
            firstWord->charPtr = newChar; 
            firstWord->numChars = numChars;
            firstWord->posWord = posWord+1;
            // the sentence points to the first word
            newSentence->wordPtr = firstWord;
        }
        else { // if it is not the first word then just create a new word to add onto the word pointer in the linked list
            newWord(firstWord, currentWord, numChars, posWord); 
        }
        posWord ++; 
        currentWord = strtok(NULL, " "); // collects the next word
        if (currentWord==NULL) break; // if there is no next word, then break the loop
    }
    
    // set the rest of the information for the sentence
    newSentence->line = line+1;
    newSentence->numWords = posWord;
    
    if(line!=0) { // if this is not the first sentence, then set the old sentence to point to the new sentence
        currentSentence->nextSentence = newSentence;
    }
    return newSentence;
}



