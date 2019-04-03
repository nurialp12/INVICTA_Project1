#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

//////// TODO: acabar animacions, fer que graphics2 funcioni, que avanci Terry

ModulePlayer::ModulePlayer()
{
	position.x = 100;
	position.y = 220;

	// idle animation (arcade sprite sheet)
	idle.PushBack({7, 14, 60, 90});
	idle.PushBack({95, 15, 60, 89});
	idle.PushBack({184, 14, 60, 90});
	idle.PushBack({276, 11, 60, 93});
	idle.PushBack({366, 12, 60, 92});
	idle.speed = 0.2f;

	// walk forward animation (arcade sprite sheet)
	//forward.frames.PushBack({9, 136, 53, 83});
	forward.PushBack({78, 131, 60, 88});
	forward.PushBack({162, 128, 64, 92});
	forward.PushBack({259, 128, 63, 90});
	forward.PushBack({352, 128, 54, 91});
	forward.PushBack({432, 131, 50, 89});
	forward.speed = 0.1f;

	// TODO 4: Make ryu walk backwards with the correct animations

	// walk backward animation (arcade sprite sheet)
	//backward.frames.PushBack({9, 136, 53, 83});
	backward.PushBack({ 432, 131, 50, 89 });
	backward.PushBack({ 352, 128, 54, 91 });
	backward.PushBack({ 259, 128, 63, 90 });
	backward.PushBack({ 162, 128, 64, 92 });
	backward.PushBack({ 78, 131, 60, 88 });
	backward.speed = 0.1f;




	//////////////////// HERE ////////////////////

	Terryposition.x = 150;
	Terryposition.y = 220;

	// idle animation of Terry
	//Terryidle.PushBack({ 428, 915, 79, 109 });
	//Terryidle.PushBack({ 505, 915, 68, 105 });
	//Terryidle.speed = 0.2f;

	Terryidle.PushBack({ 27, 914, 60, 105 });
	Terryidle.PushBack({ 95, 916, 61, 104 });
	Terryidle.PushBack({ 164, 916, 60, 103 });
	Terryidle.PushBack({ 95, 916, 61, 104 });
	Terryidle.speed = 0.2f;

	// TODO

	//// walk forward animation of Terry
	////TerryForward.frames.PushBack({/**/, /**/, /**/, /**/});
	//TerryForward.PushBack({ /**/, /**/, /**/, /**/ });
	//TerryForward.PushBack({ /**/, /**/, /**/, /**/ });
	//TerryForward.PushBack({ /**/, /**/, /**/, /**/ });
	//TerryForward.speed = 0.1f;


	//// walk backward animation of Terry
	////TerryBackwards.frames.PushBack({/**/, /**/, /**/, /**/});
	//TerryBackwards.PushBack({ /**/, /**/, /**/, /**/ });
	//TerryBackwards.PushBack({ /**/, /**/, /**/, /**/ });
	//TerryBackwards.PushBack({ /**/, /**/, /**/, /**/ });
	//TerryBackwards.speed = 0.1f;


	//// jump animation of Terry
	////TerryJump.frames.PushBack({/**/, /**/, /**/, /**/});
	//TerryJump.PushBack({ /**/, /**/, /**/, /**/ });
	//TerryJump.PushBack({ /**/, /**/, /**/, /**/ });
	//TerryJump.PushBack({ /**/, /**/, /**/, /**/ });
	//TerryJump.speed = 0.1f;


	// kick animation of Terry
	//TerryKick.frames.PushBack({/**/, /**/, /**/, /**/});
	TerryKick.PushBack({ 570, 463, 67, 110 });
	TerryKick.PushBack({ 638, 463, 83, 125 });
	TerryKick.PushBack({ 732, 463, 128, 117 });
	TerryKick.speed = 0.1f;

	// punch animation of Terry
	//TerryPunch.frames.PushBack({/**/, /**/, /**/, /**/});
	//TerryPunch.PushBack({ 428, 915, 79, 109 });
	//TerryPunch.PushBack({ 505, 915, 68, 105 });
	//TerryPunch.PushBack({ 570, 915, 107, 109 });
	//TerryPunch.speed = 0.1f;

	TerryPunch.PushBack({ 435, 918, 73, 100 });
	TerryPunch.PushBack({ 507, 918, 62, 102 });
	TerryPunch.PushBack({ 574, 917, 97, 103 });
	TerryPunch.speed = 0.2f;



}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player textures");
	bool ret = true;
	//graphics = App->textures->Load("ryu.png"); // arcade version

	//////////////////// HERE ////////////////////

	graphics = App->textures->Load("spritesTerryBogard.png");
	graphics2 = App->textures->Load("TerryAvanzar + SaltoEstatico + Patada + Retroceder.png");
	

	return ret;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	//Animation* current_animation = &idle;

	//int speed = 1;

	//if(App->input->keyboard[SDL_SCANCODE_D] == 1)
	//{
	//	current_animation = &forward;
	//	position.x += speed;
	//}

	//if (App->input->keyboard[SDL_SCANCODE_A] == 1)
	//{
	//	current_animation = &backward;
	//	position.x -= speed;
	//}



	//////////////////// HERE ////////////////////

	Animation* current_animation = &Terryidle;

	int speed = 1;


	//int gravity = -0.3f;

	if (App->input->keyboard[SDL_SCANCODE_D] == 1)
	{
		current_animation = &TerryForward;
		position.x += speed;
	}

	if (App->input->keyboard[SDL_SCANCODE_A] == 1)
	{
		current_animation = &TerryBackwards;
		position.x -= speed;
	}

	//if (App->input->keyboard[SDL_SCANCODE_W] == 1)
	//{
	//	current_animation = &TerryJump;
	//	position.y += speed;
	//	
	//	if (App->input->keyboard[SDL_SCANCODE_W] == 0)
	//	{
	//		position.y -= speed;
	//	}
	//}

	if (App->input->keyboard[SDL_SCANCODE_P] == 1)
	{
		current_animation = &TerryPunch;
		
	}

	if (App->input->keyboard[SDL_SCANCODE_K] == 1)
	{
		current_animation = &TerryKick;
		
	}
	


	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	App->render->Blit(graphics, position.x, position.y - r.h, &r);


	//App->render->Blit(graphics, Terryposition.x, Terryposition.y - r.h, &r);
	//App->render->Blit(graphics2, Terryposition.x, Terryposition.y - r.h, &r);


	return UPDATE_CONTINUE;
}
