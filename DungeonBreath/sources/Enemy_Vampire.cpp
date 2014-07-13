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
	
	add_sprite(20, 0, 580, 900);
	add_sprite(620, 0, 580, 900);
	add_sprite(1200, 0, 600, 900);
	add_sprite(1800, 0, 600, 900);
	add_sprite(2400, 0, 600, 900);
	add_sprite(3000, 0, 600, 900);
	
	for(int i = 0; i < 6; ++i)
	{
			get_sprite(i)->setScale(size_x / get_sprite(i)->getLocalBounds().width, size_y / get_sprite(i)->getLocalBounds().height);
			get_sprite(i)->setOrigin(get_sprite(i)->getLocalBounds().width / 2, get_sprite(i)->getLocalBounds().height / 2);
	}
	
	set_velocity_x(0);
	set_velocity_y(0);
	
	active_sprite = 0;
	
	update_count = 0;
	
	my_type = Enemy;
	set_collide_type(All);
	set_alive(true);
	
	time_alive = 0;
	
	my_state = idle;
	reset_state_vars();
	hero = 0;
	
	idle_anim.push_back(0);
	idle_anim.push_back(1);
	
	chasing_anim.push_back(0);
	chasing_anim.push_back(1);
	
	attacking_anim.push_back(2);
	attacking_anim.push_back(3);
	attacking_anim.push_back(4);
	attacking_anim.push_back(5);
	attacking_anim.push_back(4);
	attacking_anim.push_back(3);
	
	look_left = true;
}

void Enemy_Vampire::update(int delta)
{
	if(get_alive())
    {
	
		if(hero == 0)
		{
			std::vector<Actor *> *actors = get_all_actors();

			for(int i = 0; i < actors[0].size(); ++i)
			{
				if(actors[0][i]->get_type() == Player)
				{
					hero = actors[0][i];
					break;
				}
			}
		}
	
	
		time_alive += delta;
		update_count++;
		if(my_state == idle)
		{
			idle_anim_timer -= delta;
			if(idle_anim_timer <= 0)
			{
				idle_index = (idle_index + 1) % idle_anim.size();
				active_sprite = idle_anim[idle_index];
				idle_anim_timer = idle_anim_time;
			}
			
			double diff_x = get_rect().left - hero->get_rect().left;
			double diff_y = get_rect().top - hero->get_rect().top;
		
			double hypot = sqrt((diff_x * diff_x) + (diff_y * diff_y));
			
			
			time_till_wander -= delta;
			if(hypot < distance_before_chase)
			{
				my_state = chasing;
				reset_state_vars();
				return;
			}
			else if(time_till_wander <= 0)
			{
				my_state = wandering;
				reset_state_vars();
				return;
			}
		}
		else if(my_state == chasing)
		{
			chasing_anim_timer -= delta;
			if(chasing_anim_timer <= 0)
			{
				chasing_index = (chasing_index + 1) % chasing_anim.size();
				active_sprite = chasing_anim[chasing_index];
				chasing_anim_timer = chasing_anim_time;
			}
		
		
			if(get_rect().left < hero->get_rect().left)
			{
				look_left = false;
			}
			else
			{
				look_left = true;
			}
		
			double diff_x = get_rect().left - hero->get_rect().left;
			double diff_y = get_rect().top - hero->get_rect().top;
		
			double hypot = sqrt((diff_x * diff_x) + (diff_y * diff_y));
		
			if(hypot < distance_before_attack)
			{
				my_state = attacking;
				reset_state_vars();
				return;
			}
			else if(hypot > distance_before_chase)
			{
				my_state = idle;
				reset_state_vars();
				return;
			}
		
			diff_x = (diff_x / hypot) * speed_multiplier * (delta >> delta_shift);
			diff_y = (diff_y / hypot) * speed_multiplier * (delta >> delta_shift);
		
			set_velocity_x(-diff_x);
			set_velocity_y(-diff_y);

		}
		else if(my_state == wandering)
		{
			chasing_anim_timer -= delta;
			if(chasing_anim_timer <= 0)
			{
				chasing_index = (chasing_index + 1) % chasing_anim.size();
				active_sprite = chasing_anim[chasing_index];
				chasing_anim_timer = chasing_anim_time;
			}
			
			wandering_timer -= delta;
			time_till_wander -= delta;
			if(wandering_timer <= 0)
			{
				srand( time_alive );
				
				dir_x = (rand() % 100) - 50;
				dir_y = (rand() % 100) - 50;
				
				if(dir_x < 0)
				{
					look_left = true;
				}
				else
				{
					look_left = false;
				}
				
				double hypot = sqrt((dir_x * dir_x) + (dir_y * dir_y));
				dir_x = dir_x / hypot;
				dir_y = dir_y / hypot;
				
				wandering_timer = time_idle_per_direction;
			}
			
			if(time_till_wander <= 0)
			{
				my_state = idle;
				reset_state_vars();
				return;
			}
			
			double diff_x = get_rect().left - hero->get_rect().left;
			double diff_y = get_rect().top - hero->get_rect().top;
		
			double hypot = sqrt((diff_x * diff_x) + (diff_y * diff_y));
			
			if(hypot < distance_before_chase)
			{
				my_state = chasing;
				reset_state_vars();
				return;
			}
			
			set_velocity_x(dir_x * speed_multiplier * (delta >> delta_shift));
			set_velocity_y(dir_y * speed_multiplier * (delta >> delta_shift));
			
		}
		else if(my_state == attacking)
		{
			attacking_anim_timer -= delta;
			if(attacking_anim_timer <= 0)
			{
				attacking_index = attacking_index + 1;
				active_sprite = attacking_anim[attacking_index];
				attacking_anim_timer = attacking_anim_time;
			}
			if(get_rect().left < hero->get_rect().left)
			{
				look_left = false;
			}
			else
			{
				look_left = true;
			}
			if(attacking_index == attacking_anim.size() - 1)
			{
				my_state = idle;
				reset_state_vars();
			}
			else if(attacking_index == 4)
			{
				if(look_left)
				{
					hero->hurt(1,C_Right);
				}
				else
				{
					hero->hurt(1, C_Left);
				}
			}
		}
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
				get_sprite(active_sprite)->setPosition(get_rect().left + (get_rect().width / 2), get_rect().top + (get_rect().height / 2));
				if(look_left)
				{
					get_sprite(active_sprite)->setScale(get_sprite(active_sprite)->getScale().x, get_sprite(active_sprite)->getScale().y);
				}
				else
				{
					get_sprite(active_sprite)->setScale(-get_sprite(active_sprite)->getScale().x, get_sprite(active_sprite)->getScale().y);
				}
				window.draw(*get_sprite(active_sprite));
			}
		}
	}
}

void Enemy_Vampire::hurt(int raw_dmg, CollideType direction)
{
	
}

Actor *Enemy_Vampire::clone()
{
	Enemy_Vampire *temp = new Enemy_Vampire(*this);
	return temp;
}

inline void Enemy_Vampire::reset_state_vars()
{
	idle_index = 0;
	idle_anim_timer = idle_anim_time;
	chasing_index = 0;
	chasing_anim_timer = chasing_anim_time;
	attacking_index = 0;
	attacking_anim_timer = attacking_anim_time;
	
	time_till_wander = time_idle_before_wander;
	wandering_timer = time_idle_per_direction;
}
