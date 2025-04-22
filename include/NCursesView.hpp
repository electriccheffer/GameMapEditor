#ifndef NCURSESVIEW_HPP
#define NCURSESVIEW_HPP 
#include <ncurses.h>
#define MAX_WINDOWS 3

class NCursesView{
	
	public:
	       NCursesView(); 	
	       void recieveCharacter(int character); 
	protected: 
		WINDOW *editorWindow; 
		WINDOW *optionsWindow; 
		WINDOW *descriptionWindow; 
		WINDOW *activeWindow;
		int detailsBoxWidth = COLS; 
		int detailsBoxHeight = LINES / 2; 
		int detailsBoxStartX = 0; 
		int detailsBoxStartY = detailsBoxHeight; 
		int mapEditorBoxWidth = COLS/2; 
		int mapEditorBoxHeight = LINES / 2;
		int mapEditorBoxStartY = 0; 
		int mapEditorBoxStartX = 0;	
		int optionsBoxWidth = mapEditorBoxWidth; 
		int optionsBoxHeight = mapEditorBoxHeight; 
		int optionsBoxStartY = 0; 
		int optionsBoxStartX = COLS / 2;
		int windowIndex = 0;
	        int borderXPosition = 0; 
		int borderYPosition = 0; 	
		int cursorXPosition = 1; 
		int cursorYPosition = 1; 
		WINDOW *windows[MAX_WINDOWS]; 
	       	void rewriteScreen(); 
};
#endif
