#ifndef TESTSUBCLASSES_HPP
#define TESTSUBCLASSES_HPP
#include "../include/NCursesController.hpp"
#include "../include/NCursesModel.hpp"
#include "../include/NCursesContext.hpp"
#include "../include/ObjectEditor/Factories.hpp"
#include "../include/ObjectEditor/ObjectModel.hpp"
#include "../include/ObjectEditor/Buffer.hpp"

class TestDescriptionModel : public ObjectEditorDescriptionModel{

	public: 
		TestDescriptionModel(std::vector<TextObject> text):
			    			ObjectEditorDescriptionModel(text){} 
		InputBuffer& getBuffer(); 	

}; 
#endif
