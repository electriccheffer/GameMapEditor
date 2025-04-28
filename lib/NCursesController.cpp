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

	this->view.updateModel(this->model); 	

}


EditorController::EditorController(EditorModel& model, EditorView& view):NCursesController(dynamic_cast<NCursesModel&>(model),dynamic_cast<NCursesView&>(view)){


}
void EditorController::takeInput(int character){


	this->view.updateModel(this->model); 	

}

DescriptionController::DescriptionController(DescriptionModel& model, DescriptionView& view)
					:NCursesController(dynamic_cast<NCursesModel&>(model),dynamic_cast<NCursesView&>(view)){
}
void DescriptionController::takeInput(int character){


	this->view.updateModel(this->model); 	

}
