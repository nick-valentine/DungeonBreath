#ifndef ATTACK_H
#define ATTACK_H

#include "Actor.h"
#include "Direction.h"

class Attack : public Actor
{
 public:
 	Attack();
 	void init(int x, int y, int width, int height, int speed, std::string img_name);
 	
 	virtual void update(int delta) = 0;
 	virtual void draw(sf::RenderWindow &window) = 0;
 	
 	virtual Actor *clone() = 0;
 	void set_velocities(Attack *x);
 	
 	Direction get_facing() const;
 	void set_facing(Direction x);
 
 	int get_speed() const;
 	void set_speed(int x);
 
 private:
 	int my_speed;
 	Direction my_facing;
};

#endif //ATTACK_H
