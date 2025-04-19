build : ./build/main 
	./build/main
	rm ./build/main

./build/main: ./src/main.cpp
	gcc -o ./build/main ./src/main.cpp -lncurses

