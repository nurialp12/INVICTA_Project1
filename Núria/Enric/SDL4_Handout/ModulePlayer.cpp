#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"

// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

//////// TODO: acabar animacions (que salti, canviar la velocitat, canviar Backwards), Terry s'enfonsa a l'avançar

ModulePlayer::ModulePlayer()
{
	
	Terryposition.x = 100;
	Terryposition.y = 220;

	// idle animation of Terry					//spritesTerryBogard.png

	//Terryidle.PushBack({ 428, 915, 79, 109 });
	//Terryidle.PushBack({ 505, 915, 68, 105 });
	//Terryidle.speed = 0.2f;

	Terryidle.PushBack({ 27, 914, 60, 105 });
	Terryidle.PushBack({ 95, 916, 61, 104 });
	Terryidle.PushBack({ 164, 916, 60, 103 });
	Terryidle.PushBack({ 95, 916, 61, 104 });
	Terryidle.speed = 0.2f;


	// walk forward animation of Terry					//TerryAvanzar+SaltoEstatico+Patada+Retroceder.png
	
	//TerryForward.frames.PushBack({/**/, /**/, /**/, /**/});
	
	TerryForward.PushBack({ 20, 277, 61, 104 });
	TerryForward.PushBack({ 95, 274, 61 /*71*/, 107 });
	TerryForward.PushBack({ 177, 275, 61, 106 });
	TerryForward.PushBack({ 251, 278, 61, 61 });
	TerryForward.speed = 0.2f;


	// walk backward animation of Terry					//TerryAvanzar+SaltoEstatico+Patada+Retroceder.png

	//TerryBackwards.frames.PushBack({/**/, /**/, /**/, /**/});

	TerryBackwards.PushBack({ 441, 275, 57, 106 });
	TerryBackwards.speed = 0.1f;
	

	// jump animation of Terry				//TerryAvanzar+SaltoEstatico+Patada+Retroceder.png

	//TerryJump.frames.PushBack({/**/, /**/, /**/, /**/});
	
	TerryJump.PushBack({ 535, 12, 53, 125 });
	TerryJump.PushBack({ 598, 22, 59, 105 });
	TerryJump.PushBack({ 667, 33, 59, 94 });
	TerryJump.speed = 0.1f;


	// kick animation of Terry				//TerryAvanzar+SaltoEstatico+Patada+Retroceder.png

	//TerryKick.frames.PushBack({/**/, /**/, /**/, /**/});
	TerryKick.PushBack({ 20, 129, 49, 95 });
	TerryKick.PushBack({ 73, 129, 59, 111 });
	TerryKick.PushBack({ 138, 129, 44, 107 });
	TerryKick.PushBack({ 200, 141, 118, 99 });
	TerryKick.PushBack({ 331, 129, 64, 111 });
	TerryKick.speed = 0.1f;


	// punch animation of Terry					//spritesTerryBogard.png

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

	graphics = App->textures->Load("spritesTerryBogard.png");

	graphics2 = App->textures->Load("TerryAvanzar+SaltoEstatico+Patada+Retroceder.png");
	

	return ret;
}

// Update: draw background
update_status ModulePlayer::Update()
{

	Animation* current_animation = &Terryidle;

	int speed = 1;

	if (App->input->keyboard[SDL_SCANCODE_D] == 1)
	{
		current_animation = &TerryForward;
		Terryposition.x += speed;
	}

	if (App->input->keyboard[SDL_SCANCODE_A] == 1)
	{
		current_animation = &TerryBackwards;
		Terryposition.x -= speed;
	}

	if (App->input->keyboard[SDL_SCANCODE_W] == 1)
	{
		current_animation = &TerryJump;
		position.y += speed;					////NO PUJA XD
		
		//if (App->input->keyboard[SDL_SCANCODE_W] == 0)
		//{
		//	position.y += speed;
		//}
	}

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
	
	//if ((App->input->keyboard[SDL_SCANCODE_K] || App->input->keyboard[SDL_SCANCODE_W] || App->input->keyboard[SDL_SCANCODE_A] || App->input->keyboard[SDL_SCANCODE_D]) == 1)
	//{
	//App->render->Blit(graphics2, Terryposition.x, Terryposition.y - r.h, &r);

	//}

	if ((current_animation == (&TerryKick)) || current_animation == (&TerryJump) || current_animation == (&TerryForward) || current_animation == (&TerryBackwards)/*current_animation == (&TerryKick || &TerryJump || &TerryForward || &TerryBackwards)*/)
	{
		App->render->Blit(graphics2, Terryposition.x, Terryposition.y - r.h, &r);

	}


	else
	{
		App->render->Blit(graphics, Terryposition.x, Terryposition.y - r.h, &r);
	}
	


	return UPDATE_CONTINUE;
}
