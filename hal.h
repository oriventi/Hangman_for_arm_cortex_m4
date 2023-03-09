#ifndef HAL_H
#define HAL_H

#define CLOCKS_TO_TICK 799999 //count of cpu cycles until SysTick_Handler() triggers
#define INTERRUPTS_UNTIL_INVALID 800 //count of interrupts until user input is invalid (~13s)

#include<stdint.h>

// for Init the UART:
void uartInit(void);

// Output Routines:
void printCharL(char c);
void printStringL(const char *text);
void printStringWithLen(const char *text, int len);

// Input Routines:
char read_input(void);

// Generic Register-Access:
void WriteToRegister( uint32_t address, uint32_t value);

uint32_t ReadFromRegister(uint32_t address);

/**
 * @brief initializes the systickhandler with CLOCKS_TO_TICK
 * doesn't start the actual handler
 */
void initSystickHandler();

/**
 * @brief resets the systickhandler and enables it
 */
void startSystickHandler();

#endif