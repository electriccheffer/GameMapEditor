#include <ncurses.h>
#include "../include/NCursesModel.hpp"
#include <string>
 
NCursesModel::NCursesModel(){
	this->cursorXStartPosition = 0;
	this->cursorYStartPosition = 0;
//	this->windowWidth = 0;
//	this->windowHeight = 0; 
//	this->cursorXPosition = 0; 
//	this->cursorYPosition = 0; 
}


unsigned int NCursesModel::getCursorXStartPosition(){

	return this->cursorXStartPosition; 
}

unsigned int NCursesModel::getCursorYStartPosition(){

	return this->cursorYStartPosition;
	
}

/**
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

std::string Model::getWindowDescription(){

	return this->description; 

}

EditorModel::EditorModel(){

	this->windowWidth = COLS/2; 
	this->windowHeight = LINES / 2; 
	this->description = "Map Editor Box Window";
	this->cursorXStartPosition = 0; 
	this->cursorYStartPosition = 0; 
	this->cursorXPosition = 1; 
	this->cursorYPosition = 1;
}

OptionsModel::OptionsModel(){

	this->windowWidth = COLS/2; 
	this->windowHeight = LINES / 2; 
	this->description = "Options Box Window";
	this->cursorXStartPosition = COLS/2; 
	this->cursorYStartPosition = 0; 
	this->cursorXPosition = 1; 
	this->cursorYPosition = 1;
}

DetailsModel::DetailsModel(){

	this->windowWidth = COLS; 
	this->windowHeight = LINES/2 ; 
	this->description = "Details Box Window";
	this->cursorXStartPosition = 0 ; 
	this->cursorYStartPosition = LINES/2; 
	this->cursorXPosition = 1; 
	this->cursorYPosition = 1;
}
**/

