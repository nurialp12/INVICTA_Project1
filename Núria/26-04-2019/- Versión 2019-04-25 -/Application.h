#ifndef __APPLICATION_H__
#define __APPLICATION_H__

#include "Globals.h"

#define NUM_MODULES 15

class ModuleWindow;
class ModuleInput;
class ModuleTextures;
class ModuleRender;
class ModuleScene1;
class ModuleScene2;
class ModulePlayer;
class ModulePlayer2;
class ModuleFadeToBlack;
class ModuleSceneEnd;
class ModuleSceneIni;
class ModuleParticles;
class ModuleCollision;
class Module;
class ModuleAudio;
class ModuleFonts;


class Application
{
public:

	Module* modules[NUM_MODULES];
	ModuleWindow* window;
	ModuleRender* render;
	ModuleInput* input;
	ModuleTextures* textures;
	ModuleScene1* scene_1;
	ModuleScene2* scene_2;
	ModulePlayer* player;
	ModulePlayer2* player2;
	ModuleFadeToBlack* fade;
	ModuleSceneEnd* end_game;
	ModuleSceneIni* ini;
	ModuleParticles* particles;
	ModuleCollision* collisions;
	ModuleAudio* audio;
	ModuleFonts* fonts;

public:

	Application();
	~Application();

	bool Init();
	update_status Update();
	bool CleanUp();

};

// Global var made extern for Application ---
extern Application* App;

#endif // __APPLICATION_H__