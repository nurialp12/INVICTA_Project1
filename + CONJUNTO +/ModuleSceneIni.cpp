#include "Globals.h"
#include "Application.h"
#include "ModuleScene1.h"
#include "ModuleScene2.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneIni.h"
#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )



ModuleSceneIni::ModuleSceneIni()
{
	background = { 0, 0, 300, 150 };
}




ModuleSceneIni::~ModuleSceneIni()
{}

// Load assets
bool ModuleSceneIni::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("start_game.png");

	// TODO 1: Enable (and properly disable) the player module
	App->player->destroyed = true;
	App->player2->destroyed = true;
	return ret;
}

// Load assets
bool ModuleSceneIni::CleanUp()
{

	graphics = nullptr;
	SDL_DestroyTexture(App->textures->Load("start_game.png"));

	LOG("Unloading ini stage");


	return true;
}

// Update: draw background
update_status ModuleSceneIni::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(graphics, 35, 35, &background);

	App->render->camera.x = 0;
	App->render->camera.y = 0;



	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack(App->ini, App->scene_2, 2.5);
	}



	return UPDATE_CONTINUE;
}