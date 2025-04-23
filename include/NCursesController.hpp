#ifndef NCURSESCONTROLLER_HPP
#define NCURSESCONTROLLER_HPP
#define MAX_WINDOWS 3 
#include "../include/NCursesModel.hpp"
#include <memory>

class Controller{

	public:
		Controller(); 
		void takeInput(int character);				
	protected:
	       	int getCurrentModelIndex();
		Model& getCurrentModel(); 
		int currentModelIndex; 
		std::unique_ptr<Model> models[MAX_WINDOWS]; 			
}; 

#endif
