#include "../include/Position.hpp"

Position::Position(){

	this->xPosition = 0; 
	this->yPosition = 0; 
}

unsigned int Position::getX(){
	
	return this->xPosition; 
}

unsigned int Position::getY(){

	return this->yPosition; 
}

void Position::setX(unsigned int newX){

	this->xPosition = newX; 
}

void Position::setY(unsigned int newY){

	this->yPosition = newY; 
}
