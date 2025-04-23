#ifndef TESTSUBCLASSES_HPP
#define TESTSUBCLASSES_HPP
#include "../include/NCursesController.hpp"
#include "../include/NCursesModel.hpp"
#include <memory>

class ControllerTestSubclass : public Controller{

	public: 
		int getCurrentModelIndexTestAccess(); 		
		Model& getCurrentModelTestAccess(); 
	protected:
}; 
#endif
