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
