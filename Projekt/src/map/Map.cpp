#include <vector>
#include "Map.h"


std::vector<Platform> Map::getPlatforms() { return platforms; }

void Map::setMapPath(char *_path) { mapPath = _path; }
void Map::addPlatform(Platform _platform) { platforms.push_back(_platform); }

void Map::loadPlatforms()
{
	/*	TODO:
		otwiera plik platforms korzystajac z pola mapPath (zawierajacego sciezke do katalogu w ktorym znajduje sie ten plik)
		wczytuje z niego informacje na temat kazdej platformy (1 platforma - 1 linia) - x y w h plik_graficzny.bmp
		tworzy dla kazdej wczytanej platformy instancje klasy Platform zgodnie z wczytanymi danymi
	*/
}
