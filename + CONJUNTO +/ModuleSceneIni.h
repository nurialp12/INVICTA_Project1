#pragma once
#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleSceneIni : public Module
{
public:
	ModuleSceneIni();
	~ModuleSceneIni();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	SDL_Texture* graphics = nullptr;

	//SDL_Texture* graphics2 = nullptr;
	//SDL_Texture* graphicsM = nullptr;
	//SDL_Texture* graphics2M = nullptr;

	Animation background;



};
