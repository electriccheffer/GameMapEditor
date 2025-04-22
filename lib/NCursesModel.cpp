#include "../include/NCursesModel.hpp"


unsigned int Model::getCursorXPosition(){

	return this->cursorXPosition; 
}

unsigned int Model::getCursorYPosition(){

	return 0; 
}

void Model::setCursorXPosition(unsigned int newCursorXPosition){

	this->cursorXPosition = newCursorXPosition; 
}
