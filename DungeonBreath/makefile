


all: build/main.o build/TextureMap.o
	g++ -o DungeonBreath build/main.o build/TextureMap.o -lsfml-graphics -lsfml-window -lsfml-system
	
build/main.o: sources/main.cpp
	g++ -c sources/main.cpp -o build/main.o
	
build/TextureMap.o: sources/TextureMap.cpp headers/TextureMap.h
	g++ -c sources/TextureMap.cpp -o build/TextureMap.o
