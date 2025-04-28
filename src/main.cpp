#include <ncurses.h>
#include <iostream>
#include "../include/NCursesView.hpp"
#include <thread>
#include <chrono>
#include "../include/NCursesController.hpp"
#include "../include/NCursesContext.hpp"
#include "../include/NCursesModel.hpp"
#include "../include/Position.hpp"
#include "../include/TextObject.hpp"
#include "../include/Factories.hpp"
#include <vector>

int main(int argc, char** argv){

	initscr(); 
	cbreak();
        noecho();
	curs_set(2);	
	keypad(stdscr,true); 
	int typedCharacter; 
	refresh(); 
	
	std::string editorTitle = "Editor Box Window"; 
	Position editorPosition = {}; 
	TextObject editorTextObject = {editorTitle,editorPosition}; 
	std::vector<TextObject> editorTextList = {};
	editorTextList.push_back(editorTextObject);
	EditorModel editorModel = {editorTextList}; 


	DescriptionModelFactory descriptionFactory = {}; 	
	DescriptionModel descriptionModel = descriptionFactory.getModel(); 
	
	OptionsModelFactory optionsFactory = {}; 
	OptionsModel optionsModel = optionsFactory.getModel(); 	
	
	EditorView editorView(&editorModel); 
	DescriptionView descriptionView(&descriptionModel); 
	OptionsView optionsView(&optionsModel); 
	
	EditorController editorController(editorModel,editorView); 
	DescriptionController descriptionController(descriptionModel,descriptionView); 
	OptionsController optionsController(optionsModel,optionsView);
	
	ControllerContext context(&optionsController,&editorController,
				&descriptionController); 
		
	while(((typedCharacter = getch()) != KEY_F(1))){
		NCursesController* controller = context.takeInput(typedCharacter);		
		controller->takeInput(typedCharacter);
	}
	endwin();
	return 0; 

}

