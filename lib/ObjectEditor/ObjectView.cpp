#include "../../include/ObjectEditor/ObjectView.hpp"
#include "../../include/ObjectEditor/ObjectModel.hpp"
#include <ncurses.h>
#include <iostream>

ObjectEditorRenderView::ObjectEditorRenderView(ObjectEditorRenderModel* model):NCursesView(model){
	
	this->renderModel(*model);
	
}


void ObjectEditorRenderView::renderModel(NCursesModel& localModel){
	auto castModel = dynamic_cast<ObjectEditorRenderModel*>(this->model); 
	box(this->window,0, 0); 
	std::vector<TextObject> textList = castModel->getText(); 
	for(auto textObject : textList ){
		
		std::string text = textObject.getText();
		Position textPosition = textObject.getPosition(); 
				mvwprintw(this->window,textPosition.getX() ,
				textPosition.getY() 
				,"%s",text.c_str());


	}
	int height,width; 
	getmaxyx(this->window,height,width);
	init_pair(1,castModel->getForeground(),castModel->getBackground());
	wattron(this->window,COLOR_PAIR(1));
	wattron(this->window,A_BOLD);
	mvwaddch(this->window,height/2,width/2,castModel->getCharacter()); 
	wmove(this->window,castModel->getCursorXPosition(),
		castModel->getCursorYPosition());
	wrefresh(this->window);	
	wattroff (this->window,COLOR_PAIR(1)); 
	wattrset(this->window,A_NORMAL);
}

ObjectEditorOptionsView::ObjectEditorOptionsView(ObjectEditorOptionsModel* model):NCursesView(model){


	this->renderModel(*model); 

}


void ObjectEditorOptionsView::renderModel(NCursesModel& model){

	auto castModel = dynamic_cast<ObjectEditorOptionsModel*>(&model); 
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

ObjectEditorPaletteView::ObjectEditorPaletteView(ObjectEditorPaletteModel* model):NCursesView(model){

	this->renderModel(*model); 	
}

void ObjectEditorPaletteView::renderModel(NCursesModel& model){

	auto castModel = dynamic_cast<ObjectEditorPaletteModel*>(&model); 
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

ObjectEditorDescriptionView::ObjectEditorDescriptionView(ObjectEditorDescriptionModel* model): NCursesView(model){

	this->renderModel(*model);
	
}

void ObjectEditorDescriptionView::renderModel(NCursesModel& model){

	auto castModel = dynamic_cast<ObjectEditorDescriptionModel*>(&model); 
	box(this->window,0, 0); 
	std::vector<TextObject> textList = castModel->getText(); 
	for(auto textObject : textList ){
		
		std::string text = textObject.getText();
		Position textPosition = textObject.getPosition(); 
		wmove(this->window, textPosition.getX(),0);
		wclrtoeol(this->window);
		mvwprintw(this->window,textPosition.getX() ,
			   textPosition.getY() 
			   ,"%s",text.c_str());


	}
	wmove(this->window,castModel->getCursorXPosition(),
		castModel->getCursorYPosition());
	wrefresh(this->window);
}
