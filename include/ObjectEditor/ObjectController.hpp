#ifndef OBJECTCONTROLLER_HPP
#define OBJECTCONTROLLER_HPP
#include "../NCursesController.hpp"
#include "../../include/ObjectEditor/ObjectController.hpp"
#include "../../include/ObjectEditor/ObjectView.hpp"
#include "../../include/ObjectEditor/ObjectModel.hpp"
#include "Mediator.hpp"

class ObjectEditorOptionsController : public NCursesController{

	public: 
		ObjectEditorOptionsController(NCursesModel& model, NCursesView& view,
				 		RenderDescriptionMediator& renderMediator,
					SaveDescriptionMediator& saveDescriptionMediator,
					LoadDescriptionMediator& loadDescriptionMediator); 
		void takeInput(int character)override; 
	protected: 
		RenderDescriptionMediator& mediator; 
		SaveDescriptionMediator& saveDescriptionMediator;
	        LoadDescriptionMediator& loadDescriptionMediator; 	
};


class ObjectEditorRenderController : public NCursesController{

	public: 
		ObjectEditorRenderController(NCursesModel& model, NCursesView& view);
	        void takeInput(int character)override; 	
	protected: 
       		ObjectEditorRenderModel& model; 
 		ObjectEditorRenderView& view; 		
}; 


class ObjectEditorPaletteController : public NCursesController{


	public: 
		ObjectEditorPaletteController(NCursesModel& model, NCursesView& view);
		void takeInput(int character)override;
	        void setModel(ObjectEditorPaletteModel& model); 	
	protected: 
		ObjectEditorPaletteModel& model; 
		ObjectEditorPaletteView& view; 
};

class ObjectEditorDescriptionController : public NCursesController{

	public: 
		ObjectEditorDescriptionController(ObjectEditorDescriptionModel& model,ObjectEditorDescriptionView& view);
		void takeInput(int character)override; 
	protected:
		ObjectEditorDescriptionModel& model; 
		ObjectEditorDescriptionView& view; 
};
#endif
