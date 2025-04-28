#ifndef FACTORIES_HPP
#define FACTORIES_HPP
#include "../include/NCursesModel.hpp"

class ModelFactory{}; 

class OptionsModelFactory{

	public:
	       	OptionsModelFactory();	
		OptionsModel& getModel(); 
	protected: 
		void setStaticText(); 	
		OptionsModel model; 

};

class DescriptionModelFactory{};

class EditorModelFactory{};
#endif
