/*
 * @file main.h
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
 *This file contains all header files required by the main.c file
 */


#include <stdio.h>
#include <stdint.h>//for using unit32_t data type.
#include <stdlib.h>//for using malloc() function.
#include <math.h>
#include <limits.h>

#include "board.h"
#include "peripherals.h"
#include "pin_mux.h"
#include "clock_config.h"
#include "MKL25Z4.h"
#include "fsl_debug_console.h"
#include "fsl_gpio.h"
#include "fsl_uart.h"
#include "time.h"

//#define PC_RUN
#define FB_RUN
