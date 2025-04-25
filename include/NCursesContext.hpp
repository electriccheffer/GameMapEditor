#ifndef NCURSESCONTEXT_HPP
#define NCURSESCONTEXT_HPP
#include "NCursesController.hpp"

class ControllerContext{

	public:
	        ControllerContext();	
		ControllerContext(OptionsController options,DescriptionController description
				,EditorController editor); 
		Controller& takeInput(int character); 
		
	protected:
	        int getControllerContext(); 	
		int currentControllerContext; 
		Controller controllers[MAX_WINDOWS]; 
}; 

#endif
