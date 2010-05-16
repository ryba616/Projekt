#ifndef CHARACTER_H
#define CHARACTER_H

#include <allegro.h>
#include "../logic/hitTest/HTObj.h"

class Character : public HTObj
{
public:
	int getX();
	int getY();
	int getW();
	int getH();
	bool isMoveable();
	char* getGfxPath();
	void setX(int _x);
	void setY(int _y);
	void setGfxPath(char *_gfxPath);
	
	bool getCollisionState();
	HTObj *getCollisionTarget();
	void setCollisionState(bool p_state);
	void setCollisionTarget(HTObj *p_target);
	bool isStanding();

protected:
	char *gfxPath;
	int x, y, w, h;
	bool m_collisionState;
	HTObj *m_collisionTarget;
	
};

#endif