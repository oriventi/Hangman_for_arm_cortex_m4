#include"io_adapter.h"
#include"string.h"

void printChar(char c){
    printCharL(c);
}

void printString(const char* str){
    printStringL(str);
}

unsigned int stringLength(const char* str){
    unsigned int strlength = 0;
    for(unsigned char i = 0; i < 255; ++i){
        if(str[i] == '\0'){
            strlength++;
            break;
        }
        strlength++;
    }
    if(strlength >= 255){strlength = 0;}
    return strlength;
}

void printStringWithoutNewLine(const char* text){
    printStringWithoutNewLineL(text);
}

char getChar(){
    return read_input();
}

void clearConsole(){
    printString("\033[2J\033[;H");
}

void resetColor(){
    printStringWithoutNewLine("\033[0m");
}

/**
 * @brief returns 0 is character c is not a valid input character
 * 
 * @param c given input character
 * @return unsigned char: 0 if INVALID and any other value if valid
 */
unsigned char isCharacterValid(char c){
    if(c >= 97 && c <= 122){
        return 0xa;
    }
    return 0;
}


