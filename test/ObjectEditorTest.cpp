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

TEST(InputBufferTest,NonNullConstructorTest){

	std::vector<int> integerBuffer = {}; 
	int number = 22; 
	integerBuffer.push_back(number);
	InputBuffer buffer = {integerBuffer}; 
	std::vector<int> rawBuffer = buffer.getBuffer(); 
	EXPECT_EQ(number,rawBuffer[0]);
};

TEST(InputBufferTest,SetInputBufferTest){

	std::vector<int> integerBuffer = {}; 
	int number = 22; 
	integerBuffer.push_back(number);
	InputBuffer buffer = {}; 
	buffer.setBuffer(integerBuffer); 
	std::vector<int> rawBuffer = buffer.getBuffer(); 
	EXPECT_EQ(number,rawBuffer[0]);
};

TEST(InputBufferTest,AddCharacterTest){

	int newCharacter = 33; 
	InputBuffer buffer = {}; 
	buffer.addCharacter(newCharacter);
	std::vector<int> rawBuffer = buffer.getBuffer(); 
	EXPECT_EQ(newCharacter,rawBuffer[0]);
};


TEST(InputBufferTest,AddCharacterAtLocationTest){

	int newCharacter = 33; 
	unsigned int location = 0; 
	InputBuffer buffer = {}; 
	buffer.addCharacter(22);
        buffer.addCharacter(44);
	buffer.addCharacter(location,newCharacter);
	std::vector<int> rawBuffer = buffer.getBuffer();
	EXPECT_EQ(newCharacter,rawBuffer[location]);	
};
