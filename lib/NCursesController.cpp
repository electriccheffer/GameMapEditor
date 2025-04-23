#include "../include/NCursesController.hpp"
#include <ncurses.h>

Controller::Controller(){

	this->currentModelIndex = 0; 		

}


void Controller::takeInput(int character){
	
	switch(character){
	
		case KEY_PPAGE:
			this->currentModelIndex = (this->currentModelIndex + 1)
			       			% MAX_WINDOWS; 
			break; 
	
		case KEY_NPAGE:
			this->currentModelIndex = (this->currentModelIndex - 1 + MAX_WINDOWS)
						  % MAX_WINDOWS; 
			break; 

	}	

}


int Controller::getCurrentModelIndex(){

	return this->currentModelIndex; 

}
