#include <gtest/gtest.h>
#include "../include/NCursesModel.hpp"
#include <ncurses.h>
#include "TestSubclasses.hpp"
#include "../include/NCursesController.hpp"
#include <iostream>

TEST(TrivialTest,AlwaysPasses){

	EXPECT_TRUE(true);
}

TEST(ModelTest,GetCursorXPosition){

	Model model = {}; 
	unsigned int xPosition = model.getCursorXPosition(); 
	EXPECT_EQ(0,xPosition);
}

TEST(ModelTest,GetCursorYPosition){

	Model model = {}; 
	unsigned int yPosition = model.getCursorYPosition(); 
	EXPECT_EQ(0,yPosition);
}

TEST(ModelTest,SetCursorXPosition){
	
	Model model = {}; 
	unsigned int xPosition = 1; 
	model.setCursorXPosition(xPosition);
        EXPECT_EQ(xPosition,model.getCursorXPosition()); 
}

TEST(ModelTest,SetCursorYPosition){
	
	Model model = {}; 
	unsigned int yPosition = 1; 
	model.setCursorYPosition(yPosition);
        EXPECT_EQ(yPosition,model.getCursorYPosition()); 
}

TEST(EditorModelTest,DefaultConstructor){
	
	EditorModel editorModel = {}; 
	unsigned int windowWidth = COLS/2; 
	unsigned int windowHeight = LINES / 2; 
	EXPECT_EQ(windowWidth,editorModel.getWindowWidth());
	EXPECT_EQ(windowHeight,editorModel.getWindowHeight());
}

TEST(ControllerTest,TakeInputPageUpTest){

	ControllerTestSubclass controller = {}; 
	controller.takeInput(KEY_PPAGE);
        int currentModel = controller.getCurrentModelIndexTestAccess(); 
 	EXPECT_EQ(1,currentModel); 	
} 

TEST(ControllerTest,TakeInputPageDownTest){
	
	ControllerTestSubclass controller = {}; 
	controller.takeInput(KEY_NPAGE);
        int currentModel = controller.getCurrentModelIndexTestAccess(); 
 	EXPECT_EQ(2,currentModel);
}

TEST(ControllerTest,GetCurrentModelTest){

	ControllerTestSubclass controller = {}; 
	Model& model = controller.getCurrentModelTestAccess(); 
	EXPECT_EQ(typeid(model),typeid(OptionsModel));
}
