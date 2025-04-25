buildDirectory = ./build

libraryDirectory = ./lib

testDirectory = ./test

buildObjectFiles = $(buildDirectory)/NCursesModel.o $(buildDirectory)/NCursesView.o\
		   $(buildDirectory)/window_functions.o\
		   $(buildDirectory)/NCursesContext.o\
		   $(buildDirectory)/NCursesController.o\
		   
testObjectFiles = $(testDirectory)/test.o

gtestLink = -lgtest -lgtest_main -lncurses

test :  $(testObjectFiles) $(buildObjectFiles)
	g++ $(buildObjectFiles) $(testObjectFiles) -o $(testDirectory)/test $(gtestLink)
	$(testDirectory)/test
	make clean

clean: 
	rm -f $(buildObjectFiles)
	rm -f $(testObjectFiles)
	rm -f test/test

$(testObjectFiles): $(testDirectory)/test.cpp 
	g++ -c $(testDirectory)/test.cpp -o $(testDirectory)/test.o

$(buildObjectFiles): $(libraryDirectory)/NCursesModel.cpp $(libraryDirectory)/NCursesView.cpp $(libraryDirectory)/NCursesController.cpp
	g++ -c $(libraryDirectory)/NCursesModel.cpp -o $(buildDirectory)/NCursesModel.o
	g++ -c $(libraryDirectory)/window_functions.cpp -o $(buildDirectory)/window_functions.o
	g++ -c $(libraryDirectory)/NCursesView.cpp -o $(buildDirectory)/NCursesView.o 
	g++ -c $(libraryDirectory)/NCursesContext.cpp -o $(buildDirectory)/NCursesContext.o
	g++ -c $(libraryDirectory)/NCursesController.cpp -o $(buildDirectory)/NCursesController.o
