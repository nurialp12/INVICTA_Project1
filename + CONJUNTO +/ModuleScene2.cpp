#include "Globals.h"
#include "Application.h"
#include "ModuleScene2.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleEnd.h"
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

	// Background / sky
	background.PushBack({ 40, 34, 619, 224 });
	background.PushBack({ 40, 300, 619, 224 });
	background.speed = 0.05f;

	// flag animation
	/*water.PushBack({8, 447, 283, 9});
	water.PushBack({296, 447, 283, 12});
	water.PushBack({588, 447, 283, 18});
	water.speed = 0.02f;*/
}

ModuleScene2::~ModuleScene2()
{}

// Load assets
bool ModuleScene2::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("Pao_Pao_Cafe.png");

	// TODO 1: Enable (and properly disable) the player module
	App->player->Enable();
	App->player2->Enable();
	App->particles->Enable();
	App->collisions->Enable();

	// TODO 1: Add colliders for the first columns of the level
	

	App->audio->PlayMusic("music/Haremar religion/Haremar religion.ogg");

	return ret;
}

// Load assets
bool ModuleScene2::CleanUp()
{
	// TODO 4: Remove all memory leaks
	graphics = nullptr;
	SDL_DestroyTexture(App->textures->Load("Pao_Pao_Cafe.png"));

	LOG("Unloading second stage");
	
	
	App->player->Disable();
	return true;
}

// Update: draw background
update_status ModuleScene2::Update()
{
	// Draw everything --------------------------------------	
	//App->render->Blit(graphics, 0, 160, &ground);
	App->render->Blit(graphics, 0, 0, &(background.GetCurrentFrame()), 0.70f); // back of the room
	
	//App->render->Blit(graphics, 280, 125, &foreground);
	//App->render->Blit(graphics, 305, 136, &(water.GetCurrentFrame())); // water animation
	//App->render->Blit(graphics, 0, -16, &roof, 0.75f);

	// TODO 3: make so pressing SPACE the KEN stage is loaded
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1)
	{
		App->fade->FadeToBlack(App->scene_2, App->end_game, 2.5);  
	}


	return UPDATE_CONTINUE;
}