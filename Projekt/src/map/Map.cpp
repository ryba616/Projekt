#include <vector>
#include <fstream>
#include <string>
#include "Map.h"
#include <iostream>


std::vector<Platform> Map::getPlatforms() { return platforms; }
std::string Map::getMapPath() { return mapPath; }
std::string Map::getName() { return name; }
std::string Map::getBgPath() { return bgPath; }

void Map::setMapPath(std::string _path) { mapPath = _path; }
void Map::addPlatform(Platform _platform) { platforms.push_back(_platform); }

int Map::platformCount() { return platforms.size(); }
Platform *Map::getPlatform(int p_id) { return &platforms[p_id]; }

void Map::loadPlatforms()
{
//	std::fstream platformsFile;
	FILE *platformsFile;

	// tworzenie sciezki do pliku z platformami
	std::string platformsPath;
	platformsPath = mapPath;
	platformsPath += "platforms";

	platformsFile = fopen(platformsPath.c_str(), "r");
	
	while (!feof(platformsFile))
	{
		std::string _bgPath = mapPath;
		int _x;
		int _y;
		int _w;
		int _h;
		char buffer[256];

		fscanf(platformsFile, "%d %d %d %d %s\n", &_x, &_y, &_w, &_h, buffer);

		_bgPath += buffer;

		Platform p1;
		p1.setBgPath(_bgPath);
		p1.setX(_x);
		p1.setY(_y);
		p1.setW(_w);
		p1.setH(_h);
		platforms.push_back(p1);
	}
}

void Map::loadInfo()
{
	std::fstream info;

	std::string path = mapPath;
	path += "info";

	info.open(path.c_str(), std::ios::in);

	// pobieranie informacji
	getline(info, name);
	std::string bgName;
	getline(info, bgName);
	bgPath = mapPath;
	bgPath += bgName;


}
