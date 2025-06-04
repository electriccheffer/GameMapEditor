#ifndef MEDIATOR_HPP
#define MEDIATOR_HPP
#include "ObjectModel.hpp"

class ObjectEditorRenderController;

class RenderDescriptionMediator{

	public:
		RenderDescriptionMediator(ObjectEditorDescriptionModel& model,
					  ObjectEditorRenderController& controller);
		void toColleague(); 
	protected:
		ObjectEditorDescriptionModel& descriptionModel; 
		ObjectEditorRenderController& renderController; 
}; 
#endif
