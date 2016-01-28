
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#define getch() _getch()  
#define kbhit() _kbhit()
#define ECHO 1
#define NOECHO 0
#define BS 8
#define CR 0x0D
#define SPACE 0x20
bool strequal(char *addr1, char *addr2);
char getstr(char *ptr, bool bEcho);

int _tmain(int argc, _TCHAR* argv[]) {
	char id1[] = { "rootshinmin" };
	char pwd1[] = { "12345678" };
	char k, p;
	char id2[20];
	char pwd2[20];
	printf("\n 請輸入帳號 \n");
	k = getstr(&id2[0], ECHO);	//get ID
	printf("\n 請輸入密碼 \n");
	p = getstr(&pwd2[0], NOECHO);
	if (strequal(&id1[0], &id2[0]) && strequal(&pwd1[0], &pwd2[0])) {
		printf("\n 相等 ! \n");
	}
	else {
		printf("\n 不等 ! %d \n", (int)k);
	}
	printf("\n 請按任意鍵結束此程式 ! \n");
	getch();
	return 0;
}

char getstr(char *ptr, bool bEcho) {
	char i = 0,j, ch;
	bool bLoop = 1;
	while (bLoop) {
		if (kbhit()) {
			ch = getch();
			if (ch == CR) {
				bLoop = 0;
				ptr[i] = '\0';		//Fixed the bug!
			}
			else {
				if (ch == BS) {
					ptr[i] = '\0';		//Fixed the bug!
					if (--i < 0) i = 0;
					putchar ( CR );
					//for (j=0; j<i; j++) putchar ( ptr[j] );
					if (bEcho) {
						printf( ptr );
						putchar ( SPACE );
					}
				}
				else {
					ptr[i] = ch;
					if (++i >= 20) bLoop = 0;
				}
				if (bEcho) putchar(ch);
			}
		}
	}
	return i;
}
bool strequal(char *addr1, char *addr2) {
	bool bEqual = 1;
	char i = 0;
	while (*addr1) {
		if (*addr1 != *addr2) bEqual = 0;
		++addr1;
		++addr2;
	}
	if (*addr2) bEqual = 0;
	return bEqual;
}

//char id2[] = {"rootshinmin"};	//debug
//for ( char i=0; i<k; i++ ) putchar( id2[i] );