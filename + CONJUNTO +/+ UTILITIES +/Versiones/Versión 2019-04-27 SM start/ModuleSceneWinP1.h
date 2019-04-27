#pragma once
#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleSceneWinP1 : public Module
{
public:
	ModuleSceneWinP1();
	~ModuleSceneWinP1();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect background;
	

};
