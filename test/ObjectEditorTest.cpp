#include <gtest/gtest.h>
#include <ncurses.h>
#include <vector>
#include <typeinfo>
#include <string>
#include <iostream>
#include <filesystem>
#include <nlohmann/json.hpp>
#include "../include/ObjectEditor/ObjectModel.hpp"
#include "../include/ObjectEditor/ObjectView.hpp"
#include "../include/ObjectEditor/ObjectController.hpp"
#include "../include/ObjectEditor/Buffer.hpp"
#include "../lib/ObjectEditor/Errors.cpp"
#include "../include/ObjectEditor/Factories.hpp"
#include "../include/ObjectEditor/ControllerContext.hpp"
#include "../include/ObjectEditor/DataStructures.hpp"
#include "../include/ObjectEditor/IO.hpp"
#include "../include/TextObject.hpp"

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

TEST(ObjectEditorDescriptionModelTest,CompareModelEqual){
	ObjectDescriptionModelFactory factory = {}; 
	ObjectEditorDescriptionModel model = factory.getModel(); 
	ObjectEditorDescriptionModel otherModel = factory.getModel();
       	EXPECT_TRUE((model == otherModel));	
}

TEST(ObjectEditorDescriptionModelTest,CompareModelNotEqual){
	
	ObjectDescriptionModelFactory factory = {}; 
	ObjectEditorDescriptionModel model = factory.getModel(); 
	ObjectEditorDescriptionModel otherModel = factory.getModel();
	int character = 82; 
	otherModel.addText(character);
       	EXPECT_FALSE((model == otherModel));	
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
	ObjectEditorRenderController renderController = {renderModel,renderView};	
	
	ObjectOptionsModelFactory optionsModelFactory = {}; 
	ObjectEditorOptionsModel optionsModel = optionsModelFactory.getModel(); 
	ObjectEditorOptionsView optionsView(&optionsModel); 
		ObjectPaletteModelFactory paletteFactory = {}; 
	ObjectEditorPaletteModel paletteModel = paletteFactory.getModel(); 
	ObjectEditorPaletteView paletteView(&paletteModel); 
	ObjectEditorPaletteController paletteController = {paletteModel,paletteView}; 
	
	ObjectDescriptionModelFactory descriptionFactory = {}; 
	ObjectEditorDescriptionModel descriptionModel = descriptionFactory.getModel(); 
	ObjectEditorDescriptionView descriptionView(&descriptionModel);
	ObjectEditorDescriptionController descriptionController = {descriptionModel,
								   descriptionView}; 
	
	RenderDescriptionMediator mediator(descriptionModel,renderController,renderModel);
	PaletteList paletteList = {}; 
	SaveDescriptionMediator saveDescriptionMediator(paletteList,descriptionModel,paletteController,paletteModel); 
	LoadDescriptionMediator loadDescriptionMediator(paletteModel,descriptionController,descriptionModel,paletteList);
	ObjectEditorOptionsController optionsController(optionsModel,optionsView,mediator,saveDescriptionMediator,loadDescriptionMediator); 
	ObjectEditorControllerContext context(&optionsController,&descriptionController,
						&paletteController);
	NCursesController* controllerContext = context.getContext();
	EXPECT_EQ(typeid(*controllerContext),typeid(ObjectEditorOptionsController)); 
}


TEST(ControllerContextTest,ChangeController){
	
	ObjectRenderModelFactory factory = {}; 
	ObjectEditorRenderModel renderModel = factory.getModel(); 
	ObjectEditorRenderView renderView(&renderModel); 
	ObjectEditorRenderController renderController = {renderModel,renderView};	
	
	ObjectOptionsModelFactory optionsModelFactory = {}; 
	ObjectEditorOptionsModel optionsModel = optionsModelFactory.getModel(); 
	ObjectEditorOptionsView optionsView(&optionsModel); 
		ObjectPaletteModelFactory paletteFactory = {}; 
	ObjectEditorPaletteModel paletteModel = paletteFactory.getModel(); 
	ObjectEditorPaletteView paletteView(&paletteModel); 
	ObjectEditorPaletteController paletteController = {paletteModel,paletteView}; 
	
	ObjectDescriptionModelFactory descriptionFactory = {}; 
	ObjectEditorDescriptionModel descriptionModel = descriptionFactory.getModel(); 
	ObjectEditorDescriptionView descriptionView(&descriptionModel);
	ObjectEditorDescriptionController descriptionController = {descriptionModel,
								   descriptionView}; 
	
	RenderDescriptionMediator mediator(descriptionModel,renderController,renderModel);
	PaletteList paletteList = {}; 
	SaveDescriptionMediator saveDescriptionMediator(paletteList,descriptionModel,paletteController,paletteModel); 
	LoadDescriptionMediator loadDescriptionMediator(paletteModel,descriptionController,descriptionModel,paletteList);
	ObjectEditorOptionsController optionsController(optionsModel,optionsView,mediator,saveDescriptionMediator,loadDescriptionMediator);	
	ObjectEditorControllerContext context(&optionsController,&descriptionController,
						&paletteController);
	NCursesController* controllerContext = context.takeInput(KEY_PPAGE);
	EXPECT_EQ(typeid(*controllerContext),typeid(ObjectEditorPaletteController)); 
}

TEST(ControllerContextTest,ChangeControllerDown){
	
	ObjectRenderModelFactory factory = {}; 
	ObjectEditorRenderModel renderModel = factory.getModel(); 
	ObjectEditorRenderView renderView(&renderModel); 
	ObjectEditorRenderController renderController = {renderModel,renderView};	
	
	ObjectOptionsModelFactory optionsModelFactory = {}; 
	ObjectEditorOptionsModel optionsModel = optionsModelFactory.getModel(); 
	ObjectEditorOptionsView optionsView(&optionsModel); 
	ObjectPaletteModelFactory paletteFactory = {}; 
	ObjectEditorPaletteModel paletteModel = paletteFactory.getModel(); 
	ObjectEditorPaletteView paletteView(&paletteModel); 
	ObjectEditorPaletteController paletteController = {paletteModel,paletteView}; 
	
	ObjectDescriptionModelFactory descriptionFactory = {}; 
	ObjectEditorDescriptionModel descriptionModel = descriptionFactory.getModel(); 
	ObjectEditorDescriptionView descriptionView(&descriptionModel);
	ObjectEditorDescriptionController descriptionController = {descriptionModel,
								   descriptionView}; 
	
	RenderDescriptionMediator mediator(descriptionModel,renderController,renderModel);
	
	
	PaletteList paletteList = {}; 
	SaveDescriptionMediator saveDescriptionMediator(paletteList,descriptionModel,paletteController,paletteModel); 
	LoadDescriptionMediator loadDescriptionMediator(paletteModel,descriptionController,descriptionModel,paletteList);
	ObjectEditorOptionsController optionsController(optionsModel,optionsView,mediator,saveDescriptionMediator,loadDescriptionMediator);
	ObjectEditorControllerContext context(&optionsController,&descriptionController,
						&paletteController);
	NCursesController* controllerContext = context.takeInput(KEY_NPAGE);
	EXPECT_EQ(typeid(*controllerContext),typeid(ObjectEditorOptionsController)); 
}

TEST(ObjectRenderModelFactory,ChangeModels){

	// Create a Description Model
	std::string titleText = "Palette Description";
	Position titlePosition = {};
        TextObject title = {titleText,titlePosition}; 

	std::string nameText = "Name:whirlpool";
	Position namePosition = {1,0}; 
	TextObject name = {nameText,namePosition}; 

	std::string characterText = "Render Character:@";
	Position characterPosition = {3,0};	
	TextObject character = {characterText,characterPosition}; 

	std::string backgroundText = "Background Color:green";
        Position backgroundPosition = {5,0};	
	TextObject background = {backgroundText,backgroundPosition};

	std::string foregroundText = "Foreground Color:yellow";
        Position foregroundPosition = {7,0};	
	TextObject foreground = {foregroundText,foregroundPosition};
		
	std::vector<TextObject> textData = {};
	textData.push_back(title);
	textData.push_back(name);
	textData.push_back(character);
	textData.push_back(background);
	textData.push_back(foreground);
	ObjectEditorDescriptionModel descriptionModel = {textData}; 	
	
	// Create a Render model expected result
	ObjectRenderModelFactory expectedModelFactory = {}; 
	ObjectEditorRenderModel expectedRenderModel = expectedModelFactory.getModel(); 
	expectedRenderModel.setCharacter('@');
	expectedRenderModel.setBackground(COLOR_GREEN);
	expectedRenderModel.setForeground(COLOR_YELLOW);
	// Create a Render Model from factory with description model 
	ObjectRenderModelFactory renderFactory = {descriptionModel};
        ObjectEditorRenderModel renderModel = renderFactory.getModel();
	EXPECT_EQ(renderModel.getCharacter(),expectedRenderModel.getCharacter());
	EXPECT_EQ(renderModel.getBackground(),expectedRenderModel.getBackground());
	EXPECT_EQ(renderModel.getForeground(),expectedRenderModel.getForeground());
}

TEST(PalletteListTest,MakeEmptyList){

	PaletteList listObject = {}; 
	std::vector<ObjectEditorDescriptionModel> list = listObject.getList(); 
	EXPECT_EQ(0,list.size()); 
}

TEST(PaletteListTest,AddToListSingle){

	PaletteList listObject = {}; 
	ObjectDescriptionModelFactory factory = {}; 
	ObjectEditorDescriptionModel model = factory.getModel(); 
	listObject.addModel(model);
	std::vector<ObjectEditorDescriptionModel> list = listObject.getList(); 
	EXPECT_TRUE((list[0] == model));
}

TEST(PaletteListTest,AddToListUnique){
	
	PaletteList listObject = {}; 
	ObjectDescriptionModelFactory factory = {}; 
	ObjectEditorDescriptionModel model = factory.getModel(); 
	listObject.addModel(model);
	ObjectEditorDescriptionModel otherModel = factory.getModel(); 
	int character = 80; 
	otherModel.addText(character);
	listObject.addModel(otherModel);
	std::vector<ObjectEditorDescriptionModel> list = listObject.getList();
	EXPECT_FALSE(list[0]==list[1]);
}

TEST(PaletteListTest,AddToListNonUnique){

	PaletteList listObject = {}; 
	ObjectDescriptionModelFactory factory = {}; 
	ObjectEditorDescriptionModel model = factory.getModel(); 
	listObject.addModel(model);
	ObjectEditorDescriptionModel otherModel = factory.getModel(); 
	EXPECT_THROW(listObject.addModel(otherModel),PaletteListError);

}

TEST(SaveOptionTest,AddToPaletteList){
	
	std::string windowText = "Palette Description"; 
	Position position = {}; 
	TextObject title = {windowText,position}; 

	std::string nameText = "Name:Pool";
	Position namePosition = {1,0}; 
	TextObject name = {nameText,namePosition}; 

	std::string characterText = "Render Character:@";
	Position characterPosition = {3,0}; 
	TextObject character = {characterText,characterPosition}; 
	
	std::string backgroundText = "Background Color:blue";
	Position backgroundPosition = {5,0}; 	
	TextObject background = {backgroundText,backgroundPosition}; 

	std::string foregroundText = "Foreground Color:cyan";
	Position foregroundPosition = {7,0}; 
	TextObject foreground = {foregroundText,foregroundPosition}; 

	std::vector<TextObject> textList = {};
	textList.push_back(title); 
	textList.push_back(name); 
	textList.push_back(character);
	textList.push_back(background);
	textList.push_back(foreground);
	PaletteList paletteList = {}; 
	ObjectEditorDescriptionModel model = {textList}; 

	ObjectPaletteModelFactory paletteFactory = {}; 
	ObjectEditorPaletteModel paletteModel = paletteFactory.getModel(); 
	ObjectEditorPaletteView paletteView(&paletteModel); 
	ObjectEditorPaletteController paletteController = {paletteModel,paletteView}; 
	

	SaveDescriptionMediator descriptionMediator = {paletteList,model,paletteController,paletteModel};
	
	descriptionMediator.toColleague(); 
	std::vector<ObjectEditorDescriptionModel> list = paletteList.getList(); 
	EXPECT_TRUE((list[0] == model));	
}

TEST(PaletteModelFactoryTest,PaletteModelFromPaletteList){

	std::string windowText = "Palette Description"; 
	Position position = {}; 
	TextObject title = {windowText,position}; 

	std::string nameText = "Name:Pool";
	Position namePosition = {1,0}; 
	TextObject name = {nameText,namePosition}; 

	std::string characterText = "Render Character:@";
	Position characterPosition = {3,0}; 
	TextObject character = {characterText,characterPosition}; 
	
	std::string backgroundText = "Background Color:blue";
	Position backgroundPosition = {5,0}; 	
	TextObject background = {backgroundText,backgroundPosition}; 

	std::string foregroundText = "Foreground Color:cyan";
	Position foregroundPosition = {7,0}; 
	TextObject foreground = {foregroundText,foregroundPosition}; 

	std::vector<TextObject> textList = {};
	textList.push_back(title); 
	textList.push_back(name); 
	textList.push_back(character);
	textList.push_back(background);
	textList.push_back(foreground);
	
	ObjectEditorDescriptionModel model = {textList}; 
	PaletteList paletteList = {};
	paletteList.addModel(model);
	ObjectPaletteModelFactory factory = {paletteList};
        ObjectEditorPaletteModel paletteModelResult = factory.getModel(); 
	
	std::string paletteTitleText = "Palette"; 
	Position paletteTitlePosition = {}; 
	TextObject paletteTitle = {paletteTitleText,paletteTitlePosition}; 

	std::string paletteNameText = "Pool"; 
	Position paletteNamePosition = {0,1}; 
	TextObject palettePool = {paletteNameText,paletteNamePosition};

	std::vector<TextObject> paletteModelText = {}; 
	paletteModelText.push_back(paletteTitle);
	paletteModelText.push_back(palettePool); 

	ObjectEditorPaletteModel paletteModel = {paletteModelText}; 
	EXPECT_TRUE((paletteModelResult == paletteModel));

}


TEST(PaletteModelTest,EqualityTestTrue){

	ObjectEditorPaletteModel model = {}; 
	ObjectEditorPaletteModel otherModel = {}; 
	EXPECT_TRUE((model == otherModel));
}

TEST(PaletteModelTest,EqualityTestFalse){

	std::string titleText = "Palette"; 
	Position titlePosition = {}; 
	TextObject title = {titleText,titlePosition}; 
	std::string nameText = "pool"; 
	Position poolPosition = {1,0}; 
	TextObject pool = {nameText,poolPosition}; 
	std::vector<TextObject> text = {}; 
	text.push_back(title);
	text.push_back(pool);
	ObjectEditorPaletteModel model = {text}; 
	
	std::string otherTitleText = "Palette"; 
	Position otherTitlePosition = {}; 
	TextObject otherTitle = {titleText,titlePosition};
	std::vector<TextObject> otherText = {}; 
	otherText.push_back(otherTitle);
	ObjectEditorPaletteModel otherModel = {otherText};
	EXPECT_FALSE((model == otherModel));
}

TEST(PositionSerializationTest,DefaultConstructorTest){
	
	Position position = {}; 
	nlohmann::json serializedPosition = position; 
	nlohmann::json serializedResult = {{"xPosition",0},{"yPosition",0}};
	EXPECT_EQ(serializedResult,serializedPosition);

}


TEST(PositionSerializationTest,NonDefaultTest){
	unsigned int xPosition = 1; 
	unsigned int yPosition = 2; 
	Position position = {xPosition,yPosition}; 
	nlohmann::json serializedPosition = position; 
	nlohmann::json serializedResult = {{"xPosition",xPosition},{"yPosition",yPosition}};
	EXPECT_EQ(serializedResult,serializedPosition);
}

TEST(TextObjectSerialization,TestSerialization){
	unsigned int xPosition = 1; 
	unsigned int yPosition = 2; 
	Position position = {xPosition,yPosition};
	std::string rawText = "Name:pool"; 
	TextObject text = {rawText,position};
	nlohmann::json serializedTextObject = text; 
	nlohmann::json serializedResult = {
					  {"text","Name:pool"},
					  {"position",{
						  {"xPosition",1},
						  {"yPosition",2}
						      }
					  }
					}; 
	EXPECT_EQ(serializedResult,serializedTextObject);
}

TEST(DescriptionModelSerialization,TestSerialization){
	ObjectDescriptionModelFactory factory = {}; 
	ObjectEditorDescriptionModel model = factory.getModel(); 
	nlohmann::json serializedDescriptionModel = model; 
	std::string windowText = "Palette Description"; 
	Position position = {}; 
	TextObject title = {windowText,position}; 

	std::string nameText = "Name:";
	Position namePosition = {1,0}; 
	TextObject name = {nameText,namePosition}; 

	std::string characterText = "Render Character:";
	Position characterPosition = {3,0}; 
	TextObject character = {characterText,characterPosition}; 
	
	std::string backgroundText = "Background Color:";
	Position backgroundPosition = {5,0}; 	
	TextObject background = {backgroundText,backgroundPosition}; 

	std::string foregroundText = "Foreground Color:";
	Position foregroundPosition = {7,0}; 
	TextObject foreground = {foregroundText,foregroundPosition}; 

	std::vector<TextObject> textList = {};
	textList.push_back(title); 
	textList.push_back(name); 
	textList.push_back(character);
	textList.push_back(background);
	textList.push_back(foreground);	
	nlohmann::json serializedResult = textList; 
	EXPECT_EQ(serializedResult,serializedDescriptionModel); 
}

TEST(PaletteListSerializationTest,PaletteSerialization){

	PaletteList paletteList = {}; 
	
	ObjectDescriptionModelFactory factory = {}; 
	ObjectEditorDescriptionModel model = factory.getModel(); 
	
	std::string windowText = "Palette Description"; 
	Position position = {}; 
	TextObject title = {windowText,position}; 
	std::string nameText = "Name:pool";
	Position namePosition = {1,0}; 
	TextObject name = {nameText,namePosition}; 
	std::string characterText = "Render Character:@";
	Position characterPosition = {3,0}; 
	TextObject character = {characterText,characterPosition}; 
	std::string backgroundText = "Background Color:blue";
	Position backgroundPosition = {5,0}; 	
	TextObject background = {backgroundText,backgroundPosition}; 
	std::string foregroundText = "Foreground Color:cyan";
	Position foregroundPosition = {7,0}; 
	TextObject foreground = {foregroundText,foregroundPosition}; 
	std::vector<TextObject> textList = {};
	textList.push_back(title); 
	textList.push_back(name); 
	textList.push_back(character);
	textList.push_back(background);
	textList.push_back(foreground);	
	ObjectEditorDescriptionModel otherModel = {textList}; 

	paletteList.addModel(model);
	paletteList.addModel(otherModel);

	nlohmann::json serializedPaletteList = paletteList; 
	
	std::vector<ObjectEditorDescriptionModel> rawList = {}; 
	rawList.push_back(model);
	rawList.push_back(otherModel);

	nlohmann::json serializedResult = rawList; 

	EXPECT_EQ(serializedResult,serializedPaletteList);	
}

TEST(TestPositionDeserialization,DefaultPositionTest){

	nlohmann::json serializedPosition = {{"xPosition",0},{"yPosition",0}};
	Position positionResult = {}; 
	Position position; 
	from_json(serializedPosition,position);
	EXPECT_TRUE((positionResult == position));
}

TEST(TestPositionDeserialization,NonDefaultDeserialization){

	nlohmann::json serializedPosition = {{"xPosition",1},{"yPosition",2}};
	Position positionResult = {1,2}; 
	Position position; 
	from_json(serializedPosition,position);
	EXPECT_TRUE((positionResult == position));
}

TEST(TestTextObjectDeserialization,DeserializationTest){

	nlohmann::json serializedTextObject = {
					  {"text","Name:pool"},
					  {"position",{
						  {"xPosition",1},
						  {"yPosition",2}
						      }
					  }
					};
	std::string rawText = "Name:pool"; 
	Position textPosition = {1,2}; 
	TextObject text = {rawText,textPosition}; 
	TextObject textResult; 
	from_json(serializedTextObject,textResult);
	EXPECT_TRUE((textResult==text));
}

TEST(TestDescriptionModelDeserialization,ModelDeserializationDefault){

	ObjectDescriptionModelFactory factory = {}; 
	ObjectEditorDescriptionModel modelResult = factory.getModel(); 
	std::string windowText = "Palette Description"; 
	Position position = {}; 
	TextObject title = {windowText,position}; 

	std::string nameText = "Name:";
	Position namePosition = {1,0}; 
	TextObject name = {nameText,namePosition}; 

	std::string characterText = "Render Character:";
	Position characterPosition = {3,0}; 
	TextObject character = {characterText,characterPosition}; 
	
	std::string backgroundText = "Background Color:";
	Position backgroundPosition = {5,0}; 	
	TextObject background = {backgroundText,backgroundPosition}; 

	std::string foregroundText = "Foreground Color:";
	Position foregroundPosition = {7,0}; 
	TextObject foreground = {foregroundText,foregroundPosition}; 

	std::vector<TextObject> textList = {};
	textList.push_back(title); 
	textList.push_back(name); 
	textList.push_back(character);
	textList.push_back(background);
	textList.push_back(foreground);
	nlohmann::json jsonList = textList; 
	ObjectEditorDescriptionModel model; 
	from_json(jsonList,model);
	EXPECT_TRUE((model == modelResult));
}

TEST(PaletteListDeserialization,DeserializationTest){

	PaletteList paletteList = {}; 
	
	ObjectDescriptionModelFactory factory = {}; 
	ObjectEditorDescriptionModel model = factory.getModel(); 
	
	std::string windowText = "Palette Description"; 
	Position position = {}; 
	TextObject title = {windowText,position}; 
	std::string nameText = "Name:pool";
	Position namePosition = {1,0}; 
	TextObject name = {nameText,namePosition}; 
	std::string characterText = "Render Character:@";
	Position characterPosition = {3,0}; 
	TextObject character = {characterText,characterPosition}; 
	std::string backgroundText = "Background Color:blue";
	Position backgroundPosition = {5,0}; 	
	TextObject background = {backgroundText,backgroundPosition}; 
	std::string foregroundText = "Foreground Color:cyan";
	Position foregroundPosition = {7,0}; 
	TextObject foreground = {foregroundText,foregroundPosition}; 
	std::vector<TextObject> textList = {};
	textList.push_back(title); 
	textList.push_back(name); 
	textList.push_back(character);
	textList.push_back(background);
	textList.push_back(foreground);	
	ObjectEditorDescriptionModel otherModel = {textList}; 

	paletteList.addModel(model);
	paletteList.addModel(otherModel);

	nlohmann::json jsonPaletteList = paletteList.getList(); 

	PaletteList listOutput; 

	from_json(jsonPaletteList,listOutput); 

	std::vector<ObjectEditorDescriptionModel> modelList = listOutput.getList(); 

	EXPECT_TRUE((modelList[0] == model));
	EXPECT_TRUE((modelList[1] == otherModel));
}

TEST(TestJsonToFile,WritingAndReading){

	std::filesystem::path path = "./jsonTest.json"; 
	PaletteList paletteList = {}; 
	
	ObjectDescriptionModelFactory factory = {}; 
	ObjectEditorDescriptionModel model = factory.getModel(); 
	
	std::string windowText = "Palette Description"; 
	Position position = {}; 
	TextObject title = {windowText,position}; 
	std::string nameText = "Name:pool";
	Position namePosition = {1,0}; 
	TextObject name = {nameText,namePosition}; 
	std::string characterText = "Render Character:@";
	Position characterPosition = {3,0}; 
	TextObject character = {characterText,characterPosition}; 
	std::string backgroundText = "Background Color:blue";
	Position backgroundPosition = {5,0}; 	
	TextObject background = {backgroundText,backgroundPosition}; 
	std::string foregroundText = "Foreground Color:cyan";
	Position foregroundPosition = {7,0}; 
	TextObject foreground = {foregroundText,foregroundPosition}; 
	std::vector<TextObject> textList = {};
	textList.push_back(title); 
	textList.push_back(name); 
	textList.push_back(character);
	textList.push_back(background);
	textList.push_back(foreground);	
	ObjectEditorDescriptionModel otherModel = {textList}; 

	paletteList.addModel(model);
	paletteList.addModel(otherModel);

	nlohmann::json jsonOut; 
	to_json(jsonOut,paletteList);
	write_json_to_file(path,jsonOut);
	std::string jsonData = read_json_from_file(path);
	PaletteList paletteOutput; 
	nlohmann::json jsonPalette = nlohmann::json::parse(jsonData);
	from_json(jsonPalette,paletteOutput);
        std::vector<ObjectEditorDescriptionModel> modelList = paletteOutput.getList(); 	
	EXPECT_TRUE((modelList[0] == model));
	EXPECT_TRUE((modelList[1] == otherModel));
}
