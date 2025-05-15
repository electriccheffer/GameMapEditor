#include "../../include/ObjectEditor/Buffer.hpp"
#include <vector>

InputBuffer::InputBuffer(){}

InputBuffer::InputBuffer(std::vector<int>& rawBuffer):rawBuffer(rawBuffer){}

std::vector<int>& InputBuffer::getBuffer(){
	
	return this->rawBuffer; 
}

void InputBuffer::setBuffer(std::vector<int>& newBuffer){

	this->rawBuffer = newBuffer; 

}
