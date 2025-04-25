#include "../include/NCursesContext.hpp"
#include "../include/NCursesController.hpp"

ControllerContext::ControllerContext(OptionsController* options, EditorController* editor,
				  DescriptionController* description) {

	this->currentControllerContext = 0; 
	this->controllers[0] = options; 
	this->controllers[1] = editor;
	this->controllers[2] = description;
}

int ControllerContext::getControllerContext(){

	return this->currentControllerContext; 

}

NCursesController* ControllerContext::takeInput(int character){

	switch(character){
	
		case KEY_PPAGE:
			this->currentControllerContext = (this->currentControllerContext + 1)
			       			% MAX_WINDOWS; 
			break; 
	
		case KEY_NPAGE:
			this->currentControllerContext = (this->currentControllerContext - 1
				       			  + MAX_WINDOWS) % MAX_WINDOWS; 
			break; 

	}	
	
       return controllers[this->currentControllerContext]; 	
}
