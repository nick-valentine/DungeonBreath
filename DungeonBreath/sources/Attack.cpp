#include "../headers/Attack.h"

Attack::Attack()
{

}

void Attack::init(int x, int y, int width, int height, int speed, std::string img_name)
{
	Actor::init(x, y, width, height, img_name);
    add_sprite(0, 0, 100, 100);
    
    set_velocity_x(0);
    set_velocity_y(0);
    
    my_speed = speed;
    
    my_type = Null;
    set_collide_type(BlocksOnly);
}

void Attack::set_velocities(Attack *x)
{
	if(my_facing == D_Up)
	{
		x->set_velocity_x(0);
		x->set_velocity_y(-my_speed);
	}else if(my_facing == D_Down)
	{
		x->set_velocity_x(0);
		x->set_velocity_y(my_speed);
	}else if(my_facing == D_Left)
	{
		x->set_velocity_x(-my_speed);
		x->set_velocity_y(0);
	}else if(my_facing == D_Right)
	{
		x->set_velocity_x(my_speed);
		x->set_velocity_y(0);
	}
}

Direction Attack::get_facing() const 
{
	return this->my_facing;
}

void Attack::set_facing(Direction x)
{
	this->my_facing = x;
}

int Attack::get_speed() const
{
	return this->my_speed;
}

void Attack::set_speed(int x)
{
	this->my_speed = x;
}

