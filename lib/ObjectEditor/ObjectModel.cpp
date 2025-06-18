#include <ncurses.h>
#include <string>
#include <vector>
#include <iostream>
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
	this->character = '^';
	this->foreground = COLOR_GREEN;
	this->background = COLOR_YELLOW;
	
} 

std::vector<TextObject>& ObjectEditorRenderModel::getText(){

	return this->text; 
}

short ObjectEditorRenderModel::getBackground(){

	return this->background; 
}

short ObjectEditorRenderModel::getForeground(){
	
	return this->foreground;
}

char ObjectEditorRenderModel::getCharacter(){

	return this->character; 
}


void ObjectEditorRenderModel::setBackground(short background){
	
	this->background = background; 
}


void ObjectEditorRenderModel::setForeground(short foreground){

	this->foreground = foreground; 
}


void ObjectEditorRenderModel::setCharacter(char character){
	
	this->character = character; 
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

const std::vector<TextObject>& ObjectEditorPaletteModel::getText()const{

	return this->text;
}

bool ObjectEditorPaletteModel::operator==(const ObjectEditorPaletteModel& otherModel)const{

	std::vector<TextObject> otherText = otherModel.getText(); 
	int otherTextSize = otherText.size(); 
	int thisTextSize = this->text.size(); 
	if(otherTextSize != thisTextSize){
	
		return false; 
	}
	else{
	
		for(int i = 0 ;i < thisTextSize ;i++){
		
			if(this->text[i].getText() != otherText[i].getText()){
			
				return false; 
			}
		
		}
	}
	return true; 
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

const std::vector<TextObject>& ObjectEditorDescriptionModel::getText()const{

	return this->text; 

}

void ObjectEditorDescriptionModel::addText(int character){

	char asCharacter = static_cast<char>(character);
	std::string currentText = this->text[this->textPosition].getText(); 
	int stringLength = currentText.size(); 
	size_t startPosition = currentText.find(':');	
	if(this->cursorYPosition-1 < startPosition){
		return; 
	}
	if(this->cursorYPosition == stringLength){
		currentText += asCharacter;
	}
	else{
		currentText.insert(asCharacter,1,this->cursorYPosition);
	}
	this->cursorYPosition++; 
	this->text[this->textPosition].setText(currentText); 
}

void ObjectEditorDescriptionModel::removeText(){
	std::string currentText = this->text[this->textPosition].getText(); 
	int stringLength = currentText.size(); 
	size_t startPosition = currentText.find(':');
	if(this->cursorYPosition-1 <= startPosition){
		return; 
	}
	currentText.erase(this->cursorYPosition-1);
	this->cursorYPosition--; 
	this->text[this->textPosition].setText(currentText);
}

void ObjectEditorDescriptionModel::cursorUp(){

	this->textPosition -= 1; 
	this->textPosition %= 5; 
	if(this->textPosition == 0 ){
	
		this->textPosition++; 
	}
	std::string localText = this->text[this->textPosition].getText();
        Position position = this->text[this->textPosition].getPosition(); 
	unsigned int newXPosition = position.getX(); 
	unsigned int newYPosition = localText.size();
	this->setCursorYPosition(newYPosition);	
	this->setCursorXPosition(newXPosition);
}

void ObjectEditorDescriptionModel::cursorDown(){
	
	this->textPosition += 1; 
	this->textPosition %= 5; 
	if(this->textPosition == 0 ){
	
		this->textPosition++; 
	}
	
	std::string localText = this->text[this->textPosition].getText();
        Position position = this->text[this->textPosition].getPosition(); 
	unsigned int newXPosition = position.getX(); 
	unsigned int newYPosition = localText.size();
	this->setCursorYPosition(newYPosition);
	this->setCursorXPosition(newXPosition);
}

bool ObjectEditorDescriptionModel::operator==(const ObjectEditorDescriptionModel& otherModel)											const{

	std::vector<TextObject> otherText = otherModel.getText(); 
	int sizeOfText = otherText.size(); 
	for(int i = 0 ; i < sizeOfText ; i++){
	
		if(this->text[i].getText() != otherText[i].getText()){
		
			return false; 
		}	
	
	}
	return true; 
}
