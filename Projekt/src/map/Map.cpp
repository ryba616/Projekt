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

void Map::loadPlatforms()
{
	std::fstream platforms;
	platforms.open(mapPath.c_str(),std::ios::in);
	/*	TODO:
		otwiera plik platforms korzystajac z pola mapPath (zawierajacego sciezke do katalogu w ktorym znajduje sie ten plik)
		wczytuje z niego informacje na temat kazdej platformy (1 platforma - 1 linia) - x y w h plik_graficzny.bmp
		tworzy dla kazdej wczytanej platformy instancje klasy Platform zgodnie z wczytanymi danymi
	*/
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