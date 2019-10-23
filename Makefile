PC_RUN: main.c Logger.c Memory_Functions.c Delay_Function.c LED_Blink.c 
	gcc -Wall -Werror main.c Logger.c Memory_Functions.c Delay_Function.c LED_Blink.c -o PC_RUN

clean: 
	-rm -f main.o Logger.o Memory_Functions.o Delay_Function.o LED_Blink.o PC_RUN
