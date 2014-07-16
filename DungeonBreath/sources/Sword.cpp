#include "../headers/Sword.h"

Sword::Sword() : Attack()
{

}

void Sword::init(int pos_x, int pos_y, int size_x, int size_y, std::string img_name)
{
	Attack::init(pos_x, pos_y, size_x, size_y,0, img_name);
	//up
	add_sprite(0, 0, 100, 100);
	get_sprite(0)->setOrigin(10, 90);
	add_sprite(100, 0, 100, 100);
	get_sprite(1)->setOrigin(10, 90);
	get_sprite(2)->setOrigin(10, 90);
	add_sprite(200, 0, 100, 100);
	get_sprite(3)->setOrigin(50, 90);
	add_sprite(300, 0, 100, 100);
	get_sprite(4)->setOrigin(90, 90);
	add_sprite(400, 0, 100, 100);
	get_sprite(5)->setOrigin(90, 90);
	
	damage = 1;
	knockback = 40;
	
	my_type = Actor::A_Sword;
	my_type = Null;
	set_collide_type(BlocksOnly);
	anim_timer = anim_time;
	active_sprite = 1;
	first_run = true;
	frame_num = 0;
	rotation = 0;
}

void Sword::update(int delta)
{
	if(get_alive())
	{
		if(first_run)
		{
			if(get_facing() == D_Up)
			{
				set_rect(sf::Rect<int>(hero->get_rect().left, hero->get_rect().top - 50, get_rect().width, get_rect().height));
				rotation = 0;
     		}
			else if(get_facing() == D_Down)
			{
				set_rect(sf::Rect<int>(hero->get_rect().left, hero->get_rect().top + 50, get_rect().width, get_rect().height));
				rotation = 180;
			}
			else if(get_facing() == D_Left)
			{
				set_rect(sf::Rect<int>(hero->get_rect().left - 50, hero->get_rect().top, get_rect().width, get_rect().height));
				rotation = 270;
			}
			else if(get_facing() == D_Right)
			{
				set_rect(sf::Rect<int>(hero->get_rect().left + 50, hero->get_rect().top, get_rect().width, get_rect().height));
				rotation = 90;
			}
			hero->set_velocity_x(0);
			hero->set_velocity_y(0);
			
			first_run = false;
		}
		else
		{
			hero->set_velocity_x(0);
			hero->set_velocity_y(0);
			
			anim_timer -= delta;
			if(anim_timer <= 0)
			{
				active_sprite++;
				frame_num++;
				anim_timer = anim_time;
			}
			common_update(delta);
			
			for(int i = 0; i < last_collided.size(); ++i)
			{
				if(last_collided[i].second->get_type() == Enemy)
				{
					last_collided[i].second->hurt(damage, last_collided[i].first, this, knockback);
				}
			}
			
			if(frame_num == 5)
			{
				kill();
			}
		}
	}
}

void Sword::draw(sf::RenderWindow &window)
{
	
    if(get_alive())
    {
			sf::Vector2f origin = get_sprite(active_sprite)->getOrigin();
			get_sprite(active_sprite)->setOrigin(50, 50);
			get_sprite(active_sprite)->setRotation(rotation);
			get_sprite(active_sprite)->setOrigin(origin);
			get_sprite(active_sprite)->setScale(get_rect().width / 100.0, get_rect().height / 100.0);
			get_sprite(active_sprite)->setPosition(get_rect().left + ( get_rect().width / 2 ), get_rect().top + ( get_rect().height / 2 ));
			
			window.draw(*get_sprite(active_sprite));
			/*
			sf::RectangleShape rect(sf::Vector2f(get_rect().width, get_rect().height));
			rect.setPosition(get_rect().left, get_rect().top);
			rect.setFillColor(sf::Color::Transparent);
			rect.setOutlineThickness(2);
			rect.setOutlineColor(sf::Color::White);
			window.draw(rect);
			*/
	}
}

Actor *Sword::clone()
{
    Sword *temp = new Sword(*this);
    set_velocities(temp);
    return temp;
}
