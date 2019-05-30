#include "Globals.h"
#include "Application.h"
#include "ModuleScene2.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneWinP1.h"
#include "ModuleSceneWinP2.h"
#include "ModuleSceneTie.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModuleAudio.h"

#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )



ModuleScene2::ModuleScene2()
{
	// ground
	//ground = {8, 376, 848, 64};

	// roof
	//roof = {91, 7, 765, 49};

	// foreground
	//foreground = {164, 66, 336, 51};

	//// Background / sky
	//background.PushBack({ 40, 34, 619, 224 });
	//background.PushBack({ 40, 300, 619, 224 });
	//background.speed = 0.05f;

	// flag animation
	/*water.PushBack({8, 447, 283, 9});
	water.PushBack({296, 447, 283, 12});
	water.PushBack({588, 447, 283, 18});
	water.speed = 0.02f;*/

	// bus
	/*bus.x = 480;
	bus.y = 525;
	bus.w = 145;
	bus.h = 73;*/

	// Background / sky
	background.x = 3;
	background.y = 3;
	background.w = 473;
	background.h = 117;

	// flag animation
	background1.PushBack({ 718, 390, 619, 224 });
	background1.PushBack({ 1349, 390, 619, 224 });
	background1.PushBack({ 718, 642, 619, 224 });
	background1.speed = 0.05f;
}

ModuleScene2::~ModuleScene2()
{}

// Load assets
bool ModuleScene2::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	//graphics = App->textures->Load("Assets/Sprites/Pao_Pao_Cafe.png");

	App->render->camera.x = -245;
	App->render->camera.y = -10;


	graphics = App->textures->Load("Assets/Sprites/Sound_Beach2.png");

	App->player->Enable();
	App->player2->Enable();
	App->particles->Enable();
	App->collisions->Enable();

	// TODO 1: Add colliders for the first columns of the level
	App->collisions->AddCollider({ 0, 0, 10, 300 }, COLLIDER_WALL);
	App->collisions->AddCollider({ 650, 0, 10, 300 }, COLLIDER_WALL);

	// TODO 1: Add colliders for the first columns of the level
	

	App->audio->PlayMusic("Assets/music/The ocean knows/The ocean knows.ogg", -1);


	return ret;
}

// Load assets
bool ModuleScene2::CleanUp()
{
	// TODO 4: Remove all memory leaks
	graphics = nullptr;
	SDL_DestroyTexture(App->textures->Load("Assets/Sprites/Sound_Beach2.png"));

	LOG("Unloading second stage");
	
	
	App->player->Disable();
	return true;
}

// Update: draw background
update_status ModuleScene2::Update()
{
	// Draw everything --------------------------------------	
	//App->render->Blit(graphics, 0, 160, &ground);
	App->render->Blit(graphics, 0, -25, &background, 0.60f);
	App->render->Blit(graphics, 0, 0, &(background1.GetCurrentFrame()), 0.70f); // back of the room
	

	//N�RIA: BLOQUEA LA C�MARA EN EL CENTRO DURANTE EL PAOPAO
	//App->render->camera.x = -480;
	//App->render->camera.y = 0;

	//App->render->Blit(graphics, 412, 111, &bus, 0.70f);

	//App->render->Blit(graphics, 280, 125, &foreground);
	//App->render->Blit(graphics, 305, 136, &(water.GetCurrentFrame())); // water animation
	//App->render->Blit(graphics, 0, -16, &roof, 0.75f);


	if (App->input->keyboard[SDL_SCANCODE_F9] == 1)
	{
		App->audio->MuteMusic("Assets/music/The ocean knows/The ocean knows.ogg", -1);
	}


	// TODO 3: make so pressing SPACE the KEN stage is loaded
	if (App->input->keyboard[SDL_SCANCODE_F2] == 1)
	{
		
		App->fade->FadeToBlack(App->scene_2, App->end_game1, 2.5);  
	}
	if (App->input->keyboard[SDL_SCANCODE_F3] == 1)
	{
		App->fade->FadeToBlack(App->scene_2, App->end_game2, 2.5);
	}
	if (App->input->keyboard[SDL_SCANCODE_F4] == 1)
	{
		App->fade->FadeToBlack(App->scene_2, App->end_game1, 2.5);
	}
	if (App->input->keyboard[SDL_SCANCODE_F6] == 1)
	{
		App->fade->FadeToBlack(App->scene_2, App->end_game2, 2.5);
	}
	if (App->input->keyboard[SDL_SCANCODE_F7] == 1)
	{
		App->fade->FadeToBlack(App->scene_2, App->end_game1, 2.5);
	}
	if (App->player->life_score <= 0)
	{
		App->fade->FadeToBlack(App->scene_2, App->end_game2, 2.5);
	}
	if (App->player2->life_score <= 0)
	{
		App->fade->FadeToBlack(App->scene_2, App->end_game1, 2.5);
	}
	if (App->player2->life_score <= 0 && App->player->life_score <= 0)
	{
		App->fade->FadeToBlack(App->scene_2, App->end_game1, 2.5);
	}


	return UPDATE_CONTINUE;
}