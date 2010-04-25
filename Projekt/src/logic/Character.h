#ifndef CHARACTER_H
#define CHARACTER_H

#include <allegro.h>


class Character
{
public:
	int getX();
	int getY();
	char* getGfxPath();
	void setX(int _x);
	void setY(int _y);
	void setGfxPath(char *_gfxPath);

protected:
	char *gfxPath;
	int x;
	int y;
	
};

#endif