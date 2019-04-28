#include "Globals.h"
#include "Application.h"
#include "ModuleSceneWinP2.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include"ModuleScene2.h"
#include "ModulePlayer2.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneIntro.h"
#include "SDL/include/SDL.h"
#include "ModuleParticles.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )



ModuleSceneWinP2::ModuleSceneWinP2()
{

	background = { 0, 0, 304, 224 };
}




ModuleSceneWinP2::~ModuleSceneWinP2()
{}

// Load assets
bool ModuleSceneWinP2::Start()
{

	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("Win_p2.png");

	// TODO 1: Enable (and properly disable) the player module
	App->render->camera.x = App->render->camera.y = 0;
	App->player->destroyed = true;
	App->player2->destroyed = true;
	App->particles->Disable();
	return ret;
}

// Load assets
bool ModuleSceneWinP2::CleanUp()
{

	graphics = nullptr;
	SDL_DestroyTexture(App->textures->Load("Win_p2.png"));

	LOG("Unloading end stage");


	return true;
}

// Update: draw background
update_status ModuleSceneWinP2::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(graphics, 0, 0, &background);

	


	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack(App->end_game2, App->intro, 2.5);
	}


	return UPDATE_CONTINUE;
}
