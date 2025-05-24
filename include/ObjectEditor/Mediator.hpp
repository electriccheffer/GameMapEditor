#ifndef MEDIATOR_HPP
#define MEDIATOR_HPP
#include "ObjectController.hpp"
#include "ObjectModel.hpp"

class RenderDescriptionMediator{

	public:
	protected:
		ObjectEditorDescriptionModel& descriptionModel; 
		ObjectEditorRenderController& renderController; 
}; 
#endif
