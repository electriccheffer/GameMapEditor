#ifndef IO_HPP
#define IO_HPP
#include "../Position.hpp"
#include "../TextObject.hpp"
#include <nlohmann/json.hpp>

void to_json(nlohmann::json& jsonObject, const Position& position); 
void to_json(nlohmann::json& jsonObject, const TextObject& textObject);
#endif
