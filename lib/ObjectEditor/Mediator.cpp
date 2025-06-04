#include "../../include/ObjectEditor/Mediator.hpp"
#include "../../include/ObjectEditor/ObjectModel.hpp"
#include "../../include/ObjectEditor/ObjectController.hpp"
#include "../../include/ObjectEditor/Factories.hpp"
#include <iostream>

RenderDescriptionMediator::RenderDescriptionMediator(ObjectEditorDescriptionModel& model,
						  ObjectEditorRenderController& controller):
						  descriptionModel(model),
						  renderController(controller){


}

void RenderDescriptionMediator::toColleague(){
	ObjectRenderModelFactory factory = {this->descriptionModel};
	ObjectEditorRenderModel renderModel = factory.getModel(); 
	this->renderController.setModel(renderModel); 

}
