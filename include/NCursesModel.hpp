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
		unsigned int cursorXPosition;
	        unsigned int cursorYPosition; 	
		unsigned int windowWidth; 
		unsigned int windowHeight; 
		std::string description; 
}; 


class EditorModel : public Model{

	public: 
		EditorModel(); 			
	protected: 
		 
};

class OptionsModel : public Model{

	public: 
		OptionsModel(); 	
	protected: 
};

class DetailsModel : public Model{

	public:
		DetailsModel(); 	
	protected: 
};
#endif 
