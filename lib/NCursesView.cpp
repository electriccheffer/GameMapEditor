#include <ncurses.h>
#include "../include/NCursesView.hpp"
#include "../include/window_functions.hpp"
#include "../include/NCursesModel.hpp"
/*
 *TODO: Alter constructor for Model based build.  
 *
 *
 * **/
NCursesView::NCursesView(Model models[]){
	
	this->models[0] = models[0]; 
	this->models[1] = models[1]; 
	this->models[2] = models[2]; 

	this->modelMap[typeid(OptionsModel)] = 0; 
	this->modelMap[typeid(DetailsModel)] = 1; 
	this->modelMap[typeid(EditorModel)] = 2; 

	OptionsModel optionsModel = this->models[0];  
	EditorModel editorModel =  this->models[1]; 
	DetailsModel detailsModel =  this->models[2]; 
	
	WINDOW *optionsWindow = create_new_window(optionsModel.getWindowHeight(),
						optionsModel.getWindowWidth(),
						optionsModel.getCursorYPosition(),
						optionsModel.getCursorXPosition()); 
	WINDOW *editorWindow = create_new_window( editorModel.getWindowHeight(),
						editorModel.getWindowWidth(),
						editorModel.getCursorYPosition(),
						editorModel.getCursorXPosition()); 
	WINDOW *detailsWindow = create_new_window(detailsModel.getWindowHeight(),
						detailsModel.getWindowWidth(),
						detailsModel.getCursorYPosition(),
						detailsModel.getCursorXPosition()); 	
	this->windows[0] = optionsWindow; 
	this->windows[1] = editorWindow; 
	this->windows[2] = detailsWindow; 

	for(Model model : this->models){
	
		this->renderModel(model);
	
	}
}

void NCursesView::renderModel(Model& model){

	int windowIndex = modelMap[typeid(model)];
	WINDOW *currentWindow = windows[windowIndex];
	box(currentWindow,0,0);
	mvprintw(currentWindow,model.getWindowDescription()); 
	wmove(currentWindow,model.getCursorXPosition(),model.getCursorYPosition()); 	
	wrefresh(currentWindow); 
}


void NCursesView::updateModel(Model& model){

	int modelIndex = this->modelMap[typeid(model)]; 
	this->models[modelIndex] = model; 
	this->renderModel(this->models[modelIndex]);
}
