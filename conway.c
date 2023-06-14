#include <c64.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define P_SCREEN0 ((char *)0x2000)
#define P_COLOR0  ((char *)0x0400)

#define P_SCREEN1 ((char *)0x6000)
#define P_COLOR1  ((char *)0x4400)

//HighRes Mode 300x200px
#define XMAX 40
#define YMAX 25
#define ROUNDS 1

//static const char array[XMAX][YMAX] 
static char spielfeld[XMAX][YMAX] = {
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,1},
{1,0,0,0,0,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,0,0,0,1,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,1},
{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
{1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,1,1,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0},
};

//static char spielfeld[XMAX][YMAX];
static char temp[XMAX][YMAX];

int main(void)
{
  clock_t       t;
  unsigned short sec;
  unsigned      sec10;
  unsigned short fps;
  unsigned      fps10;
  char background;
  char text;
        
	char x;
	char y;
	char round = 0;

revers(1);

  t = clock ();
  clrscr();
	background = bgcolor(COLOR_BLACK);
	text = textcolor(COLOR_WHITE);
	for(y = 0; y< YMAX; ++y){
		for(x = 0; x< XMAX; ++x){
			if(spielfeld[x][y] == 1){
 			cputcxy (x, y, 32);
			}
		}
	}
//	signal (int sig, __sigfunc func);


	while(round < ROUNDS && !kbhit()){
		for(y = 0; y< YMAX; ++y){
			for(x = 0; x< XMAX; ++x){
				char lebende = 0;

		char yStart, xStart, yEnd, xEnd;

		if(y == 0){
			yStart = YMAX - 1;
			yEnd = y + 1;
		}else if(y == YMAX - 1){
			yEnd = 0;
			yStart = y - 1;
		}else{
			yStart = y - 1;
			yEnd = y + 1;
		}

		if(x == 0){
			xStart = XMAX - 1;
			xEnd = x + 1;
		}else if(x == XMAX - 1){
			xEnd = 0;
			xStart = x - 1;
		}else{
			xStart = x - 1;
			xEnd = x + 1;
		}

		lebende = spielfeld[xStart][yStart] + spielfeld[x][yStart] + spielfeld[xEnd][yStart] + spielfeld[xStart][y] + spielfeld[xEnd][y] + spielfeld[xStart][yEnd] + spielfeld[x][yEnd] + spielfeld[xEnd][yEnd];

	if(spielfeld[x][y] == 0 ){
		if(lebende == 3){
			temp[x][y] = 1;
		}
	}else{
		if(lebende < 2 || lebende > 3){
			temp[x][y] = 0;
		}else{
			temp[x][y] = 1;
		}
	}
			}// for x
		}// for y

		memcpy(spielfeld,temp,XMAX*YMAX);
	
		++round;
		clrscr();
	for(y = 0; y< YMAX; ++y){
		for(x = 0; x< XMAX; ++x){
			if(spielfeld[x][y] == 1){
 				cputcxy (x, y, 32);
			}
		}
	}
	}
		t = clock() - t;
	
  /* Reset screen colors */
    bgcolor (background);
    textcolor (text);
    clrscr ();

    /* Calculate stats */
    sec   = (t * 10) / CLK_TCK;
    sec10 = sec % 10;
    sec  /= 10;
    fps   = (round * (CLK_TCK * 10)) / t;
    fps10 = fps % 10;
    fps  /= 10;

    /* Output stats */
    gotoxy (0, 0); cprintf ("time  : %u.%us", sec, sec10);
    gotoxy (0, 1); cprintf ("frames: %u", round);
    gotoxy (0, 2); cprintf ("fps   : %u.%u", fps, fps10);

    /* Wait for a key, then end */
    cputsxy (0, 4, "Press any key when done...");
    (void) cgetc ();

    /* Done */
    return EXIT_SUCCESS;
}