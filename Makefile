buildDirectory = ./build

libraryDirectory = ./lib

testDirectory = ./test

testObjectFiles = $(testDirectory)/test.o  

gtestLink = -lgtest -lgtest_main -lncurses

test :  $(testObjectFiles)
	g++ $(testObjectFiles) -o $(testDirectory)/test $(gtestLink)
	$(testDirectory)/test
	rm $(testObjectFiles)
	rm test/test


