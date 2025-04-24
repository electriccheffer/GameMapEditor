#include <ncurses.h>
#include "../include/NCursesModel.hpp"
#include "../include/NCursesView.hpp"
#include "../include/window_functions.hpp"
#include <string>
#include <chrono>
#include <thread>
#include <iostream>
/*
 *TODO: Alter constructor for Model based build.  
 *
 *
 * **/
NCursesView::NCursesView(std::array<std::unique_ptr<Model>, 3> models){
	for (int i = 0; i < 3; i++) {
        	this->models[i] = std::move(models[i]);
    	}

	this->modelMap[typeid(OptionsModel)] = 2; 
	this->modelMap[typeid(DetailsModel)] = 0; 
	this->modelMap[typeid(EditorModel)] = 1; 
       	
	OptionsModel* optionsModel = dynamic_cast<OptionsModel*>(this->models[2].get());  
	EditorModel* editorModel =  dynamic_cast<EditorModel*>(this->models[1].get());  
	DetailsModel* detailsModel = dynamic_cast<DetailsModel*>(this->models[0].get());  

	WINDOW *optionsWindow = create_new_window(optionsModel->getWindowHeight(),
						optionsModel->getWindowWidth(),
						optionsModel->getCursorYStartPosition(),
						optionsModel->getCursorXStartPosition()); 
	
	WINDOW *editorWindow = create_new_window( editorModel->getWindowHeight(),
						editorModel->getWindowWidth(),
						editorModel->getCursorYStartPosition(),
						editorModel->getCursorXStartPosition()); 
	
	WINDOW *detailsWindow = create_new_window(detailsModel->getWindowHeight(),
						detailsModel->getWindowWidth(),
						detailsModel->getCursorYStartPosition(),
						detailsModel->getCursorXStartPosition()); 	
		
	this->windows[2] = optionsWindow; 
	this->windows[0] = detailsWindow; 
	this->windows[1] = editorWindow; 
	for(auto& model : this->models){
		this->renderModel(*model);
	}
}

void NCursesView::renderModel(Model& model){

	int windowIndex = modelMap[typeid(model)];
	WINDOW *currentWindow = windows[windowIndex];
	box(currentWindow,0,0);
	mvwprintw(currentWindow,0,0,"%s",model.getWindowDescription().c_str()); 
	wmove(currentWindow,model.getCursorXPosition(),model.getCursorYPosition()); 	
	wrefresh(currentWindow); 
	
}


void NCursesView::updateModel(Model& model){

	int modelIndex = this->modelMap[typeid(model)]; 
	this->models[modelIndex] = std::make_unique<Model>(model); 
	this->renderModel(model);
}
