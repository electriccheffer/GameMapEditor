#ifndef OBJECTFACTORIES_HPP
#define OBJECTFACTORIES_HPP
#include "./ObjectModel.hpp"
#include "../NCursesModel.hpp"
#include "../Factories.hpp"
#include "../TextObject.hpp"
#include "../Position.hpp"

class ObjectFactory:public ModelFactory{};

class ObjectRenderModelFactory : public ObjectFactory{


	public: 
		ObjectRenderModelFactory();
		ObjectEditorRenderModel& getModel(); 		
	protected: 
		void setStaticText(); 
		ObjectEditorRenderModel model;		
}; 

class ObjectOptionsModelFactory : public ObjectFactory{

	public:
		ObjectOptionsModelFactory();
		ObjectEditorOptionsModel& getModel(); 
	protected: 
		void setStaticText(); 
		ObjectEditorOptionsModel model; 
}; 

class ObjectPaletteFactory : public ObjectFactory{


	public: 
		ObjectPaletteFactory(); 
		ObjectEditorPaletteModel& getModel(); 
	protected: 
		void setStaticText();
		ObjectEditorPaletteModel model; 
}; 
#endif
