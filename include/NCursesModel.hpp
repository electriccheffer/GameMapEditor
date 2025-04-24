#ifndef NCURSESMODEL_HPP
#define NCURSESMODEL_HPP
#include <ncurses.h>
#include <string>

class Model{

	public:
		Model();
		virtual ~Model() = default; 
		unsigned int getCursorXPosition();		
		unsigned int getCursorYPosition();
		unsigned int getWindowWidth();
		unsigned int getWindowHeight(); 
		void setCursorXPosition(unsigned int newCursorXPosition);
		void setCursorYPosition(unsigned int newCursorYPosition);
		std::string getWindowDescription(); 
	protected:	
		unsigned int cursorXPosition = 1;
	        unsigned int cursorYPosition = 1; 	
		unsigned int windowWidth = 0; 
		unsigned int windowHeight = 0; 
		std::string description; 
}; 


class EditorModel : public Model{

	public: 
			
	protected: 
		unsigned int windowWidth = COLS/2; 
		unsigned int windowHeight = LINES / 2; 
		std::string description = "Map Editor Box Window"; 
};

class OptionsModel : public Model{

	public: 
			
	protected: 
		unsigned int windowWidth = COLS/2; 
		unsigned int windowHeight = LINES / 2; 
		std::string description = "Options Box Window";
};

class DetailsModel : public Model{

	public:
	
	protected: 
		unsigned int windowWidth = COLS; 
		unsigned int windowHeight = LINES / 2; 
		std::string description = "Details Box Window";
};
#endif 
