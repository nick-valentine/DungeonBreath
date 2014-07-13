#include "../headers/EnemyFollower.h"

EnemyFollower::EnemyFollower() : Actor()
{
	//init(0, 0, 0, 0);
}

EnemyFollower::EnemyFollower(const EnemyFollower &other) : Actor()
{
	this->update_count = other.get_update_count();
	this->active_sprite = other.get_active_sprite();

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

void EnemyFollower::init(int pos_x, int pos_y, int size_x, int size_y)
{
    Actor::init(pos_x, pos_y, size_x, size_y, "./img/Enemy.png");

    add_sprite(0,0,100,100);
	add_sprite(100,0,100,100);
	add_sprite(0,100,100,100);

	set_velocity_x(0);
	set_velocity_y(0);

	active_sprite = 0;
	update_count = 0;
	
	my_type = Enemy;
	set_collide_type(All);
	set_alive(true);
}

void EnemyFollower::update(int delta)
{
    if(get_alive())
    {
	    update_count++;
	
	    if(update_count%5 == 0)
	    {
		    active_sprite = (active_sprite + 1) % 3;
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

void EnemyFollower::draw(sf::RenderWindow &window)
{
    if(get_alive())
    {
	    if(active_sprite != -1)
	    {
			if((abs(hero->get_rect().left - get_rect().left) + abs(hero->get_rect().top - get_rect().top)) < min_distance + min_distance)
			{
				get_sprite(active_sprite)->setPosition(get_rect().left, get_rect().top);
				get_sprite(active_sprite)->setScale(get_rect().width / 100.0, get_rect().height / 100.0);
				window.draw(*get_sprite(active_sprite));
			}
	    }
    }
}

void EnemyFollower::hurt(int raw_dmg, CollideType direction)
{
	
}

Actor *EnemyFollower::clone()
{
    EnemyFollower *temp = new EnemyFollower(*this);
    return temp;
}

int EnemyFollower::get_active_sprite() const
{
	return this->active_sprite;
}

int EnemyFollower::get_update_count() const
{
	return this->update_count;
}
