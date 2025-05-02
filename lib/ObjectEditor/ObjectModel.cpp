#include <ncurses.h>
#include <string>
#include <vector>
#include "../../include/Position.hpp"
#include "../../include/TextObject.hpp"
#include "../../include/ObjectEditor/ObjectModel.hpp"

ObjectEditorRenderModel::ObjectEditorRenderModel(){

	this->windowWidth = COLS/2; 
	this->windowHeight = LINES;
	this->description = "Render Model"; 
	this->cursorXStartPosition = 0; 
	this->cursorYStartPosition = 0; 
	this->cursorXPosition = 1; 
	this->cursorYPosition = 1; 

}


ObjectEditorRenderModel::ObjectEditorRenderModel(std::vector<TextObject>& text){
	
	this->windowWidth = COLS/2; 
	this->windowHeight = LINES;
	this->description = "Render Model"; 
	this->cursorXStartPosition = 0; 
	this->cursorYStartPosition = 0; 
	this->cursorXPosition = 1; 
	this->cursorYPosition = 1; 
	this->text = text; 
}

std::vector<TextObject>& ObjectEditorRenderModel::getText(){

	return this->text; 
}


ObjectEditorOptionsModel::ObjectEditorOptionsModel(){

	this->windowWidth = COLS/2; 
	this->windowHeight = LINES;
	this->description = "Options Model"; 
	this->cursorXStartPosition = 0; 
	this->cursorYStartPosition = 0; 
	this->cursorXPosition = 1; 
	this->cursorYPosition = 1; 
}

ObjectEditorOptionsModel::ObjectEditorOptionsModel(std::vector<TextObject>& text){

	this->windowWidth = COLS/2; 
	this->windowHeight = 7;
	this->description = "Options Model"; 
	this->cursorXStartPosition = this->windowWidth; 
	this->cursorYStartPosition = 0; 
	this->cursorXPosition = 1; 
	this->cursorYPosition = 1;
	this->text = text; 
}

std::vector<TextObject>& ObjectEditorOptionsModel::getText(){
	
	return this->text; 

}
