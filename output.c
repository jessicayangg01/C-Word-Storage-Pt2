
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
/* This function will output sentences word by word and line by line */
void outputSentences(struct list *linkedList){
    
    // formating 
    printf("\n\n");
    printf("This is all the words printed out on the same line as entered:");
    struct sentence *currentSentence = linkedList->firstSentence;
    // will loop through each sentence and print the sentence line by line
    while(currentSentence){ // while the sentence points to a word structure exists
        struct word *currentWord = currentSentence->wordPtr;
        printf("\n");
        while(currentWord){ // while the word points to a char exists
            printf("%s ", currentWord->charPtr); // print the next word
            currentWord = currentWord->nextWord;
        }
        currentSentence = currentSentence->nextSentence;
        
    }
    printf("\n\n");
}
