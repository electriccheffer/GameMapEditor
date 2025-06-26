#include "../../include/ObjectEditor/DataStructures.hpp"
#include <vector>
#include "../../include/ObjectEditor/ObjectModel.hpp"
#include "../../lib/ObjectEditor/Errors.cpp"
#include "../../include/ObjectEditor/Factories.hpp"
PaletteList::PaletteList(){

	this->list = {}; 
}

const std::vector<ObjectEditorDescriptionModel>& PaletteList::getList()const{

	return this->list; 
}

void PaletteList::setList(std::vector<ObjectEditorDescriptionModel>& list){

	this->list =list; 
}

void PaletteList::addModel(ObjectEditorDescriptionModel& model){

	ObjectDescriptionModelFactory factory = {}; 
	ObjectEditorDescriptionModel emptyModel = factory.getModel(); 
	if(model == emptyModel){
	
		throw PaletteListError("PaletteListError: Object is empty"); 
	}
	for(ObjectEditorDescriptionModel localModel : this->list){
	
		if((localModel == model)){
		
			throw PaletteListError(
		 "PaletteListError: Object is already in palette. Remove or chage existing"
		 );

		}
		
	}	

	this->list.push_back(model);
}
