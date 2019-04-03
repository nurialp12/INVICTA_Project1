#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphics2 = nullptr;
	Animation TerryPunch;
	Animation TerryKick;
	Animation TerryJump;
	Animation TerryForward;
	Animation TerryBackwards;
	Animation Terryidle;
	iPoint Terryposition;
};

#endif