#include <gtest/gtest.h>
#include <ncurses.h>
#include <vector>
#include <typeinfo>
#include "../include/ObjectEditor/ObjectModel.hpp"
#include "../include/ObjectEditor/ObjectView.hpp"
#include "../include/ObjectEditor/ObjectController.hpp"
#include "../include/ObjectEditor/Buffer.hpp"
#include "../lib/ObjectEditor/Errors.cpp"
#include "../include/ObjectEditor/Factories.hpp"
#include "../include/ObjectEditor/ControllerContext.hpp"

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
       	int character = 84; 	
	model.addText(character);
	std::vector<TextObject> text = model.getText(); 
	std::string rawText = text[1].getText(); 
	EXPECT_EQ(character,rawText[rawText.size() - 1]);	
}

TEST(ModelViewControllerTest,CallingFromController){

	ObjectDescriptionModelFactory factory = {}; 
	ObjectEditorDescriptionModel model = factory.getModel();
       	int character = 84; 	
	ObjectEditorDescriptionView view(&model);
	ObjectEditorDescriptionController controller(model,view); 
	controller.takeInput(character);
	std::vector<TextObject> text = model.getText(); 
	std::string rawText = text[1].getText(); 

}

TEST(ModelViewControllerTest,DeleteFromController){

	ObjectDescriptionModelFactory factory = {}; 
	ObjectEditorDescriptionModel model = factory.getModel();
       	int character = 116;
	int character2 = 114; 
	int character3 = 101; 
	int character4 = 101; 	
	ObjectEditorDescriptionView view(&model);
	ObjectEditorDescriptionController controller(model,view); 
	controller.takeInput(character);
	controller.takeInput(character2);
	controller.takeInput(character3);
	controller.takeInput(character4);
	controller.takeInput(KEY_BACKSPACE);
	std::vector<TextObject> text = model.getText(); 
	std::string rawText = text[1].getText(); 
	EXPECT_EQ(rawText[5],'t');
}

TEST(ModelViewControllerTest,CursorDownTest){

	ObjectDescriptionModelFactory factory = {}; 
	ObjectEditorDescriptionModel model = factory.getModel(); 
	ObjectEditorDescriptionView view(&model); 
	ObjectEditorDescriptionController controller(model,view);
	controller.takeInput(KEY_DOWN);
	EXPECT_EQ(3,model.getCursorXPosition());
	EXPECT_EQ(17,model.getCursorYPosition());	

}

TEST(ModelViewControllerTest,CursorDownTestTwo){

	ObjectDescriptionModelFactory factory = {}; 
	ObjectEditorDescriptionModel model = factory.getModel(); 
	ObjectEditorDescriptionView view(&model); 
	ObjectEditorDescriptionController controller(model,view);
	controller.takeInput(KEY_DOWN);
	controller.takeInput(KEY_DOWN);
	EXPECT_EQ(5,model.getCursorXPosition());
	EXPECT_EQ(17,model.getCursorYPosition());	

}

TEST(ModelViewControllerTest,CursorDownTestThree){

	ObjectDescriptionModelFactory factory = {}; 
	ObjectEditorDescriptionModel model = factory.getModel(); 
	ObjectEditorDescriptionView view(&model); 
	ObjectEditorDescriptionController controller(model,view);
	controller.takeInput(KEY_DOWN);
	controller.takeInput(KEY_DOWN);
	controller.takeInput(KEY_DOWN); 
	EXPECT_EQ(7,model.getCursorXPosition());
	EXPECT_EQ(17,model.getCursorYPosition());	

}

TEST(ModelViewControllerTest,InputAndMoveTest){

	ObjectDescriptionModelFactory factory = {}; 
	ObjectEditorDescriptionModel model = factory.getModel(); 
	ObjectEditorDescriptionView view(&model); 
	ObjectEditorDescriptionController controller(model,view);
	int character = 116; 
	controller.takeInput(character);
	controller.takeInput(KEY_DOWN); 
	controller.takeInput(character); 
	EXPECT_EQ(3,model.getCursorXPosition());
	EXPECT_EQ(18,model.getCursorYPosition());	

}

TEST(ModelViewControllerTest,InputAndMoveTestViewText){

	ObjectDescriptionModelFactory factory = {}; 
	ObjectEditorDescriptionModel model = factory.getModel(); 
	ObjectEditorDescriptionView view(&model); 
	ObjectEditorDescriptionController controller(model,view);
	int character = 116; 
	controller.takeInput(character);
	controller.takeInput(KEY_DOWN); 
	controller.takeInput(character); 
	std::vector<TextObject> text = model.getText();
	std::string rawText = text[1].getText(); 
}

TEST(ControllerContextTest,InitialState){
	
	ObjectRenderModelFactory factory = {}; 
	ObjectEditorRenderModel renderModel = factory.getModel(); 
	ObjectEditorRenderView renderView(&renderModel); 
	
	ObjectOptionsModelFactory optionsModelFactory = {}; 
	ObjectEditorOptionsModel optionsModel = optionsModelFactory.getModel(); 
	ObjectEditorOptionsView optionsView(&optionsModel); 
	ObjectEditorOptionsController optionsController = {optionsModel,optionsView}; 

	ObjectPaletteFactory paletteFactory = {}; 
	ObjectEditorPaletteModel paletteModel = paletteFactory.getModel(); 
	ObjectEditorPaletteView paletteView(&paletteModel); 
	ObjectEditorPaletteController paletteController = {paletteModel,paletteView}; 
	
	ObjectDescriptionModelFactory descriptionFactory = {}; 
	ObjectEditorDescriptionModel descriptionModel = descriptionFactory.getModel(); 
	ObjectEditorDescriptionView descriptionView(&descriptionModel);
	ObjectEditorDescriptionController descriptionController = {descriptionModel,
								   descriptionView}; 

	ObjectEditorControllerContext context(&optionsController,&descriptionController,
						&paletteController);
	NCursesController* controllerContext = context.getContext();
	EXPECT_EQ(typeid(*controllerContext),typeid(ObjectEditorOptionsController)); 
}


TEST(ControllerContextTest,ChangeController){
	
	ObjectRenderModelFactory factory = {}; 
	ObjectEditorRenderModel renderModel = factory.getModel(); 
	ObjectEditorRenderView renderView(&renderModel); 
	
	ObjectOptionsModelFactory optionsModelFactory = {}; 
	ObjectEditorOptionsModel optionsModel = optionsModelFactory.getModel(); 
	ObjectEditorOptionsView optionsView(&optionsModel); 
	ObjectEditorOptionsController optionsController = {optionsModel,optionsView}; 

	ObjectPaletteFactory paletteFactory = {}; 
	ObjectEditorPaletteModel paletteModel = paletteFactory.getModel(); 
	ObjectEditorPaletteView paletteView(&paletteModel); 
	ObjectEditorPaletteController paletteController = {paletteModel,paletteView}; 
	
	ObjectDescriptionModelFactory descriptionFactory = {}; 
	ObjectEditorDescriptionModel descriptionModel = descriptionFactory.getModel(); 
	ObjectEditorDescriptionView descriptionView(&descriptionModel);
	ObjectEditorDescriptionController descriptionController = {descriptionModel,
								   descriptionView}; 

	ObjectEditorControllerContext context(&optionsController,&descriptionController,
						&paletteController);
	NCursesController* controllerContext = context.takeInput(KEY_PPAGE);
	EXPECT_EQ(typeid(*controllerContext),typeid(ObjectEditorPaletteController)); 
}

TEST(ControllerContextTest,ChangeControllerDown){
	
	ObjectRenderModelFactory factory = {}; 
	ObjectEditorRenderModel renderModel = factory.getModel(); 
	ObjectEditorRenderView renderView(&renderModel); 
	
	ObjectOptionsModelFactory optionsModelFactory = {}; 
	ObjectEditorOptionsModel optionsModel = optionsModelFactory.getModel(); 
	ObjectEditorOptionsView optionsView(&optionsModel); 
	ObjectEditorOptionsController optionsController = {optionsModel,optionsView}; 

	ObjectPaletteFactory paletteFactory = {}; 
	ObjectEditorPaletteModel paletteModel = paletteFactory.getModel(); 
	ObjectEditorPaletteView paletteView(&paletteModel); 
	ObjectEditorPaletteController paletteController = {paletteModel,paletteView}; 
	
	ObjectDescriptionModelFactory descriptionFactory = {}; 
	ObjectEditorDescriptionModel descriptionModel = descriptionFactory.getModel(); 
	ObjectEditorDescriptionView descriptionView(&descriptionModel);
	ObjectEditorDescriptionController descriptionController = {descriptionModel,
								   descriptionView}; 

	ObjectEditorControllerContext context(&optionsController,&descriptionController,
						&paletteController);
	NCursesController* controllerContext = context.takeInput(KEY_NPAGE);
	EXPECT_EQ(typeid(*controllerContext),typeid(ObjectEditorOptionsController)); 
}



