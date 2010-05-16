#include "HitTest.h"
#include "../../map/Platform.h"
#include "../Character.h"
#include <vector>


void HitTest::addCharacter(Character *c) { characters.push_back(c); }
void HitTest::setMap(Map *p_map) { map = p_map; }
void HitTest::loadPlatforms()
{
	for (int i = 0; i < map->platformCount(); i++)
	{
		platforms.push_back(map->getPlatform(i));
	}
}

void HitTest::run()
{
	collisions.clear();
	// TODO: petelki sprawdzajacace hittesty postaci
	for (unsigned int c = 0; c < characters.size(); c++) {
		characters[c]->setCollisionState(false);
		// 1: platforms
		for (unsigned int p = 0; p < platforms.size(); p++) {
			if (singleCheck(characters[c], platforms[p])) {
				characters[c]->setCollisionState(true);
				characters[c]->setCollisionTarget(platforms[p]);
				//collisions.push_back(Collision(characters[c], platforms[p]));
				// test
//				char buff[256];
//				_itoa_s(characters[c]->getX(), buff, 10);
//				textout_ex(screen, font, buff, 10, 10, makecol(0, 255, 0), -1);
				// end test
			}
		} // end 1
	}




/*	// testy
	if (singleCheck(characters[0], platforms[0])) {
		char buff[256];
		_itoa_s(characters[0]->getX(), buff, 10);
		textout_ex(screen, font, buff, 10, 10, makecol(0, 255, 0), -1);
	} else if (singleCheck(characters[0], platforms[1])) {
		char buff[256];
		_itoa_s(characters[0]->getX(), buff, 10);
		textout_ex(screen, font, buff, 10, 10, makecol(255, 0, 0), -1);
	}
*/
//	char buff[256];
//	_itoa_s(characters.size(), buff, 10);
//	textout_ex(screen, font, buff, 10, 30, makecol(0, 255, 0), -1);
	
//	_itoa_s(platforms.size(), buff, 10);
//	textout_ex(screen, font, buff, 40, 30, makecol(0, 255, 0), -1);

//	_itoa_s(characters[0]->getX(), buff, 10);
//	textout_ex(screen, font, buff, 10, 10, makecol(0, 0, 255), -1);
}

bool HitTest::singleCheck(HTObj *a, HTObj *b)
{

	// pozycje
	int xa = a->getX();
	int ya = a->getY();
	int xb = b->getX();
	int yb = b->getY();

	// rozmiary bound boxa
	int bbw;
	int bbh;
	
	// obliczam prawa krawedz bound boxa i ustawiam jej wartosc jako bbw
	if (a->getX() + a->getW() > b->getX() + b->getW()) bbw = a->getX() + a->getW();
	else bbw = b->getX() + b->getW();
	// nastepnie usuwam od wartosci bbw odleglosc od 0 na osi X, aby pozostal sam rozmiar width
	if (a->getX() < b->getX()) bbw -= a->getX();
	else bbw -= b->getX();

	// robie analogicznie dla bbh
	if (a->getY() + a->getH() > b->getY() + b->getH()) bbh = a->getY() + a->getH();
	else bbh = b->getY() + b->getH();
	// separator dla wygody :) - zeby "wygladalo" analogicznie ;)
	if (a->getY() < b->getY()) bbh -= a->getY();
	else bbh -= b->getY();

	// HIT TEST
	// sumy rozmiarow badanych obiektow
	int sw = a->getW() + b->getW();
	int sh = a->getH() + b->getH();
	bool condition = (sw >= bbw) && (sh >= bbh); // sprawdza czy obydwa wymiary boundboxa sa mniejsze od sumy wymiarow obiektow badanych
	if (condition) return true; // jezeli tak, oznacza ze nachodza na siebie
	else return false;

}