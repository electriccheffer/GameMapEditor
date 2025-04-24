#ifndef NCURSESCONTROLLER_HPP
#define NCURSESCONTROLLER_HPP
#define MAX_WINDOWS 3 
#include <memory>
#include "NCursesView.hpp"
#include "NCursesModel.hpp"
#include <array>

class Controller{

	public:
		Controller(); 
		void takeInput(int character);				
	protected:
	       	int getCurrentModelIndex();
		Model& getCurrentModel(); 
		int currentModelIndex; 
		std::array<std::unique_ptr<Model>,3> models; 			
		void updateView(); 
		NCursesView view; 
}; 

#endif
