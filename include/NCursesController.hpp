#ifndef NCURSESCONTROLLER_HPP
#define NCURSESCONTROLLER_HPP
#define MAX_WINDOWS 3 
#include <memory>
#include "NCursesView.hpp"
#include "NCursesModel.hpp"
#include <array>

class NCursesController{

	public:
	        NCursesController(NCursesModel& model, NCursesView& view);
       	      	virtual void takeInput(int character) = 0;	       
	protected: 
		NCursesModel model;
		NCursesView view; 
}; 


class OptionsController : public Controller{
	public:
	        OptionsController(OptionsModel& model, OptionsView& view);
       	      	void takeInput(int character) override;	       
	protected: 

		

};

class EditorController : public Controller{
	public:
	        EditorController(EditorModel& model, EditorView& view);
       	      	void takeInput(int character) override;	       
	protected: 




}; 

class DescriptionController : public Controller{

	public:
	        DescriptionController(DescriptionModel& model, DescriptionView& view);
       	      	void takeInput(int character) override;	       
	protected: 
}; 

#endif
