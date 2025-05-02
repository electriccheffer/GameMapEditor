#include <string>
#include <vector> 
#include "../../include/NCursesModel.hpp"
#include "../../include/ObjectEditor/Factories.hpp"
#include "../../include/TextObject.hpp"
#include "../../include/Position.hpp"

ObjectRenderModelFactory::ObjectRenderModelFactory(){

	this->setStaticText(); 

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


ObjectPaletteFactory::ObjectPaletteFactory(){

	this->setStaticText(); 

}

ObjectEditorPaletteModel& ObjectPaletteFactory::getModel(){

	return this->model; 
}

void ObjectPaletteFactory::setStaticText(){
	std::string windowTitle = "Palette"; 
	Position position = {}; 
	TextObject title = {windowTitle,position};	
	std::vector<TextObject> textList = {}; 
	textList.push_back(title);
	this->model = {textList}; 
}
