
/* CS2211a 2020 */
/* Assignment 04 */
/* Jessica Yang */
/* 251083596 */
/* jyang762 */
/* November 21, 2020 */ 

#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"
#include "header.h"


int main()
{
    struct list *linkedList = userInput(); // stores the users input in a sentence structurE
    outputSentences(linkedList); // outputs the sentences 
    searchword(linkedList); // searches for a word in the sentences
    delete(linkedList); // deletes sentence in the linked list
    freeStrutures(); // frees the memory allocated for the sentences
    
}



