#include "../../include/ObjectEditor/ObjectView.hpp"
#include "../../include/ObjectEditor/ObjectModel.hpp"

ObjectEditorRenderView::ObjectEditorRenderView(ObjectEditorRenderModel* model):NCursesView(model){
	
	this->renderModel(*model);

}


void ObjectEditorRenderView::renderModel(NCursesModel& model){

	auto castModel = dynamic_cast<ObjectEditorRenderModel*>(&model); 
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
				mvwprintw(this->window,textPosition.getX() ,
				textPosition.getY() 
				,"%s",text.c_str());


	}
	wmove(this->window,castModel->getCursorXPosition(),
		castModel->getCursorYPosition());
	wrefresh(this->window);
	

}
