#include <ncurses.h>
#include "../include/NCursesView.hpp"
#include "../include/window_functions.hpp"
#include "../include/NCursesModel.hpp"

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
	
	this->rewriteScreen();  
}

void NCursesView::recieveCharacter(int character){

	switch(character){
		
		case KEY_PPAGE:
			this->windowIndex = (this->windowIndex + 1) % MAX_WINDOWS; 
			this->activeWindow = this->windows[this->windowIndex]; 
			break; 
		case KEY_NPAGE: 
			this->windowIndex = (this->windowIndex - 1 + MAX_WINDOWS) % 
						MAX_WINDOWS;
			this->activeWindow = this->windows[this->windowIndex]; 
			break; 
		
	}
	
	this->rewriteScreen(); 	
}

void NCursesView::rewriteScreen(){
		
		box(this->descriptionWindow,0,0);
		box(this->editorWindow,0,0);
		box(this->optionsWindow,0,0);
		
		mvwprintw(this->descriptionWindow,this->borderYPosition,
	       		this->borderXPosition,"Details Box Window"); 
		mvwprintw(this->editorWindow,this->borderYPosition,
			this->borderXPosition,"Map Editor Box Window");
		mvwprintw(this->optionsWindow,this->borderYPosition,
			this->borderXPosition,"Options Box Window");
	
		for(int i = 0 ; i < MAX_WINDOWS ; i++){
		
			if(i == this->windowIndex){
			
				continue; 
			}
			wrefresh(windows[i]); 
		
		}	

		wmove(this->activeWindow,this->cursorXPosition,
			this->cursorYPosition);

		wrefresh(this->activeWindow); 
		
 }


void NCursesView::renderModel(Model& model){


}
