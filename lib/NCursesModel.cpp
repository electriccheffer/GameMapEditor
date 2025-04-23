#include "../include/NCursesModel.hpp"

Model::Model(){
	this->cursorXPosition = 0;
	this->cursorYPosition = 0;
	this->windowWidth = 0;
	this->windowHeight = 0; 
}

unsigned int Model::getCursorXPosition(){

	return this->cursorXPosition; 
}

unsigned int Model::getCursorYPosition(){

	return this->cursorYPosition; 
}

void Model::setCursorXPosition(unsigned int newCursorXPosition){

	this->cursorXPosition = newCursorXPosition; 
}

void Model::setCursorYPosition(unsigned int newCursorYPosition){

	this->cursorYPosition = newCursorYPosition; 
}

unsigned int Model::getWindowWidth(){
	
	return this->windowWidth; 

}

unsigned int Model::getWindowHeight(){
	
	return this->windowHeight; 

}
