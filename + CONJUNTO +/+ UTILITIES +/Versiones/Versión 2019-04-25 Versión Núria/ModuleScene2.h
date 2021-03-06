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
	//SDL_Rect ground;
	//SDL_Rect roof;
	//SDL_Rect foreground;
	Animation background;
	//Animation water;
};

#endif // __MODULESCENE2_H__