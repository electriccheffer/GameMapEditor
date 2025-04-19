build : ./build/main.o
	gcc ./build/main.o ./build/window_functions.o -o ./build/main -lncurses
	./build/main
	rm ./build/main
	rm ./build/window_functions.o ./build/main.o

./build/main.o: ./src/main.cpp ./build/window_functions.o 
	gcc -c ./src/main.cpp -o ./build/main.o -lncurses

./build/window_functions.o: ./lib/window_functions.cpp
	gcc -c ./lib/window_functions.cpp -o ./build/window_functions.o 
