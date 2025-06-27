buildDirectory = ./build

libraryDirectory = ./lib

ObjectLibrary=$(libraryDirectory)/ObjectEditor

testDirectory = ./test

srcDir =./src

buildObjectFiles =$(buildDirectory)/NCursesModel.o $(buildDirectory)/NCursesView.o\
		   $(buildDirectory)/window_functions.o $(buildDirectory)/NCursesContext.o\
		   $(buildDirectory)/NCursesController.o $(buildDirectory)/Position.o \
		   $(buildDirectory)/TextObject.o $(buildDirectory)/Factories.o

libraryFiles = $(libraryDirectory)/NCursesModel.cpp $(libraryDirectory)/NCursesView.cpp\
		$(libraryDirectory)/NCursesController.cpp $(libraryDirectory)/NCursesContext.cpp\
		$(libraryDirectory)/Position.cpp $(libraryDirectory)/TextObject.cpp\
		$(libraryDirectory)/Factories.cpp

objectEditorLibraryFiles =$(ObjectLibrary)/Factories.cpp $(ObjectLibrary)/ObjectModel.cpp\
			  $(ObjectLibrary)/ObjectView.cpp $(ObjectLibrary)/ObjectController.cpp\
			  $(ObjectLibrary)/Errors.cpp\
			  $(testDirectory)/TestSubclasses.cpp $(ObjectLibrary)/ControllerContext.cpp\
			  $(ObjectLibrary)/Mediator.cpp $(ObjectLibrary)/DataStructures.cpp\
			  $(ObjectLibrary)/IO.cpp

objectEditorBuildFiles = $(buildDirectory)/ObjectFactories.o $(buildDirectory)/ObjectModel.o\
			 $(buildDirectory)/ObjectView.o $(buildDirectory)/ObjectController.o\
			 $(buildDirectory)/Errors.o\
			 $(buildDirectory)/ControllerContext.o $(buildDirectory)/Mediator.o\
			 $(buildDirectory)/DataStructures.o $(buildDirectory)/IO.o

gtestLink = -lgtest -lgtest_main -lncurses -ljsoncpp

ncurseLink = -lncurses

test :  $(buildObjectFiles) 
	g++ -c $(testDirectory)/test.cpp -o $(buildDirectory)/test.o 
	g++ $(buildObjectFiles) $(buildDirectory)/test.o -o $(testDirectory)/test $(gtestLink)
	$(testDirectory)/test
	make clean

character_test: $(testDirectory)/ObjectEditorTest.cpp $(objectEditorBuildFiles) $(buildObjectFiles)
	g++ $(testDirectory)/ObjectEditorTest.cpp $(objectEditorBuildFiles) $(buildObjectFiles) -o $(testDirectory)/test $(gtestLink)
	$(testDirectory)/test
	make clean

build: $(buildObjectFiles) 
	g++ -c $(srcDir)/main.cpp  -o $(buildDirectory)/main.o
	g++ $(buildObjectFiles) $(buildDirectory)/main.o -o $(buildDirectory)/main $(ncurseLink)
	$(buildDirectory)/main
	make clean	

character: $(buildObjectFiles) $(objectEditorBuildFiles)
	g++ -c $(srcDir)/objectEditorMain.cpp -o $(buildDirectory)/ObjectEditor.o
	g++ $(buildObjectFiles) $(objectEditorBuildFiles) $(buildDirectory)/ObjectEditor.o -o $(buildDirectory)/ObjectEditor $(ncurseLink)
	$(buildDirectory)/ObjectEditor
	make clean

character_build: $(buildObjectFiles) $(objectEditorBuildFiles)
	g++ -c $(srcDir)/objectEditorMain.cpp -o $(buildDirectory)/ObjectEditor.o
	g++ $(buildObjectFiles) $(objectEditorBuildFiles) $(buildDirectory)/ObjectEditor.o -o $(buildDirectory)/ObjectEditor $(ncurseLink)
	make character_build_clean 

character_install: $(buildObjectFiles) $(objectEditorBuildFiles)
	g++ -c $(srcDir)/objectEditorMain.cpp -o $(buildDirectory)/ObjectEditor.o
	g++ $(buildObjectFiles) $(objectEditorBuildFiles) $(buildDirectory)/ObjectEditor.o -o $(buildDirectory)/ObjectEditor $(ncurseLink)
	make character_build_clean
	chmod +x install.sh
	./install.sh

character_build_clean: $(buildObjectFiles) $(objectEditorBuildFiles)
	rm -f $(buildObjectFiles)
	rm -f $(objectEditorBuildFiles)
	rm -f $(buildDirectory)/ObjectEditor.o 

$(objectEditorBuildFiles): $(objectEditorLibraryFiles)
	g++ -c $(ObjectLibrary)/Factories.cpp -o $(buildDirectory)/ObjectFactories.o
	g++ -c $(ObjectLibrary)/ObjectModel.cpp -o $(buildDirectory)/ObjectModel.o
	g++ -c $(ObjectLibrary)/ObjectView.cpp -o $(buildDirectory)/ObjectView.o
	g++ -c $(ObjectLibrary)/ObjectController.cpp -o $(buildDirectory)/ObjectController.o
	g++ -c $(ObjectLibrary)/Errors.cpp -o $(buildDirectory)/Errors.o
	g++ -c $(ObjectLibrary)/ControllerContext.cpp -o $(buildDirectory)/ControllerContext.o
	g++ -c $(ObjectLibrary)/Mediator.cpp -o $(buildDirectory)/Mediator.o
	g++ -c $(ObjectLibrary)/DataStructures.cpp -o $(buildDirectory)/DataStructures.o 
	g++ -c $(ObjectLibrary)/IO.cpp -o $(buildDirectory)/IO.o

clean: 
	rm -f $(buildObjectFiles)
	rm -f build/main.o
	rm -f build/test.o
	rm -f test/test
	rm -f $(buildDirectory)/main
	rm -f $(buildDirectory)/*
	rm -f jsonTest.json

$(buildObjectFiles): $(libraryFiles) 
	mkdir -p build
	g++ -c $(libraryDirectory)/NCursesModel.cpp -o $(buildDirectory)/NCursesModel.o
	g++ -c $(libraryDirectory)/window_functions.cpp -o $(buildDirectory)/window_functions.o
	g++ -c $(libraryDirectory)/NCursesView.cpp -o $(buildDirectory)/NCursesView.o 
	g++ -c $(libraryDirectory)/NCursesContext.cpp -o $(buildDirectory)/NCursesContext.o
	g++ -c $(libraryDirectory)/NCursesController.cpp -o $(buildDirectory)/NCursesController.o
	g++ -c $(libraryDirectory)/Position.cpp -o $(buildDirectory)/Position.o 
	g++ -c $(libraryDirectory)/TextObject.cpp -o $(buildDirectory)/TextObject.o
	g++ -c $(libraryDirectory)/Factories.cpp -o $(buildDirectory)/Factories.o
