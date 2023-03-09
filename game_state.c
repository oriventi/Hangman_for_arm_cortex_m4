#include "game_state.h"

// DON'T FORGET TO ADJUST, IHR SCHLAWINER
#define POSSIBLE_WORDS_LENGTH 4

unsigned int currentBuildLevel = 0;

unsigned int correctWordLength = 0;
char *correctWord;
char correctGuessedLetters[MAX_CORRECT_WORD_LENGTH];
unsigned int correctGuessedLettersLength = 0;

char wordWithoutGuessedLetters[MAX_CORRECT_WORD_LENGTH];

//max length 
static const char *possibleWords[POSSIBLE_WORDS_LENGTH] = { "simics", "schlawiner", "airbus", "eiersalat" };

void initializeCorrectWord( unsigned int randomNumber )
{
  // initialize random number
  randomNumber %= POSSIBLE_WORDS_LENGTH;

  // initialize correct word
  char *selectedWord = possibleWords[randomNumber];
  correctWordLength = stringLength( selectedWord );
  if ( correctWordLength == 0 )
    return;
  correctWord = selectedWord;

  // initialize correct guessed letters
  correctGuessedLettersLength = 0;
  for ( unsigned char i = 0; i < MAX_CORRECT_WORD_LENGTH; ++i )
  {
    correctGuessedLetters[i] = '\0';
  }

  // initialize wordWithGuessedLettersRemoved
  for ( unsigned char i = 0; i < correctWordLength; ++i )
  {
    wordWithoutGuessedLetters[i] = correctWord[i];
  }
}

void addCorrectGuessedLetter( char selectedLetter )
{
  for ( unsigned char i = 0; i < correctWordLength; ++i )
  {
    if ( wordWithoutGuessedLetters[i] == selectedLetter )
    {
      correctGuessedLettersLength++;
      wordWithoutGuessedLetters[i] = '\0';
      int isAlreadySet = 0;
      for ( unsigned char j = 0; j < correctGuessedLettersLength; ++j )
      {
        if ( selectedLetter == correctGuessedLetters[j] )
        {
          isAlreadySet = 0xcaffee;
        }
      }
      if ( isAlreadySet == 0 )
      {
        correctGuessedLetters[correctGuessedLettersLength - 1] = selectedLetter;
      }
    }
  }
}

short isSelectedLetterCorrect( char selectedLetter )
{
  for ( int i = 0; i < correctWordLength; ++i )
  {
    if ( selectedLetter == wordWithoutGuessedLetters[i] )
    {
      return 0xaffe;
    }
  }
  return 0;
}

int isGameLost()
{
  if ( currentBuildLevel <= MAX_BUILDING_COUNT )
  {
    return 0;
  }
  return 0xfac;
}

int isGameWon()
{
    int isWon = 1;
    for(unsigned char i = 0; i < correctWordLength; ++i){
        if(wordWithoutGuessedLetters[i] != '\0'){
            isWon = 0;
        }
    }
    return isWon;
}