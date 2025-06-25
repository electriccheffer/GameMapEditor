#ifndef DATASTRUCTURES_HPP
#define DATASTRUCTURES_HPP
#include <vector>
#include "../../include/ObjectEditor/ObjectModel.hpp"

class PaletteList{
	
	public:
		PaletteList();
		const std::vector<ObjectEditorDescriptionModel>& getList()const; 
		void addModel(ObjectEditorDescriptionModel& model);
	protected: 
		std::vector<ObjectEditorDescriptionModel> list; 

}; 
#endif 
