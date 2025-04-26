#ifndef TEXTOBJECT_HPP
#define TEXTOBJECT_HPP
#include <string>
#include "../include/Position.hpp"

class TextObject{
	
	public:
		TextObject(); 
		void setPosition(Position& newPosition);
		void setText(std::string& newText); 
		const std::string& getText()const; 	
		const Position& getPosition()const; 
		bool operator==(const TextObject& otherTextObject);
	protected: 
		std::string text; 
		Position position; 
};
#endif
