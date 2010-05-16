#ifndef PLATFORM_H
#define PLATFORM_H

#include <Allegro.h>
#include "../common/Vec.h"
#include <string>
#include "../logic/hitTest/HTObj.h"


class Platform : public HTObj {
public:
	void setX(int _x);
	void setY(int _y);
	void setW(int _w);
	void setH(int _h);
	void setBgPath(std::string _bgPath);
	int getX();
	int getY();
	int getW();
	int getH();
	bool isMoveable();
	std::string getBgPath();
	bool getCollisionState();
	HTObj *getCollisionTarget();
	void setCollisionState(bool p_state);
	void setCollisionTarget(HTObj *p_target);

private:
	int x, y, w, h;
	std::string bgPath;
	bool m_collisionState;
	HTObj *m_collisionTarget;

};

#endif