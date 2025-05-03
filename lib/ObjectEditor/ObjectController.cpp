#include "../../include/ObjectEditor/ObjectController.hpp"
#include "../../include/ObjectEditor/ObjectView.hpp"
#include "../../include/ObjectEditor/ObjectModel.hpp"

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
