#pragma once
#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleSceneWinP2 : public Module
{
public:
	ModuleSceneWinP2();
	~ModuleSceneWinP2();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;
	SDL_Rect background;


};