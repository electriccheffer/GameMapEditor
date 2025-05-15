#include <gtest/gtest.h>
#include <ncurses.h>
#include <vector>
#include "../include/ObjectEditor/Buffer.hpp"

TEST(TrivialTest,AlwaysPasses){

	EXPECT_TRUE(true);

}; 

TEST(InputBufferTest,ContructorTest){

	InputBuffer buffer = {};
	std::vector<int> rawBuffer = buffer.getBuffer(); 
	EXPECT_EQ(0,rawBuffer.size());
};
