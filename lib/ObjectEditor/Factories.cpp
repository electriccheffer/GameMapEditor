#include <string>
#include <vector> 
#include "../NCursesModel.hpp"
#include "../Factories.hpp"
#include "../TextObject.hpp"
#include "../Position.hpp"

ObjectRenderModelFactory::ObjectRenderModelFactory(){

	this->setStaticText(); 

}

ObjectEditorRenderModel& ObjectRenderModelFactory::getModel(){

	return this->model; 

}

void ObjectRenderModelFactory;:setStaticText(){
	
	std::string windowTitle = "Object Render";
	Position position = {}; 
	TextObject title = {windowTitle,position}; 
	std::vector<TextObject> textObjectList = {}; 
	textObjectList.push_back(title);
	this->model = {textObjectList}; 
}
