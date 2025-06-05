#include "../../include/ObjectEditor/DataStructures.hpp"
#include <vector>
#include "../../include/ObjectEditor/ObjectModel.hpp"

PaletteList::PaletteList(){

	this->list = {}; 
}

std::vector<ObjectEditorDescriptionModel>& PaletteList::getList(){

	return this->list; 

}
