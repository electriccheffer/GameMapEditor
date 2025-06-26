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
#include "../include/ObjectEditor/Mediator.hpp"
#include "../include/ObjectEditor/DataStructures.hpp"
#include <vector>
#include <filesystem>

int main(int argc, char** argv){

	initscr();
        start_color();
	use_default_colors(); 	
	cbreak();
        noecho();
	curs_set(2);	
	keypad(stdscr,true); 
	int typedCharacter; 
	refresh(); 
	
	ObjectRenderModelFactory factory = {}; 
	ObjectEditorRenderModel renderModel = factory.getModel(); 
	ObjectEditorRenderView renderView(&renderModel); 
	ObjectEditorRenderController renderController = {renderModel,renderView}; 
	
	ObjectOptionsModelFactory optionsModelFactory = {}; 
	ObjectEditorOptionsModel optionsModel = optionsModelFactory.getModel(); 
	ObjectEditorOptionsView optionsView(&optionsModel); 
	
	PaletteList paletteList = {}; 	
	ObjectPaletteModelFactory paletteFactory = {paletteList}; 
	
	ObjectEditorPaletteModel paletteModel = paletteFactory.getModel(); 
	ObjectEditorPaletteView paletteView(&paletteModel); 
	ObjectEditorPaletteController paletteController = {paletteModel,paletteView}; 
	
	ObjectDescriptionModelFactory descriptionFactory = {}; 
	ObjectEditorDescriptionModel descriptionModel = descriptionFactory.getModel(); 
	ObjectEditorDescriptionView descriptionView(&descriptionModel);
	ObjectEditorDescriptionController descriptionController = {descriptionModel,
								   descriptionView}; 
	RenderDescriptionMediator mediator(descriptionModel,renderController,renderModel);	
	
	SaveDescriptionMediator saveDescriptionMediator(paletteList,descriptionModel,paletteController,paletteModel);		
	
	LoadDescriptionMediator loadDescriptionMediator(paletteModel,descriptionController,descriptionModel,paletteList); 
	
	std::filesystem::path filePath = "./character.json"; 
	Writer writer(filePath);

	ObjectEditorOptionsController optionsController(optionsModel,optionsView,mediator,
				saveDescriptionMediator,loadDescriptionMediator,writer,paletteList); 
	
	ObjectEditorControllerContext context(&optionsController,&descriptionController,
						&paletteController);

	while(((typedCharacter = getch()) != KEY_F(1))){
		NCursesController* controller = context.takeInput(typedCharacter);
		controller->takeInput(typedCharacter); 
	}
	endwin();
	return 0; 

}

