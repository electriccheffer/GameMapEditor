#ifndef NCURSESCONTROLLER_HPP
#define NCURSESCONTROLLER_HPP
#define MAX_WINDOWS 3 
#include <memory>
#include "NCursesView.hpp"
#include "NCursesModel.hpp"
#include <array>

class NCursesController{

	public:
		virtual ~NCursesController() = default; 
		NCursesController(NCursesModel& model, NCursesView& view);
       	      	virtual void takeInput(int character) = 0;	       
	protected: 
		void updateView(); 
		NCursesModel& model;
		NCursesView& view; 
}; 


class OptionsController : public NCursesController{
	public:
	        OptionsController(OptionsModel& model, OptionsView& view);
       	      	void takeInput(int character) override;	       
	protected: 

		

};

class EditorController : public NCursesController{
	public:
	        EditorController(EditorModel& model, EditorView& view);
       	      	void takeInput(int character) override;	       
	protected: 




}; 

class DescriptionController : public NCursesController{

	public:
	        DescriptionController(DescriptionModel& model, DescriptionView& view);
       	      	void takeInput(int character) override;	       
	protected: 
}; 

#endif
