
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
char inputString[100];

/* This function will prompt user for a word to search and print out which line and position the word exists*/
void delete(struct list *linkedList){
    int line; // stores the number of the line that the user wants to delete
    do{ 
        // will continue to prompt the user for an input
        printf("\nEnter a line to delete: ");
        fgets(inputString, sizeof inputString, stdin);
        if (strlen(inputString) == 1) return;
        line = atoi(inputString); // turns the line into an int
        if (line<= 0 || line>linkedList->numSentences) printf("Invalide input. Please try again."); // stops when user inputs an empty string
        else if (line== 1){ // if its the first line
            struct sentence *sentenceDeleted = linkedList->firstSentence; // set the first line as the sentence to delete
            linkedList->firstSentence = linkedList->firstSentence->nextSentence; // the linked list now points to the second line 
            struct sentence *currentSentence = linkedList->firstSentence; // set the current sentence as the new first sentence
            while(currentSentence) { // go through every sentence in the list to set its line number as one lower
                currentSentence->line --; 
                currentSentence = currentSentence->nextSentence;
            } 
            free(sentenceDeleted); // free first sentence
            linkedList->numSentences --; // set the number of sentences in the linked list to one less
            printf("Deleted line %d:", line);
            outputSentences(linkedList); // prints the new list
            
        }
        else{ // if the line to be deleted is not the first line
            struct sentence *currentSentence = linkedList->firstSentence; // set current sentence as the first line
            // loop through every sentence until it reaches the line inputed by the user
            while(currentSentence->nextSentence && currentSentence->nextSentence->line != line) currentSentence = currentSentence->nextSentence;
            
            // set the sentence before and after the deleted sentence as well as the deleted sentence
            struct sentence *sentenceBefore = currentSentence;
            struct sentence *sentenceDeleted = currentSentence->nextSentence;
            struct sentence *sentenceAfter = currentSentence->nextSentence->nextSentence;
            
            while(currentSentence->nextSentence) { // will loop through the rest of the sentences to move its line number down by one
                currentSentence->nextSentence->line --; 
                currentSentence = currentSentence->nextSentence;
            }
            sentenceBefore->nextSentence = sentenceAfter; // set the sentence before to point to the sentence after the deleted sentence
            linkedList->numSentences --; // set the number of sentences in the linked list to one less
            free(sentenceDeleted); // delete the sentence
            printf("Deleted line %d:", line);
            outputSentences(linkedList); // print the new list
        }
        
    } while (strlen(inputString) != 1); // will loop until an empty string is inputed 
    
}