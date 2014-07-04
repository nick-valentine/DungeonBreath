#ifndef ACTORBOARD_H
#define ACTORBOARD_H

#include <SFML/Graphics.hpp>

#include <vector>
#include <string>

class ActorBoard
{
public:
    struct factory_info
    {
        int group;
        int spawn_frequency;
        int max_spawn_rate;
    };

    enum actor
    {
        Player,
        EnemyFollower,
        StoneWallBottom,
        StoneWallSide,
        StoneWallCorner,
        Treasure
    };

    ActorBoard();
    ~ActorBoard();

    void init();

    std::vector<std::string> getBoardText();

    void set_sides(int left, int top, int right, int bottom);
    sf::IntRect get_sides();

    void set_active_actor(actor new_active);
    actor get_active_actor();

    void set_factory_info(factory_info);
    factory_info get_factory_info();

    void update(sf::RenderWindow &window);
    void draw(sf::RenderWindow &window);
private:
    const static int width = 16;
    const static int height = 16;
    const static int area = width * height;
    const static float scale_factor = 0.25f;

    sf::IntRect my_sides;

    sf::Texture my_walls;
    std::vector<sf::Texture> my_actors;

    std::vector<sf::Sprite> my_sprites;
    std::vector<sf::IntRect> actor_factories;
    std::vector<int> actor_factory_groups;

    std::vector<sf::Sprite> actors_for_factories;
    std::vector<sf::Sprite> actor_groups;

    int active_actor;
    sf::Sprite active_sprite;

    bool adding_to_factory;
    factory_info current_factory_info;
};

#endif // ACTORBOARD_H
