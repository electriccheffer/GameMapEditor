#include <gtest/gtest.h>
#include <ncurses.h>
#include <vector>
#include "../include/ObjectEditor/Buffer.hpp"
#include "../lib/ObjectEditor/Errors.cpp"
#include "./TestSubclasses.hpp"

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

TEST(InputBufferTest,AddCharacterAtInvalidLocation){

	unsigned int location = 1;
        int character = 22; 	
	InputBuffer buffer = {}; 
	buffer.addCharacter(33); 
	EXPECT_THROW(buffer.addCharacter(location,character),InputBufferException); 

}; 


TEST(InputBufferTest,RemoveCharacter){
	unsigned int location = 1;
	int character = 1; 
	InputBuffer buffer = {}; 
	buffer.addCharacter(0);
	buffer.addCharacter(character);
	buffer.removeCharacter(location);
	std::vector<int> rawBuffer = buffer.getBuffer(); 
	EXPECT_EQ(1,rawBuffer.size());
	EXPECT_EQ(0,rawBuffer[0]);
}; 

TEST(InputBufferTest,RemoveCharacterErrorCase){

	unsigned int location = 2;
	int character = 1; 
	InputBuffer buffer = {}; 
	buffer.addCharacter(0);
	buffer.addCharacter(character);
	EXPECT_THROW(buffer.removeCharacter(location),InputBufferException);
};

TEST(ObjectEditorDescriptionModelTest,AddCharacterInputBuffer){

	ObjectDescriptionModelFactory factory = {}; 
	ObjectEditorDescriptionModel model = factory.getModel(); 
	std::vector<TextObject> text = model.getText();
	TestDescriptionModel testModel = {text};
       	int character = 33; 	
	testModel.addText(character);
	InputBuffer buffer = testModel.getBuffer(); 
	std::vector<int> rawBuffer = buffer.getBuffer(); 
        EXPECT_EQ(character,rawBuffer[0]);	
}


