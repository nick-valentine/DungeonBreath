#include "../headers/EnemyFollower.h"

EnemyFollower::EnemyFollower() : Actor()
{
	init(0, 0, 0, 0);
}

void EnemyFollower::init(int pos_x, int pos_y, int size_x, int size_y)
{
    Actor::init(pos_x, pos_y, size_x, size_y, "./img/Enemy.png");

    add_sprite(0,0,100,100);
	add_sprite(100,0,100,100);
	add_sprite(0,100,100,100);

	active_sprite = 0;
	update_count = 0;
}

void EnemyFollower::update(int delta)
{
	update_count++;
	
	if(update_count%5 == 0)
	{
		active_sprite = (active_sprite + 1) % 3;
	}
	
	std::vector<Actor *> *actors = get_all_actors();
	
	Actor *Hero = actors[0][0];
	
	double diff_x = get_rect().left - Hero->get_rect().left;
	double diff_y = get_rect().top - Hero->get_rect().top;
	
	double hypot = sqrt((diff_x * diff_x) + (diff_y * diff_y));
	
	diff_x = (diff_x / hypot) * 5;
	diff_y = (diff_y / hypot) * 5;
	
	set_rect(sf::Rect<int>((int)(get_rect().left - diff_x), (int)(get_rect().top - diff_y), get_rect().width, get_rect().height));

    common_update(delta);
}

void EnemyFollower::draw(sf::RenderWindow &window)
{
	if(active_sprite != -1)
	{
	    get_sprite(active_sprite)->setPosition(get_rect().left, get_rect().top);
	    get_sprite(active_sprite)->setScale(get_rect().width / 100.0, get_rect().height / 100.0);
		window.draw(*get_sprite(active_sprite));
	}
}
