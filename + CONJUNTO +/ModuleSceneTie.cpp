#include "Globals.h"
#include "Application.h"
#include "ModuleSceneTie.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneIni.h"
#include"ModuleScene2.h"
#include "SDL/include/SDL.h"
#include "ModuleParticles.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )



ModuleSceneTie::ModuleSceneTie()
{

	background = { 110, 150, 500, 400 };
}




ModuleSceneTie::~ModuleSceneTie()
{}

// Load assets
bool ModuleSceneTie::Start()
{

	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("game_over.png");

	// TODO 1: Enable (and properly disable) the player module
	App->render->camera.x = App->render->camera.y = 0;
	App->player->destroyed = true;
	App->player2->destroyed = true;
	App->particles->Disable();
	return ret;
}

// Load assets
bool ModuleSceneTie::CleanUp()
{

	graphics = nullptr;
	SDL_DestroyTexture(App->textures->Load("game_over.png"));

	LOG("Unloading end stage");


	return true;
}

// Update: draw background
update_status ModuleSceneTie::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(graphics, 0, 0, &background);

	App->render->camera.x = 0;
	App->render->camera.y = 0;


	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack(App->tie, App->scene_2, 2.5);
	}


	return UPDATE_CONTINUE;
}