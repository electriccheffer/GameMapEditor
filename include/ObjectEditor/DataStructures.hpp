#ifndef DATASTRUCTURES_HPP
#define DATASTRUCTURES_HPP
#include <vector>
#include "../../include/ObjectEditor/ObjectModel.hpp"

class PaletteList{
	
	public:
		PaletteList();
		std::vector<ObjectEditorDescriptionModel>& getList(); 
	protected: 
		std::vector<ObjectEditorDescriptionModel> list; 

}; 
#endif 
