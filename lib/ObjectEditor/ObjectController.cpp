#include "../../include/ObjectEditor/ObjectController.hpp"
#include "../../include/ObjectEditor/ObjectView.hpp"
#include "../../include/ObjectEditor/ObjectModel.hpp"
#include "../../include/ObjectEditor/Mediator.hpp"
#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include "../../include/ObjectEditor/IO.hpp"

ObjectEditorOptionsController::ObjectEditorOptionsController
				(NCursesModel& model,NCursesView& view,
				 RenderDescriptionMediator& renderMediator,
				 SaveDescriptionMediator& saveDescriptionMediator,
				 LoadDescriptionMediator& loadDescriptionMediator,
				 Writer& writer,PaletteList& paletteList)
				   :NCursesController(dynamic_cast<NCursesModel&>(model),
						   dynamic_cast<NCursesView&>(view)),
				 mediator(renderMediator),
				 saveDescriptionMediator(saveDescriptionMediator),
				 loadDescriptionMediator(loadDescriptionMediator),
				 paletteList(paletteList),writer(writer){
}

void ObjectEditorOptionsController::takeInput(int character){
	
	unsigned int moveVariable; 

	switch(character){
	
		case KEY_UP:
			moveVariable = this->model.getCursorXPosition(); 
			moveVariable -= 1; 
			moveVariable %= 8; 
			if(moveVariable == 0){
				
				moveVariable += 1; 
			}
			this->model.setCursorXPosition(moveVariable); 
			break;
		case KEY_DOWN:
			moveVariable = this->model.getCursorXPosition(); 
			moveVariable += 1; 
			moveVariable %= 8; 
			if(moveVariable == 0){
				
				moveVariable += 1; 
			}
			this->model.setCursorXPosition(moveVariable);
			break; 
		case '\n': 
			if(this->model.getCursorXPosition() == 2){
				this->mediator.toColleague(); 
			}
			if(this->model.getCursorXPosition() == 1){
				this->saveDescriptionMediator.toColleague(); 
			}
			if(this->model.getCursorXPosition() == 4){
				this->loadDescriptionMediator.toColleague(); 
			}
			if(this->model.getCursorXPosition() == 5){
				endwin(); 	
				exit(0); 
			}
			if(this->model.getCursorXPosition() == 6){
				writer.write(this->paletteList); 
			}	
			break; 	
	}
	this->view.updateModel(this->model); 	

}


ObjectEditorRenderController::ObjectEditorRenderController
				(NCursesModel& model,NCursesView& view)
				:model(dynamic_cast<ObjectEditorRenderModel&>(model)),
				 view(dynamic_cast<ObjectEditorRenderView&>(view)),
				 NCursesController(dynamic_cast<NCursesModel&>(model),
				    		   dynamic_cast<NCursesView&>(view)){



}


void ObjectEditorRenderController::takeInput(int character){}

ObjectEditorPaletteController::ObjectEditorPaletteController
				(NCursesModel& model,NCursesView& view)
				:model(dynamic_cast<ObjectEditorPaletteModel&>(model)),
				view(dynamic_cast<ObjectEditorPaletteView&>(view)),
				NCursesController(dynamic_cast<NCursesModel&>(model),
				    		   dynamic_cast<NCursesView&>(view)){
				
				
}

void ObjectEditorPaletteController::takeInput(int character){

	unsigned int moveVariable; 

	switch(character){
	
		case KEY_UP:
			moveVariable = this->model.getCursorXPosition(); 
			moveVariable -= 1; 
			moveVariable %= 13; 
			if(moveVariable == 0){
				
				moveVariable += 1; 
			}
			this->model.setCursorXPosition(moveVariable); 
			break;
		case KEY_DOWN:
			moveVariable = this->model.getCursorXPosition(); 
			moveVariable += 1; 
			moveVariable %= 13; 
			if(moveVariable == 0){
				
				moveVariable += 1; 
			}
			this->model.setCursorXPosition(moveVariable);
			break; 
		case '\n':
			break; 		
	
	}
	this->view.updateModel(this->model); 	
}

void ObjectEditorPaletteController::setModel(ObjectEditorPaletteModel& model){
	
	this->model = model;
       	this->view.updateModel(this->model); 	

}

ObjectEditorDescriptionController::ObjectEditorDescriptionController(
					ObjectEditorDescriptionModel& model,
					ObjectEditorDescriptionView& view):	
					NCursesController(
						 model,view),model(model),view(view){
				
				
}

void ObjectEditorDescriptionController::takeInput(int character){

	
	if(character >= 32 && character <= 126){

		this->model.addText(character);
	}
	if(character == KEY_BACKSPACE){

		this->model.removeText(); 
	}
	if(character == KEY_DOWN){
		
		this->model.cursorDown(); 	
	}
	if(character == KEY_UP){
	
		this->model.cursorUp(); 	
	}
	if(character == '\n' || character == '\r'){
	
		this->model.cursorDown(); 
	}
	this->updateView(); 	

}

