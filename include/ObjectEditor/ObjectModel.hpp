#ifndef OBJECTMODEL_HPP
#define OBJECTMODEL_HPP
#include <ncurses.h>
#include <string>
#include <vector>
#include "../NCursesModel.hpp"
#include "./Buffer.hpp"

class ObjectEditorModel : public NCursesModel{

	
		
};



class ObjectEditorRenderModel : public ObjectEditorModel{

	public: 
		ObjectEditorRenderModel();
		ObjectEditorRenderModel(std::vector<TextObject>& text); 
		std::vector<TextObject>& getText(); 
	protected: 	
		std::vector<TextObject> text; 
}; 

class ObjectEditorOptionsModel : public ObjectEditorModel{

	public: 
		ObjectEditorOptionsModel(); 
		ObjectEditorOptionsModel(std::vector<TextObject>& text);
	        std::vector<TextObject>& getText(); 

	protected: 
		std::vector<TextObject> text; 	



};

class ObjectEditorPaletteModel : public ObjectEditorModel{

	public: 
		ObjectEditorPaletteModel(); 
		ObjectEditorPaletteModel(std::vector<TextObject>& text); 
		std::vector<TextObject>& getText();
			
	protected: 
		std::vector<TextObject> text; 
}; 

class ObjectEditorDescriptionModel : public ObjectEditorModel{

	public: 
		ObjectEditorDescriptionModel(); 
		ObjectEditorDescriptionModel(std::vector<TextObject>& text);
		std::vector<TextObject>& getText();	
		void addText(int character);	
		void removeText(); 
	protected: 
		std::vector<TextObject> text; 
}; 
#endif
