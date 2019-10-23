/*
 * @file Memory_Functions.c
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
 *This file contains the functions related to memory test cycle
 *
 */



#include "Memory_Functions.h"
//This version is for running the code on freedom board
#ifdef FB_RUN


#include "Logger.h"
#include "LED_Blink.h"
#include "Delay_Function.h"

//#define NULL ((void*)0)
uint8_t array5[16]={0};
uint8_t array4[16]={0};
uint8_t array3[16]={0};
uint8_t array2[16]={0};
uint32_t *ptr=NULL;//pointer for memory allocation function.


//size_t MAX=16;//size of the memory in bytes.
const int NUMB_OF_BYTES=16;
size_t length=NUMB_OF_BYTES*(sizeof(int));//size of the memory in bytes.

const int NUMB_OF_INVERTING_BYTES=4;//Number of Bytes to be Inverted
size_t Inverting_length=NUMB_OF_INVERTING_BYTES*(sizeof(uint8_t));//length for which we invert the bytes
int i=0;



//Dynamic Memory Allocaton Function
uint32_t *allocate_words()
{
    ptr=(uint32_t*)malloc(length);//dynamic memory allocation using malloc().
    if(NUMB_OF_BYTES>16 && NUMB_OF_BYTES<0)//checking for maximum allowed memory.
      {
    	LED_RED_ON();
         ptr=0;
      }

      return ptr;
}

//freeing the pointer to previously allocated memory.
void free_words(uint32_t *ptr)
{
	if(ptr==NULL)
	{
		Log_String("memory not allocated to free");

	}

	free(ptr);
}

//function to get the address of the location
uint32_t * get_address(uint32_t *base_address,int offset)
{
	uint8_t *offset_ptr2=NULL;
offset_ptr2=(uint8_t*)(base_address);

 	 for(i=0;i<offset;i++)
 	 {
 		 offset_ptr2++;
 	 }

 	 uint32_t *physical_address=NULL;
 	 physical_address=(uint32_t*)(offset_ptr2);
 	 Log_Data((unsigned int)physical_address);
return 0;
}


// Code for random generator
// Reference:   https://rosettacode.org/wiki/Linear_congruential_generator
void write_pattern(uint32_t * loc, size_t length,uint32_t seed)
{

  //PRINTF("\nrand max is %u\n", RANDOM_MAX);
	Log_String("rand max is");
	Log_Data(RANDOM_MAX);

 	for (int i = 0; i < NUMB_OF_BYTES; i++)
   {
    seed = (seed * 13124245 + 12345 ) & RANDOM_MAX;

    array2[i]=seed;
    //writing the random number array to the allocated memory.
    loc[i]=array2[i];
    //PRINTF("%x\n",(unsigned int)*(ptr+i));
    }
}
//return the pointer for allocated memory and display its value.
uint32_t display_memory()
{
	for (int i = 0; i < NUMB_OF_BYTES; i++)
	{
	  ptr[i]=array2[i];
      //PRINTF("\npattern_generated is:%x\n",(unsigned int)*(ptr+i));
      Log_Data((unsigned int)*(ptr+i));
	}
   return *ptr;
}

//Function for Writing value at a particular Memory Location.
//*loc = the memory location at which we have to write the value.
void Write_Value_To_Memory(uint32_t * base_address,int offset, uint32_t value)
{
//calculating the offset for the address in the allocated memory.
	uint32_t *offset_ptr=NULL;
	offset_ptr=base_address;
	for(i=0;i<offset;i++)
	{
   //incrementing it to the offset value required.
	offset_ptr++;
	}
    uint32_t *physical_address=NULL;
    //calculating the physical address with the help of offset pointer value above.
    physical_address=(uint32_t*)(offset_ptr);

    *physical_address=value;
    Log_String("\nPattern after modifying the value at the given location is");

    PRINTF("\n:%x\n",(unsigned int)(*physical_address));
      uint32_t *printer=NULL;
      printer=ptr;
    for(i=0;i<NUMB_OF_BYTES;i++)
    {
    //PRINTF("\n%x", *(printer+i));
    Log_Data(*(printer+i));
    }
}

//Inverting each byte of the array of random numbers allocated.
void invert_block(uint32_t * base_address,int offset2, size_t Inverting_length)
{

  //calculating the offset for the address in the allocated memory.
	uint32_t *offset_ptr3=NULL;
	offset_ptr3=base_address;
	for(i=0;i<offset2;i++)
	{
		//incrementing it to the offset value required.
		offset_ptr3++;
	}
    uint32_t *physical_address=NULL;
    //calculating the physical address with the help of offset pointer value above.
    physical_address=(uint32_t*)(offset_ptr3);

    Log_String("\n\ninverted bytes are:");

    for(i=0;i<NUMB_OF_INVERTING_BYTES;i++)
    {
      //EXORing the array allocated to inverse the bits in it.
      array4[i]=(array2[i]^(0xff));
      base_address[i]=array4[i];

    }

    for(i=0;i<NUMB_OF_BYTES;i++)
    {
      // base_address[i]=array2[i];
      //PRINTF("\n%x",*(base_address+i));
      Log_Data(*(base_address+i));
    }
}

void ReInvert_block(uint32_t * base_address,int offset2, size_t Inverting_length)
{

	//calculating the offset for the address in the allocated memory.
	 uint32_t *offset_ptr4=NULL;
	 offset_ptr4=base_address;
	 	 for(i=0;i<offset2;i++)
	 	 {
	   //incrementing it to the offset value required.
	 		 offset_ptr4++;
	 	 }
	    uint32_t *physical_address=NULL;
	    //calculating the physical address with the help of offset pointer value above.
	    physical_address=(uint32_t*)(offset_ptr4);


	    for(i=0;i<NUMB_OF_INVERTING_BYTES;i++)
	    {
	      //EXORing the array allocated to inverse the bits in it.
	      array5[i]=(array4[i]^(0xff));
	      base_address[i]=array5[i];

	    }

	    for(i=0;i<NUMB_OF_BYTES;i++)
	    {
	      // base_address[i]=array2[i];
	      //PRINTF("\n%x",*(base_address+i));
	      Log_Data(*(base_address+i));
	    }


}


//verifying if the original pattern and different patterns generated match.
uint32_t * verify_pattern(uint32_t * loc, size_t length, uint32_t seed)
{

 //generating the random pattern again with the same seed value to verify different patterns.
 	for (int i = 0; i < NUMB_OF_BYTES; i++)
 	{
 		seed = (seed * 13124245 + 12345 ) & RANDOM_MAX;
 		array3[i]=seed;
 	}

    for(i=0;i<NUMB_OF_BYTES;i++)
    {
    	if(loc[i]==array3[i])
    	{
    		BLUE_LED_ON();
    		Delay_Time(200);
    		BLUE_LED_OFF();
    		Delay_Time(100);

      Log_String("\nallocated memories are equal");

    }

    else if(loc[i]!=array3[i])
    {
    		RED_LED_ON();
    		Delay_Time(200);
    		RED_LED_OFF();
    		Delay_Time(100);

      Log_String("\nerror generated at address");
      //PRINTF("\n%x",(unsigned int)&loc[i]);
      Log_Data((unsigned int)&loc[i]);
    }

    }
  return 0;
}
#endif


//This version is for running the code on development system i.e windows or Linux
#ifdef PC_RUN


//#include "memory_functions.h"
#include "Logger.h"
#include "LED_Blink.h"
#include "Delay_Function.h"

//#define NULL ((void*)0)
uint8_t array5[16]={0};
uint8_t array4[16]={0};
uint8_t array3[16]={0};
uint8_t array2[16]={0};
uint32_t *ptr=NULL;//pointer for memory allocation function.


//size_t MAX=16;//size of the memory in bytes.
int NUMB_OF_BYTES=16;
size_t length=16/*NUMB_OF_BYTES*/*(sizeof(int));//size of the memory in bytes.

int NUMB_OF_INVERTING_BYTES=4;//Number of Bytes to be Inverted
size_t Inverting_length=16/*NUMB_OF_INVERTING_BYTES*/*(sizeof(uint8_t));//length for which we invert the bytes
int i=0;



//Dynamic Memory Allocaton Function
uint32_t *allocate_words()
{
    ptr=(uint32_t*)malloc(length);//dynamic memory allocation using malloc().
    if(NUMB_OF_BYTES>16 && NUMB_OF_BYTES<0)//checking for maximum allowed memory.
      {
    	LED_RED_ON();
         ptr=0;
      }

      return ptr;
}

//freeing the pointer to previously allocated memory.
void free_words(uint32_t *ptr)
{
	if(ptr==NULL)
	{
		printf("memory not allocated to free");
	}
		free(ptr);
}


uint32_t * get_address(uint32_t *base_address,int offset)
{
	uint8_t *offset_ptr2=NULL;
	offset_ptr2=(uint8_t*)(base_address);

	for(i=0;i<offset;i++)
	{
		offset_ptr2++;
	}
	uint32_t *physical_address=NULL;
	physical_address=(uint32_t*)(offset_ptr2);
	printf("\n\n\r physical address is:%p",physical_address);
	return 0;
}


// Code for random generator
// Reference:   https://rosettacode.org/wiki/Linear_congruential_generator
void write_pattern(uint32_t * loc, size_t length,uint32_t seed)
{

	printf("\n\r rand max is %u\n", RANDOM_MAX);

 	for (int i = 0; i < NUMB_OF_BYTES; i++)
 	{
 		seed = (seed * 13124245 + 12345 ) & RANDOM_MAX;

 		array2[i]=seed;
 		//writing the random number array to the allocated memory.
 		loc[i]=array2[i];
    }
}
//return the pointer for allocated memory and display its value.
uint32_t display_memory()
{
	for (int i = 0; i < NUMB_OF_BYTES; i++)
	{
		printf("\n\r pattern_generated is:%x\n",(unsigned int)*(ptr+i));
	}
   return *ptr;
}

//Function for Writing value at a particular Memory Location.
//*loc = the memory location at which we have to write the value.
void Write_Value_To_Memory(uint32_t * base_address,int offset, uint32_t value)
{
	//calculating the offset for the address in the allocated memory.
	uint32_t *offset_ptr=NULL;
	offset_ptr=base_address;
	for(i=0;i<offset;i++)
	{
		//incrementing it to the offset value required.
		offset_ptr++;
	}
    uint32_t *physical_address=NULL;
    //calculating the physical address with the help of offset pointer value above.
    physical_address=(uint32_t*)(offset_ptr);

    *physical_address=value;
    printf("\n\r Pattern after modifying the value at the given location is");

    printf("\n\r:%x\n",(*physical_address));
    uint32_t *printer=NULL;
    printer=ptr;
    for(i=0;i<NUMB_OF_BYTES;i++)
    {
    	printf("\n\r%x", *(printer+i));
    }
}

//Inverting each byte of the array of random numbers allocated.
void invert_block(uint32_t * base_address,int offset2, size_t Inverting_length)
{

  //calculating the offset for the address in the allocated memory.
 uint32_t *offset_ptr3=NULL;
 offset_ptr3=base_address;
 for(i=0;i<offset2;i++)
 {
   //incrementing it to the offset value required.
  offset_ptr3++;
 }
    //uint32_t *physical_address=NULL;
    //calculating the physical address with the help of offset pointer value above.
    //physical_address=(uint32_t*)(offset_ptr3);

    printf("\n\n\rinverted bytes are:");

    for(i=0;i<NUMB_OF_INVERTING_BYTES;i++)
    {
      //EXORing the array allocated to inverse the bits in it.
      array4[i]=(array2[i]^(0xff));
      base_address[i]=array4[i];

    }

    for(i=0;i<NUMB_OF_BYTES;i++)
    {
      // base_address[i]=array2[i];
      printf("\n\r%x",*(base_address+i));
    }
}

void ReInvert_block(uint32_t * base_address,int offset2, size_t Inverting_length)
{

	//calculating the offset for the address in the allocated memory.
	 uint32_t *offset_ptr4=NULL;
	 offset_ptr4=base_address;
	 for(i=0;i<offset2;i++)
	 {
	   //incrementing it to the offset value required.
		 offset_ptr4++;
	 }
	    //uint32_t *physical_address=NULL;
	    //calculating the physical address with the help of offset pointer value above.
	    //physical_address=(uint32_t*)(offset_ptr4);

	    printf("\n\n\rinverted bytes are:");

	    for(i=0;i<NUMB_OF_INVERTING_BYTES;i++)
	    {
	      //EXORing the array allocated to inverse the bits in it.
	      array5[i]=(array4[i]^(0xff));
	      base_address[i]=array5[i];

	    }

	    for(i=0;i<NUMB_OF_BYTES;i++)
	    {
	      // base_address[i]=array2[i];
	      printf("\n\r%x",*(base_address+i));
	    }


}


//verifying if the original pattern and different patterns generated match.
uint32_t * verify_pattern(uint32_t * loc, size_t length, uint32_t seed)
{

 //generating the random pattern again with the same seed value to verify different patterns.
 	for (int i = 0; i < NUMB_OF_BYTES; i++)
   {
 		seed = (seed * 13124245 + 12345 ) & RANDOM_MAX;

 		array3[i]=seed;
   }

    for(i=0;i<NUMB_OF_BYTES;i++)
    {
    	if(loc[i]==array3[i])
    	{
    		BLUE_LED_ON();
    		printf("\n\rallocated memories are equal");

    	}

    	else if(loc[i]!=array3[i])
    	{
    		RED_LED_ON();
    		printf("\n\rerror generated at address:");
    		printf("%p",&loc[i]);
    	}
    }
  return 0;
}
#endif
