#include "../include/TextObject.hpp"
#include <string>
#include "../include/Position.hpp"

TextObject::TextObject(){

	this->text = ""; 
}

TextObject::TextObject(std::string& text, Position& position){

	this->text = text; 
	this->position = position; 

}

void TextObject::setPosition(Position& newPosition){
	
	this->position = newPosition; 
}

void TextObject::setText(std::string& newText){

	this->text = newText; 
}

const Position& TextObject::getPosition()const{

	return this->position;
}

const std::string& TextObject::getText()const{

	return this->text; 

}


bool TextObject::operator==(const TextObject& otherTextObject){

	Position otherPosition = otherTextObject.getPosition(); 
	std::string otherText = otherTextObject.getText(); 
	return (otherPosition == this->position && otherText == this->text);

}

bool TextObject::operator!=(const TextObject& otherTextObject){

	return !(*this == otherTextObject);

}
