#include "../../include/ObjectEditor/IO.hpp"
#include "../../include/TextObject.hpp"
#include "../../include/ObjectEditor/ObjectModel.hpp"
#include "../../include/ObjectEditor/DataStructures.hpp"

void to_json(nlohmann::json& jsonObject, const Position& position){

	jsonObject = {{"xPosition",position.getX()},{"yPosition",position.getY()}}; 
	
}

void from_json(const nlohmann::json& jsonObject,Position& position){

	position.setX(jsonObject.at("xPosition").get<unsigned int>()); 

	position.setY(jsonObject.at("yPosition").get<unsigned int>()); 
}

void to_json(nlohmann::json& jsonObject, const TextObject& textObject){

	jsonObject = {
			{"text",textObject.getText()},
			{"position",textObject.getPosition()}
	}; 
}

void to_json(nlohmann::json& jsonObject, 
		const ObjectEditorDescriptionModel& descriptionModel){

	jsonObject = descriptionModel.getText(); 
}

void to_json(nlohmann::json& jsonObject,const PaletteList& paletteList){
	
	jsonObject = paletteList.getList(); 
}
