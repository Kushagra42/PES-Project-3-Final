# PES-Project-3-Final PES Poject 3
 Created by: Vaidehi Salway
	      Kushagra Pandey
Date: 21st Oct 2019


References: Insights were taken from the link mentioned below to write the code for Pseudo Random Pattern Generator.

https://www.guru99.com/c-dynamic-memory-allocation.html

Repo Content: 
Code Source files 
UML Activity Diagram
UML Sequence Diagram
Code PDF
Readme.txt

Assignment Description: There are several key elements to creation and demonstration of this utility,
			including: a suite of memory tests, a pattern generator, a logger, an LED control, 
			a main program to run an example test set, and (optionally) µcUnit test cases.

Program Files Description: The program contains multiple files as mentioned below to generate random pattterns and test various conditions:

1. main.c/main.h :-The main file contains all the function calls for FB_RUN and PC_RUN mode of operation.

2. Memory_Functions.c/Memory_Functions.h :- Memory_Functions file genarates randon patterns and contains test functions for the memory test.

3. Logger./Logger.h :- Loggger file contains the logger enable/disable functions and log statements to print on MCUxpresso terminal using UART.

4. LED_Blink.c/LED_Blink.h :- LED_Blink file contains the LED initialization and LED ON/ LED OFF funtions.

5. Delay_Function.c/Delay_Function.h :- Delay_Function contains the routiine for delay.


Program execution instruction:

1. Choose between PC_RUN version and FB_RUN version by uncommenting #define PC_RUN and Commenting #define FB_RUN and vice-verca in main.h
2. Select UART from Quick setting menu to run the FB_RUN version of the code
3. Select Semihost from Quick setting menu to run PC_RUN version of the code
4. Enable logging and disable logging by un-commenting #define Logging_init and commenting Logging_notinit and vice-verca in Logger.h
5. While running the program on development envirnoment or KL25Z, input  the requirements as asked in console/terminal by clicking in front of it.


Program Execution:

1. Memory is allocated using the malloc function.
2. User inputs the offset value and seed value.
3. Random pattern is generated and written on the alocated memory.
4. Memory test functions run and check for the given problem tasks.
5. Log messages are printed on MCUxpresso terminnal for FB_RUN verion via UART.
6. Log messages are printed on MCUxpresso console for PC_RUN verion.
7. LED indications are run in KL25Z freedom board.  


Difficulties faced:
1. Allocating memory on KL25Z did not work even after running many iterations of code
2. Re-writting the values in preallocated the memory using pointers
3. Setting the location i.e. the physical address 

Last two difficulties were solved by reading in depth about pointers and running multiple test programs to widen understanding.

 
