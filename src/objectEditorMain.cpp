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
#include "../include/ObjectEditor/ObjectModel.hpp"
#include "../include/ObjectEditor/Factories.hpp"
#include "../include/ObjectEditor/ObjectView.hpp"
#include "../include/ObjectEditor/ObjectController.hpp"
#include "../include/ObjectEditor/ControllerContext.hpp"
#include <vector>

int main(int argc, char** argv){

	initscr(); 
	cbreak();
        noecho();
	curs_set(2);	
	keypad(stdscr,true); 
	int typedCharacter; 
	refresh(); 
	
	ObjectRenderModelFactory factory = {}; 
	ObjectEditorRenderModel renderModel = factory.getModel(); 
	ObjectEditorRenderView renderView(&renderModel); 
	
	ObjectOptionsModelFactory optionsModelFactory = {}; 
	ObjectEditorOptionsModel optionsModel = optionsModelFactory.getModel(); 
	ObjectEditorOptionsView optionsView(&optionsModel); 
	ObjectEditorOptionsController optionsController = {optionsModel,optionsView}; 

	ObjectPaletteFactory paletteFactory = {}; 
	ObjectEditorPaletteModel paletteModel = paletteFactory.getModel(); 
	ObjectEditorPaletteView paletteView(&paletteModel); 
	ObjectEditorPaletteController paletteController = {paletteModel,paletteView}; 
	
	ObjectDescriptionModelFactory descriptionFactory = {}; 
	ObjectEditorDescriptionModel descriptionModel = descriptionFactory.getModel(); 
	ObjectEditorDescriptionView descriptionView(&descriptionModel);
	ObjectEditorDescriptionController descriptionController = {descriptionModel,
								   descriptionView}; 

	ObjectEditorControllerContext context(&optionsController,&descriptionController,
						&paletteController);
	while(((typedCharacter = getch()) != KEY_F(1))){
		NCursesController* controller = context.takeInput(typedCharacter);
		controller->takeInput(typedCharacter); 
	}
	endwin();
	return 0; 

}

