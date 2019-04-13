#include "Globals.h"
#include "Application.h"
#include "ModuleEnd.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleIni.h"
#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )



ModuleEnd::ModuleEnd()
{

	background = { 110, 150, 500, 400 };
}

	


ModuleEnd::~ModuleEnd()
{}

// Load assets
bool ModuleEnd::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("game_over.png");

	// TODO 1: Enable (and properly disable) the player module

	return ret;
}

// Load assets
bool ModuleEnd::CleanUp()
{

	graphics = nullptr;
	SDL_DestroyTexture(App->textures->Load("game_over.png"));

	LOG("Unloading end stage");


	return true;
}

// Update: draw background
update_status ModuleEnd::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(graphics, 0, 0, &background);
	

	
	
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack(App->end_game, App->ini, 2.5);
	}


	return UPDATE_CONTINUE;
}
