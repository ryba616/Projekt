#include <allegro.h>
#include "../logic/PlayerPhysics.h"
#include <Math.h>

void PlayerPhysics::move()
{
	int wallID = 0;
	if (m_player->getCollisionState()) wallID = getCollisionPlace();
	if (wallID != 2) gravity(); // jezeli postac nie stoi na czyms to wlaczamy grawitacje
	resistances();
	inputReaction();
	if (m_player->getCollisionState()) collisionReaction();
//	else {
		m_player->setX(m_player->getX() + m_moveVector.x);
		m_player->setY(m_player->getY() + m_moveVector.y);
//	}
//	m_player->setCollisionState(false);
}

void PlayerPhysics::resistances()
{
//	char buff[10];
	//_itoa_s(m_moveVector.x, buff, 10);
//	sprintf_s(buff, "%f", m_moveVector.x);
//	const char *final = buff;
//	textout_ex(screen, font, buff, 10, 10, makecol(0, 0, 255), -1);


	// tarcie o podloze
	m_moveVector.x *= 0.7;
	if (floor(abs(m_moveVector.x) + 0.5) <= 1) m_moveVector.x = 0;
	//m_moveVector.y = 0;
}

void PlayerPhysics::inputReaction()
{
	int wallID = 0;
	if (m_player->getCollisionState()) wallID = getCollisionPlace();
	if (m_input->RIGHT && (wallID != 1)) m_moveVector.x += 3;
	if (m_input->LEFT && (wallID != 3)) m_moveVector.x -= 3;
	if (m_input->JUMP && (wallID != 4)) m_moveVector.y -= 15;
}

void PlayerPhysics::collisionReaction()
{
	char buff[256];
	_itoa_s(getCollisionPlace(), buff, 10, 10);
	textout_ex(screen, font, buff, 200, 10, makecol(255, 50, 50), -1);
	_itoa_s(m_player->getY(), buff, 10, 10);
	textout_ex(screen, font, buff, 100, 10, makecol(0, 0, 255), -1);


	collisionCorrection(getCollisionPlace());
//	m_player->setX(m_player->getX() - 2*m_moveVector.x);
//	m_player->setY(m_player->getY() - 2*m_moveVector.y);
//	m_moveVector.x *= -2;
//	m_moveVector.y *= -2;

}

void PlayerPhysics::collisionCorrection(int p_wallID)
{
	// testy
	char buff[256];
//	int wynik = m_player->getCollisionTarget()->getX() - m_player->getW() - 1;
//	_itoa_s(wynik, buff, 10, 10);
//	textout_ex(screen, font, buff, 200, 30, makecol(255, 50, 50), -1);
	_itoa_s(m_moveVector.x, buff, 10, 10);
	textout_ex(screen, font, buff, 50, 50, makecol(255, 255, 255), -1);


	// korekta zgodna z najwnoszymi zalozeniami
	if (p_wallID == 1) // lewa sciana
	{
		// przy pierwszej iteracji kolizji zerowanie skladowej X wektora
		if (m_player->getX() > m_player->getCollisionTarget()->getX() - m_player->getW())
			m_moveVector.x = 0;

		m_player->setX (m_player->getCollisionTarget()->getX() - m_player->getW());
	}
	else if (p_wallID == 2) // gora
	{
		// przy pierwszej iteracji kolizji zerowanie skladowej Y wektora ruchu
		if (m_player->getY() > m_player->getCollisionTarget()->getY() - m_player->getH())
			m_moveVector.y = 0;

		m_player->setY (m_player->getCollisionTarget()->getY() - m_player->getH());
	}
	else if (p_wallID == 3) // prawa sciana
	{
		// przy pierwszej iteracji kolizji zerowanie skladowej X wektora
		if (m_player->getX() < m_player->getCollisionTarget()->getX() + m_player->getCollisionTarget()->getW())
			m_moveVector.x = 0;

		m_player->setX (m_player->getCollisionTarget()->getX() + m_player->getCollisionTarget()->getW());
	}
	else if (p_wallID == 4) // sufit
	{
		// najmniej wazne - zrobie pozniej
	}


	// przestarzala korekta
	// na boki - player uderzyl w sciane, sprawdza czy X gracza jest wiekszy czy mniejszy od sciany i ustawia go tak aby siê styka³ ze œcian¹
	// ale nie by³ w ni¹ wbity
/*	if (m_player->getX() < m_player->getCollisionTarget()->getX()) //player jest po lewej
	{
		m_player->setX (m_player->getCollisionTarget()->getX() - m_player->getW() - 1);
	}
	else if (m_player->getX() > m_player->getCollisionTarget()->getX()) // player jest po prawej
	{
		m_player->setX (m_player->getCollisionTarget()->getX() + m_player->getCollisionTarget()->getW() + 1);
	}
	m_moveVector.x = 0;
*/
}

int PlayerPhysics::getCollisionPlace()
{
	// Jest to bardzo wazna metoda, ktora mozliwe ze bedzie trzeba udoskonalic. Podejrzewam ze moga wystapic spore problemy gdy gracz wpadnie na rog
	// platformy - wtedy teoretycznie bedzie w hittescie z dwoma scianami, a zwrocona bedzie musiala byc tylko jedna - wstepnie takie sytuacje ignoruje.

	// roznica w polozeniu:
	int x = m_player->getX() - m_player->getCollisionTarget()->getX();
	int y = m_player->getY() - m_player->getCollisionTarget()->getY();


	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	if (x < 0) // sciana 1
	{
		if (m_player->getY() < m_player->getCollisionTarget()->getY()) // 1 lub 2
		{
			return 1; // tutaj nalezy sprawdzic czy 1 czy 2
		}
		else if (m_player->getY() > (m_player->getCollisionTarget()->getY() + m_player->getCollisionTarget()->getH() - m_player->getH())) // 1 lub 4
		{
			return 1; // tutaj nalezy sprawdzic czy 1 czy 4
		}
		else return 1;
	}
	else if (x > m_player->getCollisionTarget()->getW() - m_player->getW()) // sciana 3
	{
		if (m_player->getY() < m_player->getCollisionTarget()->getY()) // 3 lub 2
		{
			return 3; // tutaj nalezy sprawdzic czy 3 czy 2
		}
		else if (m_player->getY() > (m_player->getCollisionTarget()->getY() + m_player->getCollisionTarget()->getH() - m_player->getH())) // 3 lub 4
		{
			return 3; // tutaj nalezy sprawdzic czy 3 czy 4
		}
		else return 3;
	}
	else if (m_player->getY() < m_player->getCollisionTarget()->getY()) return 2; // sciana 2
	else if (m_player->getY() < (m_player->getCollisionTarget()->getY() + m_player->getCollisionTarget()->getH())) return 4; // sciana 4
	else return 0; // niewiadomo jaka sciana - najprawdopodobniej cos jest bardzo nie tak jak powinno byæ i generalnie jest zle ...

}

void PlayerPhysics::gravity()
{
	m_moveVector.y += 1;
}




void PlayerPhysics::setPlayer(Character *p_player) { m_player = p_player; }
void PlayerPhysics::setInput(InputListener *p_input) { m_input = p_input; }
void PlayerPhysics::setHitTest(HitTest *p_ht) { m_ht = p_ht; }
