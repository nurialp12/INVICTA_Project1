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
	background.PushBack({ 0, 0, 303, 224 });
	background.PushBack({ 304, 0, 303, 224 });
	background.PushBack({ 608, 0, 303, 224 });
	background.PushBack({ 912, 0, 303, 224 });
	background.PushBack({ 1216, 0, 303, 224 });
	background.PushBack({ 0, 224, 303, 224 });
	background.PushBack({ 304, 224, 303, 224 });
	background.PushBack({ 608, 224, 303, 224 });
	background.PushBack({ 912, 224, 303, 224 });
	background.PushBack({ 1216, 224, 303, 224 });
	background.PushBack({ 0, 448, 303, 224 });
	background.PushBack({ 304, 448, 303, 224 });
	background.PushBack({ 608, 448, 303, 224 });
	background.PushBack({ 912, 448, 303, 224 });
	background.PushBack({ 1212, 448, 303, 224 });
	background.PushBack({ 0, 672, 303, 224 });
	background.PushBack({ 304, 672, 303, 224 });
	background.PushBack({ 608, 672, 303, 224 });
	background.PushBack({ 912, 672, 303, 224 });
	background.PushBack({ 1216, 672, 303, 224 });
	background.PushBack({ 0, 896, 303, 224 });
	background.PushBack({ 304, 896, 303, 224 });
	background.PushBack({ 608, 896, 303, 224 });
	background.PushBack({ 912, 896, 303, 224 });
	background.PushBack({ 1216, 896, 303, 224 });
	background.PushBack({ 0, 1120, 303, 224 });
	background.PushBack({ 304, 1120, 303, 224 });
	background.PushBack({ 608, 1120, 303, 224 });
	background.PushBack({ 912, 1120, 303, 224 });
	background.PushBack({ 1216, 1120, 303, 224 });
	background.PushBack({ 0, 1344, 303, 224 });
	background.PushBack({ 304, 1344, 303, 224 });
	background.PushBack({ 608, 1344, 303, 224 });
	background.PushBack({ 912, 1344, 303, 224 });
	background.PushBack({ 1216, 1344, 303, 224 });
	background.PushBack({ 0, 1568, 303, 224 });
	background.PushBack({ 304, 1568, 303, 224 });
	background.PushBack({ 608, 1568, 303, 224 });
	background.PushBack({ 912, 1568, 303, 224 });
	background.PushBack({ 1216, 1568, 303, 224 });
	background.PushBack({ 0, 1792, 303, 224 });
	background.PushBack({ 304, 1792, 303, 224 });
	background.PushBack({ 608, 1792, 303, 224 });
	background.PushBack({ 912, 1792, 303, 224 });
	background.PushBack({ 1216, 1792, 303, 224 });
	background.PushBack({ 0, 2016, 303, 224 });
	background.PushBack({ 304, 2016, 303, 224 });
	background.PushBack({ 608, 2016, 303, 224 });
	background.PushBack({ 912, 2016, 303, 224 });
	background.PushBack({ 1216, 2016, 303, 224 });
	background.PushBack({ 0, 2240, 303, 224 });
	background.PushBack({ 304, 2240, 303, 224 });
	background.PushBack({ 608, 2240, 303, 224 });
	background.PushBack({ 912, 2240, 303, 224 });
	background.PushBack({ 1216, 2240, 303, 224 });
	background.PushBack({ 0, 2464, 303, 224 });
	background.PushBack({ 304, 2464, 303, 224 });
	background.PushBack({ 608, 2464, 303, 224 });
	background.PushBack({ 912, 2464, 303, 224 });
	background.PushBack({ 1216, 2464, 303, 224 });
	background.PushBack({ 0, 2688, 303, 224 });
	background.PushBack({ 304, 2688, 303, 224 });
	background.PushBack({ 608, 2688, 303, 224 });
	background.PushBack({ 912, 2688, 303, 224 });
	background.PushBack({ 1216, 2688, 303, 224 });
	background.PushBack({ 0, 2912, 303, 224 });
	background.PushBack({ 304, 2912, 303, 224 });
	background.PushBack({ 608, 2912, 303, 224 });
	background.PushBack({ 912, 2912, 303, 224 });
	background.PushBack({ 1216, 2912, 303, 224 });
	background.PushBack({ 0, 3136, 303, 224 });
	background.PushBack({ 304, 3136, 303, 224 });
	background.PushBack({ 608, 3136, 303, 224 });
	background.PushBack({ 912, 3136, 303, 224 });
	background.PushBack({ 1216, 3136, 303, 224 });
	background.PushBack({ 0, 3360, 303, 224 });
	background.PushBack({ 304, 3360, 303, 224 });
	background.PushBack({ 608, 3360, 303, 224 });
	background.PushBack({ 912, 3360, 303, 224 });
	background.PushBack({ 1216, 3360, 303, 224 });
	background.PushBack({ 0, 3584, 303, 224 });
	background.PushBack({ 304, 3584, 303, 224 });
	background.PushBack({ 608, 3584, 303, 224 });
	background.PushBack({ 912, 3584, 303, 224 });
	background.PushBack({ 1216, 3584, 303, 224 });
	background.PushBack({ 0, 3808, 303, 224 });
	background.PushBack({ 304, 3808, 303, 224 });
	background.PushBack({ 608, 3808, 303, 224 });
	background.PushBack({ 912, 3808, 303, 224 });
	background.PushBack({ 1216, 3808, 303, 224 });
	background.PushBack({ 0, 4032, 303, 224 });
	background.PushBack({ 304, 4032, 303, 224 });
	background.PushBack({ 608, 4032, 303, 224 });
	background.PushBack({ 912, 4032, 303, 224 });
	background.PushBack({ 1216, 4032, 303, 224 });
	background.PushBack({ 0, 4256, 303, 224 });
	background.speed = 0.25f;
}




ModuleSceneIni::~ModuleSceneIni()
{}

// Load assets
bool ModuleSceneIni::Start()
{
	LOG("Loading background assets");
	
	bool ret = true;
	graphics = App->textures->Load("Neo_Geo.png");


	// TODO 1: Enable (and properly disable) the player module
	App->player->destroyed = true;
	App->player2->destroyed = true;
	return ret;
}

// Load assets
bool ModuleSceneIni::CleanUp()
{

	graphics = nullptr;
	SDL_DestroyTexture(App->textures->Load("Neo_Geo.png"));

	LOG("Unloading ini stage");


	return true;
}

// Update: draw background
update_status ModuleSceneIni::Update()
{
	// Draw everything --------------------------------------	

	//App->render->Blit(graphics, 35, 35, &background);

	App->render->Blit(graphics, -10, 0, &(background.GetCurrentFrame()), 0.70f);

	App->render->camera.x = 0;
	App->render->camera.y = 0;


	if (background.Finished())
	{
		App->fade->FadeToBlack(App->ini, App->scene_2, 2.5);
	}


	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack(App->ini, App->scene_2, 2.5);
	}



	return UPDATE_CONTINUE;
}