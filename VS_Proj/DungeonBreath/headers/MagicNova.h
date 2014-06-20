#ifndef MAGICNOVA_H
#define MAGICNOVA_H

#include <vector>
#include <math.h>
#include <algorithm>

#include "Attack.h"
#include "MagicMissile.h"

class MagicNova : public Attack
{
 public:
	MagicNova();
 	void init(int pos_x, int pos_y, int size_x, int size_y, double vel_x, double vel_y, bool will_be_cloned, std::string img_name);
 	
 	void update(int delta);
 	void draw(sf::RenderWindow &window);
 	
 	Actor *clone();
 private:
 	static const int lifespan;
    static const int num_missiles;
    
    int lifetime;
    
    std::vector<MagicMissile *> missiles;
};

#endif //MAGICNOVA_H
