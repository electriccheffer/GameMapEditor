#ifndef NCURSESMODEL_HPP
#define NCURSESMODEL_HPP
#include <ncurses.h>
#include <string>

class NCursesModel{

	public:
		NCursesModel(); 
		unsigned int getCursorXStartPosition(); 
		unsigned int getCursorYStartPosition(); 
       	protected: 
		unsigned int cursorXStartPosition; 
		unsigned int cursorYStartPosition;
}; 


class EditorModel : public NCursesModel{

	 
};

class OptionsModel : public NCursesModel{

 
};

class DetailsModel : public NCursesModel{
 
};
#endif 
