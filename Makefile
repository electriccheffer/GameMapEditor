buildDirectory = ./build

libraryDirectory = ./lib

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

gtestLink = -lgtest -lgtest_main -lncurses

ncurseLink = -lncurses

test :  $(buildObjectFiles)
	g++ -c $(testDirectory)/test.cpp -o $(buildDirectory)/test.o 
	g++ $(buildObjectFiles) $(buildDirectory)/test.o -o $(testDirectory)/test $(gtestLink)
	$(testDirectory)/test
	make clean

build: $(buildObjectFiles) 
	g++ -c $(srcDir)/main.cpp  -o $(buildDirectory)/main.o
	g++ $(buildObjectFiles) $(buildDirectory)/main.o -o $(buildDirectory)/main $(ncurseLink)
	$(buildDirectory)/main
	make clean	
	
clean: 
	rm -f $(buildObjectFiles)
	rm -f build/main.o
	rm -f build/test.o
	rm -f test/test
	rm -f $(buildDirectory)/main

$(buildObjectFiles): $(libraryFiles) 
	g++ -c $(libraryDirectory)/NCursesModel.cpp -o $(buildDirectory)/NCursesModel.o
	g++ -c $(libraryDirectory)/window_functions.cpp -o $(buildDirectory)/window_functions.o
	g++ -c $(libraryDirectory)/NCursesView.cpp -o $(buildDirectory)/NCursesView.o 
	g++ -c $(libraryDirectory)/NCursesContext.cpp -o $(buildDirectory)/NCursesContext.o
	g++ -c $(libraryDirectory)/NCursesController.cpp -o $(buildDirectory)/NCursesController.o
	g++ -c $(libraryDirectory)/Position.cpp -o $(buildDirectory)/Position.o 
	g++ -c $(libraryDirectory)/TextObject.cpp -o $(buildDirectory)/TextObject.o
	g++ -c $(libraryDirectory)/Factories.cpp -o $(buildDirectory)/Factories.o
