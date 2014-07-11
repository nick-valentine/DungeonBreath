#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H

#include "Scene.h"
#include "Button.h"

#include "GameScene.h"

class MainMenuScene : public Scene
{
 public:
	MainMenuScene();
    ~MainMenuScene();
    void init(int width, int height);
    
    void update(int delta, sf::RenderWindow &window);
    
    void draw(sf::RenderWindow &window);
 private:
    sf::View main_window;
    Button play_button;
    Button exit_button;
};

#endif //MAINMENUSCENE_H
