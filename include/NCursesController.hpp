#ifndef NCURSESCONTROLLER_HPP
#define NCURSESCONTROLLER_HPP
#define MAX_WINDOWS 3 

class Controller{

	public:
		Controller(); 
		void takeInput(int character);
				
	protected: 
		int currentWindowContext; 
		Model[MAX_WINDOWS] windowModels; 	
		NcursesView view; 
		void updateModel(); 
		void updateView();
	        int getCurrentModel(); 	
}; 

#endif
