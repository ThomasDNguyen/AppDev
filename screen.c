#include "screen.h"
#include <stdio.h>

//function definitions
void clearScreen(void){
	printf("\033[2J");
	fflush(stdout);
}

void setFGcolor(int fg){	//fg is a value between 30 and 37
	printf("\033[%d;1m", fg);
	fflush(stdout);		//send out the esc sequence to terminal
}

void resetColors(void){
	printf("\033[0m");
	fflush(stdout);
}

void gotoXY(int row, int col){
	//row number should be 1-30 col should be 1-30
	printf("\033[%d;%dH", row, col);
	fflush(stdout);
}

void displayBar(int col, double rms){
	int  i;
	for(i=0; i<rms/150; i++){
		if(i==58) break;
		if(i<10) setFGcolor(MAGENTA);
		else if(i<20) setFGcolor(BLUE);
		else if(i<30) setFGcolor(CYAN);
		else if(i<40) setFGcolor(GREEN);
		else if(i<50) setFGcolor(YELLOW);
		else if(i<60) setFGcolor(RED);
		gotoXY(60-i, col);
#ifdef UNICODE
		printf("%s", BAR);
#else
		printf("*");
#endif
	}
	fflush(stdout);
}
