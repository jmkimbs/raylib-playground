.PHONY: clean run copylibs

INCLUDE=lib/raylib-4.0.0_linux_amd64/include
LIB_PATHS=lib/raylib-4.0.0_linux_amd64/lib
LIBS=raylib

all: bin/game

bin/game: build/game.o $(LIB_PATHS) | bin copylibs
	@echo "-- Building the game binary... --"
	g++ -o bin/game build/game.o -L lib/raylib-4.0.0_linux_amd64/lib -lraylib -L. -Wl,-rpath,"\$$ORIGIN/lib"
	@echo ""

bin:
	mkdir bin
	mkdir bin/lib

copylibs:
	cp lib/raylib-4.0.0_linux_amd64/lib/libraylib.so.4.0.0 bin/lib/libraylib.so.400



build/game.o: src/game.cpp $(INCLUDE) | build
	@echo "-- Building the game objects... --"
	g++ $(INCLUDE:%=-I %) -c -o build/game.o src/game.cpp

build:
	mkdir build

clean:
	rm -rf build
	rm -rf bin

run: bin/game
	./bin/game