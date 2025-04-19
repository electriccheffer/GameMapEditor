#include <ncurses.h>
#include "../include/window_functions.hpp"


int main(int argc, char** argv){

	initscr(); 
	//Create three divided windows
	refresh(); 
	getch(); 
	endwin();
	return 0; 

}
