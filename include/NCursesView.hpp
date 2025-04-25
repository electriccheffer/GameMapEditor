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
		NCursesView(NCursesModel* model);
		virtual ~NCursesView() = default; 
		void updateModel(NCursesModel& model); 
	protected:
		virtual void renderModel(NCursesModel& model) = 0; 	
		WINDOW *window; 	
		NCursesModel* model; 
};


class OptionsView : public NCursesView{

	public:
		OptionsView(OptionsModel* model);	
	protected: 
		void renderModel(NCursesModel& model) override;
	
};

class DescriptionView : public NCursesView{

	public:
		DescriptionView(DescriptionModel* model);
	protected:
	       void renderModel(NCursesModel& model)override; 	
};

class EditorView : public NCursesView{

	public: 
		EditorView(EditorModel* model);
	protected: 
		void renderModel(NCursesModel& model)override;
}; 

#endif
