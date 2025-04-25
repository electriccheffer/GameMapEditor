#include <ncurses.h>
#include "../include/NCursesModel.hpp"
#include "../include/NCursesView.hpp"
#include "../include/window_functions.hpp"
#include <string>
#include <chrono>
#include <thread>
#include <iostream>

NCursesView::NCursesView(Model& model){
	
	this->model = model; 
	this->*optionsWindow = create_new_window(this->model.getWindowHeight(),
						 this->model.getWindowWidth(),
						 this->model.getCursorYStartPosition(),
						 this->model.getCursorXStartPosition()); 
	this->renderModel(this->model); 	
	
}

void NCursesView::updateModel(Model& model){
	
	this->model = model; 
	this->renderModel(model);
}

OptionsView::OptionsView(OptionsModel& model):NCursesView(model){}

void OptionsView::renderModel(OptionsModel& model){
	
	box(this->window,0,0); 
	mvprintw(this->window,0,0,this->model.getWindowDescription().c_str());
	wmove(this->window,this->model.getCursorXStartPosition(),
			    this->model.getCursorYStartPosition()); 
	wrefresh(this->window);
}

DescriptionView::DescriptionView(DescriptionModel& model):NCursesView(model){}

void DescriptionView::renderModel(DescriptionModel& model){

	box(this->window,0,0); 
	mvprintw(this->window,0,0,this->model.getWindowDescription().c_str());
	wmove(this->window,this->model.getCursorXStartPosition(),
			    this->model.getCursorYStartPosition()); 
	wrefresh(this->window);
}

EditorView::EditorView(EditorModel& model):NCursesView(model){}

void EditorView::renderModel(EditorModel& model){

	box(this->window,0,0); 
	mvprintw(this->window,0,0,this->model.getWindowDescription().c_str());
	wmove(this->window,this->model.getCursorXStartPosition(),
			    this->model.getCursorYStartPosition()); 
	wrefresh(this->window);
}
