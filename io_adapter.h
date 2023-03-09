#ifndef IO_ADAPTER_H
#define IO_ADAPTER_H

//clear console screen in c using cls method
#include"hal.h"

    /**
     * @brief prints a char to the console, no newLine.
     * 
     * @param c char to print
     */
    void printChar(char c);

    /**
     * @brief returns the length of str
     * 
     * @param str \0 terminated string
     * @return unsigned int length of str
     */
    unsigned int stringLength(const char* str);

    /**
     * @brief prints a new string to the console, new line added
     * 
     * @param str string to print
     */
    void printString(const char* str);

    /**
     * @brief waits for user char input. After ~13 seconds of no input returns 0.
     * 
     * @return char 
     */
    char getChar();

    /**
     * @brief clears the console
     * 
     */
    void clearConsole();

    /**
     * @brief checks whether char is a lowercaseletter (ascii 7-bit).
     * 
     * 
     * @return unsigned char returns 0 if false else any other number
     */
    unsigned char isCharacterValid(char);

    /**
     * @brief prints a new string to the console, NO new line added
     * 
     * @param str string to print
     */
    void printStringWithoutNewLine(const char* str);

    /**
     * @brief sets the console foreground-color to standard
     */
    void resetColor();


#endif