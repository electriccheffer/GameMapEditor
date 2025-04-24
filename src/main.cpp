#include <ncurses.h>
#include <iostream>
#include "../include/NCursesView.hpp"
#include <thread>
#include <chrono>
#include "../include/NCursesController.hpp"

int main(int argc, char** argv){

	initscr(); 
	cbreak();
        noecho();
	curs_set(2);	
	keypad(stdscr,true); 
	int typedCharacter; 
	refresh(); 
	Controller controller = {}; 	
	while(((typedCharacter = getch()) != KEY_F(1))){
		controller.takeInput(typedCharacter);		
	}
	endwin();
	return 0; 

}

