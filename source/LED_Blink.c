/*
 * @file LED_Blink.c
 * author: kushagra Pandey & Vaidehi Salway
 * Date:10/16/2019
 *
 * This .c file contains two modes of operations
 * 1. FB_RUN: When running on frdm board
 * 			  The LED on the board turn ON/OFF
 * 2. PC_RUN: When running on development environment i.e. windows/linux
 * 			  Message on the console prints indicating the state of the LED ON/OFF
 *
 *Different modes of operations will run based on which target is built
 *
 *
 */



#include "LED_Blink.h"

// This mode of operation is for running on KL25Z frdm board
#ifdef FB_RUN


#include "Memory_Functions.h"



//Configuring Pin direction and initial digital output value
gpio_pin_config_t LED_config=
	{
			kGPIO_DigitalOutput, 1,
	};

//initializing green led GPIO Pin
void GREEN_LED_INIT()
	{

		GPIO_PinInit(BOARD_LED_GREEN_GPIO, BOARD_LED_GREEN_GPIO_PIN, &LED_config);

	}
//setting ON green led GPIO Pin
void GREEN_LED_ON()
	{

		GPIO_ClearPinsOutput(BOARD_LED_GREEN_GPIO, 1U << BOARD_LED_GREEN_GPIO_PIN);

	}
//setting OFF green led GPIO Pin
void GREEN_LED_OFF()
	{

		GPIO_SetPinsOutput(BOARD_LED_GREEN_GPIO, 1U << BOARD_LED_GREEN_GPIO_PIN);

	}

//initializing red led GPIO Pin
void RED_LED_INIT()
	{

		GPIO_PinInit(BOARD_LED_RED_GPIO, BOARD_LED_RED_GPIO_PIN, &LED_config);

	}
//setting ON red led GPIO Pin
void RED_LED_ON()
	{

		GPIO_ClearPinsOutput(BOARD_LED_RED_GPIO, 1U << BOARD_LED_RED_GPIO_PIN);

	}
//setting OFF red led GPIO Pin
	void RED_LED_OFF()
	{

		GPIO_SetPinsOutput(BOARD_LED_RED_GPIO, 1U << BOARD_LED_RED_GPIO_PIN);

	}


//initializing blue led GPIO Pin
	void BLUE_LED_INIT()
	{

		GPIO_PinInit(BOARD_LED_BLUE_GPIO, BOARD_LED_BLUE_GPIO_PIN, &LED_config);

	}
//setting ON blue led GPIO Pin
void BLUE_LED_ON()
	{

	 	 GPIO_ClearPinsOutput(BOARD_LED_BLUE_GPIO, 1U << BOARD_LED_BLUE_GPIO_PIN);

	}
//setting OFF blue led GPIO Pin
void BLUE_LED_OFF()
	{

	 	 GPIO_SetPinsOutput(BOARD_LED_BLUE_GPIO, 1U << BOARD_LED_BLUE_GPIO_PIN);

	}

#endif


// This mode of operation is for running on the development environment
#ifdef PC_RUN

#include "Memory_Functions.h"


//Configuring Pin direction and initial digital output value
gpio_pin_config_t LED_config=
	{
		kGPIO_DigitalOutput, 1,
	};


//setting ON green led GPIO Pin
void GREEN_LED_ON()
	{

		printf("\n\rGREEN_LED_ON");
	}
//setting OFF green led GPIO Pin
void GREEN_LED_OFF()
	{

		printf("\n\rGREEN_LED_OFF");

	}


//setting ON red led GPIO Pin
void RED_LED_ON()
	{

		printf("\n\rRED_LED_ON");

	}
//setting OFF red led GPIO Pin
void RED_LED_OFF()
	{

		printf("\n\rRED_LED_OFF");

	}



//setting ON blue led GPIO Pin
void BLUE_LED_ON()
	{

		printf("\n\rBLUE_LED_ON");

	}
//setting OFF blue led GPIO Pin
void BLUE_LED_OFF()
	{

		printf("\n\rBLUE_LED_OFF");

	}



#endif

