#include <allegro.h>
#include "InputListener.h"


void InputListener::run()
{
	// resetowanie informacji na temat stanu klawiszy
	LEFT = false;
	RIGHT = false;
	ESC = false;
	JUMP = false;

	// wywolanie listenerow dla klawiszy
	walkListener();
	jumpListener();
	interfaceListener();
}

void InputListener::walkListener()
{
	if(key[KEY_LEFT]) LEFT = true;
	if(key[KEY_RIGHT]) RIGHT = true;
}

void InputListener::interfaceListener()
{
	if (key[KEY_ESC]) ESC = true;
}

void InputListener::jumpListener()
{
	// ta metoda musi nie tylko przechwytywac stan klawisza tak jak to jest w walkListener() ale rowniez musi dbac o to, aby po wcisnieciu klawisza
	// jego stan zostal w nastepnej iteracji zmieniony na false, oraz musi utrzymac ten stan przez jakis czas, ze wzgledu na to zeby postac nie
	// podskakiwala przy kazdej iteracji podczas ktorej klawisz jest wcisniety
	if(key[KEY_SPACE]) { // klawisz wcisniety
		if (!m_isJumpPressed) JUMP = true; // klawisz dopiero wcisnieto
		else JUMP = false; // klawisz zostal wcisniety juz wczesniej
		m_isJumpPressed = true;
	} else m_isJumpPressed = false;
}

InputListener::InputListener() :
	ESC(false),
	LEFT(false),
	RIGHT(false),
	JUMP(false)
{}