#include "main.h"

#include<stdint.h>

static void setRegister( uint32_t address, uint32_t value );

static uint32_t getRegister( uint32_t address );

static unsigned int restartGame(char selectedChar){
  if(selectedChar == 'y' || selectedChar == 'Y'){
    return 0xabc;
  }
  return 0;
}

unsigned int interruptCount = 0;

int myMain( void )
{
  uartInit();
  initSystickHandler();
  unsigned short wrongAnswers = 0;
  unsigned short correctAnswers = 0; 

  printString("Please enter any random character: ");
  char randomInitChar = getChar();
  initializeCorrectWord(randomInitChar);
  printChar(randomInitChar);
  printString("");
  unsigned int currentLoopCount = 0;
  //MAIN LOOP
  while(currentBuildLevel < MAX_BUILDING_COUNT){
      ++currentLoopCount;
      printString("Guess a new letter: ");
      startSystickHandler();
      char selectedLetter = getChar();
      if(isSelectedLetterCorrect(selectedLetter) == 0 || isCharacterValid(selectedLetter) == 0 ){
          //LETTER IS NOT CORRECT
          wrongAnswers++;
          clearConsole();
          printStringWithoutNewLine("Selected Letter: ");
          printChar(selectedLetter);
          printString("");
          printString("\033[31mWRONG ANSWER!\r\n");
          resetColor();
          ++currentBuildLevel;
          if(isGameLost() != 0){
              //Game is lost
              drawScreen(currentBuildLevel, correctGuessedLetters, correctGuessedLettersLength, correctWord, correctWordLength);
              printString("\033[35mGAME IS LOST\r\n");
              resetColor();
              break;
          }
          drawScreen(currentBuildLevel, correctGuessedLetters, correctGuessedLettersLength, correctWord, correctWordLength);
      }else{
          //LETTER IS CORRECT:
          correctAnswers++;
          clearConsole();
          addCorrectGuessedLetter(selectedLetter);
          printStringWithoutNewLine("Selected Letter: ");
          printChar(selectedLetter);
          printString("");
          printString("\033[32mCORRECT ANSWER!\r\n");
          resetColor();
          if(isGameWon() != 0){
              //Game is won
              drawScreen(currentBuildLevel, correctGuessedLetters, correctGuessedLettersLength, correctWord, correctWordLength);
              printString("\033[35mGAME IS WON\r\n\0");
              resetColor();
              break;
          }
          drawScreen(currentBuildLevel, correctGuessedLetters, correctGuessedLettersLength, correctWord, correctWordLength);
      }
  }
    //GAME Is Over show statistics
    printString("\033[35mGAME IS OVER!\0");
    resetColor();
    printString("-----------------------");
    printStringWithoutNewLine("The correct word was: ");
    printString(correctWord);
    printString("-----------------------");    
    printString("Stats: ");
    printStringWithoutNewLine("Correct answers: ");
    printChar(correctAnswers + '0');
    printString("");
    printStringWithoutNewLine("Wrong answers: ");
    printChar(wrongAnswers + '0');
    printString("");
    printString("Do you want to restart (y/n): ");
    if(restartGame(getChar()) != 0){
      return 0;
    }
    printString("Exit!");
    return 1;
}