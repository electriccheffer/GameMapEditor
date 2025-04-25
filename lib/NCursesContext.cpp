#include "../include/NCursesContext.hpp"

ControllerContext::ControllerContext(){

	this->currentControllerContext = 0; 

}

int ControllerContext::getControllerContext(){

	return this->currentControllerContext; 

}

NCursesController& ControllerContext::takeInput(int character){

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
	
       return *controllers[this->currentControllerContext]; 	
}
