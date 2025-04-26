#include "../include/TextObject.hpp"
#include <string>
#include "../include/Position.hpp"

TextObject::TextObject(){

	this->text = ""; 

}

void TextObject::setText(std::string& newText){

	this->text = newText; 
}

const Position& TextObject::getPosition()const{

	return this->position;
}

const std::string TextObject::getText()const{

	return this->text; 

}



