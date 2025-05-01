#ifndef OBJECTFACTORIES_HPP
#define OBJECTFACTORIES_HPP
#include "./OptionsModel.hpp"
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
} 

#endif
