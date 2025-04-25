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
}

void NCursesController::updateView(){
	
	this->view.updateModel(this->model); 
}

void OptionsController::takeInput(int character){}

void EditorController::takeInput(int character){}

void DescriptionController::takeInput(int character){}
