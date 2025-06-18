#include <iostream>
#include <string>
#include <vector> 
#include "../../include/NCursesModel.hpp"
#include "../../include/ObjectEditor/Factories.hpp"
#include "../../include/TextObject.hpp"
#include "../../include/Position.hpp"
#include "../../include/ObjectEditor/DataStructures.hpp"

ObjectRenderModelFactory::ObjectRenderModelFactory(){

	this->setStaticText(); 

}

ObjectRenderModelFactory::ObjectRenderModelFactory(ObjectEditorDescriptionModel& model){

	std::vector<TextObject> text = model.getText();
	char character = this->returnCharacter(text[2].getText());
	short background = this->returnColor(text[3].getText());
	short foreground = this->returnColor(text[4].getText());

	ObjectRenderModelFactory factory = {}; 
	this->model = factory.getModel(); 
	this->model.setCharacter(character);
	this->model.setBackground(background);
	this->model.setForeground(foreground);
}

char ObjectRenderModelFactory::returnCharacter(std::string text){
	
	std::string field = this->parseLine(text); 
	return field[0]; 
}

short ObjectRenderModelFactory::returnColor(std::string text){
	std::string field = this->parseLine(text);
	//remove spaces 
	std::string trimmed; 
	for(unsigned char character : field){
	
		if(!std::isspace(character)){
		
			trimmed.push_back(std::toupper(character));
		}	
	}
	if(trimmed.find("GREEN") != std::string::npos ){
	
		return COLOR_GREEN; 
	}		
	if(trimmed.find("YELLOW") != std::string::npos){
		return COLOR_YELLOW; 
	}
	if(trimmed.find("BLUE") != std::string::npos){
	
		return COLOR_BLUE;
	}
	if(trimmed.find("RED") != std::string::npos){
	
		return COLOR_RED;
	}
	if(trimmed.find("BLACK") != std::string::npos){
	
		return COLOR_BLACK;
	}
	if(trimmed.find("CYAN") != std::string::npos){
	
		return COLOR_CYAN;
	}
	return COLOR_MAGENTA; 
}

std::string ObjectRenderModelFactory::parseLine(std::string text){
	
	size_t position = text.find(':');
	std::string field = text.substr(position+1,text.size()-1); 
	return field; 
}

ObjectEditorRenderModel& ObjectRenderModelFactory::getModel(){

	return this->model; 

}

void ObjectRenderModelFactory::setStaticText(){
	
	std::string windowTitle = "Object Render";
	Position position = {}; 
	TextObject title = {windowTitle,position}; 
	std::vector<TextObject> textObjectList = {}; 
	textObjectList.push_back(title);
	this->model = {textObjectList}; 
}

ObjectOptionsModelFactory::ObjectOptionsModelFactory(){

	this->setStaticText(); 
}

ObjectEditorOptionsModel& ObjectOptionsModelFactory::getModel(){

	return this->model; 
}

void ObjectOptionsModelFactory::setStaticText(){

	std::string windowTitle = "Options";
	std::string saveOption = "SAVE"; 
	std::string renderOption = "RENDER";
	std::string newOption = "NEW OBJECT";
	std::string loadOption = "LOAD";
	std::string quitOption = "QUIT";

	Position position = {}; 
	Position savePosition = {1,1}; 
	Position renderPosition = {2,1}; 
	Position newPosition = {3,1};
	Position loadPosition = {4,1};
	Position quitPosition = {5,1};

	TextObject title = {windowTitle,position}; 
	TextObject save = {saveOption,savePosition}; 
	TextObject render = {renderOption,renderPosition}; 
	TextObject newObject = {newOption,newPosition}; 
	TextObject load = {loadOption,loadPosition};
	TextObject quit = {quitOption,quitPosition}; 

	std::vector<TextObject> textObjectList = {}; 
	
	textObjectList.push_back(title);
	textObjectList.push_back(save);
	textObjectList.push_back(render);
	textObjectList.push_back(newObject);
	textObjectList.push_back(load);
	textObjectList.push_back(quit);
	this->model = {textObjectList};
}


ObjectPaletteModelFactory::ObjectPaletteModelFactory(){

	this->setStaticText(); 

}

ObjectPaletteModelFactory::ObjectPaletteModelFactory(PaletteList& paletteList){


	this->processPaletteList(paletteList); 
}

void ObjectPaletteModelFactory::processPaletteList(PaletteList& paletteList){
	
	std::vector<ObjectEditorDescriptionModel> modelList = paletteList.getList(); 
	int modelListLength = modelList.size(); 
	
	if(modelListLength == 0){
		return; 	
	}
	else{
		unsigned int palettePosition = 1;
	        std::vector<TextObject> modelText = {}; 	
		std::string windowTitle = "Palette"; 
		Position position = {}; 
		TextObject title = {windowTitle,position};	
		modelText.push_back(title);

		for(unsigned int i = 0 ; i < modelListLength ; i++){
				
			ObjectEditorDescriptionModel descriptionModel = modelList[i]; 	
			std::vector<TextObject> textList = descriptionModel.getText(); 
			TextObject textObject = textList[palettePosition]; 
			std::string text = textObject.getText();
			std::string paletteText = this->extractTitle(text);
			Position textPosition = {0,i+1};
			TextObject paletteTextObject(paletteText,textPosition);
			modelText.push_back(paletteTextObject);	
		}
		this->model = {modelText}; 	
	}

}

std::string ObjectPaletteModelFactory::extractTitle(std::string& text){

	int textStart = 0; 
	int textEnd = text.size(); 
	while(text[textStart] != ':'){
		textStart += 1;
	}
	std::string name = text.substr(textStart,textEnd-1);
	return name; 
}


ObjectEditorPaletteModel& ObjectPaletteModelFactory::getModel(){

	return this->model; 
}

void ObjectPaletteModelFactory::setStaticText(){
	std::string windowTitle = "Palette"; 
	Position position = {}; 
	TextObject title = {windowTitle,position};	
	std::vector<TextObject> textList = {}; 
	textList.push_back(title);
	this->model = {textList}; 
}



ObjectDescriptionModelFactory::ObjectDescriptionModelFactory(){
	
	this->setStaticText(); 
}

ObjectEditorDescriptionModel& ObjectDescriptionModelFactory::getModel(){
	
	return this->model; 
}



void ObjectDescriptionModelFactory::setStaticText(){
	
	std::string windowText = "Palette Description"; 
	Position position = {}; 
	TextObject title = {windowText,position}; 

	std::string nameText = "Name:";
	Position namePosition = {1,0}; 
	TextObject name = {nameText,namePosition}; 

	std::string characterText = "Render Character:";
	Position characterPosition = {3,0}; 
	TextObject character = {characterText,characterPosition}; 
	
	std::string backgroundText = "Background Color:";
	Position backgroundPosition = {5,0}; 	
	TextObject background = {backgroundText,backgroundPosition}; 

	std::string foregroundText = "Foreground Color:";
	Position foregroundPosition = {7,0}; 
	TextObject foreground = {foregroundText,foregroundPosition}; 

	std::vector<TextObject> textList = {};
	textList.push_back(title); 
	textList.push_back(name); 
	textList.push_back(character);
	textList.push_back(background);
	textList.push_back(foreground);
	this->model = {textList};
}
