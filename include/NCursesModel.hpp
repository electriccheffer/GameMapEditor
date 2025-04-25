#ifndef NCURSESMODEL_HPP
#define NCURSESMODEL_HPP
#include <ncurses.h>
#include <string>

class NCursesModel{

	public:
		NCursesModel(); 
		virtual ~NCursesModel() = default; 
		unsigned int getCursorXStartPosition(); 
		unsigned int getCursorYStartPosition(); 
		unsigned int getCursorXPosition(); 
		unsigned int getCursorYPosition();
	        unsigned int getWindowWidth(); 	
		unsigned int getWindowHeight(); 
		std::string getWindowDescription(); 
		void setCursorXPosition(unsigned int newCursorXPosition); 
		void setCursorYPosition(unsigned int newCursorYPosition); 
       	protected: 
		unsigned int cursorXStartPosition; 
		unsigned int cursorYStartPosition;
		unsigned int cursorXPosition;
		unsigned int cursorYPosition;
	       	unsigned int windowWidth; 	
		unsigned int windowHeight; 
		std::string description; 
}; 


class EditorModel : public NCursesModel{
	
	public: 
		EditorModel();  
};

class OptionsModel : public NCursesModel{
	
	public: 
		OptionsModel(); 
 
};

class DescriptionModel : public NCursesModel{
	public: 
	       	DescriptionModel(); 	
};
#endif 
