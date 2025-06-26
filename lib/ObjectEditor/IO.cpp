#include <fstream>
#include <string>
#include <filesystem>
#include <iostream>
#include <sstream>
#include "../../include/ObjectEditor/IO.hpp"
#include "../../include/TextObject.hpp"
#include "../../include/ObjectEditor/ObjectModel.hpp"
#include "../../include/ObjectEditor/DataStructures.hpp"


Writer::Writer(std::filesystem::path& path):path(path){}

void Writer::write(PaletteList& paletteList){
	
	nlohmann::json jsonPalette; 
	to_json(jsonPalette,paletteList); 
	write_json_to_file(this->path,jsonPalette); 

}

Reader::Reader(std::filesystem::path& path):path(path){}

PaletteList Reader::read(){
	
	std::string fileJson = read_json_from_file(this->path); 
	nlohmann::json jsonObject = nlohmann::json::parse(fileJson);
        PaletteList newPalette; 
	from_json(jsonObject,newPalette);
	return newPalette; 	
}

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

void from_json(const nlohmann::json& jsonObject,TextObject& textObject){

	Position position = jsonObject.at("position").get<Position>(); 
	std::string text = jsonObject.at("text").get<std::string>();
	textObject.setText(text);
	textObject.setPosition(position);

}

void to_json(nlohmann::json& jsonObject, 
		const ObjectEditorDescriptionModel& descriptionModel){

	jsonObject = descriptionModel.getText(); 
}


void from_json(const nlohmann::json& jsonObject,
		ObjectEditorDescriptionModel& descriptionModel){

	std::vector<TextObject> textList = jsonObject.get<std::vector<TextObject>>(); 
	descriptionModel.setText(textList);  
}

void to_json(nlohmann::json& jsonObject,const PaletteList& paletteList){
	
	jsonObject = paletteList.getList(); 
}

void from_json(const nlohmann::json& jsonObject,PaletteList& palette){
	
	std::vector<ObjectEditorDescriptionModel> modelList = jsonObject.
					get<std::vector<ObjectEditorDescriptionModel>>(); 
	palette.setList(modelList);
	
}


void write_json_to_file(std::filesystem::path path, nlohmann::json jsonData){
	
	std::ofstream jsonFile(path); 
	std::string jsonDump = jsonData.dump(); 
	jsonFile << jsonDump; 
	jsonFile.close(); 
}

std::string read_json_from_file(std::filesystem::path path){

	std::ifstream jsonInFile(path);
	std::ostringstream jsonStringStream; 
	jsonStringStream << jsonInFile.rdbuf();
	std::string jsonString; 
	jsonString = jsonStringStream.str(); 
	return jsonString; 
}
