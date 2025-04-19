#include <ncurses.h>


int main(int argc, char** argv){

	initscr(); 
	printw("HELLO, WORLD!");
	refresh(); 
	getch(); 
	endwin();
	return 0; 

}
