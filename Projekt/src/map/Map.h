#ifndef MAP_H
#define MAP_H

#include <vector>
#include "Platform.h"

class Map
{
public:
	void setMapPath(char *_mapPath);
	void loadPlatforms();
	std::vector<Platform> getPlatforms();
	void addPlatform(Platform _platform);

private:
	char *mapPath;
	char *name;
	std::vector<Platform> platforms;
	BITMAP *map;
	BITMAP *bg;
	BITMAP *platform_bg;

};

#endif