/*
 * @file main.c
 * author: kushagra Pandey & Vaidehi Salway
 * Date:10/17/2019
 *
 * There are two modes of operations to choose from in the main routine
 * 1. FB_RUN: When this target is built the routine for the freedom board KL25Z gets built.
 * 			  This version prints the outputs on MCUxpresso terminal using UART
 * 			  LED indications are given on the freedom board as per the test results
 * 2. PC_RUN: When this target is built the routine for the development environment i.e. windows/linux gets built
 * 			  This version prints the output on MCUxpresso console
 * 			  Test indications are given by printing X LED ON the console
 *
 *This file calls all the routines of the program in the main function
 *
 */






#include "main.h"

// This version of the code is for operating in KL25Z freedom board
#ifdef FB_RUN


#include "Logger.h"
#include "Memory_Functions.h"
#include "LED_Blink.h"
#include "Delay_Function.h"

extern int NUMB_OF_INVERTING_BYTES;//Number of Bytes to be Inverted
extern size_t Inverting_length;//length for which we invert the bytes

extern int NUMB_OF_BYTES;
extern size_t length;//size of the memory in bytes.

//#define NULL ((void*)0)
extern uint8_t array5[16];
extern uint8_t array4[16];
extern uint8_t array3[16];
extern uint8_t array2[16];
extern uint32_t *ptr;//pointer for memory allocation function.

uint32_t milli_sec_val=0;

// main function calling all the function routines
int main(void)
{

BOARD_InitBootPins();
BOARD_InitBootClocks();
BOARD_InitBootPeripherals();
BOARD_InitDebugConsole();
BOARD_InitPins();
BOARD_BootClockRUN();

Log_Enabled();
GREEN_LED_INIT();
RED_LED_INIT();
BLUE_LED_INIT();


BLUE_LED_ON();


//calling the memory allocation function.
allocate_words();

//USER INPUT FOR OFFSET VALUE
//PRINTF("\nENTER THE OFFSET VALUE:");
Log_String("\n\rENTER THE OFFSET VALUE");

int offset;

// Store user input to offset variable
SCANF("\n\r%d",&offset);

//taking the address of allocated memory
get_address(ptr,offset);

//USER INPUT FOR SEED VALUE
Log_String("\n\rENTER THE SEED VALUE:");

uint32_t seed;

// Store user input to seed variable
SCANF("\n\r%d",&seed);


//writing the randomly generated pattern to the allocated memory.
write_pattern(ptr, length,seed);
//comparing the newly generated array with the patter from pattern generation function
verify_pattern(ptr, length, seed);
display_memory();

Log_String("\n\n\rpattern after writing the value");
//writing the value to given address.
Write_Value_To_Memory(ptr,offset, 0xFFEE);
//comparing the newly generated array with the patter from write function
verify_pattern(ptr, length, seed);

Log_String("\n\n\rpattern generated with the same seed value");
//writing the randomly generated pattern to the allocated memory.
write_pattern(ptr, length,seed);
//comparing the newly generated array with the patter from write function
display_memory();
verify_pattern(ptr, length, seed);

Log_String("\n\n\rENTER THE OFFSET VALUE FOR INVERTING BYTES FUNCTION:");
int offset2;
SCANF("\n\r%d",&offset2);
invert_block(ptr,offset2, Inverting_length);
//comparing the newly generated array with the patter from inverse function
verify_pattern(ptr, length, seed);

Log_String("\n\n\rpattern after re-inverting the blocks");
ReInvert_block(ptr,offset2, Inverting_length);
verify_pattern(ptr, length, seed);


//calling the free memory function
free_words(ptr);
Log_String("\n\n\rallocated memory FREE");
GREEN_LED_ON();
return 0;

}

#endif



//This version of the program is for running Development environment mode of operation
#ifdef PC_RUN
#include "Logger.h"
#include "Memory_Functions.h"
#include "LED_Blink.h"
#include "Delay_Function.h"

extern const int NUMB_OF_INVERTING_BYTES;//Number of Bytes to be Inverted
extern size_t Inverting_length;//length for which we invert the bytes

extern const int NUMB_OF_BYTES;
extern size_t length;//size of the memory in bytes.

//#define NULL ((void*)0)
extern uint8_t array5[16];
extern uint8_t array4[16];
extern uint8_t array3[16];
extern uint8_t array2[16];
extern uint32_t *ptr;//pointer for memory allocation function.

uint32_t milli_sec_val=0;

// main functions calling all the function routines
int main(void)
{

//BOARD_InitBootPins();
//BOARD_InitBootClocks();
//BOARD_InitBootPeripherals();
//BOARD_InitDebugConsole();
//BOARD_InitPins();
//BOARD_BootClockRUN();


BLUE_LED_ON();

//calling the memory allocation function.
allocate_words();

//USER INPUT FOR OFFSET VALUE
//PRINTF("\nENTER THE OFFSET VALUE:");
printf("\n\rENTER THE OFFSET VALUE");
int offset;
//Stores the user input to offset variable
scanf("%d",&offset);
//taking the address of allocated memory
get_address(ptr,offset);

//USER INPUT FOR SEED VALUE
printf("\n\rENTER THE SEED VALUE:");
uint32_t seed;
scanf("%u",&seed);



//writing the randomly generated pattern to the allocated memory.
write_pattern(ptr, length,seed);
//comparing the newly generated array with the patter from pattern generation function
verify_pattern(ptr, length, seed);
display_memory();

printf("\n\n\rpattern after writing the value");
//writing the value to given address.
Write_Value_To_Memory(ptr,offset, 0xFFEE);
//comparing the newly generated array with the patter from write function
verify_pattern(ptr, length, seed);

printf("\n\n\rpattern generated with the same seed value");
//writing the randomly generated pattern to the allocated memory.
write_pattern(ptr, length,seed);
//comparing the newly generated array with the patter from write function
display_memory();
verify_pattern(ptr, length, seed);

printf("\n\n\rENTER THE OFFSET VALUE FOR INVERTING BYTES FUNCTION:");
int offset2;
//Stores the user input to offset2 variable
scanf("%d",&offset2);

invert_block(ptr,offset2, Inverting_length);
//comparing the newly generated array with the patter from inverse function
verify_pattern(ptr, length, seed);
printf("\n\n\rpattern after re-inverting the blocks");
ReInvert_block(ptr,offset2, Inverting_length);
verify_pattern(ptr, length, seed);


//calling the free memory function
free_words(ptr);
printf("\n\n\rallocated memory FREE");
GREEN_LED_ON();
return 0;

}
#endif
