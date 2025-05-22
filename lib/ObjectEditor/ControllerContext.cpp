#include "../../include/ObjectEditor/ControllerContext.hpp"
#include "../../include/NCursesController.hpp"

ObjectEditorControllerContext::ObjectEditorControllerContext(
					     ObjectEditorOptionsController* options,
			         	     ObjectEditorDescriptionController* description,
					     ObjectEditorPaletteController* palette){

	this->controllers[0] = options; 
	this->controllers[1] = palette; 
	this->controllers[2] = description; 
}

NCursesController* ObjectEditorControllerContext::getContext(){

	return this->controllers[this->currentControllerContext];

}

NCursesController* ObjectEditorControllerContext::takeInput(int character){

	switch(character){
	
		case KEY_PPAGE: 
			this->currentControllerContext++;
			this->currentControllerContext %= 3;
		       	break; 	
		case KEY_NPAGE:
			if(this->currentControllerContext == 0){
				break; 
			}
			this->currentControllerContext--;
		        this->currentControllerContext %= 3;
			break;  
	}
       return this->controllers[this->currentControllerContext]; 	
}
