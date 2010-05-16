#ifndef HITTEST_H
#define HITTEST_H

#include <Allegro.h>
#include <vector>
#include "Collision.h"
#include "../../map/Platform.h"
#include "../Character.h"
#include "../../map/Map.h"


class HitTest
{
public:
	void run(); // sprawdza czy jakis obiekt jest w kolizji z innym
	void setMap(Map *p_map);
	void addCharacter(Character *c);
	void loadPlatforms();

	// metody zwiazane z obsluga kolizji
	int countCollisions();
	Collision getCollision(int p_id);


private:
	bool singleCheck(HTObj *c1, HTObj *p1);
	std::vector<Character*> characters;
	std::vector<Platform*> platforms;
	std::vector<Collision> collisions;
	Map *map;
	
};


#endif