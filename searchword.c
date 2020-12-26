
/* CS2211a 2020 */
/* Assignment 04 */
/* Jessica Yang */
/* 251083596 */
/* jyang762 */
/* November 21, 2020 */ 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "definitions.h"
#include "header.h"

/* This function will prompt user for a word to search and print out which line and position the word exists*/
void searchword(struct list *linkedList){
    
    // will continue to prompt the user for an input
    char inputString[1000];
    do{
        printf("\nEnter a word to search: ");
        fgets(inputString, sizeof inputString, stdin);
        if (strlen(inputString) == 1) return; // stops when user inputs an empty string
        if(inputString[strlen(inputString)-1] == '\n') inputString[strlen(inputString)-1] = '\0'; // chops off the new line
        
        // will search through every word in sentence 
        struct sentence *currentSentence = linkedList->firstSentence;
        // will loop through each sentence and print the sentence line by line
        while(currentSentence){ // while the sentence points to a word structure exists
            struct word *currentWord = currentSentence->wordPtr;
            while(currentWord){ // while the word exists
                if(strcmp(currentWord->charPtr, inputString)==0) { // checks if the current word equals the input string
                    printf("%s found in line %d position %d \n", inputString, currentSentence->line, currentWord->posWord); // if it does then print out its info
                    break;
                }
                currentWord = currentWord->nextWord;
            }
            currentSentence = currentSentence->nextSentence;
        
        }
        
    } while(strlen(inputString) != 1); // will keep looping until the user inputs an empty string 
   
    
}