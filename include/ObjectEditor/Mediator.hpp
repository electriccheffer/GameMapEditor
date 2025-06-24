#ifndef MEDIATOR_HPP
#define MEDIATOR_HPP
#include "ObjectModel.hpp"
#include "DataStructures.hpp"

class ObjectEditorRenderController;
class ObjectEditorPaletteController; 
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

class SaveDescriptionMediator{

	public: 
		SaveDescriptionMediator(PaletteList& paletteList,
					ObjectEditorDescriptionModel& descriptionModel,
					ObjectEditorPaletteController& paletteController,
					ObjectEditorPaletteModel& paletteModel);
		void toColleague();
	protected: 
		PaletteList& paletteList; 
		ObjectEditorDescriptionModel& descriptionModel; 	
		ObjectEditorPaletteModel& paletteModel; 
		ObjectEditorPaletteController& paletteController; 
}; 
#endif
