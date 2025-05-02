#ifndef OBJECTVIEW_HPP
#define OBJECTVIEW_HPP
#include "../NCursesView.hpp"
#include "./ObjectModel.hpp"


class ObjectEditorRenderView : public NCursesView{

	
	public: 
		ObjectEditorRenderView(ObjectEditorRenderModel* model);
	protected: 
		void renderModel(NCursesModel& model) override;	


};


class ObjectEditorOptionsView : public NCursesView{

	public:
		ObjectEditorOptionsView(ObjectEditorOptionsModel* model);
	protected: 
		void renderModel(NCursesModel& model) override; 	

}; 
#endif
