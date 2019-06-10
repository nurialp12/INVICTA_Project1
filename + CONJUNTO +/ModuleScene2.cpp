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

	//bus
	bus.PushBack({ 480, 525, 145, 73 });
	bus.PushBack({ 480, 524, 145, 74 });
	bus.speed = 0.05f;

	// Background / sky
	background.x = 1349;
	background.y = 631;
	background.w = 469;
	background.h = 107;

	//Shadow
	shadow.x = 522;
	shadow.y = 478;
	shadow.w = 66;
	shadow.h = 12;

	// flag animation
	background1.PushBack({ 718, 379, 619, 235 });
	background1.PushBack({ 1349, 379 , 619, 235 });
	background1.PushBack({ 718, 631, 619, 235 });
	background1.speed = 0.05f;


	//{ /*x*/, /*y*/, /*w*/, /*h*/ });  


	people1.PushBack({ 39, 403, 64, 100 });  
	people1.PushBack({ 39, 512, 64, 100 });
	people1.speed = 0.05f;

	people2.PushBack({ 143, 411, 65, 97 });  
	people2.PushBack({ 143, 518, 65, 97 });
	people2.speed = 0.05f;

	people3.PushBack({ 246, 404, 62, 99 }); 
	people3.PushBack({ 246, 512, 62, 99 });
	people3.speed = 0.05f;

	people4.PushBack({ 347, 402, 69, 95 }); 
	people4.PushBack({ 347, 514, 69, 95 });
	people4.speed = 0.05f;


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


	graphics = App->textures->Load("Assets/Sprites/Sound_Beach.png");

	App->player->Enable();
	App->player2->Enable();
	App->particles->Enable();
	App->collisions->Enable();
	App->player->life_score = 94;
	App->player2->life_score = 94;
	p1won = false;
	p2won = false;

	// TODO 1: Add colliders for the first columns of the level
	

	// TODO 1: Add colliders for the first columns of the level
	

	App->audio->PlayMusic("Assets/music/The ocean knows/The ocean knows.ogg", -1);


	return ret;
}

// Load assets
bool ModuleScene2::CleanUp()
{
	// TODO 4: Remove all memory leaks
	graphics = nullptr;
	SDL_DestroyTexture(App->textures->Load("Assets/Sprites/Sound_Beach.png"));

	LOG("Unloading second stage");
	
	
	App->player->Disable();
	return true;
}

// Update: draw background
update_status ModuleScene2::Update()
{
	// Draw everything --------------------------------------	
	//App->render->Blit(graphics, 0, 160, &ground);
	if (reboot && (p1won || p2won))
	{
		App->player->Disable();
		App->player2->Disable();

		App->player->Enable();
		App->player2->Enable();
		App->collisions->Enable();
		App->render->camera.x = -245;
		App->render->camera.y = -10;
		App->player->life_score = 94;
		App->player2->life_score = 94;
		reboot = false;
	}
	
	App->render->Blit(graphics, 0, -5, &background, 0.35f);
	App->render->Blit(graphics, 0, -11, &(background1.GetCurrentFrame()), 0.60f); // back of the room

	if(App->player->mirror) App->render->Blit(graphics, App->player->Andyposition.x, 202, &shadow);
	else App->render->Blit(graphics, App->player->Andyposition.x - 10, 202, &shadow);
	if(App->player2->mirror2)App->render->Blit(graphics, App->player2->Andy2position.x, 202, &shadow);
	else App->render->Blit(graphics, App->player2->Andy2position.x - 10, 202, &shadow);
	App->render->Blit(graphics, 474, 110, &(bus.GetCurrentFrame()), 0.60f);


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

	App->render->Blit(graphics, 27, 100, &(people1.GetCurrentFrame()), 0.60f);
	App->render->Blit(graphics, 92, 100, &(people3.GetCurrentFrame()), 0.60f);
	App->render->Blit(graphics, 153, 100, &(people2.GetCurrentFrame()), 0.60f);
	App->render->Blit(graphics, 217, 100, &(people4.GetCurrentFrame()), 0.60f);

	App->render->Blit(graphics, 282, 100, &(people1.GetCurrentFrame()), 0.60f);
	App->render->Blit(graphics, 348, 100, &(people3.GetCurrentFrame()), 0.60f);
	App->render->Blit(graphics, 409, 100, &(people2.GetCurrentFrame()), 0.60f);
	/*App->render->Blit(graphics, 200, 100, &(people4.GetCurrentFrame()), 0.60f);*/


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

	if (App->player->life_score <= 0 && !p2won)
	{
		p2won = true;
		App->collisions->Disable();
		//App->player->Disable();
		//App->player2->Disable();
		App->fade->Reboot(2.5);
		
	}
	else if (App->player2->life_score <= 0 && !p1won)
	{
		p1won = true;
		App->collisions->Disable();
		
		App->fade->Reboot(1.5);
	}
	else if (App->player->life_score <= 0 && p2won)
	{
		App->fade->FadeToBlack(App->scene_2, App->end_game2, 2.5);
	}
	else if (App->player2->life_score <= 0 && p1won)
	{
	
		App->fade->FadeToBlack(App->scene_2, App->end_game1, 2.5);
	}
	else if (App->player2->life_score <= 0 && App->player->life_score <= 0)
	{
		App->fade->Reboot(1.5);
	}

	return UPDATE_CONTINUE;
}