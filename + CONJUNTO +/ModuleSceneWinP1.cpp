#include "Globals.h"
#include "Application.h"
#include "ModuleSceneWinP1.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include"ModuleScene2.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneIntro.h"
#include "SDL/include/SDL.h"
#include "ModuleParticles.h"
#include "ModuleAudio.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )



ModuleSceneWinP1::ModuleSceneWinP1()
{

	background = { 0, 0, 304, 224 };
}

	


ModuleSceneWinP1::~ModuleSceneWinP1()
{}

// Load assets
bool ModuleSceneWinP1::Start()
{
	
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("Assets/Sprites/Win_p1.png");
	App->audio->PlayMusic("Assets/music/Results are everything/Results are everything.ogg", 0);

	// TODO 1: Enable (and properly disable) the player module
	App->render->camera.x = App->render->camera.y = -10;
	App->player->destroyed = true;
	App->player2->destroyed = true;
	App->particles->Disable();
	return ret;
}

// Load assets
bool ModuleSceneWinP1::CleanUp()
{

	graphics = nullptr;
	SDL_DestroyTexture(App->textures->Load("Assets/Sprites/Win_p1.png"));

	LOG("Unloading end stage");


	return true;
}

// Update: draw background
update_status ModuleSceneWinP1::Update()
{
	// Draw everything --------------------------------------	
	App->render->Blit(graphics, -7, 0, &background);
	

	
	
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack(App->end_game1, App->intro, 2.5);
	}


	return UPDATE_CONTINUE;
}
