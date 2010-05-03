#ifndef MAP_H
#define MAP_H

#include <vector>
#include "Platform.h"
#include <string>

class Map
{
public:
	void setMapPath(std::string _mapPath);
	void loadPlatforms();
	std::vector<Platform> getPlatforms();
	void addPlatform(Platform _platform);
	void loadInfo();

	std::string getMapPath();
	std::string getName();
	std::string getBgPath();

private:
	std::string mapPath;
	std::string name;
	std::string bgPath;
	std::vector<Platform> platforms;
	BITMAP *map;
	BITMAP *bg;

};

#endif