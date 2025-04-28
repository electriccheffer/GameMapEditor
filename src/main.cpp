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


	std::string descriptionTitle = "Description Box Window"; 
	Position descriptionPosition = {}; 
	TextObject descriptionTextObject = {descriptionTitle,descriptionPosition}; 
	std::vector<TextObject> descriptionTextList = {};
	descriptionTextList.push_back(descriptionTextObject);
	DescriptionModel descriptionModel = {descriptionTextList}; 

	std::string textTitle = "Options Box Window"; 
	std::string saveText = "SAVE"; 
	std::string loadText = "LOAD";
	std::string renderText = "RENDER";
	std::string quitText = "QUIT";
	
	Position titlePosition = {0,0};
	Position savePosition = {1,1};
	Position loadPosition = {2,1};
	Position renderPosition = {3,1};
	Position quitPosition = {4,1};

	TextObject titleObject = {textTitle,titlePosition}; 
	TextObject saveObject = {saveText,savePosition};
	TextObject loadObject = {loadText,loadPosition};
	TextObject renderObject = {renderText,renderPosition}; 
	TextObject quitObject = {quitText,quitPosition}; 
	
	std::vector<TextObject> textObjectList = {}; 
	textObjectList.push_back(titleObject);
	textObjectList.push_back(saveObject);
	textObjectList.push_back(loadObject);
	textObjectList.push_back(renderObject);
	textObjectList.push_back(quitObject);
	
        OptionsModel optionsModel = {textObjectList}; 	
	
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

