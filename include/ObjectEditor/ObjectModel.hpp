#ifndef OBJECTMODEL_HPP
#define OBJECTMODEL_HPP
#include <ncurses>
#include <string>
#include <vector>
#include "../NCursesModel.hpp"


class ObjectEditorModel : NCursesModel{

	
		
};



class ObjectEditorRenderModel : ObjectEditorModel{

	public: 
		ObjectEditorRenderModel();
		ObjectEditorRenderModel(std::vector<TextObject>& text); 
		std::vector<TextObject>& getText(); 
	protected: 	
		std::vector<TextObject> text; 
}

#endif
