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
       	protected: 
		unsigned int cursorXStartPosition; 
		unsigned int cursorYStartPosition;
		unsigned int cursorXPosition;
		unsigned int cursorYPosition; 
}; 


class EditorModel : public NCursesModel{

	 
};

class OptionsModel : public NCursesModel{

 
};

class DetailsModel : public NCursesModel{
 
};
#endif 
