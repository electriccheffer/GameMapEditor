#include "TestSubclasses.hpp"
#include "../include/NCursesModel.hpp"
#include "./TestSubclasses.hpp"
#include "../include/ObjectEditor/Buffer.hpp"
#include <memory>


InputBuffer& TestDescriptionModel::getBuffer(){
	
	return this->buffer; 
}
