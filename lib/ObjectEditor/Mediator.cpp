#include "../../include/ObjectEditor/Mediator.hpp"
#include "../../include/ObjectEditor/ObjectModel.hpp"
#include "../../include/ObjectEditor/ObjectController.hpp"
#include "../../include/ObjectEditor/Factories.hpp"
#include <iostream>
RenderDescriptionMediator::RenderDescriptionMediator(ObjectEditorDescriptionModel& model,
						  ObjectEditorRenderController& controller,
						  ObjectEditorRenderModel& renderModel):
						  descriptionModel(model),
						  renderController(controller),
						  renderModel(renderModel){


}

void RenderDescriptionMediator::toColleague(){
	ObjectRenderModelFactory factory = {this->descriptionModel};
	this->renderModel = factory.getModel(); 
	this->renderController.setModel(this->renderModel); 

}

SaveDescriptionMediator::SaveDescriptionMediator(PaletteList& paletteList,
					ObjectEditorDescriptionModel& descriptionModel,
					ObjectEditorPaletteController& paletteController,
					ObjectEditorPaletteModel& paletteModel):
					paletteList(paletteList),
					descriptionModel(descriptionModel),
					paletteController(paletteController),
					paletteModel(paletteModel){
										
}

void SaveDescriptionMediator::toColleague(){

	this->paletteList.addModel(this->descriptionModel);
	ObjectPaletteModelFactory factory = {this->paletteList}; 
	this->paletteModel = factory.getModel(); 
	this->paletteController.setModel(this->paletteModel);
	
}

LoadDescriptionMediator::LoadDescriptionMediator(ObjectEditorPaletteModel& paletteModel, 
				ObjectEditorDescriptionController& descriptionController,
				ObjectEditorDescriptionModel& descriptionModel,
				PaletteList& paletteList):
				paletteModel(paletteModel),
				descriptionController(descriptionController),
				descriptionModel(descriptionModel),
				paletteList(paletteList){

}

void LoadDescriptionMediator::toColleague(){

	std::vector<ObjectEditorDescriptionModel> modelList = this->paletteList.getList(); 
	unsigned int paletteModelIndex = this->paletteModel.getCursorXPosition() - 1 ;
	this->descriptionModel = modelList[paletteModelIndex]; 
	this->descriptionController.setModel(this->descriptionModel);	
}


