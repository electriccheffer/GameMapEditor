#include <ncurses.h>
#include "../include/window_functions.hpp"
#include <iostream>

int main(int argc, char** argv){

	initscr(); 
	cbreak();
        noecho();
	curs_set(0);	
	int detailsBoxWidth = COLS; 
	int detailsBoxHeight = LINES / 2; 
	int detailsBoxStartX = 0; 
	int detailsBoxStartY = detailsBoxHeight; 
	int mapEditorBoxWidth = COLS/2; 
	int mapEditorBoxHeight = LINES / 2;
	int mapEditorBoxStartY = 0; 
	int mapEditorBoxStartX = 0;	
	int optionsBoxWidth = mapEditorBoxWidth; 
	int optionsBoxHeight = mapEditorBoxHeight; 
	int optionsBoxStartY = 0; 
	int optionsBoxStartX = COLS / 2; 
	WINDOW *detailsBoxWindow = create_new_window(detailsBoxHeight,detailsBoxWidth,detailsBoxStartY,detailsBoxStartX);
	WINDOW *mapEditorBoxWindow = create_new_window(mapEditorBoxHeight,mapEditorBoxWidth,mapEditorBoxStartY,mapEditorBoxStartX);
	WINDOW *optionsBoxWindow = create_new_window(optionsBoxHeight,optionsBoxWidth,optionsBoxStartY,optionsBoxStartX);
	wgetch(detailsBoxWindow); 
	endwin();
	return 0; 

}
