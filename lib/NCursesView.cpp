#include <ncurses.h>
#include "../include/NCursesModel.hpp"
#include "../include/NCursesView.hpp"
#include "../include/window_functions.hpp"
#include <string>
#include <chrono>
#include <thread>
#include <iostream>

NCursesView::NCursesView(NCursesModel* model):model(model){
	
	this->window = create_new_window(model->getWindowHeight(),
					model->getWindowWidth(),
					 model->getCursorYStartPosition(),
					 model->getCursorXStartPosition()); 
	
}

void NCursesView::updateModel(NCursesModel& model){
	
	this->model = &model; 
	this->renderModel(model);

}

OptionsView::OptionsView(OptionsModel* model):NCursesView(model){

	this->renderModel(*model); 

}

void OptionsView::renderModel(NCursesModel& model){
	
	auto castModel = dynamic_cast<OptionsModel*>(&model);
	box(this->window,0,0); 
	mvwprintw(this->window,0,0,"%s",castModel->getWindowDescription().c_str());
	wmove(this->window,castModel->getCursorXStartPosition(),
			    castModel->getCursorYStartPosition()); 
	wrefresh(this->window);
}

DescriptionView::DescriptionView(DescriptionModel* model):NCursesView(model){

	this->renderModel(*model); 
}

void DescriptionView::renderModel(NCursesModel& model){
	auto castModel = dynamic_cast<DescriptionModel*>(&model); 
	box(this->window,0,0); 
	mvwprintw(this->window,0,0,"%s",castModel->getWindowDescription().c_str());
	wmove(this->window,castModel->getCursorXStartPosition(),
			    castModel->getCursorYStartPosition()); 
	wrefresh(this->window);
}

EditorView::EditorView(EditorModel* model):NCursesView(model){


	this->renderModel(*model); 


}

void EditorView::renderModel(NCursesModel& model){

	auto castModel = dynamic_cast<EditorModel*>(&model);
	box(this->window,0,0); 
	mvwprintw(this->window,0,0,"%s",castModel->getWindowDescription().c_str());
	wmove(this->window,castModel->getCursorXStartPosition(),
			    castModel->getCursorYStartPosition()); 
	wrefresh(this->window);
}
