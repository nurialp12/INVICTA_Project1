#pragma once

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro();
	~ModuleSceneIntro();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	
	SDL_Texture* graphics5 = nullptr;
	SDL_Texture* graphics6 = nullptr;
	SDL_Texture* graphics7 = nullptr;
	
	Animation background5;
	Animation background6;
	Animation background7;
	//Animation game;



};
