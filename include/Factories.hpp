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

class DescriptionModelFactory{
	public:
		DescriptionModelFactory();
		DescriptionModel& getModel(); 
	protected: 
		void setStaticText(); 
		DescriptionModel model; 
};

class EditorModelFactory{

	public:
		EditorModelFactory(); 
		EditorModel& getModel(); 
	protected:
		void setStaticText(); 
		EditorModel model; 
};
#endif
