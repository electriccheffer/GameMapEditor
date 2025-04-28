#include "../include/Factories.hpp"
#include "../include/NCursesModel.hpp"

OptionsModelFactory::OptionsModelFactory(){

	this->setStaticText(); 
}

OptionsModel& OptionsModelFactory::getModel(){

	return this->model; 
}

void OptionsModelFactory::setStaticText(){

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
	this->model = {textObjectList}; 
}

