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

DescriptionModelFactory::DescriptionModelFactory(){

	this->setStaticText(); 
}

DescriptionModel& DescriptionModelFactory::getModel(){
	
	return this->model; 

}

void DescriptionModelFactory::setStaticText(){

	std::string descriptionTitle = "Description Box Window"; 
	Position descriptionPosition = {}; 
	TextObject descriptionTextObject = {descriptionTitle,descriptionPosition}; 
	std::vector<TextObject> descriptionTextList = {};
	descriptionTextList.push_back(descriptionTextObject);
	this->model = {descriptionTextList}; 
}

EditorModelFactory::EditorModelFactory(){

	this->setStaticText(); 

}

EditorModel& EditorModelFactory::getModel(){

	return this->model; 
}

void EditorModelFactory::setStaticText(){

	std::string editorTitle = "Editor Box Window"; 
	Position editorPosition = {}; 
	TextObject editorTextObject = {editorTitle,editorPosition}; 
	std::vector<TextObject> editorTextList = {};
	editorTextList.push_back(editorTextObject);
	this->model = {editorTextList}; 
}
