#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "io_adapter.h"

#define MAX_BUILDING_COUNT 7 //the max layers of the hangman statue to be completely constructed
#define MAX_CORRECT_WORD_LENGTH 9 //limits the length of the correctword to this value

extern unsigned int currentBuildLevel;

extern unsigned int correctWordLength;
extern char* correctWord;

extern char correctGuessedLetters[MAX_CORRECT_WORD_LENGTH];
extern unsigned int correctGuessedLettersLength;

//array of the correct word with the correct guessed letters removed
extern char wordWithoutGuessedLetters[MAX_CORRECT_WORD_LENGTH];

/**
 * @brief sets the correctWord in gamestate
 * 
 * @param randomNumber any random unsigned integer from which the word is chosen 
 */
void initializeCorrectWord(unsigned int randomNumber);

/**
 * @brief adds newTestedLetter to correctGuessedLetters array
 * 
 * @param newTestedLetter character to add
 */
void addCorrectGuessedLetter(char newTestedLetter);

/**
 * @brief checks if selectedLetter is a correct letter in the word
 * @param selectedLetter the new letter which was checked by the user
 * @return if letter is NOT correct 0 is returned, any other number means it is correct
 */
short isSelectedLetterCorrect(char selectedLetter);

/**
 * @brief checks if the game is lost. if 0 is returned it needn't be won either
 * 
 * @return if game is not lost yet 0 is returned 
 */
int isGameLost();

/**
 * @brief checks if game is won. if 0 is returned it needn't be lost either
 * 
 * @return if game is not won yet 0 is returned
 */
int isGameWon();

#endif