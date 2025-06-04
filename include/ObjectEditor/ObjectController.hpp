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
				 		RenderDescriptionMediator& renderMediator); 
		void takeInput(int character)override; 
	protected: 
		RenderDescriptionMediator& mediator; 
};


class ObjectEditorRenderController : public NCursesController{

	public: 
		ObjectEditorRenderController(NCursesModel& model, NCursesView& view);
		void setModel(ObjectEditorRenderModel model); 
	       void takeInput(int character)override; 	
	protected: 
       		ObjectEditorRenderModel& model; 
 		ObjectEditorRenderView& view; 		
}; 


class ObjectEditorPaletteController : public NCursesController{


		public: 
			ObjectEditorPaletteController(
						NCursesModel& model, NCursesView& view);
			void takeInput(int character)override; 
};

class ObjectEditorDescriptionController : public NCursesController{

		public: 
			ObjectEditorDescriptionController(
					ObjectEditorDescriptionModel& model,
				       	ObjectEditorDescriptionView& view);
			void takeInput(int character)override; 
		protected:
			ObjectEditorDescriptionModel& model; 
			ObjectEditorDescriptionView& view; 
};
#endif
