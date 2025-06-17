#ifndef OBJECTFACTORIES_HPP
#define OBJECTFACTORIES_HPP
#include "./ObjectModel.hpp"
#include "../NCursesModel.hpp"
#include "../Factories.hpp"
#include "../TextObject.hpp"
#include "../Position.hpp"
#include "DataStructures.hpp"

class ObjectFactory:public ModelFactory{};

class ObjectRenderModelFactory : public ObjectFactory{


	public: 
		ObjectRenderModelFactory();
		ObjectRenderModelFactory(ObjectEditorDescriptionModel& model);
		ObjectEditorRenderModel& getModel(); 		
	protected: 
		void setStaticText(); 
		char returnCharacter(std::string text);
		short returnColor(std::string text);
		std::string parseLine(std::string text); 
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

class ObjectDescriptionModelFactory : public ObjectFactory{


	public: 
		ObjectDescriptionModelFactory(); 
		ObjectEditorDescriptionModel& getModel(); 
	protected: 
		void setStaticText(); 
		ObjectEditorDescriptionModel model; 

};
#endif
