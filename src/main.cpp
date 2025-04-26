#include <ncurses.h>
#include <iostream>
#include "../include/NCursesView.hpp"
#include <thread>
#include <chrono>
#include "../include/NCursesController.hpp"
#include "../include/NCursesContext.hpp"
#include "../include/NCursesModel.hpp"

int main(int argc, char** argv){

	initscr(); 
	cbreak();
        noecho();
	curs_set(2);	
	keypad(stdscr,true); 
	int typedCharacter; 
	refresh(); 
	
	EditorModel editorModel = {}; 
	OptionsModel optionsModel = {}; 
	DescriptionModel descriptionModel = {}; 

	EditorView editorView(&editorModel); 
	OptionsView optionsView(&optionsModel); 
	DescriptionView descriptionView(&descriptionModel); 

	EditorController editorController(editorModel,editorView); 
	OptionsController optionsController(optionsModel,optionsView);
	DescriptionController descriptionController(descriptionModel,descriptionView); 

	ControllerContext context(&optionsController,&editorController,
				&descriptionController); 
		
	while(((typedCharacter = getch()) != KEY_F(1))){
		NCursesController* controller = context.takeInput(typedCharacter);		
		controller->takeInput(typedCharacter);
	}
	endwin();
	return 0; 

}

