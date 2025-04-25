#ifndef NCURSESCONTEXT_HPP
#define NCURSESCONTEXT_HPP
#include "NCursesController.hpp"

class ControllerContext{

	public:
		ControllerContext(); 
		NCursesController& takeInput(int character);
				
	protected:
		void setCurrentController(NCursesController& newCurrentController);
		int currentControllerContext;
	        NCursesController& currentController; 	
		NCursesController& controllers[MAX_WINDOWS]; 
}; 

#endif
