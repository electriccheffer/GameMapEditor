#ifndef NCURSESVIEW_HPP
#define NCURSESVIEW_HPP 
#include <ncurses.h>
#include <unordered_map>
#include <typeindex>
#include <memory>
#include "../include/NCursesModel.hpp"

#define MAX_WINDOWS 3

class NCursesView{
	
	public:
	       NCursesView(); 	
	       void recieveCharacter(int character);
	       void updateModel(Model& model); 

	protected: 
		WINDOW *windows[MAX_WINDOWS]; 
		WINDOW windows[MAX_WINDOWS]; 
		std::unordered_map<std::type_index,int> modelMap; 
		Model models[MAX_WINDOWS]; 
		void rewriteScreen(); 
		void renderModel(Model& model);

};
#endif
