
all: build/main.o build/TextureMap.o build/Actor.o build/Hero.o
	g++ -o DungeonBreath build/main.o build/TextureMap.o build/Actor.o build/Hero.o -lsfml-graphics -lsfml-window -lsfml-system

clean:
	rm ./build/*.o
	
build/main.o: sources/main.cpp
	g++ -c sources/main.cpp -o build/main.o
	
build/TextureMap.o: sources/TextureMap.cpp headers/TextureMap.h
	g++ -c sources/TextureMap.cpp -o build/TextureMap.o
	
build/Actor.o: sources/Actor.cpp headers/Actor.h
	g++ -c sources/Actor.cpp -o build/Actor.o
	
build/Hero.o: sources/Hero.cpp headers/Hero.h headers/Actor.h
	g++ -c sources/Hero.cpp -o build/Hero.o
	
