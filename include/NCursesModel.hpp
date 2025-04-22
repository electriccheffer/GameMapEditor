#ifndef NCURSESMODEL_HPP
#define NCURSESMODEL_HPP

class Model{

	public: 
		unsigned int getCursorXPosition();		
		unsigned int getCursorYPosition();
		void setCursorXPosition(unsigned int newCursorXPosition);
	protected: 
		unsigned int cursorXPosition = 0;
	        unsigned int cursorYPosition; 	

}; 


class EditorModel : public Model{

	public: 
			
	protected: 

};

class OptionsModel : public Model{

	public: 
			
	protected: 

};

class DetailsModel : public Model{

	public:
	
	protected: 

};
#endif 
