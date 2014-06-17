
all: build/main.o build/TextureMap.o build/Actor.o build/Hero.o build/Wall.o build/EnemyFollower.o
	g++ -o DungeonBreath build/main.o build/TextureMap.o build/Actor.o build/Hero.o build/Wall.o build/EnemyFollower.o -lsfml-graphics -lsfml-window -lsfml-system

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
	
build/Wall.o: sources/Wall.cpp headers/Wall.h headers/Actor.h
	g++ -c sources/Wall.cpp -o build/Wall.o
	
build/EnemyFollower.o: sources/EnemyFollower.cpp headers/EnemyFollower.h headers/Actor.h
	g++ -c sources/EnemyFollower.cpp -o build/EnemyFollower.o
