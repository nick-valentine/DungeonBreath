#include "actorboard.h"

ActorBoard::ActorBoard()
{
}

ActorBoard::~ActorBoard()
{
}

void ActorBoard::init()
{
    //Load Hero
    my_actors.push_back(sf::Texture());
    if(!my_actors[my_actors.size() - 1].loadFromFile("./img/Hero.png"))
    {
        std::cout<<"Could not load Hero.png\n";
        exit( 1 );
    }

    //Load Enemy
    my_actors.push_back(sf::Texture());
    if(!my_actors[my_actors.size() - 1].loadFromFile("./img/Enemy.png"))
    {
        std::cout<<"Could not load Enemy.png\n";
        exit( 1 );
    }

    //Load Walls
    my_actors.push_back(sf::Texture());
    if(!my_actors[my_actors.size() - 1].loadFromFile("./img/WallSheet.png"))
    {
        std::cout<<"Could not load WallSheet.png\n";
        exit( 1 );
    }

    //Load ActorFactory
    my_actors.push_back(sf::Texture());
    if(!my_actors[my_actors.size() - 1].loadFromFile("./img/Factory.png"))
    {
        std::cout<<"Could not load Factory.png\n";
        exit( 1 );
    }

    this->active_actor = 1;
    this->active_sprite = sf::Sprite(my_actors[3], sf::IntRect(0, 0, 100, 100));
    this->active_sprite.setPosition(-50, -50);

}

std::vector<std::string> ActorBoard::getBoardText()
{
    std::vector<std::string> return_val;

    for(int i = 0; i < my_sprites.size(); ++i)
    {
        std::stringstream ss;

        if(board_actors[i] == Player)
        {
            ss<<"(hero "<<my_sprites[i].getGlobalBounds().left / 25<<" "<<my_sprites[i].getGlobalBounds().top / 25<<")\n";
        }
        else if(board_actors[i] == EnemyFollower)
        {
            ss<<"(enemy_orc "<<my_sprites[i].getGlobalBounds().left / 25<<" "<<my_sprites[i].getGlobalBounds().top / 25<<")\n";
        }
        else if(board_actors[i] == StoneWallBottom)
        {
            ss<<"(wall 1 1 "<<my_sprites[i].getGlobalBounds().left / 25<<" "<<my_sprites[i].getGlobalBounds().top / 25<<")\n";
        }
        else if(board_actors[i] == StoneWallSide)
        {
            ss<<"(wall 2 1 "<<my_sprites[i].getGlobalBounds().left / 25<<" "<<my_sprites[i].getGlobalBounds().top / 25<<")\n";
        }
        else if(board_actors[i] == StoneWallCorner)
        {
            ss<<"(wall 3 1 "<<my_sprites[i].getGlobalBounds().left / 25<<" "<<my_sprites[i].getGlobalBounds().top / 25<<")\n";
        }
        else if(board_actors[i] == Treasure)
        {
            ss<<"(wall 4 1 "<<my_sprites[i].getGlobalBounds().left / 25<<" "<<my_sprites[i].getGlobalBounds().top / 25<<")\n";
        }

        return_val.push_back(ss.str());
    }

    for(int i = 0; i < return_val.size(); ++i)
    {
        std::cout<<return_val[i];
    }
    return return_val;
}

void ActorBoard::set_sides(int left, int top, int right, int bottom)
{
    my_sides = sf::IntRect(left, top, right, bottom);
}

sf::IntRect ActorBoard::get_sides()
{
    return this->my_sides;
}

void ActorBoard::set_active_actor(ActorBoard::actor new_active)
{
    if(this->active_actor != new_active)
    {
        this->active_actor = new_active;
        if(this->active_actor == ActorFactory)
        {
            this->active_sprite = sf::Sprite(my_actors[3], sf::IntRect(0, 0, 100, 100));
        }
        else if(this->active_actor == Player)
        {
            this->active_sprite = sf::Sprite(my_actors[0], sf::IntRect(0, 0, 100, 100));
        }
        else if(this->active_actor == EnemyFollower)
        {
            this->active_sprite = sf::Sprite(my_actors[1], sf::IntRect(0, 0, 100, 100));
        }
        else if(this->active_actor == StoneWallBottom)
        {
            this->active_sprite = sf::Sprite(my_actors[2], sf::IntRect(0, 0, 100, 100));
        }
        else if(this->active_actor == StoneWallSide)
        {
            this->active_sprite = sf::Sprite(my_actors[2], sf::IntRect(100, 0, 100, 100));
        }
        else if(this->active_actor == StoneWallCorner)
        {
            this->active_sprite = sf::Sprite(my_actors[2], sf::IntRect(200, 0, 100, 100));
        }
        else if(this->active_actor == Treasure)
        {
            this->active_sprite = sf::Sprite(my_actors[2], sf::IntRect(300, 0, 100, 100));
        }

        this->active_sprite.setScale(0.25f, 0.25f);
    }
}

bool ActorBoard::get_add_to_factory()
{
    return this->adding_to_factory;
}

void ActorBoard::set_add_to_factory(bool add)
{
    this->adding_to_factory = add;
}

void ActorBoard::set_factory_info(ActorBoard::factory_info new_factory)
{
    this->current_factory_info = new_factory;
}

ActorBoard::factory_info ActorBoard::get_factory_info()
{
    return this->current_factory_info;
}

void ActorBoard::update(sf::RenderWindow &window)
{
    int mousex, mousey;
    mousex = sf::Mouse::getPosition(window).x;
    mousey = sf::Mouse::getPosition(window).y;

    int snappedx = mousex / 25;
    snappedx *= 25;
    int snappedy = mousey / 25;
    snappedy *= 25;


    active_sprite.setPosition(snappedx, snappedy);

    if(active_actor != ActorFactory)
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !last_left_mouse_button)
        {
            if(!adding_to_factory)
            {
                my_sprites.push_back(active_sprite);
            }
            else
            {
                actors_for_factories.push_back(active_sprite);
                actor_groups.push_back(current_factory_info.group);
                actor_spawn_frequencies.push_back(current_factory_info.spawn_frequency);
                board_actors.push_back((actor)active_actor);
            }
        }
    }
    else
    {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && !last_left_mouse_button)
        {
            start_drag_x = snappedx;
            start_drag_y = snappedy;
            dragging = true;
        }
        if(!sf::Mouse::isButtonPressed(sf::Mouse::Left) && last_left_mouse_button)
        {
            sf::IntRect temp(start_drag_x, start_drag_y, snappedx - start_drag_x + 25, snappedy - start_drag_y + 25);
            actor_factories.push_back(temp);
            actor_factory_info.push_back(current_factory_info);
        }
    }

    last_left_mouse_button = sf::Mouse::isButtonPressed(sf::Mouse::Left);
}

void ActorBoard::draw(sf::RenderWindow &window)
{
    for(unsigned int i = 0; i < my_sprites.size(); ++i)
    {
        window.draw(my_sprites[i]);
    }
    for(unsigned int i = 0; i < actor_factories.size(); ++i)
    {
        sf::Sprite temp(my_actors[3], sf::IntRect(0, 0, 100, 100));
        temp.setPosition(actor_factories[i].left, actor_factories[i].top);
        temp.setScale(0.01f * actor_factories[i].width, 0.01f * actor_factories[i].height);

        window.draw(temp);
    }
    for(unsigned int i = 0; i < actors_for_factories.size(); ++i)
    {
        sf::Sprite temp(my_actors[3], sf::IntRect(0, 0, 100, 100));
        temp.setPosition(actors_for_factories[i].getPosition());
        temp.setScale(0.25f, 0.25f);

        window.draw(temp);
        window.draw(actors_for_factories[i]);
    }

    window.draw(active_sprite);
}
