/*
 * @file Logger.h
 * author: kushagra Pandey & Vaidehi Salway
 * Date:10/18/2019
 *
 * This .h file contains the header files requred for Logger.c file
 * There are two modes of operating this file
 * 1. Logger Enable
 * 2. Logger Disable
 *
 * Enable or Disable the logger by un-commenting #define logging_init or #define logging_notinit respectively from Logger.h
 *
 *Defining the funcyions used in Logger.c file
 */


#include "main.h"
#include "string.h"

// Un-comment logging_init and comment logging_notinit to enable logging
#define logging_init

// Comment logging_init and un-comment logging_notinit to enable logging
//#define logging_notinit

void Log_Enabled();
void Log_Disabled();
uint8_t Status();
void Log_Data(uint32_t data);
void Log_String(char *statement);
void Log_Integer(int integer_value);

