#ifndef IO_HPP
#define IO_HPP
#include "../Position.hpp"
#include "../TextObject.hpp"
#include "ObjectModel.hpp"
#include "DataStructures.hpp"
#include <nlohmann/json.hpp>
#include <filesystem>
#include <string>
#include <fstream>

class Writer{

	public:
	      	Writer(std::filesystem::path& path); 	
		void write(PaletteList& paletteList); 
	protected: 
		std::filesystem::path& path; 		

};

void to_json(nlohmann::json& jsonObject, const Position& position); 

void from_json(const nlohmann::json& jsonObject,Position& position);

void to_json(nlohmann::json& jsonObject, const TextObject& textObject);

void from_json(const nlohmann::json& jsonObject,TextObject& textObject);

void to_json(nlohmann::json& jsonObject, 
		const ObjectEditorDescriptionModel& descriptionModel);

void from_json(const nlohmann::json& jsonObject,ObjectEditorDescriptionModel& model);

void to_json(nlohmann::json& jsonObject,const PaletteList& paletteList); 

void from_json(const nlohmann::json& jsonObject,PaletteList& paletteList);

void write_json_to_file(std::filesystem::path path,nlohmann::json jsonData);

std::string read_json_from_file(std::filesystem::path path);

#endif
