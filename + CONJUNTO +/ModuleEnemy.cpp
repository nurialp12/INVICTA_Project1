#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"
#include "ModuleFonts.h"

#include "p2Qeue.h"
#include "SDL\include\SDL.h"
#include <stdio.h>

int speed = 1;
float stantardDMG = 11.5;
int jumpspeed = 60;
int cameraspeed = 20;
bool airkick = true;

bool up = false;
bool down = false;
bool nothing = true;

ModulePlayer::ModulePlayer()
{
	lifebar = { 15, 69, 166, 75 };
	life1 = { 10, 77, 1, 6 };
	life2 = { 11, 77, 4, 6 };

	//IDLE
	Terryidle.PushBack({ 28, 909, 58, 112 });
	Terryidle.PushBack({ 96, 910, 59, 112 });
	Terryidle.PushBack({ 165, 909, 58, 112 });
	Terryidle.PushBack({ 96, 910, 59, 112 });
	Terryidle.speed = 0.1f;

	// WALK FORWARD animation of Terry					//TerryAvanzar+SaltoEstatico+Patada+Retroceder.png
	TerryForward.PushBack({ 21, 268, 59, 112 });
	TerryForward.PushBack({ 96, 268, 69, 112 });
	TerryForward.PushBack({ 178, 268, 59, 112 });
	TerryForward.PushBack({ 252, 268, 59, 112 });
	TerryForward.speed = 0.1f;

	// WALK BACKWARD animation of Terry					//spritesTerryBogard2extres.png
	TerryBackwards.PushBack({ 382, 270, 59, 112 });
	TerryBackwards.PushBack({ 442, 270, 55, 112 });
	TerryBackwards.PushBack({ 497, 270, 56, 112 });
	TerryBackwards.PushBack({ 553, 270, 57, 112 });
	TerryBackwards.speed = 0.1f;


	// JUMP animation of Terry							//spritesTerryBogard2extres.png
	//LAUNCH AND UP
	TerryGoingUp.PushBack({ 802, 0, 57, 123 });
	TerryGoingUp.PushBack({ 859, 0, 51, 123 });
	TerryGoingUp.PushBack({ 859, 0, 51, 123 });
	TerryGoingUp.PushBack({ 859, 0, 51, 123 });
	TerryGoingUp.PushBack({ 859, 0, 51, 123 });
	TerryGoingUp.PushBack({ 910, 0, 53, 123 });
	TerryGoingUp.speed = 0.1f;
	//GOING DOWN AND LAND
	TerryGoingDown.PushBack({ 967, 0, 57, 123 });
	TerryGoingDown.PushBack({ 802, 0, 57, 123 });
	TerryGoingDown.speed = 0.1f;

	// KICK animation of Terry							//spritesTerryBogard2extres.png
	TerryKick.PushBack({ 0, 134,  47, 112 });
	TerryKick.PushBack({ 47, 134,  57, 112 });
	TerryKick.PushBack({ 104, 134,  42, 112 });
	TerryKick.PushBack({ 146, 134, 116, 112 });
	TerryKick.PushBack({ 261, 134,  62, 112 });
	TerryKick.speed = 0.1f;

	//PUNCH
	TerryPunch.PushBack({ 435, 910, 71, 112 });
	TerryPunch.PushBack({ 507, 911, 61, 112 });
	TerryPunch.PushBack({ 575, 911, 95, 112 });
	TerryPunch.speed = 0.1f;

	// POWER WAVE animation of Terrry
	TerryPW.PushBack({ 623, 683, 51, 112 });
	TerryPW.PushBack({ 550, 683, 54, 112 });
	TerryPW.PushBack({ 485, 683, 60, 112 });
	TerryPW.PushBack({ 402, 683, 79, 112 });
	TerryPW.PushBack({ 330, 683, 67, 112 });
	TerryPW.PushBack({ 263, 683, 65, 112 });
	TerryPW.PushBack({ 198, 683, 60, 112 });
	TerryPW.speed = 0.1f;

	//DAMAGED BY PUNCH
	TerryDP.PushBack({ 0, 912, 59, 112 });
	TerryDP.PushBack({ 64, 912, 67, 112 });
	TerryDP.speed = 0.1f;

	//DAMAGED BY KICK
	TerryDK.PushBack({ 136, 912, 63, 112 });
	TerryDK.PushBack({ 211, 912, 68, 112 });
	TerryDK.speed = 0.1f;

	//CROUCH
	TerryCrouch.PushBack({ 488, 912, 57, 112 });
	TerryCrouch.PushBack({ 545, 912, 52, 112 });
	TerryCrouch.speed = 0.2f;
	TerryCrouch.loop = false;

	//JUMPFORWARD
	TerryJumpForward.PushBack({ 624, 912, 57, 112 });
	TerryJumpForward.PushBack({ 681, 912, 56, 112 });
	TerryJumpForward.PushBack({ 737, 912, 87, 112 });
	TerryJumpForward.PushBack({ 824, 912, 53, 112 });
	TerryJumpForward.PushBack({ 877, 912, 87, 112 });
	TerryJumpForward.PushBack({ 964, 912, 60, 112 });
	TerryJumpForward.PushBack({ 624, 912, 57, 112 });
	TerryJumpForward.speed = 0.1f;

	//JUMPBACKWARDS
	TerryJumpBackwards.PushBack({ 624, 912, 57, 112 });
	TerryJumpBackwards.PushBack({ 964, 912, 60, 112 });
	TerryJumpBackwards.PushBack({ 877, 912, 87, 112 });
	TerryJumpBackwards.PushBack({ 824, 912, 53, 112 });
	TerryJumpBackwards.PushBack({ 737, 912, 87, 112 });
	TerryJumpBackwards.PushBack({ 681, 912, 56, 112 });
	TerryJumpBackwards.PushBack({ 624, 912, 57, 112 });
	TerryJumpBackwards.speed = 0.1f;

	//CROUCHPUNCH
	TerryCrouchPunch.PushBack({ 279, 912, 56, 112 }); //Charge
	TerryCrouchPunch.PushBack({ 416, 912, 49, 112 }); //Riposte
	TerryCrouchPunch.PushBack({ 335, 912, 81, 112 }); //Punch
	TerryCrouchPunch.PushBack({ 416, 912, 49, 112 }); //Riposte x2
	TerryCrouchPunch.speed = 0.1f;

	//CROUCHKICK
	TerryCrouchKick.PushBack({ 0, 788, 56, 112 });   //Charge
	TerryCrouchKick.PushBack({ 56, 788, 58, 112 });  //Riposte
	TerryCrouchKick.PushBack({ 114, 788, 92, 112 }); //Punch
	TerryCrouchKick.PushBack({ 206, 788, 58, 112 }); //Riposte x2
	TerryCrouchKick.speed = 0.1f;

	//JUMPPUNCH
	TerryJumpPunch.PushBack({ 488, 789, 44, 112 }); //Charge
	TerryJumpPunch.PushBack({ 544, 805, 68, 96 });   //Punch
	TerryJumpPunch.PushBack({ 802, 0, 57, 123 });     //Land

	//JUMPKICK
	TerryJumpKick.PushBack({ 304, 830, 56, 70 });  //Charge
	TerryJumpKick.PushBack({ 376, 789, 78, 111 }); //Kick
	TerryJumpKick.PushBack({ 304, 830, 56, 70 });  //Discharge
	TerryJumpKick.PushBack({ 802, 0, 57, 123 });   //Land

		//hit particle animation
	hit.PushBack({ 671, 263, 22, 33 });
	hit.PushBack({ 690, 263, 24, 33 });
	hit.PushBack({ 721, 263, 32, 33 });
	hit.PushBack({ 757, 263, 32, 33 });
	hit.speed = 0.5f;


	//MIRROR -----------------------------------------------------------------------------------------				//spritesTerryBogardMIRROR.png				//spritesTerryBogard2extresMIRROR.png

	//IDLE
	TerryidleM.PushBack({ 0, 912, 59, 112 });		//1
	TerryidleM.PushBack({ 59, 912, 59, 112 });		//2
	TerryidleM.PushBack({ 118, 912, 59, 112 });		//3
	TerryidleM.PushBack({ 59, 912, 59, 112 });		//2
	TerryidleM.speed = 0.1f;

	// WALK FORWARD animation of Terry					//TerryAvanzar+SaltoEstatico+Patada+Retroceder.png
	TerryForwardM.PushBack({ 21, 268, 59, 112 });
	TerryForwardM.PushBack({ 96, 268, 69, 112 });
	TerryForwardM.PushBack({ 178, 268, 59, 112 });
	TerryForwardM.PushBack({ 252, 268, 59, 112 });
	TerryForwardM.speed = 0.1f;

	// WALK BACKWARD animation of Terry					//spritesTerryBogard2extres.png
	TerryBackwardsM.PushBack({ 382, 270, 59, 112 });
	TerryBackwardsM.PushBack({ 442, 270, 55, 112 });
	TerryBackwardsM.PushBack({ 497, 270, 56, 112 });
	TerryBackwardsM.PushBack({ 553, 270, 57, 112 });
	TerryBackwardsM.speed = 0.1f;

	// JUMP animation of Terry							//spritesTerryBogard2extres.png
	TerryJumpM.PushBack({ 802, 0, 57, 123 });
	TerryJumpM.PushBack({ 859, 0, 51, 123 });
	TerryJumpM.PushBack({ 910, 0, 53, 123 });
	TerryJumpM.PushBack({ 967, 0, 57, 123 });
	TerryJumpM.PushBack({ 802, 0, 57, 123 });
	TerryJumpM.speed = 0.1f;

	// KICK animation of Terry							//spritesTerryBogard2extres.png
	TerryKickM.PushBack({ 0, 134,  47, 112 });
	TerryKickM.PushBack({ 47, 134,  57, 112 });
	TerryKickM.PushBack({ 104, 134,  42, 112 });
	TerryKickM.PushBack({ 146, 134, 116, 112 });
	TerryKickM.PushBack({ 261, 134,  62, 112 });
	TerryKickM.speed = 0.1f;

	//PUNCH
	TerryPunchM.PushBack({ 435, 910, 71, 112 });
	TerryPunchM.PushBack({ 507, 911, 61, 112 });
	TerryPunchM.PushBack({ 575, 911, 95, 112 });
	TerryPunchM.speed = 0.1f;

	// POWER WAVE animation of Terrry
	TerryPWM.PushBack({ 623, 683, 51, 112 });
	TerryPWM.PushBack({ 550, 683, 54, 112 });
	TerryPWM.PushBack({ 485, 683, 60, 112 });
	TerryPWM.PushBack({ 402, 683, 79, 112 });
	TerryPWM.PushBack({ 330, 683, 67, 112 });
	TerryPWM.PushBack({ 263, 683, 65, 112 });
	TerryPWM.PushBack({ 198, 683, 60, 112 });
	TerryPWM.speed = 0.1f;

	//DAMAGED BY PUNCH
	TerryDPM.PushBack({ 0, 912, 59, 112 });
	TerryDPM.PushBack({ 64, 912, 67, 112 });
	TerryDPM.speed = 0.1f;

	//DAMAGED BY KICK
	TerryDKM.PushBack({ 136, 912, 63, 112 });
	TerryDKM.PushBack({ 211, 912, 68, 112 });
	TerryDKM.speed = 0.1f;

	//CROUCH
	TerryCrouchM.PushBack({ 488, 912, 57, 112 });
	TerryCrouchM.PushBack({ 545, 912, 52, 112 });
	TerryCrouchM.speed = 0.2f;
	TerryCrouchM.loop = false;

	//JUMPFORWARD
	TerryJumpForwardM.PushBack({ 624, 912, 57, 112 });
	TerryJumpForwardM.PushBack({ 681, 912, 56, 112 });
	TerryJumpForwardM.PushBack({ 737, 912, 87, 112 });
	TerryJumpForwardM.PushBack({ 824, 912, 53, 112 });
	TerryJumpForwardM.PushBack({ 877, 912, 87, 112 });
	TerryJumpForwardM.PushBack({ 964, 912, 60, 112 });
	TerryJumpForwardM.PushBack({ 624, 912, 57, 112 });
	TerryJumpForwardM.speed = 0.1f;

	//JUMPBACKWARDS
	TerryJumpBackwardsM.PushBack({ 624, 912, 57, 112 });
	TerryJumpBackwardsM.PushBack({ 964, 912, 60, 112 });
	TerryJumpBackwardsM.PushBack({ 877, 912, 87, 112 });
	TerryJumpBackwardsM.PushBack({ 824, 912, 53, 112 });
	TerryJumpBackwardsM.PushBack({ 737, 912, 87, 112 });
	TerryJumpBackwardsM.PushBack({ 681, 912, 56, 112 });
	TerryJumpBackwardsM.PushBack({ 624, 912, 57, 112 });
	TerryJumpBackwardsM.speed = 0.1f;

	//CROUCHPUNCH
	TerryCrouchPunchM.PushBack({ 279, 912, 56, 112 }); //Charge
	TerryCrouchPunchM.PushBack({ 416, 912, 49, 112 }); //Riposte
	TerryCrouchPunchM.PushBack({ 335, 912, 81, 112 }); //Punch
	TerryCrouchPunchM.PushBack({ 416, 912, 49, 112 }); //Riposte x2
	TerryCrouchPunchM.speed = 0.1f;

	//CROUCHKICK
	TerryCrouchKickM.PushBack({ 0, 788, 56, 112 });   //Charge
	TerryCrouchKickM.PushBack({ 56, 788, 58, 112 });  //Riposte
	TerryCrouchKickM.PushBack({ 114, 788, 92, 112 }); //Punch
	TerryCrouchKickM.PushBack({ 206, 788, 58, 112 }); //Riposte x2
	TerryCrouchKickM.speed = 0.1f;

	//JUMPPUNCH
	TerryJumpPunchM.PushBack({ 488, 789, 44, 112 }); //Charge
	TerryJumpPunchM.PushBack({ 544, 805, 68, 96 });   //Punch
	TerryJumpPunchM.PushBack({ 802, 0, 57, 123 });     //Land

	//JUMPKICK
	TerryJumpKickM.PushBack({ 304, 830, 56, 70 });  //Charge
	TerryJumpKickM.PushBack({ 376, 789, 78, 111 }); //Kick
	TerryJumpKickM.PushBack({ 304, 830, 56, 70 });  //Discharge
	TerryJumpKickM.PushBack({ 802, 0, 57, 123 });   //Land

			//hit particle animation
	hitM.PushBack({ 671, 263, 22, 33 });
	hitM.PushBack({ 690, 263, 24, 33 });
	hitM.PushBack({ 721, 263, 32, 33 });
	hitM.PushBack({ 757, 263, 32, 33 });
	hitM.speed = 0.5f;

}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	// MIRROR
	if (Terryposition.x <= App->player2->Terry2position.x) { mirror = false; }
	else { mirror = true; }

	LOG("Loading player");
	bool ret = true;
	graphics = App->textures->Load("Assets/Sprites/spritesTerryBogard.png");
	graphics2 = App->textures->Load("Assets/Sprites/spritesTerryBogard2extres.png");


	graphicsM = App->textures->Load("Assets/Sprites/spritesTerryBogardMIRROR.png");
	graphics2M = App->textures->Load("Assets/Sprites/spritesTerryBogard2extresMIRROR.png");

	UI = App->textures->Load("Assets/Sprites/UI.png");

	destroyed = false;
	Terryposition.x = 5 + (250);
	Terryposition.y = 100;
	score = 0;
	col = App->collisions->AddCollider({ 0, 0, 30, 101 }, COLLIDER_PLAYER, App->player);
	colj = App->collisions->AddCollider({ 1000, 1000, 36, 60 }, COLLIDER_PLAYER);
	colcp = App->collisions->AddCollider({ 1000, 1000, 25, 20 }, COLLIDER_PLAYER_SHOT, App->player);
	colck = App->collisions->AddCollider({ 1000, 1000, 40, 20 }, COLLIDER_PLAYER_SHOT, App->player);

	currentstate = ST_IDLE;
	current_animation = &Terryidle;

	font_score = App->fonts->Load("Assets/Sprites/fonts/scorenums.png", "1234567890", 1);
	return ret;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);
	App->textures->Unload(graphics2);
	App->textures->Unload(graphicsM);
	App->textures->Unload(graphics2M);

	App->fonts->UnLoad(font_score);
	if (col)
		col->to_delete = true;

	return true;
}

update_status ModulePlayer::PreUpdate()
{
	inputTerry.A_DOWN = App->input->keyboard[SDL_SCANCODE_A] == KEY_REPEAT;
	inputTerry.D_DOWN = App->input->keyboard[SDL_SCANCODE_D] == KEY_REPEAT;
	inputTerry.S_DOWN = App->input->keyboard[SDL_SCANCODE_S] == KEY_REPEAT;
	inputTerry.W_DOWN = App->input->keyboard[SDL_SCANCODE_W] == KEY_REPEAT;
	inputTerry.F_DOWN = App->input->keyboard[SDL_SCANCODE_F] == KEY_DOWN;
	inputTerry.G_DOWN = App->input->keyboard[SDL_SCANCODE_G] == KEY_DOWN;
	inputTerry.H_DOWN = App->input->keyboard[SDL_SCANCODE_H] == KEY_DOWN;
	inputTerry.SD_DOWN = (App->input->keyboard[SDL_SCANCODE_S] == KEY_DOWN) && (App->input->keyboard[SDL_SCANCODE_D] == KEY_DOWN);

	SDL_Event event;

	while (SDL_PollEvent(&event) != 0)
	{
		if (event.type == SDL_KEYUP && event.key.repeat == 0)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				break;
			case SDLK_DOWN:
				break;
			case SDLK_UP:
				break;
			case SDLK_LEFT:
				break;
			case SDLK_RIGHT:
				break;
			}
		}
		if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_SPACE:
				break;
			case SDLK_UP:
				break;
			case SDLK_DOWN:
				break;
			case SDLK_LEFT:
				break;
			case SDLK_RIGHT:
				break;
			}
		}
	}
	return UPDATE_CONTINUE;
}

update_status ModulePlayer::Update()
{
	// MIRROR
	if (Terryposition.x <= App->player2->Terry2position.x) mirror = false;
	else mirror = true;

	//IDLE
	if (currentstate == ST_IDLE)
		if (mirror)current_animation = &TerryidleM;
		else current_animation = &Terryidle;

	//MOVE FORWARD
	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_DOWN && currentstate == ST_IDLE)
	{
		currentstate = ST_WALK_FORWARD;
		if (mirror) current_animation = &TerryBackwardsM;
		else current_animation = &TerryForward;
	}
	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT && currentstate == ST_WALK_FORWARD)
	{
		if (Terryposition.x < 700 &&
			Terryposition.x * 2 - 160 < -(App->render->camera.x - App->render->camera.w))
		{
			if (mirror)
				Terryposition.x -= speed;
			else
				Terryposition.x += speed;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_UP && currentstate == ST_WALK_FORWARD)
	{
		TerryForward.resetLoops(0);
		TerryForwardM.resetLoops(0);
		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
		{
			currentstate = ST_WALK_BACKWARD;
			if (mirror) current_animation = &TerryForwardM;
			else current_animation = &TerryBackwards;
		}
		else
			currentstate = ST_IDLE;
	}

	//MOVE BACKWARD
	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN && currentstate == ST_IDLE)
	{
		currentstate = ST_WALK_BACKWARD;
		if (mirror) current_animation = &TerryForwardM;
		else current_animation = &TerryBackwards;
	}
	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT && currentstate == ST_WALK_BACKWARD)
	{
		if (Terryposition.x > 0 &&
			Terryposition.x * 2 > -App->render->camera.x)
			Terryposition.x -= speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_UP && currentstate == ST_WALK_BACKWARD)
	{
		TerryForward.resetLoops(0);
		TerryForwardM.resetLoops(0);
		if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
		{
			currentstate = ST_WALK_FORWARD;
			if (mirror) current_animation = &TerryBackwardsM;
			else current_animation = &TerryForward;
		}
		else
			currentstate = ST_IDLE;
	}


	//JUMP
	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_DOWN && currentstate == ST_IDLE)
	{
		jumping = true;
		currentstate = ST_GOING_UP;
		current_animation = &TerryGoingUp;
	}
	if (currentstate == ST_GOING_UP)
	{
		t++;
		Terryposition.y = 100 - 7 * t + 0.12 * (t * t);
		vy = -7 + 0.24 * t;
		if (vy > 0)
		{
			if (TerryGoingUp.Finished())
			{
				TerryGoingUp.resetLoops(0);
				currentstate = ST_GOING_DOWN;
				current_animation = &TerryGoingDown;
			}
			if (TerryGoingDown.Finished())
			{
				TerryGoingDown.resetLoops(0);

			}
		}
		if (Terryposition.y >= 100)
		{
			Terryposition.y = 100;
			currentstate = ST_IDLE;
			current_animation = &Terryidle;
		}
	}
	//if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_DOWN && currentstate == ST_IDLE)
	//{
	//	currentstate = ST_JUMP_NEUTRAL;
	//	if (mirror) current_animation = &TerryJumpM;
	//	else current_animation = &TerryJump;

	//	Terryposition.y -= jumpspeed;
	//	App->render->camera.y = 0;

	//	if (Terryposition.y == 80)
	//		jumpspeed = -60;
	//	//App->render->camera.y = 0;
	//	if (Terryposition.y == 120)
	//		jumpspeed = 60;
	//	//App->render->camera.y = -30;		
	//}
	//if (TerryJump.Finished() == true || TerryJumpM.Finished() == true || Terryposition.y == 10)
	//{
	//	TerryJump.resetLoops(0);
	//	TerryJumpM.resetLoops(0);
	//	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	//	{
	//		currentstate = ST_WALK_FORWARD;
	//		if (mirror) current_animation = &TerryBackwardsM;
	//		else current_animation = &TerryForward;
	//	}
	//	else if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	//	{
	//		currentstate = ST_WALK_BACKWARD;
	//		if (mirror) current_animation = &TerryForwardM; 
	//		else current_animation = &TerryBackwards; 
	//	}
	//	else
	//		currentstate = ST_IDLE;
	//	Terryposition.y = 100;
	//	App->render->camera.y = -20;
	//}

	//JUMP FORWARD
	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_DOWN && currentstate == ST_WALK_FORWARD)
	{
		if (col)
			col->to_delete = true;
		if (gmode != true)
			colj = App->collisions->AddCollider({ Terryposition.x + 13, Terryposition.y + 50, 36, 60 }, COLLIDER_PLAYER);
		currentstate = ST_JUMP_FORWARD;
		current_animation = &TerryJumpForward;
		Terryposition.y -= jumpspeed;
		App->render->camera.y = 0;
		if (Terryposition.y == 80)
			jumpspeed = -60;
		//App->render->camera.y = 0;
		if (Terryposition.y == 120)
			jumpspeed = 60;
		//App->render->camera.y = -30;

		//if (nothing) { up = true; nothing = false; }
		//
		//if (up)
		//{
		//	Terryposition.y -= jumpspeed;
		//	//App->render->camera.y += cameraspeed;
		//
		//	if (Terryposition.y <= 20) { down = true; up = false; }
		//
		//}
		//
		//if (down)
		//{
		//	Terryposition.y += jumpspeed;
		//	//App->render->camera.y -= cameraspeed;
		//
		//	if (Terryposition.y >= 99) { nothing = true; down = false; }
		//
		//}

	}
	if (TerryJumpForward.Finished() != true && currentstate == ST_JUMP_FORWARD)
	{

		//if (nothing) { up = true; nothing = false; }
		//
		//if (up)
		//{
		//	Terryposition.y -= jumpspeed;
		//	//App->render->camera.y += cameraspeed;
		//
		//	if (Terryposition.y <= 20) { down = true; up = false; }
		//
		//}
		//
		//if (down)
		//{
		//	Terryposition.y += jumpspeed;
		//	//App->render->camera.y -= cameraspeed;
		//
		//	if (Terryposition.y >= 99) { nothing = true; down = false; }
		//
		//}


		if (Terryposition.y == 80)
			jumpspeed = -60;
		if (Terryposition.y == 120)
			jumpspeed = 60;

		if (Terryposition.x < 700 &&
			Terryposition.x * 2 - 160 < -(App->render->camera.x - App->render->camera.w))
		{
			Terryposition.x += speed;
			if (App->render->camera.x > -900 /*-490*/ && App->player->destroyed == false &&
				App->player2->Terry2position.x * 2 > -App->render->camera.x &&
				App->input->keyboard[SDL_SCANCODE_RIGHT] != KEY_STATE::KEY_REPEAT)
				App->render->camera.x -= speed;
		}

	}
	if (TerryJumpForward.Finished() == true || Terryposition.y == 80)
	{
		TerryJumpForward.resetLoops(0);
		if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
		{
			currentstate = ST_WALK_FORWARD;
			current_animation = &TerryForward;
		}
		else if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
		{
			currentstate = ST_WALK_BACKWARD;
			current_animation = &TerryBackwards;
		}
		else
		{
			currentstate = ST_IDLE;
			current_animation = &Terryidle;
		}
		Terryposition.y = 100;
		App->render->camera.y = -20;
		TerryJumpForward.Reset();
		colj->to_delete = true;
		if (gmode != true)
			col = App->collisions->AddCollider({ 0, 0, 30, 101 }, COLLIDER_PLAYER, App->player);
	}

	//JUMP BACKWARDS
	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_DOWN && currentstate == ST_WALK_BACKWARD)
	{
		col->to_delete = true;
		if (gmode != true)
			colj = App->collisions->AddCollider({ Terryposition.x + 13, Terryposition.y + 50, 36, 60 }, COLLIDER_PLAYER);
		currentstate = ST_JUMP_BACKWARD;
		current_animation = &TerryJumpBackwards;
		Terryposition.y -= jumpspeed;
		App->render->camera.y = 0;
		if (Terryposition.y == 80)
			jumpspeed = -60;
		//App->render->camera.y = 0;
		if (Terryposition.y == 120)
			jumpspeed = 60;
		//App->render->camera.y = -30;
	}
	if (TerryJumpBackwards.Finished() != true && currentstate == ST_JUMP_BACKWARD)
	{
		if (Terryposition.y == 80)
			jumpspeed = -60;
		if (Terryposition.y == 120)
			jumpspeed = 60;
		if (Terryposition.x > 0 &&
			Terryposition.x * 2 > -(App->render->camera.x))
		{
			Terryposition.x -= speed;
			if (App->render->camera.x < 0 && App->player->destroyed == false &&
				(App->player2->Terry2position.x * 2 - 160) < (-(App->render->camera.x - App->render->camera.w)) &&
				App->input->keyboard[SDL_SCANCODE_LEFT] != KEY_STATE::KEY_REPEAT)
				App->render->camera.x += 2 * speed;
		}
	}
	if (TerryJumpBackwards.Finished() == true || Terryposition.y == 80)
	{
		TerryJumpBackwards.resetLoops(0);
		if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
		{
			currentstate = ST_WALK_BACKWARD;
			current_animation = &TerryBackwards;
		}
		else if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
		{
			currentstate = ST_WALK_FORWARD;
			current_animation = &TerryForward;
		}
		else
		{
			currentstate = ST_IDLE;
			current_animation = &Terryidle;
		}
		Terryposition.y = 100;
		App->render->camera.y = -20;
		TerryJumpBackwards.Reset();
		colj->to_delete = true;
		if (gmode != true)
			col = App->collisions->AddCollider({ 0, 0, 30, 101 }, COLLIDER_PLAYER, App->player);
	}

	//PUNCH
	if (App->input->keyboard[SDL_SCANCODE_F] == KEY_STATE::KEY_DOWN && ((currentstate == ST_IDLE) || (currentstate == ST_WALK_FORWARD) || (currentstate == ST_WALK_BACKWARD)))
	{
		currentstate = ST_PUNCH_STANDING;
		current_animation = &TerryPunch;
		App->audio->PlayFX("Assets/FX/punch.wav");
		colp = App->collisions->AddCollider({ Terryposition.x + 45, Terryposition.y + 20, 43, 20 }, COLLIDER_PLAYER_SHOT, App->player);
	}
	if (TerryPunch.Finished() == true)
	{
		if (colp)
			colp->to_delete = true;
		TerryPunch.resetLoops(0);
		if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
		{
			currentstate = ST_WALK_FORWARD;
			current_animation = &TerryForward;
		}
		else if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
		{
			currentstate = ST_WALK_BACKWARD;
			current_animation = &TerryBackwards;
		}
		else
		{
			currentstate = ST_IDLE;
			current_animation = &Terryidle;
		}
		App->player2->collided = false;
		TerryPunch.Reset();
	}

	//KICK
	if (App->input->keyboard[SDL_SCANCODE_G] == KEY_STATE::KEY_DOWN && ((currentstate == ST_IDLE) || (currentstate == ST_WALK_FORWARD) || (currentstate == ST_WALK_BACKWARD)))
	{
		currentstate = ST_KICK_STANDING;
		current_animation = &TerryKick;
		App->audio->PlayFX("Assets/FX/Voice/Attacks/FX_Attack4/FX_Attack4.wav");
		colk = App->collisions->AddCollider({ Terryposition.x + 45, Terryposition.y + 48, 55, 20 }, COLLIDER_PLAYER_SHOT, App->player);
		Terryposition.x += 5;
	}
	if (TerryKick.Finished() == true)
	{
		if (colk)
			colk->to_delete = true;

		TerryKick.resetLoops(0);

		if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
		{
			currentstate = ST_WALK_FORWARD;
			current_animation = &TerryForward;
		}
		else if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
		{
			currentstate = ST_WALK_BACKWARD;
			current_animation = &TerryBackwards;
		}
		else
		{
			currentstate = ST_IDLE;
			current_animation = &Terryidle;
		}

		TerryKick.Reset();
	}

	//CROUCH
	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_DOWN && (currentstate == ST_IDLE || currentstate == ST_WALK_FORWARD || currentstate == ST_WALK_BACKWARD))
	{
		currentstate = ST_CROUCH;
		current_animation = &TerryCrouch;
		col->to_delete = true;
		if (gmode != true)
			colc = App->collisions->AddCollider({ Terryposition.x + 13, Terryposition.y + 50, 36, 60 }, COLLIDER_PLAYER, App->player);
	}
	if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_UP && currentstate == ST_CROUCH)
	{
		if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
		{
			currentstate = ST_WALK_FORWARD;
			current_animation = &TerryForward;
		}
		else if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
		{
			currentstate = ST_WALK_BACKWARD;
			current_animation = &TerryBackwards;
		}
		else
		{
			currentstate = ST_IDLE;
			current_animation = &Terryidle;
		}
		colc->to_delete = true;
		if (gmode != true)
			col = App->collisions->AddCollider({ 0, 0, 30, 101 }, COLLIDER_PLAYER, App->player);
	}
	if (TerryCrouch.Finished() == true && currentstate != ST_CROUCH)
		TerryCrouch.Reset();

	//CROUCHPUNCH
	if (App->input->keyboard[SDL_SCANCODE_F] == KEY_STATE::KEY_DOWN && currentstate == ST_CROUCH)
	{
		currentstate = ST_PUNCH_CROUCH;
		current_animation = &TerryCrouchPunch;
		App->audio->PlayFX("Assets/FX/Voice/Attacks/FX_Attack4/FX_Attack4.wav");
		colcp = App->collisions->AddCollider({ Terryposition.x + 50, Terryposition.y + 55, 25, 20 }, COLLIDER_PLAYER_SHOT, App->player);
		colcp->rect.x = Terryposition.x + 50;
		colcp->rect.y = Terryposition.y + 55;
	}
	if (TerryCrouchPunch.Finished() == true)
	{
		if (colcp)
			colcp->to_delete = true;
		TerryCrouchPunch.resetLoops(0);
		App->player2->collided = false;

		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
		{
			currentstate = ST_CROUCH;
			current_animation = &TerryCrouch;
		}
		else
		{
			currentstate = ST_IDLE;
			current_animation = &Terryidle;
		}
		TerryCrouchPunch.Reset();
		colc->to_delete = true;
	}

	//CROUCHKICK
	if (App->input->keyboard[SDL_SCANCODE_G] == KEY_STATE::KEY_DOWN && currentstate == ST_CROUCH)
	{
		currentstate = ST_KICK_CROUCH;
		current_animation = &TerryCrouchKick;
		App->audio->PlayFX("Assets/FX/Voice/Attacks/FX_Attack4/FX_Attack4.wav");


		colck->rect.x = Terryposition.x + 50;
		colck->rect.y = Terryposition.y + 90;
	}
	if (TerryCrouchKick.Finished() == true)
	{
		colck->to_delete = true;
		TerryCrouchKick.resetLoops(0);
		if (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
		{
			currentstate = ST_CROUCH;
			current_animation = &TerryCrouch;
		}
		else
		{
			currentstate = ST_IDLE;
			current_animation = &Terryidle;
		}
		TerryCrouchKick.Reset();
		App->player2->collided = false;
		colck = App->collisions->AddCollider({ 0, 0, 40, 20 }, COLLIDER_PLAYER_SHOT, App->player);
	}


	if (currentstate == ST_CROUCH && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_DOWN)
	{
		currentstate = ST_SD;
		current_animation = &TerryCrouch;
	}

	if (currentstate == ST_SD && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_UP)
		currentstate = ST_CROUCH;

	if (currentstate == ST_SD && App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_UP)
	{
		currentstate = ST_WALK_FORWARD;
		current_animation = &TerryForward;
		colc->to_delete = true;
		col = App->collisions->AddCollider({ 0, 0, 30, 101 }, COLLIDER_PLAYER, App->player);
	}

	//POWER WAVE
	if (currentstate == ST_SD && App->input->keyboard[SDL_SCANCODE_F] == KEY_STATE::KEY_DOWN)
	{
		currentstate = ST_POWER_WAVE;
		current_animation = &TerryPW;
		col = App->collisions->AddCollider({ 0, 0, 30, 101 }, COLLIDER_PLAYER, App->player);
		App->audio->PlayFX("Assets/FX/Voice/Special Attacks/FX_PowerWaveAttackTerryBogardVoice/FX_PowerWaveAttackTerryBogardVoice.wav");
		colc->to_delete = true;
	}
	if (TerryPW.Finished() == true)
	{
		Uint32 inittime = 200;
		if (SDL_GetTicks() >= inittime)
		{
			App->particles->AddParticle(App->particles->terryenergy, Terryposition.x + 60, Terryposition.y + 12);
			App->particles->AddParticle(App->particles->terryenergy, Terryposition.x + 76, Terryposition.y + 12, 200);
			App->particles->AddParticle(App->particles->terryenergy, Terryposition.x + 92, Terryposition.y + 12, 400);
			App->particles->AddParticle(App->particles->terryenergy, Terryposition.x + 108, Terryposition.y + 12, 600);
			App->particles->AddParticle(App->particles->terryenergy, Terryposition.x + 124, Terryposition.y + 12, 800);
			App->particles->terryenergy.col->to_delete == true;
		}
		TerryPW.resetLoops(0);
		if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
		{
			currentstate = ST_WALK_FORWARD;
			current_animation = &TerryForward;
		}
		else if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
		{
			currentstate = ST_WALK_BACKWARD;
			current_animation = &TerryBackwards;
		}
		else
		{
			currentstate = ST_IDLE;
			current_animation = &Terryidle;
		}
		TerryPW.Reset();
	}

	if (App->input->keyboard[SDL_SCANCODE_F5] == KEY_STATE::KEY_DOWN)
	{
		if (gmode == false)
		{
			LOG("Starting GOD MODE");
			gmode = true;
			col->to_delete = true;
			if (currentstate == ST_CROUCH)
				colc->to_delete = true;
			colj->to_delete = true;
		}
		else
		{
			LOG("GOD MODE off");
			col = App->collisions->AddCollider({ 0, 0, 30, 103 }, COLLIDER_PLAYER, App->player);
			gmode = false;
		}
	}

	App->render->Blit(UI, 0, 0, &lifebar, 0);
	if (life_score >= 4)
	{
		App->render->Blit(UI, 26, 26, &life1, 0);
		App->render->Blit(UI, 27, 26, &life2, 0);
	}
	if (life_score >= 8)
		App->render->Blit(UI, 31, 26, &life2, 0);
	if (life_score >= 12)
		App->render->Blit(UI, 35, 26, &life2, 0);
	if (life_score >= 16)
		App->render->Blit(UI, 39, 26, &life2, 0);
	if (life_score >= 20)
		App->render->Blit(UI, 43, 26, &life2, 0);
	if (life_score >= 24)
		App->render->Blit(UI, 47, 26, &life2, 0);
	if (life_score >= 28)
		App->render->Blit(UI, 51, 26, &life2, 0);
	if (life_score >= 32)
		App->render->Blit(UI, 55, 26, &life2, 0);
	if (life_score >= 36)
		App->render->Blit(UI, 59, 26, &life2, 0);
	if (life_score >= 40)
		App->render->Blit(UI, 63, 26, &life2, 0);
	if (life_score >= 44)
		App->render->Blit(UI, 67, 26, &life2, 0);
	if (life_score >= 48)
		App->render->Blit(UI, 71, 26, &life2, 0);
	if (life_score >= 52)
		App->render->Blit(UI, 75, 26, &life2, 0);
	if (life_score >= 56)
		App->render->Blit(UI, 79, 26, &life2, 0);
	if (life_score >= 60)
		App->render->Blit(UI, 83, 26, &life2, 0);
	if (life_score >= 64)
		App->render->Blit(UI, 87, 26, &life2, 0);
	if (life_score >= 68)
		App->render->Blit(UI, 91, 26, &life2, 0);
	if (life_score >= 72)
		App->render->Blit(UI, 95, 26, &life2, 0);
	if (life_score >= 76)
		App->render->Blit(UI, 99, 26, &life2, 0);
	if (life_score >= 80)
		App->render->Blit(UI, 103, 26, &life2, 0);
	if (life_score >= 84)
		App->render->Blit(UI, 107, 26, &life2, 0);
	if (life_score >= 88)
		App->render->Blit(UI, 111, 26, &life2, 0);
	if (life_score >= 92)
	{
		App->render->Blit(UI, 115, 26, &life2, 0);
		App->render->Blit(UI, 119, 26, &life1, 0);
	}

	// TODO 3: Update collider position to player position
	if (currentstate != ST_JUMP_NEUTRAL)
		col->rect.y = Terryposition.y + 10;  //le sigue horizontalmente
	if (currentstate == ST_JUMP_NEUTRAL)
		col->rect.y = Terryposition.y + 30;
	col->rect.x = Terryposition.x + 15;
	if (currentstate == ST_JUMP_FORWARD || currentstate == ST_JUMP_BACKWARD)
	{
		colj->rect.x = Terryposition.x + 13;
		colj->rect.y = Terryposition.y + 50;
	}

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	// Draw everything --------------------------------------
	if (destroyed == false)
	{
		if ((current_animation == (&TerryKick)) || current_animation == &TerryGoingUp || current_animation == &TerryGoingDown || current_animation == &TerryTop
			|| current_animation == (&TerryForward) || current_animation == (&TerryBackwards) || current_animation == &TerryDP || current_animation == &TerryDK || current_animation == &TerryCrouchPunch
			|| current_animation == &TerryCrouchKick || current_animation == &TerryJumpForward || current_animation == &TerryJumpBackwards || current_animation == &TerryCrouch)
		{
			App->render->Blit(graphics2, Terryposition.x, Terryposition.y, &(current_animation->GetCurrentFrame()));
		}

		else if (current_animation == &TerryKickM || current_animation == &TerryJumpM || current_animation == &TerryForwardM
			|| current_animation == &TerryBackwardsM || current_animation == &TerryDPM || current_animation == &TerryDKM || current_animation == &TerryCrouchPunchM
			|| current_animation == &TerryCrouchKickM || current_animation == &TerryJumpForwardM || current_animation == &TerryJumpBackwardsM || current_animation == &TerryCrouchM)
		{
			App->render->Blit(graphics2M, Terryposition.x, Terryposition.y, &(current_animation->GetCurrentFrame()));
		}

		else if (current_animation == &TerryidleM || current_animation == &TerryPunchM || current_animation == &TerryPWM || current_animation == &TerryJumpPunchM
			|| current_animation == &TerryJumpKickM || current_animation == &hitM)
		{
			App->render->Blit(graphicsM, Terryposition.x, Terryposition.y, &(current_animation->GetCurrentFrame()));
		}

		else
		{
			App->render->Blit(graphics, Terryposition.x, Terryposition.y, &(current_animation->GetCurrentFrame()));
		}

		/*else if()
		else if()*/
	}

	// Draw UI (score) --------------------------------------
	//sprintf_s(score_text, 10, "%7d", score);

	// TODO 3: Blit the text of the score in at the bottom of the screen
	App->fonts->BlitText(10, 150, font_score, "546");

	return UPDATE_CONTINUE;
}
void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (c1->type == COLLIDER_PLAYER_SHOT && c2->type == COLLIDER_PLAYER && collided == false)
	{
		life_score -= stantardDMG;
		collided = true;
	}
}
