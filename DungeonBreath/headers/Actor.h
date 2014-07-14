#ifndef ACTOR_H
#define ACTOR_H

#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <utility>
#include <stdlib.h>
#include <math.h>

#include "TextureMap.h"

class Actor
{
 public:
 
 	enum ActorType
 	{
 	    Null = 0,
 	    Tile = 1,
 	    Player = 2,
 	    Block = 3,
 	    Enemy = 4,
 	    Spell = 5,
 	    A_Sword = 6,
 	    Trigger = 7
 	};
 	
 	enum CollideType
 	{
 	    C_None,
 	    C_Top,
 	    C_Bottom,
 	    C_Left,
 	    C_Right
 	};
 	
 	enum CollideResolve
 	{
 	    All,
 	    BlocksOnly,
 	    Nothing
 	};
 	
 
    Actor();
 	void init(int pos_x, int pos_y, int size_x, int size_y, std::string image_name);
 	
 	virtual void update(int delta) = 0;
 	virtual void draw(sf::RenderWindow &window) = 0;
 	virtual void hurt(int raw_dmg, CollideType direction, Actor *attacker);
	
 	void common_update(int delta);
 	
 	sf::Rect<int> get_rect() const;
 	void set_rect(sf::Rect<int> x);
 	
 	double get_velocity_x() const;
 	double get_velocity_y() const;
 	void set_velocity_x(double x);
 	void set_velocity_y(double x); 
 	
 	std::string get_image_name() const;
 	
 	sf::Texture *get_texture() const;
 	void set_texture(std::string image_name);
 	
	void set_sprites(std::vector<sf::Sprite> sprites);
	std::vector<sf::Sprite> get_sprites() const;
 	sf::Sprite *get_sprite(int x);
 	int get_num_sprites() const;
 	int add_sprite(int pos_x, int pos_y, int width, int height);
 	
 	ActorType get_type() const;
 	
 	CollideResolve get_collide_type() const;
 	void set_collide_type(CollideResolve x);
 	
 	bool get_alive() const;
 	void set_alive(bool x);
 	
 	void kill();
 	
 	bool is_colliding(Actor *x) const;
 	CollideType move_and_resolve_collision();
	
 	virtual Actor *clone() = 0;
 	
 	void unregister();
 	
 	int get_index() const;
 	void set_index(int x);
 	
 	static std::vector<Actor *>* get_all_actors();
 	static void clear_dead();
 	
	static void clear_all_actors();
 protected:
	const static unsigned int min_distance = 50 * 11;
 	double velocity_x;
 	double velocity_y;
	static Actor *hero;
 
 	sf::Rect<int> rect;
 	
 	sf::Texture *tex;
 	std::string texture_name;
 	std::vector<sf::Sprite> sprites;
 	
 	TextureMap my_map;
	
	//all actors used to clean memory when program is finished
	static std::vector<Actor *> actor_list;

	//all actors used for game management
	static std::vector<Actor *> all_actors;
 	int my_index;
 	
 	ActorType my_type;
 	             //collide type with pointer to what collided
 	std::vector<std::pair<CollideType, Actor*> > last_collided;
 	
 	CollideResolve my_collide;
 	
 	bool alive;
};

#endif //ACTOR_H
