#include <allegro.h>
#include "InputListener.h"


void InputListener::run()
{
	// resetowanie informacji na temat stanu klawiszy
	LEFT = false;
	RIGHT = false;
	ESC = false;

	// wywolanie listenerow dla klawiszy
	walkListener();
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