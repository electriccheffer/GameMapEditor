#include <ncurses.h>
#include <string>
#include <vector>
#include <iostream>
#include "../../include/Position.hpp"
#include "../../include/TextObject.hpp"
#include "../../include/ObjectEditor/ObjectModel.hpp"
#include "../../include/ObjectEditor/Buffer.hpp"

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


ObjectEditorPaletteModel::ObjectEditorPaletteModel(){

	this->windowWidth = COLS/2; 
	this->windowHeight = 15;
	this->description = "Palette Model"; 
	this->cursorXStartPosition = this->windowWidth; 
	this->cursorYStartPosition = 7; 
	this->cursorXPosition = 1; 
	this->cursorYPosition = 1;
}

ObjectEditorPaletteModel::ObjectEditorPaletteModel(std::vector<TextObject>& text){

	this->windowWidth = COLS/2; 
	this->windowHeight = 14;
	this->description = "Palette Model"; 
	this->cursorXStartPosition = this->windowWidth; 
	this->cursorYStartPosition = 7; 
	this->cursorXPosition = 1; 
	this->cursorYPosition = 1;
	this->text = text; 
}

std::vector<TextObject>& ObjectEditorPaletteModel::getText(){

	return this->text;
}

ObjectEditorDescriptionModel::ObjectEditorDescriptionModel(){

	this->windowWidth = COLS/2; 
	this->windowHeight = 16;
	this->description = "Palette Model"; 
	this->cursorXStartPosition = LINES/2; 
	this->cursorYStartPosition = 19; 
	this->cursorXPosition = 1; 
	this->cursorYPosition = 1;

}


ObjectEditorDescriptionModel::ObjectEditorDescriptionModel(std::vector<TextObject>& text){

	this->windowWidth = COLS/2; 
	this->windowHeight = 16;
	this->description = "Palette Model"; 
	this->cursorXStartPosition = COLS/2; 
	this->cursorYStartPosition = 21; 
	this->cursorXPosition = 1; 
	this->cursorYPosition = 5;
	this->text = text;

}

std::vector<TextObject>& ObjectEditorDescriptionModel::getText(){

	return this->text; 

}

void ObjectEditorDescriptionModel::addText(int character){

	char asCharacter = static_cast<char>(character);
	std::string currentText = this->text[this->cursorXPosition].getText(); 
	int stringLength = currentText.size(); 
	size_t startPosition = currentText.find(':');	
	if(this->cursorYPosition < startPosition){
		return; 
	}
	if(this->cursorYPosition == stringLength){
		currentText += asCharacter;
	}
	else{
		currentText.insert(asCharacter,1,this->cursorYPosition);
	}
	this->cursorYPosition++; 
	this->text[this->cursorXPosition].setText(currentText); 
}

void ObjectEditorDescriptionModel::removeText(){
	std::string currentText = this->text[this->cursorXPosition].getText(); 
	int stringLength = currentText.size(); 
	size_t startPosition = currentText.find(':');
	if(this->cursorYPosition-1 <= startPosition){
		return; 
	}
	currentText.erase(this->cursorYPosition-1);
	this->cursorYPosition--; 
	this->text[this->cursorXPosition].setText(currentText);
}
