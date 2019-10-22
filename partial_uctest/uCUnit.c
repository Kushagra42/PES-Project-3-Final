#include "uCUnit.h"
#include "stdint.h"

// Code for random generator
// Reference:   https://rosettacode.org/wiki/Linear_congruential_generator
//







void Test_Allocate_Memory(uint32_t *test_pointer)
{
	 uint32_t *pointer =NULL;
	 UCUNIT_Init();


	UCUNIT_TestcaseBegin("Memory Allocated");

	pointer=allocate_words();

	UCUNIT_CheckIsEqual(pointer,test_pointer);
	UCUNIT_CheckIsInRange(pointer,536866816,536870911);
	UCUNIT_TestcaseEnd();
	UCUNIT_WriteSummary();
	UCUNIT_Shutdown();


}


void Write_Patter_Check(uint32_t *test_pointer)
{
	 uint32_t *pointer =NULL;
	 UCUNIT_Init();
	UCUNIT_TestcaseBegin("Random Pattern written");

	//TEST_write_pattern(ptr, length, seed)

	//pointer= loc[i];
	UCUNIT_CheckIsEqual(pointer,test_pointer);
	UCUNIT_CheckIsInRange(pointer,536866816,536870911);
	UCUNIT_TestcaseEnd();
	UCUNIT_WriteSummary();
	UCUNIT_Shutdown();


}



void TEST_after_Value_Write(uint32_t *test_pointer)

{

//Write_Value_To_Memory(ptr, offset, 0XFFEE);
uint32_t *pointer =NULL;
UCUNIT_Init();
UCUNIT_TestcaseBegin("Random Pattern written");

//pointer=printer;
UCUNIT_CheckIsEqual(pointer,test_pointer);
UCUNIT_CheckIsInRange(pointer,536866816,536870911);
UCUNIT_TestcaseEnd();
UCUNIT_WriteSummary();
UCUNIT_Shutdown();


}






