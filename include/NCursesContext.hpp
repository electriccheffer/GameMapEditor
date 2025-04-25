#ifndef NCURSESCONTEXT_HPP
#define NCURSESCONTEXT_HPP
#include "NCursesController.hpp"
class ControllerContext{

	public:
		ControllerContext(OptionsController* options, EditorController* editor,
				  DescriptionController* description); 
		NCursesController* takeInput(int character);
				
	protected:
		int getControllerContext();
		int currentControllerContext;
		NCursesController* controllers[MAX_WINDOWS]; 
}; 

#endif
