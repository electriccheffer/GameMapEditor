#include <ncurses.h>
#include <iostream>
#include "../include/NCursesView.hpp"
#include <thread>
#include <chrono>

int main(int argc, char** argv){

	initscr(); 
	cbreak();
        noecho();
	curs_set(2);	
	keypad(stdscr,true); 
	int typedCharacter; 
	NCursesView view = {}; 	
	std::this_thread::sleep_for(std::chrono::seconds(3)); 
	while(((typedCharacter = getch()) != KEY_F(1))){
		view.recieveCharacter(typedCharacter);		
	}
	endwin();
	return 0; 

}

