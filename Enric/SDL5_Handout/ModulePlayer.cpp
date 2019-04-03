#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{

	terryposition.x = 150;
	terryposition.y = 220;

	// idle animation of Terry
	terryidle.PushBack({ 428, 915, 79, 109 });
	terryidle.PushBack({ 505, 915, 68, 105 });
	terryidle.speed = 0.2f;

	// TODO

	//// walk forward animation of Terry
	////terryforward.frames.PushBack({/**/, /**/, /**/, /**/});
	//terryforward.PushBack({ /**/, /**/, /**/, /**/ });
	//terryforward.PushBack({ /**/, /**/, /**/, /**/ });
	//terryforward.PushBack({ /**/, /**/, /**/, /**/ });
	//terryforward.speed = 0.1f;


	//// walk backward animation of Terry
	////Terrybackwards.frames.PushBack({/**/, /**/, /**/, /**/});
	//Terrybackwards.PushBack({ /**/, /**/, /**/, /**/ });
	//Terrybackwards.PushBack({ /**/, /**/, /**/, /**/ });
	//Terrybackwards.PushBack({ /**/, /**/, /**/, /**/ });
	//Terrybackwards.speed = 0.1f;


	//// jump animation of Terry
	////TerryJump.frames.PushBack({/**/, /**/, /**/, /**/});
	//TerryJump.PushBack({ /**/, /**/, /**/, /**/ });
	//TerryJump.PushBack({ /**/, /**/, /**/, /**/ });
	//TerryJump.PushBack({ /**/, /**/, /**/, /**/ });
	//TerryJump.speed = 0.1f;


	// kick animation of Terry
	//TerryKick.frames.PushBack({/**/, /**/, /**/, /**/});
	terrykick.PushBack({ 570, 463, 67, 110 });
	terrykick.PushBack({ 638, 463, 83, 125 });
	terrykick.PushBack({ 732, 463, 128, 117 });
	terrykick.speed = 0.1f;

	// punch animation of Terry
	//TerryPunch.frames.PushBack({/**/, /**/, /**/, /**/});
	terrypunch.PushBack({ 428, 915, 79, 109 });
	terrypunch.PushBack({ 505, 915, 68, 105 });
	terrypunch.PushBack({ 570, 915, 107, 109 });
	terrypunch.speed = 0.1f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	graphics = App->textures->Load("spritesTerryBogard.png"); // arcade version
	return ret;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &terryidle;

	int speed = 1;

	if(App->input->keyboard[SDL_SCANCODE_D] == 1)
	{
		current_animation = &terryforward;
		terryposition.x += speed;
	}

	if (App->input->keyboard[SDL_SCANCODE_P] == 1)
	{
		current_animation = &terrypunch;
	}

	if (App->input->keyboard[SDL_SCANCODE_K] == 1)
	{
		current_animation = &terrykick;
	}

	if (App->input->keyboard[SDL_SCANCODE_B] == 1)
	{
		App->particles->AddParticle(App->particles->terryenergy, terryposition.x+3, terryposition.y);
	}

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, terryposition.x, terryposition.y - r.h, &r);
	
	return UPDATE_CONTINUE;
}