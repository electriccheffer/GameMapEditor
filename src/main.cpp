#include <ncurses.h>
#include "../include/window_functions.hpp"
#include <iostream>
#define MAX_WINDOWS 3

	int detailsBoxWidth; 
	int detailsBoxHeight;
	int detailsBoxStartX; 
	int detailsBoxStartY;
	int mapEditorBoxWidth; 
	int mapEditorBoxHeight;
	int mapEditorBoxStartY;
	int mapEditorBoxStartX;
	int optionsBoxWidth; 
	int optionsBoxHeight;
	int optionsBoxStartY;
	int optionsBoxStartX;
	int typedCharacter;
	WINDOW *windows[MAX_WINDOWS]; 

void initializeWindowVariables(){

	detailsBoxWidth = COLS; 
	detailsBoxHeight = LINES / 2; 
	detailsBoxStartX = 0; 
	detailsBoxStartY = detailsBoxHeight; 
	mapEditorBoxWidth = COLS/2; 
	mapEditorBoxHeight = LINES / 2;
	mapEditorBoxStartY = 0; 
	mapEditorBoxStartX = 0;	
	optionsBoxWidth = mapEditorBoxWidth; 
	optionsBoxHeight = mapEditorBoxHeight; 
	optionsBoxStartY = 0; 
	optionsBoxStartX = COLS / 2;

}

int main(int argc, char** argv){

	initscr(); 
	cbreak();
	 
        noecho();
	curs_set(2);	
	initializeWindowVariables(); 
	WINDOW *detailsBoxWindow = create_new_window(detailsBoxHeight,detailsBoxWidth,detailsBoxStartY,detailsBoxStartX);
	WINDOW *mapEditorBoxWindow = create_new_window(mapEditorBoxHeight,mapEditorBoxWidth,mapEditorBoxStartY,mapEditorBoxStartX);
	WINDOW *optionsBoxWindow = create_new_window(optionsBoxHeight,optionsBoxWidth,optionsBoxStartY,optionsBoxStartX);
	
	windows[0] = detailsBoxWindow; 
	windows[1] = mapEditorBoxWindow; 
	windows[2] = optionsBoxWindow; 

	keypad(detailsBoxWindow,true);
	keypad(mapEditorBoxWindow,true);
	keypad(optionsBoxWindow,true);
	wprintw(detailsBoxWindow,"Details Box Window"); 
	wprintw(mapEditorBoxWindow,"Map Editor Box Window");
	wprintw(optionsBoxWindow,"Options Box Window");
	wrefresh(detailsBoxWindow);
	wrefresh(mapEditorBoxWindow);
	wrefresh(optionsBoxWindow); 	
	int windowIndex = 2; 	
	WINDOW *activeWindow = windows[windowIndex];
	wmove(activeWindow,1,1);	
	
	while(((typedCharacter = wgetch(activeWindow)) != KEY_F(1))){
		switch(typedCharacter){
		
			case KEY_PPAGE:
				windowIndex = (windowIndex + 1) % MAX_WINDOWS; 
				activeWindow = windows[windowIndex]; 
				wmove(activeWindow,1,1); 
				break; 
			case KEY_NPAGE: 
				windowIndex = (windowIndex - 1 + MAX_WINDOWS) % MAX_WINDOWS;
				activeWindow = windows[windowIndex]; 
				wmove(activeWindow,1,1);
				break; 
		
		}		
		
		wrefresh(activeWindow);
	
	}
	endwin();
	return 0; 

}
