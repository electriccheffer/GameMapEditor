#include <ncurses.h>
#include <string>
#include <vector>
#include "../include/NCursesModel.hpp"
#include "../include/TextObject.hpp"

NCursesModel::NCursesModel(){
	this->cursorXStartPosition = 0;
	this->cursorYStartPosition = 0;
	this->windowWidth = 0;
	this->windowHeight = 0; 
	this->cursorXPosition = 0; 
	this->cursorYPosition = 0; 
	this->description = "AbstractClassDoNotInstantiate";
}


unsigned int NCursesModel::getCursorXStartPosition(){

	return this->cursorXStartPosition; 
}

unsigned int NCursesModel::getCursorYStartPosition(){

	return this->cursorYStartPosition;
	
}

unsigned int NCursesModel::getCursorXPosition(){

	return this->cursorXPosition; 
}

unsigned int NCursesModel::getCursorYPosition(){

	return this->cursorYPosition; 
}

unsigned int NCursesModel::getWindowWidth(){
	
	return this->windowWidth; 
}

unsigned int NCursesModel::getWindowHeight(){
	
	return this->windowHeight; 

}

std::string NCursesModel::getWindowDescription(){

	return this->description; 

}

void NCursesModel::setCursorXPosition(unsigned int newCursorXPosition){

	this->cursorXPosition = newCursorXPosition; 
}

void NCursesModel::setCursorYPosition(unsigned int newCursorYPosition){

	this->cursorYPosition = newCursorYPosition; 
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

EditorModel::EditorModel(std::vector<TextObject>& text){

	this->windowWidth = COLS/2; 
	this->windowHeight = LINES / 2; 
	this->description = "Map Editor Box Window";
	this->cursorXStartPosition = 0; 
	this->cursorYStartPosition = 0; 
	this->cursorXPosition = 1; 
	this->cursorYPosition = 1;
	this->text = text; 
}

std::vector<TextObject>& EditorModel::getText(){
	
	return this->text; 
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

OptionsModel::OptionsModel(std::vector<TextObject>& textList){

	this->text = textList; 
	this->windowWidth = COLS/2; 
	this->windowHeight = LINES / 2; 
	this->description = "Options Box Window";
	this->cursorXStartPosition = COLS/2; 
	this->cursorYStartPosition = 0; 
	this->cursorXPosition = 1; 
	this->cursorYPosition = 1;
}

std::vector<TextObject>& OptionsModel::getText(){

	return this->text; 
	
}

DescriptionModel::DescriptionModel(){

	this->windowWidth = COLS; 
	this->windowHeight = LINES/2 ; 
	this->description = "Description Box Window";
	this->cursorXStartPosition = 0 ; 
	this->cursorYStartPosition = LINES/2; 
	this->cursorXPosition = 1; 
	this->cursorYPosition = 1;
}

DescriptionModel::DescriptionModel(std::vector<TextObject>& textList) {


	this->windowWidth = COLS; 
	this->windowHeight = LINES/2 ; 
	this->description = "Description Box Window";
	this->cursorXStartPosition = 0 ; 
	this->cursorYStartPosition = LINES/2; 
	this->cursorXPosition = 1; 
	this->cursorYPosition = 1;
	this->text = textList; 
}

std::vector<TextObject>& DescriptionModel::getText(){

	return this->text; 

}
