#include <gtest/gtest.h>
#include "../include/NCursesModel.hpp"

TEST(TrivialTest,AlwaysPasses){

	EXPECT_TRUE(true);
}

TEST(OptionsModelTest,GetCursorXPosition){

	OptionsModel model = {}; 
	unsigned int xPosition = model.getCursorXPosition(); 
	EXPECT_EQ(0,xPosition);
}

TEST(OptionsModelTest,GetCursorYPosition){

	OptionsModel model = {}; 
	unsigned int yPosition = model.getCursorYPosition(); 
	EXPECT_EQ(0,yPosition);
}
