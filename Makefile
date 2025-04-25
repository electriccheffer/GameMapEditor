buildDirectory = ./build

libraryDirectory = ./lib

testDirectory = ./test

buildObjectFiles = $(buildDirectory)/NCursesModel.o $(buildDirectory)/NCursesView.o \
		   $(buildDirectory)/window_functions.o

testObjectFiles = $(testDirectory)/test.o

gtestLink = -lgtest -lgtest_main -lncurses

test :  $(testObjectFiles) $(buildObjectFiles)
	g++ $(testObjectFiles) $(buildObjectFiles) -o $(testDirectory)/test $(gtestLink)
	$(testDirectory)/test
	rm $(testObjectFiles)
	rm test/test

clean: 
	rm -f $(buildObjectFiles)/*
	rm -f $(buildObjectFiles)/*.o
	rm -f $(testObjectFiles)
	rm -f test/test

$(testObjectFiles): $(testDirectory)/test.cpp 
	g++ -c $(testDirectory)/test.cpp -o $(testDirectory)/test.o

$(buildObjectFiles): $(libraryDirectory)/NCursesModel.cpp
	g++ -c $(libraryDirectory)/NCursesModel.cpp -o $(buildDirectory)/NCursesModel.o
	g++ -c $(libraryDirectory)/window_functions.cpp -o \
	       	$(buildDirectory)/window_functions.o
	g++ -c $(libraryDirectory)/NCursesView.cpp -o $(buildDirectory)/NCursesView.o 
