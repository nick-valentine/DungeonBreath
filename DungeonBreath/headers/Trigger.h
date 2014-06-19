#ifndef TRIGGER_H
#define TRIGGER_H


#include "Actor.h"

class Trigger : public Actor
{
 public:
    enum Type
    {
        Latch,
        Switch,
        Press
    };
 
    Trigger();
 	void init(int pos_x, int pos_y, int size_x, int size_y, Type type, Actor::ActorType actor_type = Null);
 	
 	void update(int delta);
 	void draw(sf::RenderWindow &window);
 	
 	bool get_active();
 	
 	Type get_trigger_type();
 	void set_trigger_type(Type x);
 	
 	Actor *clone();
 private:
    Type trigger_type;
    Actor::ActorType actor_type;
    bool active;
    bool last_on_trigger;
};

#endif
