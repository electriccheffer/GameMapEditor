#ifndef NCURSESMODEL_HPP
#define NCURSESMODEL_HPP
#include <ncurses.h>

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
	protected: 
		unsigned int cursorXPosition = 0;
	        unsigned int cursorYPosition = 0; 	
		unsigned int windowWidth = 0; 
		unsigned int windowHeight = 0; 
}; 


class EditorModel : public Model{

	public: 
			
	protected: 
		unsigned int windowWidth = COLS/2; 
		unsigned int windowHeight = LINES / 2; 
};

class OptionsModel : public Model{

	public: 
			
	protected: 
		unsigned int windowWidth = COLS/2; 
		unsigned int windowHeight = LINES / 2; 
};

class DetailsModel : public Model{

	public:
	
	protected: 
		unsigned int windowWidth = COLS; 
		unsigned int windowHeight = LINES / 2; 
};
#endif 
