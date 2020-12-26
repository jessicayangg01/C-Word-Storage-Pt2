
/* CS2211a 2020 */
/* Assignment 04 */
/* Jessica Yang */
/* 251083596 */
/* jyang762 */
/* November 21, 2020 */ 

#ifndef DEFINITIONS_H_
#define DEFINITIONS_H_
    
    /* Structure word*/
   struct word {
        char *charPtr;
        struct word *nextWord;
        int numChars;
        int posWord;
    };
    typedef struct word word;
    
    /* Structure sentence*/
    struct sentence {
        struct word *wordPtr;
        struct sentence *nextSentence;
        int line;
        int numWords;
    };
    typedef struct sentence sentence;
    
    /*Structure Linked List*/
    struct list {
        struct sentence *firstSentence;
        int numSentences;
    };
    typedef struct list list;

#endif //DEFINITIONSH