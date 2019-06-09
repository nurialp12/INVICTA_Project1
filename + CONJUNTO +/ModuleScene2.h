#ifndef __MODULESCENE2_H__
#define __MODULESCENE2_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleScene2 : public Module
{
public:
	ModuleScene2();
	~ModuleScene2();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	Animation bus;
	//SDL_Rect ground;
	//SDL_Rect roof;
	//SDL_Rect foreground;
	SDL_Rect background;
	Animation background1;

	Animation people1;
	Animation people2;
	Animation people3;
	Animation people4;
	//Animation water;
};

#endif // __MODULESCENE2_H__