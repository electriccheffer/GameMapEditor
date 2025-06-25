#include "../../include/ObjectEditor/IO.hpp"
#include "../../include/TextObject.hpp"
#include "../../include/ObjectEditor/ObjectModel.hpp"

void to_json(nlohmann::json& jsonObject, const Position& position){

	jsonObject = {{"xPosition",position.getX()},{"yPosition",position.getY()}}; 
	
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
