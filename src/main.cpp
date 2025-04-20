#include <ncurses.h>
#include "../include/window_functions.hpp"
#include <iostream>


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
	curs_set(0);	
	initializeWindowVariables(); 
	WINDOW *detailsBoxWindow = create_new_window(detailsBoxHeight,detailsBoxWidth,detailsBoxStartY,detailsBoxStartX);
	WINDOW *mapEditorBoxWindow = create_new_window(mapEditorBoxHeight,mapEditorBoxWidth,mapEditorBoxStartY,mapEditorBoxStartX);
	WINDOW *optionsBoxWindow = create_new_window(optionsBoxHeight,optionsBoxWidth,optionsBoxStartY,optionsBoxStartX);
	wgetch(detailsBoxWindow); 
	endwin();
	return 0; 

}
