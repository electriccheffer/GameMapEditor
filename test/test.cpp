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

