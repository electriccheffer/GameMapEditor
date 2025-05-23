#include <gtest/gtest.h>
#include <ncurses.h>
#include "../include/NCursesModel.hpp"
#include "../include/NCursesView.hpp"
#include "../include/NCursesController.hpp"
#include "../include/NCursesContext.hpp"
#include "../include/Position.hpp"
#include "../include/TextObject.hpp"
#include <string>

TEST(TrivialTest,AlwaysPasses){

	EXPECT_TRUE(true);
}

TEST(ModelTest,ConstructorTestCursorXStartPosition){
	
	NCursesModel model = {}; 
	unsigned int cursorXStartPosition = model.getCursorXStartPosition();
        EXPECT_EQ(0,cursorXStartPosition);	
}

TEST(ModelTest,ConstructorTestCursorYStartPosition){

	NCursesModel model = {}; 
	unsigned int cursorYStartPosition = model.getCursorYStartPosition();
        EXPECT_EQ(0,cursorYStartPosition);
}

TEST(ModelTest,ConstructorTestGetCursorXPosition){

	NCursesModel model = {}; 
	unsigned int cursorXPosition = model.getCursorXPosition(); 
	EXPECT_EQ(0,cursorXPosition);
}

TEST(ModelTest,ConstructorTestGetCursorYPosition){

	NCursesModel model = {}; 
	unsigned int cursorYPosition = model.getCursorXPosition(); 
	EXPECT_EQ(0,cursorYPosition);
}

TEST(ModelTest,ConstructorTestSetCursorXPosition){

	NCursesModel model = {}; 
	model.setCursorXPosition(1); 
	unsigned int cursorXPosition = model.getCursorXPosition();  
	EXPECT_EQ(1,cursorXPosition);
}

TEST(ModelTest,ConstructorTestSetCursorYPosition){

	NCursesModel model = {}; 
	model.setCursorYPosition(1); 
	unsigned int cursorYPosition = model.getCursorYPosition();  
	EXPECT_EQ(1,cursorYPosition);
}

TEST(ModelTest,ConstructorTestGetWindowWidth){

	NCursesModel model = {}; 
	unsigned int windowWidth = model.getWindowWidth();  
	EXPECT_EQ(0,windowWidth);
}

TEST(ModelTest,ConstructorTestGetWindowHeight){

	NCursesModel model = {}; 
	unsigned int windowHeight = model.getWindowHeight();  
	EXPECT_EQ(0,windowHeight);
}

TEST(ModelTest,ConstructorTestGetWindowDescription){

	NCursesModel model = {}; 
	std::string description = model.getWindowDescription();  
	EXPECT_EQ("AbstractClassDoNotInstantiate",description);
}

TEST(EditorModelTest,TestConstructorSubclasses){

	EditorModel model = {}; 
	unsigned int windowWidth = model.getWindowWidth(); 
	unsigned int windowHeight = model.getWindowHeight(); 
	std::string  description = model.getWindowDescription();
	unsigned int cursorXStartPosition = model.getCursorXStartPosition(); 
	unsigned int cursorYStartPosition = model.getCursorYStartPosition(); 
	unsigned int cursorXPosition = model.getCursorXPosition(); 
	unsigned int cursorYPosition = model.getCursorYPosition();
	EXPECT_EQ(windowWidth,COLS/2); 
	EXPECT_EQ(windowHeight,LINES / 2);
	EXPECT_EQ(description,"Map Editor Box Window");
	EXPECT_EQ(cursorXStartPosition,0); 
	EXPECT_EQ(cursorYStartPosition,0); 
	EXPECT_EQ(cursorXPosition,1);
	EXPECT_EQ(cursorYPosition,1); 
}

TEST(OptionsModelTest,TestConstructorSubclasses){

	OptionsModel model = {}; 
	unsigned int windowWidth = model.getWindowWidth(); 
	unsigned int windowHeight = model.getWindowHeight(); 
	std::string  description = model.getWindowDescription();
	unsigned int cursorXStartPosition = model.getCursorXStartPosition(); 
	unsigned int cursorYStartPosition = model.getCursorYStartPosition(); 
	unsigned int cursorXPosition = model.getCursorXPosition(); 
	unsigned int cursorYPosition = model.getCursorYPosition();
	EXPECT_EQ(windowWidth,COLS/2); 
	EXPECT_EQ(windowHeight,LINES / 2);
	EXPECT_EQ(description,"Options Box Window");
	EXPECT_EQ(cursorXStartPosition,COLS/2); 
	EXPECT_EQ(cursorYStartPosition,0); 
	EXPECT_EQ(cursorXPosition,1);
	EXPECT_EQ(cursorYPosition,1); 
}

TEST(OptionsModelTest,TextObjectText){

	std::string text = "Options Box Window"; 
	Position position = {};
	TextObject textObject = {text,position};
	std::vector<TextObject> textList = {textObject};
        OptionsModel optionsModel = {textList}; 	
	std::vector<TextObject> textListResult = optionsModel.getText();  		
	EXPECT_TRUE((textListResult[0] == textList[0]));
	
}

TEST(OptionsModelTest,TextObjectMultipleTextObjects){
	
	std::string textTitle = "Options Box Window"; 
	std::string saveText = "SAVE"; 
	std::string loadText = "LOAD";
	std::string renderText = "RENDER";
	std::string quitText = "QUIT";
	
	Position titlePosition = {0,0};
	Position savePosition = {1,1};
	Position loadPosition = {2,1};
	Position renderPosition = {3,1};
	Position quitPosition = {4,1};

	TextObject titleObject = {textTitle,titlePosition}; 
	TextObject saveObject = {saveText,savePosition};
	TextObject loadObject = {loadText,loadPosition};
	TextObject renderObject = {renderText,renderPosition}; 
	TextObject quitObject = {quitText,quitPosition}; 
	
	std::vector<TextObject> textObjectList = {}; 
	textObjectList.push_back(titleObject);
	textObjectList.push_back(saveObject);
	textObjectList.push_back(loadObject);
	textObjectList.push_back(renderObject);
	textObjectList.push_back(quitObject);
	
        OptionsModel optionsModel = {textObjectList}; 	
	
	std::vector<TextObject> textListResult = optionsModel.getText();  		
	EXPECT_TRUE((textListResult[3] == textObjectList[3]));
}

TEST(DetailsModelTest,TestConstructorSubclasses){

	DescriptionModel model = {}; 
	unsigned int windowWidth = model.getWindowWidth(); 
	unsigned int windowHeight = model.getWindowHeight(); 
	std::string  description = model.getWindowDescription();
	unsigned int cursorXStartPosition = model.getCursorXStartPosition(); 
	unsigned int cursorYStartPosition = model.getCursorYStartPosition(); 
	unsigned int cursorXPosition = model.getCursorXPosition(); 
	unsigned int cursorYPosition = model.getCursorYPosition();
	EXPECT_EQ(windowWidth,COLS); 
	EXPECT_EQ(windowHeight,LINES / 2);
	EXPECT_EQ(description,"Description Box Window");
	EXPECT_EQ(cursorXStartPosition,0); 
	EXPECT_EQ(cursorYStartPosition,LINES/2); 
	EXPECT_EQ(cursorXPosition,1);
	EXPECT_EQ(cursorYPosition,1); 
};

TEST(ContextControllerTest,TestGetControllerContext){
	
	EditorModel editorModel = {}; 
	OptionsModel optionsModel = {}; 
	DescriptionModel descriptionModel = {}; 
	
	EditorView editorView(&editorModel); 
	OptionsView optionsView(&optionsModel); 
	DescriptionView descriptionView(&descriptionModel); 
	
	EditorController editorController = {editorModel,editorView}; 
	OptionsController optionsController = {optionsModel,optionsView}; 
	DescriptionController descriptionController = {descriptionModel,descriptionView};

	ControllerContext context(&optionsController,&editorController,&descriptionController); 

	NCursesController* controllerResult = context.takeInput(KEY_PPAGE);

	EditorController* editorControlleResult = 
		dynamic_cast<EditorController*>(controllerResult); 
	
	EXPECT_EQ(typeid(*editorControlleResult),typeid(EditorController));


}

TEST(PositionObjectTest,GetPosition){

	Position position = {}; 
	unsigned int xPosition = position.getX();
	unsigned int yPosition = position.getY();
	EXPECT_EQ(0,xPosition); 
	EXPECT_EQ(0,yPosition); 

}

TEST(PositionObjectTest,SetPosition){

	Position position = {}; 
	unsigned int xPosition = 1; 
	unsigned int yPosition = 2; 
	position.setX(xPosition);
	position.setY(yPosition); 
	unsigned int xResult = position.getX();
	unsigned int yResult = position.getY(); 
	EXPECT_EQ(xResult,xPosition);
	EXPECT_EQ(yResult,yPosition);
}

TEST(PositionObjectTest,EqualityOperatorTrue){

	Position position = {}; 
	Position otherPosition = {}; 
	EXPECT_TRUE((position == otherPosition));

}

TEST(PositionObjectTest,EqualityOperatorFalse){

	Position position = {}; 
	Position otherPosition = {}; 
	otherPosition.setX(1); 
	EXPECT_FALSE((position == otherPosition));
}

TEST(PositionObjectTest,NonEqualityOperatorFalse){

	Position position = {}; 
	Position otherPosition = {}; 
	EXPECT_FALSE((position != otherPosition));

}

TEST(PositionObjectTest,NonEqualityOperatorTrue){
	
	Position position = {}; 
	position.setX(1); 
	Position otherPosition = {}; 
	EXPECT_TRUE((position != otherPosition));
}

TEST(PositionObjectTest,NonNullConstruct){

	Position position = {1,2}; 
	EXPECT_EQ(1,position.getX());
	EXPECT_EQ(2,position.getY());
}

TEST(TextObjectTest,GetTextTestEmptyString){

	TextObject textObject = {}; 
	std::string text = textObject.getText(); 
	EXPECT_EQ("",text);
	
}

TEST(TextObjectTest,GetPositionTest){

	TextObject textObject = {}; 
	Position expectedPosition = {}; 
	Position positionResult = textObject.getPosition(); 
	EXPECT_TRUE((expectedPosition == positionResult));
}

TEST(TextObjectTest,SetTextTest){
	
	std::string newText = "New Text"; 
	TextObject textObject = {}; 
	textObject.setText(newText);
	std::string textResult = textObject.getText(); 
	EXPECT_EQ(newText,textResult);

}

TEST(TextObjectTest,SetPositionTest){

	Position newPosition = {1,2}; 
	TextObject textObject = {};
        textObject.setPosition(newPosition);	
	Position positionResult = textObject.getPosition(); 
	EXPECT_TRUE((newPosition == positionResult));	

}


TEST(TextObjectTest,EqualityOperatorTestTrue){

	TextObject textObject = {}; 
	TextObject otherTextObject = {}; 
	EXPECT_TRUE((textObject == otherTextObject));
}

TEST(TextObjectTest,EqualityOperatorTestFalse){

	std::string newText = "NewText"; 
	TextObject textObject = {}; 
	textObject.setText(newText);
	TextObject otherTextObject = {}; 
	EXPECT_FALSE((textObject == otherTextObject));
}


TEST(TextObjectTest,NonNullConstructorTest){

	Position position = {1,2};
	std::string text = "SomeText"; 
	TextObject textObject = {text,position}; 
	EXPECT_TRUE((position == textObject.getPosition() ));
	EXPECT_TRUE((text == textObject.getText()));
}

TEST(TextObjectTest,NonEqualityOperatorNotEqual){
	
	std::string text = "SomeText";	
	Position position = {1,2}; 
	TextObject textObject = {text,position}; 
	TextObject otherTextObject = {}; 
	EXPECT_TRUE((textObject != otherTextObject)); 
}

TEST(TextObjectTest,NonEqualityOperatorEqual){
	
	TextObject textObject = {}; 
	TextObject otherTextObject = {}; 
	EXPECT_FALSE((textObject != otherTextObject)); 
}

