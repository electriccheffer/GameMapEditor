#ifndef NCURSESMODEL_HPP
#define NCURSESMODEL_HPP

class Model{

	public: 
		unsigned int getCursorXPosition();		
	protected: 
		unsigned int cursorXPosition; 

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
