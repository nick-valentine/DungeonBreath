#include "actorboard.h"

ActorBoard::ActorBoard()
{
}

ActorBoard::~ActorBoard()
{
}

void ActorBoard::init()
{

}

std::vector<std::string> ActorBoard::getBoardText()
{
    return std::vector<std::string>();
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
    this->active_actor = new_active;
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

}

void ActorBoard::draw(sf::RenderWindow &window)
{

}
