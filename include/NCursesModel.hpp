#ifndef NCURSESMODEL_HPP
#define NCURSESMODEL_HPP
#include <ncurses.h>
#include <string>

class NCursesModel{

	public:
		NCursesModel(); 
		unsigned int getCursorXStartPosition(); 
       	protected: 
		unsigned int cursorXStartPosition; 
}; 


class EditorModel : public NCursesModel{

	 
};

class OptionsModel : public NCursesModel{

 
};

class DetailsModel : public NCursesModel{
 
};
#endif 
