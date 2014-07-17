
all: build/main.o build/TextureMap.o build/Actor.o build/Hero.o build/Wall.o build/EnemyFollower.o build/MagicMissile.o build/Scene.o build/ActorFactory.o build/Trigger.o build/Attack.o build/MagicNova.o build/Tile.o build/GameScene.o build/Button.o build/MainMenuScene.o build/Files.o build/TileSet.o build/Enemy_Vampire.o build/Sword.o build/Item.o build/Gold.o
	g++ -o DungeonBreath build/main.o build/TextureMap.o build/Actor.o \
	build/Hero.o build/Wall.o build/EnemyFollower.o build/MagicMissile.o \
	build/ActorFactory.o build/Trigger.o build/Attack.o build/MagicNova.o \
	build/Tile.o build/GameScene.o build/Button.o build/MainMenuScene.o \
	build/Files.o build/TileSet.o build/Enemy_Vampire.o build/Sword.o \
	build/Item.o build/Gold.o \
	build/Scene.o -lsfml-graphics -lsfml-window -lsfml-system

windows: build/main.o build/TextureMap.o build/Actor.o build/Hero.o build/Wall.o build/EnemyFollower.o build/MagicMissile.o build/Scene.o build/ActorFactory.o build/Trigger.o build/Attack.o build/MagicNova.o build/Tile.o build/GameScene.o build/Button.o build/MainMenuScene.o build/Files.o build/TileSet.o build/Enemy_Vampire.o build/Sword.o build/Item.o build/Gold.o
	g++ -o DungeonBreath.exe build/main.o build/TextureMap.o build/Actor.o \
	build/Hero.o build/Wall.o build/EnemyFollower.o build/MagicMissile.o \
	build/ActorFactory.o build/Trigger.o build/Attack.o build/MagicNova.o \
	build/Tile.o build/GameScene.o build/Button.o build/MainMenuScene.o \
	build/Files.o build/TileSet.o build/Enemy_Vampire.o build/Sword.o \
	build/Item.o build/Gold.o \
	build/Scene.o -lsfml-graphics -lsfml-window -lsfml-system

winclean:
	rm build/*
	
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
	
build/MagicMissile.o: sources/MagicMissile.cpp headers/MagicMissile.h headers/Attack.h
	g++ -c sources/MagicMissile.cpp -o build/MagicMissile.o
	
build/Scene.o: sources/Scene.cpp headers/Scene.h headers/Actor.h
	g++ -c sources/Scene.cpp -o build/Scene.o
	
build/ActorFactory.o: sources/ActorFactory.cpp headers/ActorFactory.h headers/Actor.h
	g++ -c sources/ActorFactory.cpp -o build/ActorFactory.o
	
build/Trigger.o: sources/Trigger.cpp headers/Trigger.h headers/Actor.h
	g++ -c sources/Trigger.cpp -o build/Trigger.o
	
build/Attack.o: sources/Attack.cpp headers/Attack.h headers/Actor.h
	g++ -c sources/Attack.cpp -o build/Attack.o
	
build/MagicNova.o: sources/MagicNova.cpp headers/MagicNova.h headers/Attack.h
	g++ -c sources/MagicNova.cpp -o build/MagicNova.o
	
build/Tile.o: sources/Tile.cpp headers/Tile.h headers/Actor.h
	g++ -c sources/Tile.cpp	-o build/Tile.o

build/GameScene.o: sources/GameScene.cpp headers/GameScene.h headers/Scene.h
	g++ -c sources/GameScene.cpp -o build/GameScene.o
	
build/Button.o: sources/Button.cpp headers/Button.h
	g++ -c sources/Button.cpp -o build/Button.o
	
build/MainMenuScene.o: sources/MainMenuScene.cpp headers/MainMenuScene.h
	g++ -c sources/MainMenuScene.cpp -o build/MainMenuScene.o
	
build/Files.o: sources/Files.cpp headers/Files.h
	g++ -c sources/Files.cpp -o build/Files.o
	
build/TileSet.o: sources/TileSet.cpp headers/TileSet.h
	g++ -c sources/TileSet.cpp -o build/TileSet.o
	
build/Enemy_Vampire.o: sources/Enemy_Vampire.cpp headers/Enemy_Vampire.h
	g++ -c sources/Enemy_Vampire.cpp -o build/Enemy_Vampire.o
	
build/Sword.o: sources/Sword.cpp headers/Sword.h
	g++ -c sources/Sword.cpp -o build/Sword.o
	
build/Item.o: sources/Item.cpp headers/Item.h
	g++ -c sources/Item.cpp -o build/Item.o
	
	
build/Gold.o: sources/Gold.cpp headers/Gold.h
	g++ -c sources/Gold.cpp -o build/Gold.o
	