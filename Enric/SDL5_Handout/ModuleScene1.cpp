#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleScene1.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleScene2.h"

#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )




ModuleScene1::ModuleScene1()
{
	// bus
	bus.x = 480;
	bus.y = 525;
	bus.w = 145;
	bus.h = 73;

	// foreground
	/*foreground.x = 8;
	foreground.y = 24;
	foreground.w = 521;
	foreground.h = 181;*/

	// Background / sky
	background.x = 3;
	background.y = 3;
	background.w = 473;
	background.h = 117;

	// flag animation
	background1.PushBack({28, 139, 557, 224});
	background1.PushBack({596, 139, 557, 224});
	background1.PushBack({1171, 141, 557, 224});
	background1.speed = 0.05f;

	// Girl Animation
	/*girl.PushBack({624, 16, 32, 56});
	girl.PushBack({624, 80, 32, 56});
	girl.PushBack({624, 144, 32, 56});
	girl.speed = 0.05f;*/

	// for moving the foreground
	//foreground_pos = 0;
	//forward = true;
}

ModuleScene1::~ModuleScene1()
{}

// Load assets
bool ModuleScene1::Start()
{
	LOG("Loading first scene");
	
	graphics = App->textures->Load("Sound_Beach.png");

	// TODO 1: Enable (and properly disable) the player module
	App->player->Enable();
	return true;
}

// UnLoad assets
bool ModuleScene1::CleanUp()
{
	graphics = nullptr;
	SDL_DestroyTexture(App->textures->Load("Sound_Beach.png"));

	LOG("Unloading first scene");
	App->player->Disable();
	return true;
}

// Update: draw background
update_status ModuleScene1::Update()
{


	// Draw everything --------------------------------------
	App->render->Blit(graphics, 0, 0, &background, 0.50f); // sea and sky
	App->render->Blit(graphics, 0, 0, &(background1.GetCurrentFrame()), 0.70f); // beach animation

	//App->render->Blit(graphics, 0, (int)foreground_pos, &foreground, 0.92f);
	//App->render->Blit(graphics, 192, 104 + (int)foreground_pos, &(girl.GetCurrentFrame()), 0.92f); // girl animation
	
	App->render->Blit(graphics, 412, 111, &bus, 0.70f);

	// TODO 3: make so pressing SPACE the HONDA stage is loaded
	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1)
	{
		App->fade->FadeToBlack(App->scene_1, App->scene_2, 2.5);
	}

	return UPDATE_CONTINUE;
}