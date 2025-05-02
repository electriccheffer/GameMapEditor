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
