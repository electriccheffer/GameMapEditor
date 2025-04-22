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
