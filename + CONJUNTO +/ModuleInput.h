#ifndef __ModuleInput_H__
#define __ModuleInput_H__

#include "Module.h"
#include "Globals.h"
#include "SDL\include\SDL_scancode.h"
#include "SDL/include/SDL.h"

#define MAX_KEYS 300
#define MAX_BUTTONS 15
#define MAX_GAMEPADS 2

enum KEY_STATE
{
	KEY_IDLE = 0,
	KEY_DOWN,
	KEY_REPEAT,
	KEY_UP
};

enum BUTTON_STATE
{
	BUT_IDLE = 0,
	BUT_DOWN,
	BUT_REPEAT,
	BUT_UP
};

class ModuleInput : public Module
{
public:

	ModuleInput();
	~ModuleInput();

	bool Init();
	update_status PreUpdate();
	bool CleanUp();

public:
	KEY_STATE keyboard[MAX_KEYS];
	Uint8 gpad[MAX_BUTTONS][MAX_GAMEPADS];
	SDL_GameController* gController1 = NULL;
	SDL_GameController* gController2 = NULL;
};

#endif // __ModuleInput_H__