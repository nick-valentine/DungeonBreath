#include "../headers/Enemy_Vampire.h"

Enemy_Vampire::Enemy_Vampire() : Actor()
{
}

Enemy_Vampire::Enemy_Vampire(const Enemy_Vampire &other)
{
	this->set_alive(other.get_alive());
	this->set_collide_type(other.get_collide_type());
	this->set_rect(other.get_rect());
	this->set_texture(other.get_image_name());
	this->set_velocity_x(other.get_velocity_x());
	this->set_velocity_y(other.get_velocity_y());
	//this->set_sprites(other.get_sprites());

	init(other.get_rect().left,
			other.get_rect().top,
			other.get_rect().width,
			other.get_rect().height);
}

void Enemy_Vampire::init(int pos_x, int pos_y, int size_x, int size_y)
{
	Actor::init(pos_x, pos_y, size_x, size_y, "./img/VampSprites.png");
	
	add_sprite(0, 0, 600, 900);
	add_sprite(600, 0, 600, 900);
	add_sprite(1200, 0, 600, 900);
	add_sprite(1800, 0, 600, 900);
	add_sprite(2400, 0, 600, 900);
	add_sprite(3000, 0, 600, 900);
	
	set_velocity_x(0);
	set_velocity_y(0);
	
	active_sprite = 0;
	
	update_count = 0;
	
	my_type = Enemy;
	set_collide_type(All);
	set_alive(true);
}

void Enemy_Vampire::update(int delta)
{
	if(get_alive())
    {
	    update_count++;
	
	    if(update_count%5 == 0)
	    {
		    active_sprite = (active_sprite + 1) % 6;
	    }
	
	    std::vector<Actor *> *actors = get_all_actors();
	
	    Actor *Hero = actors[0][0];

		for(int i = 0; i < actors[0].size(); ++i)
		{
			if(actors[0][i]->get_type() == Player)
			{
				Hero = actors[0][i];
				break;
			}
		}
	
	    double diff_x = get_rect().left - Hero->get_rect().left;
	    double diff_y = get_rect().top - Hero->get_rect().top;
	
	    double hypot = sqrt((diff_x * diff_x) + (diff_y * diff_y));
	
	    diff_x = (diff_x / hypot) * 5;
	    diff_y = (diff_y / hypot) * 5;
	
	    //set_rect(sf::Rect<int>((int)(get_rect().left - diff_x), (int)(get_rect().top - diff_y), get_rect().width, get_rect().height));
		set_velocity_x(-diff_x);
		set_velocity_y(-diff_y);

		common_update(delta);
    }
}

void Enemy_Vampire::draw(sf::RenderWindow &window)
{
	if(get_alive())
	{
		if(active_sprite != -1)
		{
			if((abs(hero->get_rect().left - get_rect().left) + abs(hero->get_rect().top - get_rect().top)) < min_distance + min_distance)
			{
				get_sprite(active_sprite)->setPosition(get_rect().left, get_rect().top);
				get_sprite(active_sprite)->setScale(get_rect().width / 600.0, get_rect().height / 600.0 );
				window.draw(*get_sprite(active_sprite));
			}
		}
	}
}

Actor *Enemy_Vampire::clone()
{
	Enemy_Vampire *temp = new Enemy_Vampire(*this);
	return temp;
}
