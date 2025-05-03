#ifndef OBJECTCONTROLLER_HPP
#define OBJECTCONTROLLER_HPP
#include "../NCursesController.hpp"
#include "../../include/ObjectEditor/ObjectController.hpp"
#include "../../include/ObjectEditor/ObjectView.hpp"
#include "../../include/ObjectEditor/ObjectModel.hpp"

class ObjectEditorOptionsController : public NCursesController{

		public: 
			ObjectEditorOptionsController(
					NCursesModel& model, NCursesView& view); 
			void takeInput(int character)override; 
		protected: 
};

class ObjectEditorPaletteController : public NCursesController{


		public: 
			ObjectEditorPaletteController(
						NCursesModel& model, NCursesView& view);
			void takeInput(int character)override; 
};
#endif
