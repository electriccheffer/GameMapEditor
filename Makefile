buildDirectory = ./build

libraryDirectory = ./lib

objectFiles =  $(buildDirectory)/window_functions.o $(buildDirectory)/NCursesView.o \
	       	$(buildDirectory)/NCursesModel.o 

completedProject = $(objectFiles) $(buildDirectory)/main.o


build : $(buildDirectory)/main.o
	g++ $(completedProject) -o $(buildDirectory)/main -lncurses
	$(buildDirectory)/main
	rm $(buildDirectory)/main
	rm $(objectFiles) 

$(buildDirectory)/main.o: ./src/main.cpp $(objectFiles)
	g++ -c ./src/main.cpp -o $(buildDirectory)/main.o -lncurses

$(buildDirectory)/window_functions.o: $(libraryDirectory)/window_functions.cpp
	g++ -c $(libraryDirectory)/window_functions.cpp -o $(buildDirectory)/window_functions.o 

$(buildDirectory)/NCursesView.o: $(libraryDirectory)/NCursesView.cpp
	g++ -c $(libraryDirectory)/NCursesView.cpp -o $(buildDirectory)/NCursesView.o 

$(buildDirectory)/NCursesModel.o: $(libraryDirectory)/NCursesModel.cpp
	g++ -c $(libraryDirectory)/NCursesModel.cpp -o $(buildDirectory)/NCursesModel.o 
