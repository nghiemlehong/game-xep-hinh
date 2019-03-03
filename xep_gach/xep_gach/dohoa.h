#ifndef __DOHOA_H__
#define __DOHOA_H__


#include "windows.h"


enum
{
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	PURPLE,
	GRAY,
	WHITE,
	LIGHTGRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTPURPLE,
	LIGHTYELLOW,
	LIGHTWHITE
};

void gotoxy(int x, int y);
void clrscr();
void textcolor(WORD color);
void SetBGColor(WORD color);
void delay(int x);
void Nocursortype();

#endif