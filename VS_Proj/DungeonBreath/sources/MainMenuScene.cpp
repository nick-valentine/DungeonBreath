#include "../headers/MainMenuScene.h"

MainMenuScene::MainMenuScene()
{

}

MainMenuScene::~MainMenuScene()
{

}

void MainMenuScene::init(int width, int height)
{
	my_status = Nothing;
	
	this->width = width;
	this->height = height;

	main_window.reset(sf::FloatRect(0, 0, width, height));
	
	play_button.init(10, height - 150, 150, 50, "New Game");
	exit_button.init(10, height - 100, 75, 50, "Exit");
}

void MainMenuScene::update(int delta, sf::RenderWindow &window)
{
	play_button.update(delta, window);
	exit_button.update(delta, window);
	if(play_button.pressed())
	{
		switch_to = new GameScene;
		switch_to->init(width, height);
		my_status = Switch_Scene;
	}
	else if(exit_button.pressed())
	{
		my_status = Exit_Program;
	}
}

void MainMenuScene::draw(sf::RenderWindow &window)
{
	window.setView(main_window);
	play_button.draw(window);
	exit_button.draw(window);
}
