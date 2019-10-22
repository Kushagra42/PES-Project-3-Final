/*
 * @file Logger.c
 * author: kushagra Pandey & Vaidehi Salway
 * Date:10/18/2019
 *
 * This .c file contains the logger statements for cross-platform
 * There are two modes of operating this file
 * 1. Logger Enable
 * 2. Logger Disable
 *
 * Enable or Disable the logger by un-commenting #define logging_init or #define logging_notinit respectively from Logger.h
 *
 */


#include "Logger.h"


uint8_t log_status;

// Function log enable, when called in main returns log_status 1
void Log_Enabled()
	{
		log_status=1;
	}

// Function log disable, when called in main returns log status 0
void Log_Disabled()
	{
		PRINTF("\nLOGGERS ARE DISABLED");
		log_status=0;
	}

// checking condition to enable logging
// Status function called when logging_init is defined in logger.h
#ifdef logging_init

// Function Status calls log_Enabled
uint8_t Status()
	{
		Log_Enabled();
		return log_status;
	}
#endif


// checking condition to disable logging
// Status function called when logging_notinit is defined in logger.h
#ifdef logging_notinit

//Function Status calls log_Disabled
uint8_t Status()
	{
		Log_Disabled();
		return log_status;
	}
#endif

// Log Data function enables printing data on the terminal when running in freedom board
void Log_Data(uint32_t data)
	{
		Status();
		if(log_status==1)
			{
				PRINTF("\n\rLOG_DATA:%x",data);
			}

	}


// Log Data function enables printing Strings on the terminal when running in freedom board
void Log_String(char *statement)
	{
		Status();

		if(log_status==1)
			{
				PRINTF("\n\rLOG_STRING:%s",statement);
			}

	}


//
//void Log_User_Input(int user_input)
//{
//Status();
//
//if(log_status==1)
//{
//SCANF("\n\rLOG_STRING:%d",&user_input);
//}
//
//}


// Log Data function enables printing integer values on the terminal when running in freedom board
void Log_Integer(int integer_value)
	{
		Status();
		if(log_status==1)
			{
				PRINTF("\n\rLOG_INTEGER:%d",integer_value);
			}

	}
