#include <gtest/gtest.h>
#include <ncurses.h>
#include "../include/NCursesModel.hpp"

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

TEST(DetailsModelTest,TestConstructorSubclasses){

	DetailsModel model = {}; 
	unsigned int windowWidth = model.getWindowWidth(); 
	unsigned int windowHeight = model.getWindowHeight(); 
	std::string  description = model.getWindowDescription();
	unsigned int cursorXStartPosition = model.getCursorXStartPosition(); 
	unsigned int cursorYStartPosition = model.getCursorYStartPosition(); 
	unsigned int cursorXPosition = model.getCursorXPosition(); 
	unsigned int cursorYPosition = model.getCursorYPosition();
	EXPECT_EQ(windowWidth,COLS); 
	EXPECT_EQ(windowHeight,LINES / 2);
	EXPECT_EQ(description,"Details Box Window");
	EXPECT_EQ(cursorXStartPosition,0); 
	EXPECT_EQ(cursorYStartPosition,LINES/2); 
	EXPECT_EQ(cursorXPosition,1);
	EXPECT_EQ(cursorYPosition,1); 
}; 
