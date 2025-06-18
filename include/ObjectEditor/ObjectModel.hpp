#ifndef OBJECTMODEL_HPP
#define OBJECTMODEL_HPP
#include <ncurses.h>
#include <string>
#include <vector>
#include "../NCursesModel.hpp"

class ObjectEditorModel : public NCursesModel{

	
		
};



class ObjectEditorRenderModel : public ObjectEditorModel{

	public: 
		ObjectEditorRenderModel();
		ObjectEditorRenderModel(std::vector<TextObject>& text); 
		std::vector<TextObject>& getText(); 
		short getBackground(); 
		short getForeground(); 
		char getCharacter();
	        void setBackground(short background);
		void setForeground(short foreground); 
		void setCharacter(char character); 	
	protected: 	
		std::vector<TextObject> text; 
		short foreground; 
		short background;
		char character; 
}; 

class ObjectEditorOptionsModel : public ObjectEditorModel{

	public: 
		ObjectEditorOptionsModel(); 
		ObjectEditorOptionsModel(std::vector<TextObject>& text);
	        std::vector<TextObject>& getText(); 

	protected: 
		std::vector<TextObject> text; 	



};

class ObjectEditorPaletteModel : public ObjectEditorModel{

	public: 
		ObjectEditorPaletteModel(); 
		ObjectEditorPaletteModel(std::vector<TextObject>& text); 
		std::vector<TextObject>& getText()const;
		bool operator==(const ObjectEditorPaletteModel& otherModel)const;	
	protected: 
		std::vector<TextObject> text; 
}; 

class ObjectEditorDescriptionModel : public ObjectEditorModel{

	public: 
		ObjectEditorDescriptionModel(); 
		ObjectEditorDescriptionModel(std::vector<TextObject>& text);
		const std::vector<TextObject>& getText()const;	
		void addText(int character);	
		void removeText();
	        void cursorUp(); 
		void cursorDown(); 	
		bool operator==(const ObjectEditorDescriptionModel& otherModel) const; 
	protected: 
		std::vector<TextObject> text; 
		unsigned int textPosition = 1; 
}; 
#endif
