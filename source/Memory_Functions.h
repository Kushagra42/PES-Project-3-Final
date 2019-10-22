/*
 * @file Memory_Functions.h
 * author: Kushagra Pandey & Vaidehi Salway
 * Date:10/20/2019
 *
 * There are two modes of operations to choose from in the main routine
 * 1. FB_RUN: When this target is built the routine for the freedom board KL25Z gets built.
 * 			  This version prints the outputs on MCUxpresso terminal using UART
 * 			  LED indications are given on the freedom board as per the test results
 * 2. PC_RUN: When this target is built the routine for the development environment i.e. windows/linux gets built
 * 			  This version prints the output on MCUxpresso console
 * 			  Test indications are given by printing X LED ON the console
 *
 *This file contains header files, define statements, and function prototypes for Memory_Function.c file
 *
 */



#include "main.h"

//Function prototypes for FB_RUN MODE
#ifdef FB_RUN



#define RANDOM_MAX ((1U << 7) - 1)


uint32_t *allocate_words();
void free_words(uint32_t *ptr);
uint32_t * get_address(uint32_t *base_address,int offset);
void write_pattern(uint32_t * loc, size_t length,uint32_t seed);
uint32_t display_memory();
void Write_Value_To_Memory(uint32_t * base_address,int offset, uint32_t value);
void invert_block(uint32_t * base_address,int offset2, size_t Inverting_length);
uint32_t * verify_pattern(uint32_t * loc, size_t length, uint32_t seed);
void ReInvert_block(uint32_t * base_address,int offset2, size_t Inverting_length);

#endif

#ifdef PC_RUN

//Function prototypes for PC_RUN MODE
#define RANDOM_MAX ((1U << 7) - 1)



uint32_t *allocate_words();
void free_words(uint32_t *ptr);
uint32_t * get_address(uint32_t *base_address,int offset);
void write_pattern(uint32_t * loc, size_t length,uint32_t seed);
uint32_t display_memory();
void Write_Value_To_Memory(uint32_t * base_address,int offset, uint32_t value);
void invert_block(uint32_t * base_address,int offset2, size_t Inverting_length);
uint32_t * verify_pattern(uint32_t * loc, size_t length, uint32_t seed);
void ReInvert_block(uint32_t * base_address,int offset2, size_t Inverting_length);



#endif
