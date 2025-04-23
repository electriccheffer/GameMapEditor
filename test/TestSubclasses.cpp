#include "TestSubclasses.hpp"
#include "../include/NCursesModel.hpp"
#include <memory>

int ControllerTestSubclass::getCurrentModelIndexTestAccess(){

	return this->getCurrentModelIndex(); 	
}

Model& ControllerTestSubclass::getCurrentModelTestAccess(){

	return this->getCurrentModel(); 
}
