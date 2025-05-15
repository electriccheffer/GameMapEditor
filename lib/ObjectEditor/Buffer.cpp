#include "../../include/ObjectEditor/Buffer.hpp"
#include <vector>

InputBuffer::InputBuffer(){}

std::vector<int>& InputBuffer::getBuffer(){
	
	return this->rawBuffer; 
}
