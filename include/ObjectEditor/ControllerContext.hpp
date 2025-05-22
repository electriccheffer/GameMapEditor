#ifndef CONTROLLERCONTEXT_HPP
#define CONTROLLERCONTEXT_HPP
#include "ObjectController.hpp"
#include "../NCursesController.hpp"

class ObjectEditorControllerContext{

	public:
	       ObjectEditorControllerContext(ObjectEditorOptionsController* options,
			         	     ObjectEditorDescriptionController* description,
					     ObjectEditorPaletteController* palette);
		NCursesController* getContext();        	        
		NCursesController* takeInput(int character);

	protected: 
	        int currentControllerContext = 0; 
		NCursesController* controllers[MAX_WINDOWS]; 
};
#endif
