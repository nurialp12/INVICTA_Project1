#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleBackground.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModuleBackground::ModuleBackground()
{
	// ground
	ground.x = 8;
	ground.y = 391;
	ground.w = 896;
	ground.h = 72;

	// Background / sky
	background.x = 72;
	background.y = 208;
	background.w = 768;
	background.h = 176;

	// ship
	ship.x = 6;
	ship.y = 24;
	ship.w = 523;
	ship.h = 182;

	// flag animation
	flag.PushBack({848, 208, 40, 40});
	flag.PushBack({848, 256, 40, 40});
	flag.PushBack({848, 304, 40, 40});
	flag.speed = 0.08f;

	// girl animation
	girl.PushBack({ 624, 15, 33, 57 });
	girl.PushBack({ 624, 79, 33, 57 });
	girl.PushBack({ 624, 143, 33, 57 });
	girl.speed = 0.06f;



	// gentlemen animation
	gentlemen.PushBack({ 624, 15, 33, 57 });
	gentlemen.PushBack({ 624, 79, 33, 57 });
	gentlemen.PushBack({ 624, 143, 33, 57 });
	gentlemen.speed = 0.06f;

	// boy animation
	boy.PushBack({ 624, 15, 33, 57 });
	boy.PushBack({ 624, 79, 33, 57 });
	boy.PushBack({ 624, 143, 33, 57 });
	boy.speed = 0.06f;

	// captain animation
	captain.PushBack({ 703, 15, 50, 57 });
	captain.PushBack({ 703, 79, 50, 57 });
	captain.PushBack({ 703, 143, 50, 57 });
	captain.speed = 0.06f;

	// purpleman animation
	purpleman.PushBack({ 624, 15, 33, 57 });
	purpleman.PushBack({ 624, 79, 33, 57 });
	purpleman.PushBack({ 624, 143, 33, 57 });
	purpleman.speed = 0.06f;

	// chillman animation
	chillman.PushBack({ 624, 15, 33, 57 });
	chillman.PushBack({ 624, 79, 33, 57 });
	chillman.PushBack({ 624, 143, 33, 57 });
	chillman.speed = 0.06f;






}

ModuleBackground::~ModuleBackground()
{}

// Load assets
bool ModuleBackground::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	graphics = App->textures->Load("ken_stage.png");
	return ret;
}

// Update: draw background
update_status ModuleBackground::Update()
{
	// Draw everything --------------------------------------
	App->render->Blit(graphics, 0, 0, &background, 0.75f); // sea and sky
	App->render->Blit(graphics, 560, 8, &(flag.GetCurrentFrame()), 0.75f); // flag animation

	// TODO 2: Draw the ship from the sprite sheet with some parallax effect
	
	App->render->Blit(graphics, 0, 0, &ship, 0.9f);

	

	// TODO 3: Animate the girl on the ship (see the sprite sheet)
	
	App->render->Blit(graphics, 194, 103, &(girl.GetCurrentFrame()), 0.9f); // girl animation


	// TODO 4 (míos): Animate others on the ship (see the sprite sheet)

	App->render->Blit(graphics, 289, 95, &(captain.GetCurrentFrame()), 0.9f); // captain animation



	App->render->Blit(graphics, 0, 170, &ground);

	return UPDATE_CONTINUE;
}