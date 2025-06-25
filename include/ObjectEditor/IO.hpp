#ifndef IO_HPP
#define IO_HPP
#include "../Position.hpp"
#include "../TextObject.hpp"
#include "ObjectModel.hpp"
#include "DataStructures.hpp"
#include <nlohmann/json.hpp>

void to_json(nlohmann::json& jsonObject, const Position& position); 

void from_json(const nlohmann::json& jsonObject,Position& position);

void to_json(nlohmann::json& jsonObject, const TextObject& textObject);

void from_json(const nlohmann::json& jsonObject,TextObject& textObject);

void to_json(nlohmann::json& jsonObject, 
		const ObjectEditorDescriptionModel& descriptionModel);

void from_json(const nlohmann::json& jsonObject,ObjectEditorDescriptionModel& model);

void to_json(nlohmann::json& jsonObject,const PaletteList& paletteList); 

void from_json(const nlohmann::json& jsonObject,PaletteList& paletteList);
#endif
