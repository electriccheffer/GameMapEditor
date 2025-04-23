#include "../include/NCursesController.hpp"
#include <ncurses.h>
#include "../include/NCursesModel.hpp"
#include <memory>

Controller::Controller(){

	this->currentModelIndex = 0; 		

	this->models[0] = std::make_unique<OptionsModel>();  
	this->models[1] = std::make_unique<DetailsModel>();
	this->models[2] = std::make_unique<EditorModel>();
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

Model& Controller::getCurrentModel(){


	return *this->models[this->getCurrentModelIndex()]; 
}
