#include <ncurses.h>
#include "../include/NCursesModel.hpp"
#include "../include/NCursesView.hpp"
#include "../include/window_functions.hpp"
#include "../include/Position.hpp"
#include "../include/TextObject.hpp"
#include <string>
#include <chrono>
#include <thread>
#include <iostream>
#include <vector>

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


// abstract method that does rendering

OptionsView::OptionsView(OptionsModel* model):NCursesView(model){

	this->renderModel(*model); 

}

void OptionsView::renderModel(NCursesModel& model){
		
	auto castModel = dynamic_cast<OptionsModel*>(&model);
	box(this->window,0, 0); 
	std::vector<TextObject> textList = castModel->getText(); 
	for(auto textObject : textList ){
		
		std::string text = textObject.getText();
		Position textPosition = textObject.getPosition(); 
				mvwprintw(this->window,textPosition.getX() ,
				textPosition.getY() 
				,"%s",text.c_str());


	}
	wmove(this->window,castModel->getCursorXPosition(),
		castModel->getCursorYPosition());
	wrefresh(this->window);
	 
}

DescriptionView::DescriptionView(DescriptionModel* model):NCursesView(model){

	this->renderModel(*model); 
}

void DescriptionView::renderModel(NCursesModel& model){
	auto castModel = dynamic_cast<DescriptionModel*>(&model); 
	box(this->window,0,0); 
	mvwprintw(this->window,0,0,"%s",castModel->getWindowDescription().c_str());
	wmove(this->window,castModel->getCursorXPosition(),
			    castModel->getCursorYPosition()); 
	wrefresh(this->window);
}

EditorView::EditorView(EditorModel* model):NCursesView(model){


	this->renderModel(*model); 


}

void EditorView::renderModel(NCursesModel& model){

	auto castModel = dynamic_cast<EditorModel*>(&model);
	box(this->window,0,0); 
	mvwprintw(this->window,0,0,"%s",castModel->getWindowDescription().c_str());
	wmove(this->window,castModel->getCursorXPosition(),
			    castModel->getCursorYPosition()); 
	wrefresh(this->window);
}
