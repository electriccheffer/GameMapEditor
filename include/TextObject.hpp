#ifndef TEXTOBJECT_HPP
#define TEXTOBJECT_HPP
#include <string>

class TextObject{
	
	public:
		TextObject(); 
		std::string getText(); 	
	protected: 
		std::string text; 
};
#endif
