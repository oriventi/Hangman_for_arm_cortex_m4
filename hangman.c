#include "hangman.h"
#include "game_state.h"
#include "io_adapter.h"

void drawScreen(unsigned int currentBuildingLevel, char* correctGuessedLetters, unsigned int correctGuessedLettersLength,
 const char* correctWord, unsigned int correctWordLength){
    drawHangman(currentBuildingLevel);
    drawWordRow(correctGuessedLetters, correctGuessedLettersLength, correctWord, correctWordLength);
}

const char* getFirstLine(int currentBuildLevel){
    if(currentBuildLevel > 0){
        return "/------\\\r\n\0";
    }
    return "\r\n\0";
}

const char* getSecondLine(int currentBuildLevel){
    if(currentBuildLevel > 1){
        return "  I\r\n\0";
    }
    return "\0";
}

const char* getThirdLine(int currentBuildLevel){
    if(currentBuildLevel > 6){
        return "  I   / \\\r\n\0";
    }
    if(currentBuildLevel > 1){
        return "  I\r\n\0";
    }
    return "\0";
}

const char* getFourthLine(int currentBuildLevel){
    if(currentBuildLevel > 4){
        return "  I    | \0";
    }

    if(currentBuildLevel > 1){
        return "  I\r\n\0";
    }

    return "\0";
}

const char* getFifthLine(int currentBuildLevel){
    if(currentBuildLevel > 5){
        return "  I   \\|/ \r\n\0";
    }
    if(currentBuildLevel > 4){
        return "  I    | \r\n\0";
    }
    if(currentBuildLevel > 1){
        return "  I\r\n\0";
    }
    return "\0";
}

const char* getSixthLine(int currentBuildLevel){
    if(currentBuildLevel > 3){
        return "  I/   O\r\n\0";
    }
    if(currentBuildLevel > 2){
        return "  I/\r\n\0"; 
    }
    if(currentBuildLevel > 1){
        return "  I\r\n\0";
    }
    return "\0";
}

const char* getSeventhLine(int currentBuildLevel){
    if(currentBuildLevel > 2){
        return "  ------\r\n\0";
    }
    return "\r\n\0";
}

void drawHangman(unsigned int currentBuildLevel){
    printString(getSeventhLine(currentBuildLevel));
    printString(getSixthLine(currentBuildLevel));
    printString(getFifthLine(currentBuildLevel));
    printString(getFourthLine(currentBuildLevel));
    printString(getThirdLine(currentBuildLevel));
    printString(getSecondLine(currentBuildLevel));
    printString(getFirstLine(currentBuildLevel));
}

void drawWordRow(char* correctGuessedLetters, unsigned int correctGuessedLettersLength,
    const char* correctWord, unsigned int correctWordLength){
        //currentwordlength - 1 is used, so \0 isn't used
    for(unsigned int i = 0; i < correctWordLength - 1; ++i){
        char currentChar = correctWord[i];
        char foundChar = '_';
        for(unsigned int j = 0; j < correctGuessedLettersLength; ++j){
            if(correctGuessedLetters[j] == currentChar){
                foundChar = currentChar;
                break;
            }
        }
        //coloring
        if(foundChar == '_'){
            printStringWithoutNewLine("\033[31m");
        }else{
            printStringWithoutNewLine("\033[34m");
        }
        printChar(foundChar);
        printChar(' ');
    }
    resetColor();
    printString("");
    printString("");
}

/**
 * It should look like this :-s
 *    ------
 *    I/   O
 *    I   \|/ 
 *    I    | 
 *    I   / \
 *    I
 *  /------\
 * 
 */