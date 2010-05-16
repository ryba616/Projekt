#ifndef PLAYERPHYSICS_H
#define PLAYERPHYSICS_H

#include "../common/Vec.h"
#include "../input/InputListener.h"
#include "./hitTest/HitTest.h"

class PlayerPhysics
{
public:
	void move();
	void setPlayer(Character *p_player);
	void setInput(InputListener *p_input);
	void setHitTest(HitTest *p_ht);

private:
	void gravity();
	void resistances();

	void inputReaction();

	void collisionReaction(); // oblicza wektor reakcji ktory dziala na gracza po zderzeniu
	void collisionCorrection(int p_wallID); // po kolizji gracz zazwyczaj jest "wbity" w sciane, ta metoda przesuwa postac tak, aby tylko sie stykala ze sciana
	int getCollisionPlace(); // zwraca numer sciany z ktora nastapila kolizja: 1-lewa, 2-gorna, 3-prawa, 4-dolna


	// pola
	Character *m_player;
	InputListener *m_input;
	HitTest *m_ht;
	// wektory ruchu
	Vecf m_moveVector;
	Vecf m_gravityVector;
	Vecf m_collisionReaction;


};

#endif