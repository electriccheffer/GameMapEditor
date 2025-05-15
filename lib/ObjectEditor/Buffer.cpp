#include "../../include/ObjectEditor/Buffer.hpp"
#include <vector>
#include "../../lib/ObjectEditor/Errors.cpp"

InputBuffer::InputBuffer(){}

InputBuffer::InputBuffer(std::vector<int>& rawBuffer):rawBuffer(rawBuffer){}

std::vector<int>& InputBuffer::getBuffer(){
	
	return this->rawBuffer; 
}

void InputBuffer::setBuffer(std::vector<int>& newBuffer){

	this->rawBuffer = newBuffer; 
}

void InputBuffer::addCharacter(int newCharacter){

	this->rawBuffer.push_back(newCharacter); 
}

void InputBuffer::addCharacter(unsigned int location, int newCharacter){
	if(location >= this->rawBuffer.size()){
		throw InputBufferException("InputBufferError: index out of bounds");
	}
	this->rawBuffer[location] = newCharacter; 
}
