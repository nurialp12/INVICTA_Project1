#ifndef __MODULESCENE1_H__
#define __MODULESCENE1_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleScene1 : public Module
{
public:
	ModuleScene1();
	~ModuleScene1();

	bool Start();
	update_status Update();
	bool CleanUp();

public:
	
	SDL_Texture* graphics = nullptr;
	SDL_Rect bus;
	//SDL_Rect foreground;
	SDL_Rect background;
	Animation background1;
	//Animation girl;

	float foreground_pos;
	bool forward;
};

#endif // __MODULESCENE1_H__