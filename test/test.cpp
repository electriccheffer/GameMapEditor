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
