
/* CS2211a 2020 */
/* Assignment 04 */
/* Jessica Yang */
/* 251083596 */
/* jyang762 */
/* November 21, 2020 */ 

#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

struct list* userInput();
void outputSentences(struct list*);
void searchword(struct list*);
void freeStrutures();
struct sentence* newSentence(char*, int);
struct word* newWord(struct word*, char*, int, int);
void delete(struct list*);

#endif