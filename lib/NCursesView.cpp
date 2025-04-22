#include <ncurses.h>
#include "../include/NCursesView.hpp"
#include "../include/window_functions.hpp"

NCursesView::NCursesView(){

	this->descriptionWindow = create_new_window(this->detailsBoxHeight,
				  this->detailsBoxWidth,this->detailsBoxStartY,
				  this->detailsBoxStartX);
	this->editorWindow = create_new_window(this->mapEditorBoxHeight,
					       this->mapEditorBoxWidth,
					       this->mapEditorBoxStartY,
					       this->mapEditorBoxStartX);
	this->optionsWindow = create_new_window(this->optionsBoxHeight,this->optionsBoxWidth,
				   		this->optionsBoxStartY,
						this->optionsBoxStartX);
	windows[0] = this->descriptionWindow; 
	windows[1] = this->editorWindow; 
	windows[2] = this->optionsWindow; 
	this->activeWindow = this->optionsWindow; 
}

void NCursesView::recieveCharacter(char character){

	switch(character){
		
		case KEY_PPAGE:
			this->windowIndex = (this->windowIndex + 1) % MAX_WINDOWS; 
			this->activeWindow = this->windows[this->windowIndex]; 
			wmove(this->activeWindow,this->cursorXPosition,
				this->cursorYPosition); 
			break; 
		case KEY_NPAGE: 
			this->windowIndex = (this->windowIndex - 1 + MAX_WINDOWS) % 
						MAX_WINDOWS;
			this->activeWindow = this->windows[this->windowIndex]; 
			wmove(this->activeWindow,this->cursorXPosition,
				this->cursorYPosition);
			break; 
		
	}
	
	wrefresh(this->activeWindow); 
}
