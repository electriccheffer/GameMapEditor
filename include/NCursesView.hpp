#ifndef NCURSESVIEW_HPP
#define NCURSESVIEW_HPP 
#include <ncurses.h>
#include <unordered_map>
#include <typeindex>
#include <memory>
#include <array>
 
#define MAX_WINDOWS 3

class Model;

class NCursesView{
	
	public:
	       NCursesView(){}; 
	       NCursesView(std::array<std::unique_ptr<Model>, 3> models); 	
	       void updateModel(Model& model); 

	protected: 
		WINDOW *windows[MAX_WINDOWS]; 
		std::unordered_map<std::type_index,int> modelMap; 
		std::array<std::unique_ptr<Model>, MAX_WINDOWS> models;
		void renderModel(Model& model);

};
#endif
