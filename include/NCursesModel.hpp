#ifndef NCURSESMODEL_HPP
#define NCURSESMODEL_HPP
#include <ncurses.h>
#include <string>

class NCursesModel{

	public:
		NCursesModel(); 
		unsigned int getCursorXStartPosition(); 
		unsigned int getCursorYStartPosition(); 
		unsigned int getCursorXPosition(); 
		unsigned int getCursorYPosition();
	        unsigned int getWindowWidth(); 	
		void setCursorXPosition(unsigned int newCursorXPosition); 
		void setCursorYPosition(unsigned int newCursorYPosition); 
       	protected: 
		unsigned int cursorXStartPosition; 
		unsigned int cursorYStartPosition;
		unsigned int cursorXPosition;
		unsigned int cursorYPosition;
	       	unsigned int windowWidth; 	
}; 


class EditorModel : public NCursesModel{

	 
};

class OptionsModel : public NCursesModel{

 
};

class DetailsModel : public NCursesModel{
 
};
#endif 
