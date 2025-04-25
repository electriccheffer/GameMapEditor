#ifndef NCURSESVIEW_HPP
#define NCURSESVIEW_HPP 
#include <ncurses.h>
#include <unordered_map>
#include <typeindex>
#include <memory>
#include <array>
 
#define MAX_WINDOWS 3

class NCursesView{
	public:
		NCursesView(Model& model);
		void updateModel(Model& model); 
	protected:
		virtual void renderModel(Model& model) = 0; 	
		WINDOW *window; 	
		Model& model; 
};


class OptionsView : public NCursesView{

	public:
		OptionsView(OptionsModel& model);	
	protected: 
		void renderModel(OptionsModel& model);
	
};

class DescriptionView : public NCursesView{

	public:
		DescriptionView(DescriptionModel& model)	
	protected:
	       void renderModel(DescriptionModel& model); 	
};

class EditorView : public NCursesView{

	public: 
		EditorView(EditorModel& model);
	protected: 
		void renderModel(DescriptionModel& model);
}; 

#endif
