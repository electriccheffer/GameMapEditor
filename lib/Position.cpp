#include "../include/Position.hpp"

Position::Position(){

	this->xPosition = 0; 
	this->yPosition = 0; 
}

unsigned int Position::getX()const{
	
	return this->xPosition; 
}

unsigned int Position::getY()const{

	return this->yPosition; 
}

void Position::setX(unsigned int newX){

	this->xPosition = newX; 
}

void Position::setY(unsigned int newY){

	this->yPosition = newY; 
} 


bool Position::operator==(const Position& otherPosition){

	unsigned int otherX = otherPosition.getX(); 
	unsigned int otherY = otherPosition.getY();
	return (otherX == this->getX() && otherY == this->getY()) ? true : false; 	
}

bool Position::operator!=(const Position& otherPosition){

	return !(*this == otherPosition); 	

}
