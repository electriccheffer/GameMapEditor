#include <ncurses.h>
#include "../include/NCursesModel.hpp"
#include "../include/NCursesView.hpp"
#include "../include/window_functions.hpp"
#include <string>
/*
 *TODO: Alter constructor for Model based build.  
 *
 *
 * **/
NCursesView::NCursesView(std::array<std::unique_ptr<Model>, 3> models){
	
	for (int i = 0; i < 3; ++i) {
        	this->models[i] = std::move(models[i]);
    	}


	this->modelMap[typeid(OptionsModel)] = 0; 
	this->modelMap[typeid(DetailsModel)] = 1; 
	this->modelMap[typeid(EditorModel)] = 2; 

	OptionsModel* optionsModel = dynamic_cast<OptionsModel*>(models[0].get());  
	EditorModel* editorModel =  dynamic_cast<EditorModel*>(models[1].get());  
	DetailsModel* detailsModel = dynamic_cast<DetailsModel*>(models[2].get());  
	
	WINDOW *optionsWindow = create_new_window(optionsModel->getWindowHeight(),
						optionsModel->getWindowWidth(),
						optionsModel->getCursorYPosition(),
						optionsModel->getCursorXPosition()); 
	WINDOW *editorWindow = create_new_window( editorModel->getWindowHeight(),
						editorModel->getWindowWidth(),
						editorModel->getCursorYPosition(),
						editorModel->getCursorXPosition()); 
	WINDOW *detailsWindow = create_new_window(detailsModel->getWindowHeight(),
						detailsModel->getWindowWidth(),
						detailsModel->getCursorYPosition(),
						detailsModel->getCursorXPosition()); 	
	this->windows[0] = optionsWindow; 
	this->windows[1] = editorWindow; 
	this->windows[2] = detailsWindow; 

	for(auto& model : this->models){
	
		this->renderModel(*model);
	
	}
}

void NCursesView::renderModel(Model& model){

	int windowIndex = modelMap[typeid(model)];
	WINDOW *currentWindow = windows[windowIndex];
	box(currentWindow,0,0);
	wprintw(currentWindow,model.getWindowDescription().c_str()); 
	wmove(currentWindow,model.getCursorXPosition(),model.getCursorYPosition()); 	
	wrefresh(currentWindow); 
}


void NCursesView::updateModel(Model& model){

	int modelIndex = this->modelMap[typeid(model)]; 
	this->models[modelIndex] = std::make_unique<Model>(model); 
	this->renderModel(model);
}
