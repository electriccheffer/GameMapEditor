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
					ObjectEditorDescriptionModel& descriptionModel):
					paletteList(paletteList),
					descriptionModel(descriptionModel){
										
}

void SaveDescriptionMediator::toColleague(){

	this->paletteList.addModel(this->descriptionModel);
}
