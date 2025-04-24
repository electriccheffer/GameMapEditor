buildDirectory = ./build

libraryDirectory = ./lib

testDirectory = ./test

objectFiles =  $(buildDirectory)/window_functions.o $(buildDirectory)/NCursesView.o \
	       	$(buildDirectory)/NCursesModel.o $(buildDirectory)/NCursesController.o 

testObjectFiles = $(objectFiles) $(testDirectory)/test.o $(buildDirectory)/TestSubclasses.o 

completedProject = $(objectFiles) $(buildDirectory)/main.o

gtestLink = -lgtest -lgtest_main -lncurses

test :  $(testObjectFiles)
	g++ $(testObjectFiles) -o $(testDirectory)/test $(gtestLink)
	$(testDirectory)/test
	rm $(testObjectFiles)
	rm test/test

build : $(buildDirectory)/main.o
	g++ $(completedProject) -o $(buildDirectory)/main -lncurses
	$(buildDirectory)/main
	rm -f $(buildDirectory)/*

clean : 
	rm -f $(testObjectFiles)
	rm -f $(completedProject)
	rm -f ./build/*

$(testDirectory)/test.o: $(testDirectory)/test.cpp
	g++ -c $(testDirectory)/test.cpp -o $(testDirectory)/test.o

$(buildDirectory)/TestSubclasses.o: $(testDirectory)/TestSubclasses.cpp
	g++ -c $(testDirectory)/TestSubclasses.cpp -o $(buildDirectory)/TestSubclasses.o

$(buildDirectory)/main.o: ./src/main.cpp $(objectFiles)
	g++ -c ./src/main.cpp -o $(buildDirectory)/main.o -lncurses

$(buildDirectory)/window_functions.o: $(libraryDirectory)/window_functions.cpp
	g++ -c $(libraryDirectory)/window_functions.cpp -o $(buildDirectory)/window_functions.o 

$(buildDirectory)/NCursesView.o: $(libraryDirectory)/NCursesView.cpp
	g++ -c $(libraryDirectory)/NCursesView.cpp -o $(buildDirectory)/NCursesView.o 

$(buildDirectory)/NCursesModel.o: $(libraryDirectory)/NCursesModel.cpp
	g++ -c $(libraryDirectory)/NCursesModel.cpp -o $(buildDirectory)/NCursesModel.o 

$(buildDirectory)/NCursesController.o: $(libraryDirectory)/NCursesController.cpp
	g++ -c $(libraryDirectory)/NCursesController.cpp -o \
		$(buildDirectory)/NCursesController.o
