#ifndef HANGMAN_H
#define HANGMAN_H

/**
 * @brief writes the hangman string on the console
 * 
 * @param currentBuildingLevel currentBuildLevel in gamestate
 */
void drawHangman(unsigned int currentBuildingLevel);

/**
 * @brief draws the word row beneath the hangman drawing
 * for each item in testedLetters it replaces the _ at the correct indexes
 * 
 * @param correctGuessedLetters array of testedletters
 * @param correctGuessedLettersLength length of testedLetters
 * @param correctWord the correctword as c_string
 * @param correctWordLength the length of the correctWord
 */
void drawWordRow(char* correctGuessedLetters, unsigned int correctGuessedLettersLength,
    const char* correctWord, unsigned int correctWordLength);

/**
 * @brief draws the hangman and the wordrow beneath
 * 
 * @param currentBuildingLevel currentBuildLevel in gamestate
 * @param correctGuessedLetters array of testedletters
 * @param correctGuessedLettersLength length of testedLetters
 * @param correctWord the correctword as c_string
 * @param correctWordLength the length of the correctWord
 */
void drawScreen(unsigned int currentBuildingLevel, char* correctGuessedLetters, unsigned int correctGuessedLettersLength,
 const char* correctWord, unsigned int correctWordLength);

#endif