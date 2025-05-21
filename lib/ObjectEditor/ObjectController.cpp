#include "../../include/ObjectEditor/ObjectController.hpp"
#include "../../include/ObjectEditor/ObjectView.hpp"
#include "../../include/ObjectEditor/ObjectModel.hpp"
#include <iostream>

ObjectEditorOptionsController::ObjectEditorOptionsController
				(NCursesModel& model,NCursesView& view)
				   :NCursesController(dynamic_cast<NCursesModel&>(model),
				    			dynamic_cast<NCursesView&>(view)){				
}

void ObjectEditorOptionsController::takeInput(int character){
	
	unsigned int moveVariable; 

	switch(character){
	
		case KEY_UP:
			moveVariable = this->model.getCursorXPosition(); 
			moveVariable -= 1; 
			moveVariable %= 6; 
			if(moveVariable == 0){
				
				moveVariable += 1; 
			}
			this->model.setCursorXPosition(moveVariable); 
			break;
		case KEY_DOWN:
			moveVariable = this->model.getCursorXPosition(); 
			moveVariable += 1; 
			moveVariable %= 6; 
			if(moveVariable == 0){
				
				moveVariable += 1; 
			}
			this->model.setCursorXPosition(moveVariable);
			break; 
	
	
	}
	this->view.updateModel(this->model); 	

}

ObjectEditorPaletteController::ObjectEditorPaletteController
				(NCursesModel& model,NCursesView& view)
				:NCursesController(dynamic_cast<NCursesModel&>(model),
				    		   dynamic_cast<NCursesView&>(view)){
				
				
}

void ObjectEditorPaletteController::takeInput(int character){

	unsigned int moveVariable; 

	switch(character){
	
		case KEY_UP:
			moveVariable = this->model.getCursorXPosition(); 
			moveVariable -= 1; 
			moveVariable %= 13; 
			if(moveVariable == 0){
				
				moveVariable += 1; 
			}
			this->model.setCursorXPosition(moveVariable); 
			break;
		case KEY_DOWN:
			moveVariable = this->model.getCursorXPosition(); 
			moveVariable += 1; 
			moveVariable %= 13; 
			if(moveVariable == 0){
				
				moveVariable += 1; 
			}
			this->model.setCursorXPosition(moveVariable);
			break; 
	
	
	}
	this->view.updateModel(this->model); 	
}


ObjectEditorDescriptionController::ObjectEditorDescriptionController(
					ObjectEditorDescriptionModel& model,
					ObjectEditorDescriptionView& view):	
					NCursesController(
						 model,view),model(model),view(view){
				
				
}

void ObjectEditorDescriptionController::takeInput(int character){

	
	// if printable print it 
	if(character >= 32 && character <= 126){

		this->model.addText(character);
	}
	if(character == KEY_BACKSPACE){

		this->model.removeText(); 
	}
	if(character == KEY_DOWN){
		
		this->model.cursorDown(); 	
	}
	if(character == KEY_UP){
	
		this->model.cursorUp(); 	
	}
	this->updateView(); 	

}
