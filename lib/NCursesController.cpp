#include "../include/NCursesController.hpp"
#include <ncurses.h>
#include "../include/NCursesModel.hpp"
#include <memory>
#include "../include/NCursesView.hpp"
#include <utility>
#include <iostream>

NCursesController::NCursesController(NCursesModel& model, NCursesView& view)
	:model(model),view(view){
	this->view = view; 
	this->model = model;	
	this->view.updateModel(model); 
}

void NCursesController::updateView(){
	
	this->view.updateModel(this->model); 
}

OptionsController::OptionsController(OptionsModel& model, OptionsView& view):NCursesController(dynamic_cast<NCursesModel&>(model),dynamic_cast<NCursesView&>(view)){
	

}

void OptionsController::takeInput(int character){
	
	unsigned int moveVariable; 

	switch(character){
	
		case KEY_UP:
			moveVariable = this->model.getCursorXPosition(); 
			moveVariable -= 1; 
			moveVariable %= 5; 
			if(moveVariable == 0){
				
				moveVariable += 1; 
			}
			this->model.setCursorXPosition(moveVariable); 
			break;
		case KEY_DOWN:
			moveVariable = this->model.getCursorXPosition(); 
			moveVariable += 1; 
			moveVariable %= 5; 
			if(moveVariable == 0){
				
				moveVariable += 1; 
			}
			this->model.setCursorXPosition(moveVariable);
			break; 
	
	
	}
	this->view.updateModel(this->model); 	

}


EditorController::EditorController(EditorModel& model, EditorView& view):NCursesController(dynamic_cast<NCursesModel&>(model),dynamic_cast<NCursesView&>(view)){


}
void EditorController::takeInput(int character){

	unsigned int moveVariable; 
	switch(character){
	
		case KEY_UP:
			moveVariable = this->model.getCursorXPosition(); 
			moveVariable -= 1; 
			if(moveVariable == 0){
				
				moveVariable += 1; 
			}
			this->model.setCursorXPosition(moveVariable); 
			break;

		case KEY_DOWN:
			moveVariable = this->model.getCursorXPosition(); 
			moveVariable += 1; 
			if(moveVariable == this->model.getWindowHeight() - 1){
				
				moveVariable -= 1; 
			}
			this->model.setCursorXPosition(moveVariable);
			break; 

		case KEY_RIGHT: 
			 moveVariable = this->model.getCursorYPosition(); 	
			 moveVariable += 1; 
			 if(moveVariable == this->model.getWindowWidth() - 1){
			 	
			 	moveVariable -= 1; 
			 }
			 this->model.setCursorYPosition(moveVariable); 
			 break;

		case KEY_LEFT: 
			 moveVariable = this->model.getCursorYPosition(); 	
			 moveVariable -= 1; 
			 if(moveVariable == 0){
			 	
			 	moveVariable += 1; 
			 }
			 this->model.setCursorYPosition(moveVariable); 
			 break;
	

	}
	this->view.updateModel(this->model); 	
}

DescriptionController::DescriptionController(DescriptionModel& model, DescriptionView& view)
					:NCursesController(dynamic_cast<NCursesModel&>(model),dynamic_cast<NCursesView&>(view)){
}
void DescriptionController::takeInput(int character){

	
	this->view.updateModel(this->model); 	

}
