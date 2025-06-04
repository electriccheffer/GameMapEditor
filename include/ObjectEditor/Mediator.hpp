#ifndef MEDIATOR_HPP
#define MEDIATOR_HPP
#include "ObjectModel.hpp"

class ObjectEditorRenderController;

class RenderDescriptionMediator{

	public:
		RenderDescriptionMediator(ObjectEditorDescriptionModel& model,
					  ObjectEditorRenderController& controller,
					  ObjectEditorRenderModel& renderModel);
		void toColleague(); 
	protected:
		ObjectEditorDescriptionModel& descriptionModel; 
		ObjectEditorRenderController& renderController; 
		ObjectEditorRenderModel& renderModel; 
}; 
#endif
