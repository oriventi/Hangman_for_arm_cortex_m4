#include "hal.h"

static unsigned int interruptCount = 0;

// Specific implementation for ARM-Cortex M4 here:

void uartInit( void )
{
  // Enable FIFO:
  // LCRH <-- LCRH_FEN
  WriteToRegister( 0x4000C000 + 0x2C, 0x10 );

  // [9]    RXE   Receive enable
  // [8]    TXE   Transmit enable
  // [0] UARTEN   UART enable: 1-enable, 0-disable
  WriteToRegister( 0x4000C000 + 0x30, 0x00000031 );// Control
}

void printCharL(char c){
  WriteToRegister(0x4000C000 + 0x00, c);
}

void printStringL( const char *text )
{

  // Loop out the Data until zero reached!
  for ( int n = 0; text[n] != 0; n++ )
  {
    WriteToRegister( 0x4000C000 + 0x00, text[n] );// Data
  }

  // Append \r\n, which results in a new line
  WriteToRegister( 0x4000C000 + 0x00, '\r' );// Data
  WriteToRegister( 0x4000C000 + 0x00, '\n' );// Data
}

void printStringWithoutNewLineL(const char* text){
  // Loop out the Data until zero reached!
  for ( int n = 0; text[n] != 0; n++ )
  {
    WriteToRegister( 0x4000C000 + 0x00, text[n] );// Data
  }
}

void printStringWithLen( const char *text, int len )
{
  // Loop out the Data
  for ( int n = 0; n < len; n++ )
  {
    WriteToRegister( 0x4000C000 + 0x00, text[n] );// Data
  }

  // Append \r\n, which results in a new line
  WriteToRegister( 0x4000C000 + 0x00, '\r' );// Data
  WriteToRegister( 0x4000C000 + 0x00, '\n' );// Data
}

// =================================================================================

char read_input( )
{
  uint32_t DataRegister;
  interruptCount = 0;
  // FE = "FIFO EMPTY"
  // Active wait for not Empty fifo
  while ( ReadFromRegister( 0x4000C000 + 0x18 ) & 0x10 ){
    if(interruptCount >= INTERRUPTS_UNTIL_INVALID){
      interruptCount = 0;
      return 0;
    }
  }
  // Read from UART_O_DR
  DataRegister = ReadFromRegister( 0x4000C000 + 0x00 );

  DataRegister = DataRegister & 0x000000FF;// sanitize

  return (char)DataRegister;
}

// =================================================================================

void WriteToRegister( uint32_t address, uint32_t value )
{
  uint32_t *pointer_to_address;

  // Assign pointer to given address:
  pointer_to_address = (uint32_t *)address;

  // Write to the End of the Pointer
  *pointer_to_address = value;
}

uint32_t ReadFromRegister( uint32_t address )
{
  uint32_t * pointer_to_address;
  uint32_t value;

  // Assign pointer to given address:
  pointer_to_address = (uint32_t *)address;

  // Read from the End of the Pointer
  value = *pointer_to_address;

  // Return the read value
  return value;
}


void initSystickHandler(){
    WriteToRegister(0xE000E014, CLOCKS_TO_TICK);
    WriteToRegister(0xE000E018, 0);
    WriteToRegister(0xE000E010, 0x6);
}

void startSystickHandler(){
    WriteToRegister(0xE000E018, 0);
    WriteToRegister(0xE000E010, 0x7);
}

void SysTick_Handler(){
  ++interruptCount;
}
