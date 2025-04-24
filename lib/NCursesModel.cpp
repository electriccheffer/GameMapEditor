#include <ncurses.h>
#include "../include/NCursesModel.hpp"
#include <string>
 
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

std::string Model::getWindowDescription(){

	return this->description; 

}

EditorModel::EditorModel(){

	this->windowWidth = COLS/2; 
	this->windowHeight = LINES / 2; 
	this->description = "Map Editor Box Window";
	this->cursorXPosition = 1; 
	this->cursorYPosition = 1; 
}

OptionsModel::OptionsModel(){

	this->windowWidth = COLS/2; 
	this->windowHeight = LINES / 2; 
	this->description = "Options Box Window";
	this->cursorXPosition = 1; 
	this->cursorYPosition = 1; 
}

DetailsModel::DetailsModel(){

	this->windowWidth = COLS; 
	this->windowHeight = LINES / 2; 
	this->description = "Details Box Window";
	this->cursorXPosition = 1; 
	this->cursorYPosition = 1; 
}
