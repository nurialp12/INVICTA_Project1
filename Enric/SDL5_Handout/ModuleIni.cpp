#include "Globals.h"
#include "Application.h"
#include "ModuleScene1.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleIni.h"
#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )



ModuleIni::ModuleIni()
{
	background = { 0, 0, 300, 150 };
}




ModuleIni::~ModuleIni()
{}

// Load assets
bool ModuleIni::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("start_game.png");

	// TODO 1: Enable (and properly disable) the player module

	return ret;
}

// Load assets
bool ModuleIni::CleanUp()
{

	graphics = nullptr;
	SDL_DestroyTexture(App->textures->Load("start_game.png"));

	LOG("Unloading ini stage");


	return true;
}

// Update: draw background
update_status ModuleIni::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(graphics, 35, 35, &background);





	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1)
	{
		App->fade->FadeToBlack(App->ini, App->scene_1, 2.5);
	}



	return UPDATE_CONTINUE;
}