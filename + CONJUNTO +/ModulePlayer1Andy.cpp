//#if 0;

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
	{
		AndyIdle.PushBack({   0, 150, 59, 150 });
		AndyIdle.PushBack({  59, 150, 59, 150 });
		AndyIdle.PushBack({ 118, 150, 60, 150 });
		AndyIdle.PushBack({ 178, 150, 59, 150 });
		AndyIdle.PushBack({ 237, 150, 59, 150 });
		AndyIdle.speed = 0.1f;
	}

	// WALK FORWARD animation of Andy					
	{
		AndyForward.PushBack({ 784, 150, 55, 150 });//2
		AndyForward.PushBack({ 839, 150, 60, 150 });//4
		AndyForward.PushBack({ 899, 150, 63, 150 });//3
		AndyForward.PushBack({ 962, 150, 62, 150 });//1
		AndyForward.speed = 0.05f;
	}

	// WALK BACKWARD animation of Andy					
	{
		AndyBackwards.PushBack({ 543, 150, 53, 150 });
		AndyBackwards.PushBack({ 596, 150, 61, 150 });
		AndyBackwards.PushBack({ 657, 150, 48, 150 });
		AndyBackwards.PushBack({ 705, 150, 49, 150 });
		AndyBackwards.speed = 0.05f;
	}

	// JUMP animation 						
	{
		//LAUNCH AND UP
		AndyGoingUp.PushBack({ 296, 150, 53, 150 });
		AndyGoingUp.PushBack({ 349, 150, 42, 150 });
		AndyGoingUp.speed = 0.1f;
		AndyGoingUp.loop = false;

		//AndyTop.PushBack({ 349, 150, 42, 150 });
		//AndyTop.PushBack({ 349, 150, 42, 150 });
		//AndyTop.PushBack({ 349, 150, 42, 150 });
		//AndyTop.PushBack({ 349, 150, 42, 150 });
		//AndyTop.PushBack({ 349, 150, 42, 150 });
		//AndyTop.PushBack({ 349, 150, 42, 150 });
		//AndyTop.PushBack({ 391, 150, 51, 150 });
		//AndyTop.speed = 0.1f;
		//AndyTop.loop = false;

		//GOING DOWN AND LAND
		AndyGoingDown.PushBack({ 391, 150, 51, 150 });
		AndyGoingDown.PushBack({ 442, 150, 48, 150 });
		AndyGoingDown.PushBack({ 442, 150, 48, 150 });
		AndyGoingDown.PushBack({ 442, 150, 48, 150 });
		AndyGoingDown.PushBack({ 442, 150, 48, 150 });
		AndyGoingDown.PushBack({ 442, 150, 48, 150 });
		AndyGoingDown.PushBack({ 442, 150, 48, 150 });

		AndyGoingDown.speed = 0.08f;
	}

	// KICK animation of Terry							//spritesTerryBogard2extres.png
	{
		AndyKick.PushBack({ 129, 0,  44, 150 });
		AndyKick.PushBack({ 173, 0,  56, 150 });
		AndyKick.PushBack({ 229, 0,  52, 150 });
		AndyKick.PushBack({ 281, 0, 113, 150 });
		AndyKick.PushBack({ 394, 0,  83, 150 });
		AndyKick.PushBack({ 477, 0,  53, 150 });
		AndyKick.speed = 0.1f;
	}

	//PUNCH
	{
		AndyPunch.PushBack({ 530, 0, 49, 150 });
		AndyPunch.PushBack({ 579, 0, 48, 150 });
		AndyPunch.PushBack({ 627, 0, 93, 150 });//
		AndyPunch.PushBack({ 627, 0, 93, 150 });//
		AndyPunch.PushBack({ 627, 0, 93, 150 });//
		AndyPunch.PushBack({ 579, 0, 48, 150 });
		AndyPunch.PushBack({ 579, 0, 48, 150 });
		AndyPunch.speed = 0.15f;
	}

	//CROUCH
	{
		AndyCrouch.PushBack({ 917, 0, 59, 150 });
		AndyCrouch.PushBack({ 976, 0, 48, 150 });
		AndyCrouch.speed = 0.01f;
		AndyCrouch.loop = false;
	}

	// POWER WAVE animation of Terrry
	{
		AndyPW.PushBack({   0, 300, 65, 150 });
		AndyPW.PushBack({  65, 300, 48, 150 });
		AndyPW.PushBack({ 113, 300, 48, 150 });
		AndyPW.PushBack({ 161, 300, 98, 150 });
		
		AndyPW.speed = 0.07f;
	}

	// HELIPUNCH
	{
		AndyHeliPunch.PushBack({ 297, 0,  61, 150 });
		AndyHeliPunch.PushBack({ 358, 0,  88, 150 });
		AndyHeliPunch.PushBack({ 446, 0,  92, 150 });
		AndyHeliPunch.PushBack({ 538, 0, 110, 150 });
		AndyHeliPunch.PushBack({ 648, 0,  86, 150 });
		AndyHeliPunch.PushBack({ 734, 0,  62, 150 });
		AndyHeliPunch.PushBack({ 796, 0,  53, 150 });
		AndyHeliPunch.speed = 0.1f;
	}

	//DAMAGED BY PUNCH						 //!!!
	{
		AndyDP.PushBack({  0, 912, 59, 112 });
		AndyDP.PushBack({ 64, 912, 67, 112 });
		AndyDP.speed = 0.1f;
	}

	//DAMAGED BY KICK						 //!!!
	{
		AndyDK.PushBack({ 136, 912, 63, 112 });
		AndyDK.PushBack({ 211, 912, 68, 112 });
		AndyDK.speed = 0.1f;
	}

	
	//JUMPFORWARD
	{
		AndyGoingUpForward.PushBack({ 586, 912, 57, 112 });//CROUNCH
		AndyGoingUpForward.PushBack({ 643, 912, 56, 112 });//GOING UP
		AndyGoingUpForward.speed = 0.08f;
		AndyGoingUpForward.loop = false;

		AndyTopForward.PushBack({ 703, 912, 87, 112 });//HORIZONTAL
		AndyTopForward.PushBack({ 790, 912, 87, 112 });//VERTICAL		
		AndyTopForward.PushBack({ 877, 912, 87, 112 });//HORIZONTAL
		AndyTopForward.speed = 1.0f;
		AndyTopForward.loop = false;

		AndyGoingDownForward.PushBack({ 964, 912, 60, 112 });//GOING DOWN
		AndyGoingDownForward.PushBack({ 586, 912, 57, 112 });//CROUCH
		AndyGoingDownForward.speed = 0.02f;
		AndyGoingDownForward.loop = false;
	}

	//JUMPBACKWARDS
	{
		AndyGoingUpBackwards.PushBack({ 586, 912, 57, 112 });//CROUNCH
		AndyGoingUpBackwards.PushBack({ 643, 912, 56, 112 });//GOING UP
		AndyGoingUpBackwards.speed = 0.08f;
		AndyGoingUpBackwards.loop = false;

		AndyTopBackwards.PushBack({ 703, 912, 87, 112 });//HORIZONTAL
		AndyTopBackwards.PushBack({ 790, 912, 87, 112 });//VERTICAL		
		AndyTopBackwards.PushBack({ 877, 912, 87, 112 });//HORIZONTAL
		AndyTopBackwards.speed = 1.0f;
		AndyTopBackwards.loop = false;

		AndyGoingDownBackwards.PushBack({ 964, 912, 60, 112 });//GOING DOWN
		AndyGoingDownBackwards.PushBack({ 586, 912, 57, 112 });//CROUCH
		AndyGoingDownBackwards.speed = 0.02f;
		AndyGoingDownBackwards.loop = false;
	}

	//CROUCHPUNCH
	{
		AndyCrouchPunch.PushBack({ 279, 912, 56, 112 }); //Charge
		AndyCrouchPunch.PushBack({ 416, 912, 49, 112 }); //Riposte
		AndyCrouchPunch.PushBack({ 335, 912, 81, 112 }); //Punch
		AndyCrouchPunch.PushBack({ 416, 912, 49, 112 }); //Riposte x2
		AndyCrouchPunch.speed = 0.1f;
	}

	//CROUCHKICK
	{
		AndyCrouchKick.PushBack({   0, 600,  79, 150 });   //Charge
		AndyCrouchKick.PushBack({  79, 600,  79, 150 });  //Riposte
		AndyCrouchKick.PushBack({ 158, 600, 119, 150 }); //Punch
		AndyCrouchKick.PushBack({  79, 600,  79, 150 });
		AndyCrouchKick.PushBack({   0, 600,  79, 150 });
		AndyCrouchKick.speed = 0.1f;
	}
	//JUMPPUNCH
	AndyJumpPunch.PushBack({ 488, 789, 44, 112 }); //Charge
	AndyJumpPunch.PushBack({ 544, 805, 68,  96 });   //Punch
	AndyJumpPunch.PushBack({ 802,   0, 57, 123 });     //Land

	//JUMPKICK
	AndyJumpKick.PushBack({ 304, 830, 56,  70 });  //Charge
	AndyJumpKick.PushBack({ 376, 789, 78, 111 }); //Kick
	AndyJumpKick.PushBack({ 304, 830, 56,  70 });  //Discharge
	AndyJumpKick.PushBack({ 802,   0, 57, 123 });   //Land

		//hit particle animation
	hit.PushBack({ 671, 263, 22, 33 });
	hit.PushBack({ 690, 263, 24, 33 });
	hit.PushBack({ 721, 263, 32, 33 });
	hit.PushBack({ 757, 263, 32, 33 });
	hit.speed = 0.5f;


	//MIRROR -----------------------------------------------------------------------------------------				//spritesTerryBogardMIRROR.png				//spritesTerryBogard2extresMIRROR.png
	{
		//IDLE
		AndyIdleM.PushBack({   0, 912, 59, 112 });		//1
		AndyIdleM.PushBack({  59, 912, 59, 112 });		//2
		AndyIdleM.PushBack({ 118, 912, 59, 112 });		//3
		AndyIdleM.PushBack({  59, 912, 59, 112 });		//2
		AndyIdleM.speed = 0.1f;

		// WALK FORWARD animation of Terry					//TerryAvanzar+SaltoEstatico+Patada+Retroceder.png
		AndyForwardM.PushBack({  21, 268, 59, 112 });
		AndyForwardM.PushBack({  96, 268, 69, 112 });
		AndyForwardM.PushBack({ 178, 268, 59, 112 });
		AndyForwardM.PushBack({ 252, 268, 59, 112 });
		AndyForwardM.speed = 0.1f;

		// WALK BACKWARD animation of Terry					//spritesTerryBogard2extres.png
		AndyBackwardsM.PushBack({ 382, 270, 59, 112 });
		AndyBackwardsM.PushBack({ 442, 270, 55, 112 });
		AndyBackwardsM.PushBack({ 497, 270, 56, 112 });
		AndyBackwardsM.PushBack({ 553, 270, 57, 112 });
		AndyBackwardsM.speed = 0.1f;

		// JUMP animation of Terry							//spritesTerryBogard2extres.png
		{
			//LAUNCH AND UP
			AndyGoingUpM.PushBack({ 557, 0, 57, 123 });
			AndyGoingUpM.PushBack({ 614, 0, 51, 123 });
			AndyGoingUpM.loop = false;
			AndyGoingUpM.speed = 0.1f;

			AndyTopM.PushBack({ 665, 0, 53, 123 });

			//GOING DOWN AND LAND
			AndyGoingDownM.PushBack({ 722, 0, 57, 123 });
			AndyGoingDownM.PushBack({ 722, 0, 57, 123 });
			AndyGoingDownM.PushBack({ 722, 0, 57, 123 });
			AndyGoingDownM.PushBack({ 722, 0, 57, 123 });
			AndyGoingDownM.PushBack({ 722, 0, 57, 123 });
			AndyGoingDownM.PushBack({ 722, 0, 57, 123 });
			AndyGoingDownM.PushBack({ 557, 0, 57, 123 });
			AndyGoingDownM.speed = 0.1f;
		}

		// KICK animation of Terry							//spritesTerryBogard2extres.png
		AndyKickM.PushBack({   0, 137, 116, 112 });
		AndyKickM.PushBack({ 116, 137, 116, 112 });
		AndyKickM.PushBack({ 232, 137, 116, 112 });
		AndyKickM.PushBack({ 348, 137, 116, 112 });
		AndyKickM.PushBack({ 464, 137, 116, 112 });
		AndyKickM.speed = 0.1f;

		//PUNCH MIRROR
		{
			AndyPunchM.PushBack({ 453, 910, 95, 112 });
			AndyPunchM.PushBack({ 358, 911, 95, 112 });
			AndyPunchM.PushBack({ 263, 911, 95, 112 });
			AndyPunchM.speed = 0.1f;
		}

		// POWER WAVE animation of Terrry
		AndyPWM.PushBack({ 623, 683, 51, 112 });
		AndyPWM.PushBack({ 550, 683, 54, 112 });
		AndyPWM.PushBack({ 485, 683, 60, 112 });
		AndyPWM.PushBack({ 402, 683, 79, 112 });
		AndyPWM.PushBack({ 330, 683, 67, 112 });
		AndyPWM.PushBack({ 263, 683, 65, 112 });
		AndyPWM.PushBack({ 198, 683, 60, 112 });
		AndyPWM.speed = 0.1f;

		//DAMAGED BY PUNCH
		AndyDPM.PushBack({  0, 912, 59, 112 });
		AndyDPM.PushBack({ 64, 912, 67, 112 });
		AndyDPM.speed = 0.1f;

		//DAMAGED BY KICK
		AndyDKM.PushBack({ 136, 912, 63, 112 });
		AndyDKM.PushBack({ 211, 912, 68, 112 });
		AndyDKM.speed = 0.1f;

		//CROUCH
		AndyCrouchM.PushBack({ 488, 912, 57, 112 });
		AndyCrouchM.PushBack({ 545, 912, 52, 112 });
		AndyCrouchM.speed = 0.2f;
		AndyCrouchM.loop = false;

		//JUMPFORWARD
	;

		//JUMPBACKWARDS
		

		//CROUCHPUNCH
		AndyCrouchPunchM.PushBack({ 279, 912, 56, 112 }); //Charge
		AndyCrouchPunchM.PushBack({ 416, 912, 49, 112 }); //Riposte
		AndyCrouchPunchM.PushBack({ 335, 912, 81, 112 }); //Punch
		AndyCrouchPunchM.PushBack({ 416, 912, 49, 112 }); //Riposte x2
		AndyCrouchPunchM.speed = 0.1f;

		//CROUCHKICK
		AndyCrouchKickM.PushBack({   0, 788, 56, 112 });   //Charge
		AndyCrouchKickM.PushBack({  56, 788, 58, 112 });  //Riposte
		AndyCrouchKickM.PushBack({ 114, 788, 92, 112 }); //Punch
		AndyCrouchKickM.PushBack({ 206, 788, 58, 112 }); //Riposte x2
		AndyCrouchKickM.speed = 0.1f;

		//JUMPPUNCH
		AndyJumpPunchM.PushBack({ 488, 789, 44, 112 }); //Charge
		AndyJumpPunchM.PushBack({ 544, 805, 68,  96 });   //Punch
		AndyJumpPunchM.PushBack({ 802,   0, 57, 123 });     //Land

		//JUMPKICK
		AndyJumpKickM.PushBack({ 304, 830, 56,  70 });  //Charge
		AndyJumpKickM.PushBack({ 376, 789, 78, 111 }); //Kick
		AndyJumpKickM.PushBack({ 304, 830, 56,  70 });  //Discharge
		AndyJumpKickM.PushBack({ 802,   0, 57, 123 });   //Land

				//hit particle animation
		hitM.PushBack({ 671, 263, 22, 33 });
		hitM.PushBack({ 690, 263, 24, 33 });
		hitM.PushBack({ 721, 263, 32, 33 });
		hitM.PushBack({ 757, 263, 32, 33 });
		hitM.speed = 0.5f;
	}
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");
	bool ret = true;
	graphics = App->textures->Load("Assets/Sprites/Sprites_AndyBogard_ok.png");

	UI = App->textures->Load("Assets/Sprites/UI.png");

	destroyed = false;
	Andyposition.x = 5 + (250);
	Andyposition.y = 60;
	score = 0;
	col   = App->collisions->AddCollider({    0, Andyposition.y + 50, 31, 101 }, COLLIDER_PLAYER, App->player);
	colc  = App->collisions->AddCollider({    0, 10000, 36, 60 }, COLLIDER_PLAYER, App->player);
	colj  = App->collisions->AddCollider({    0, 10000, 36, 60 }, COLLIDER_PLAYER, App->player);
	colcp = App->collisions->AddCollider({ 1000, 10000, 25, 20 }, COLLIDER_PLAYER_SHOT, App->player);
	colck = App->collisions->AddCollider({ 1000, 10000, 40, 20 }, COLLIDER_PLAYER_SHOT, App->player);

	currentstate = ST_IDLE;
	current_animation = &AndyIdle;

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
	if(colj)
		colj->to_delete = true;
	if(colc)
		colc->to_delete = true;
	return true;
}

update_status ModulePlayer::PreUpdate()
{
	inputTerry.J_RIGHT = SDL_GameControllerGetAxis(App->input->gController1, SDL_CONTROLLER_AXIS_LEFTX) > JOYSTICK_DEAD_ZONE;
	inputTerry.J_LEFT = SDL_GameControllerGetAxis(App->input->gController1, SDL_CONTROLLER_AXIS_LEFTX) < -JOYSTICK_DEAD_ZONE;
	inputTerry.J_UP = SDL_GameControllerGetAxis(App->input->gController1, SDL_CONTROLLER_AXIS_LEFTY) < -20000;
	inputTerry.J_DOWN = SDL_GameControllerGetAxis(App->input->gController1, SDL_CONTROLLER_AXIS_LEFTY) > JOYSTICK_DEAD_ZONE;
	inputTerry.J_B = App->input->gpad[SDL_CONTROLLER_BUTTON_B][1] == KEY_DOWN;
	inputTerry.J_A = App->input->gpad[SDL_CONTROLLER_BUTTON_A][1] == KEY_DOWN;
	inputAndy.J_RIGHT = SDL_GameControllerGetAxis(App->input->gController2, SDL_CONTROLLER_AXIS_LEFTX) > JOYSTICK_DEAD_ZONE;

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
	if (Andyposition.y >= 100)
		Andyposition.y;

	// MIRROR
	if (App->player2->col->rect.x < App->player->col->rect.x ||
		App->player2->colc->rect.x < App->player->col->rect.x ||
		App->player2->colj->rect.x < App->player->col->rect.x ||
		App->player2->col->rect.x < App->player->colc->rect.x ||
		App->player2->colj->rect.x < App->player->colc->rect.x ||
		App->player2->col->rect.x < App->player->colj->rect.x ||
		App->player2->colc->rect.x < App->player->colj->rect.x ||
		App->player2->colj->rect.x < App->player->colj->rect.x)
		mirror = true;
	else mirror = false;

	//IDLE
	if (currentstate == ST_IDLE)
	{
		if (mirror)current_animation = &AndyIdleM;
		else current_animation = &AndyIdle;
	}

	//MOVE RIGHT						CAMERA FIX NEEDED
	{
		if ((inputTerry.J_RIGHT || App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_DOWN) && currentstate == ST_IDLE)
			currentstate = ST_WALK_FORWARD;
		if ((inputTerry.J_RIGHT || App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT) && currentstate == ST_WALK_FORWARD)
		{
			if (mirror)
			{
				current_animation = &AndyBackwardsM;
				if (Andyposition.x < 700 && App->player2->Terry2position.x + SCREEN_WIDTH - 60 > Andyposition.x) Andyposition.x ++;

			}
			else
			{
				current_animation = &AndyForward;
				if (Andyposition.x < 700 && App->player2->Terry2position.x + SCREEN_WIDTH - 60 > Andyposition.x)
					Andyposition.x += 2;
			}
		}
		if ((SDL_GameControllerGetAxis(App->input->gController1, SDL_CONTROLLER_AXIS_LEFTX) < 14000 && SDL_GameControllerGetAxis(App->input->gController1, SDL_CONTROLLER_AXIS_LEFTX) > 4000 
			|| App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_UP) && currentstate == ST_WALK_FORWARD)
		{
			AndyForward.resetLoops(0);
			AndyForwardM.resetLoops(0);
			if (inputTerry.J_LEFT || App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
				currentstate = ST_WALK_BACKWARD;
			else
				currentstate = ST_IDLE;
		}
	}

	//MOVE LEFT						CAMERA FIX NEEDED
	{
		if ((inputTerry.J_LEFT || App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN) && currentstate == ST_IDLE)
			currentstate = ST_WALK_BACKWARD;
		if ((inputTerry.J_LEFT || App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT) && currentstate == ST_WALK_BACKWARD)
		{
			if (mirror)
			{
				current_animation = &AndyForwardM;
				if (Andyposition.x > 0 && App->player2->Terry2position.x - SCREEN_WIDTH + 60 < Andyposition.x) Andyposition.x -= 2;
			}
			else
			{
				current_animation = &AndyBackwards;
				if (Andyposition.x > 0 && App->player2->Terry2position.x - SCREEN_WIDTH + 60 < Andyposition.x)
					Andyposition.x--;
			}
		}
		if ((SDL_GameControllerGetAxis(App->input->gController1, SDL_CONTROLLER_AXIS_LEFTX) > -14000 && SDL_GameControllerGetAxis(App->input->gController1, SDL_CONTROLLER_AXIS_LEFTX) < -4000 || App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_UP) && currentstate == ST_WALK_BACKWARD)
		{
			AndyForward.resetLoops(0);
			AndyForwardM.resetLoops(0);
			if (inputTerry.J_RIGHT || App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
				currentstate = ST_WALK_FORWARD;
			else
				currentstate = ST_IDLE;
		}
	}

	//JUMP
	{
		if ((SDL_GameControllerGetAxis(App->input->gController1, SDL_CONTROLLER_AXIS_LEFTY) > -10000 && SDL_GameControllerGetAxis(App->input->gController1, SDL_CONTROLLER_AXIS_LEFTY) < -4000 
			|| App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_DOWN) && currentstate == ST_IDLE)
		{
			currentstate = ST_GOING_UP;
			col->rect.y = Andyposition.y + 10000;
			if (!gmode) colj->rect.y = Andyposition.y + 50;
		}
		if (currentstate == ST_GOING_UP)
		{
			if(!gmode) colj->rect.y = Andyposition.y + 50;
			if (mirror)current_animation = &AndyGoingUpM;
			else current_animation = &AndyGoingUp;
			t += 0.002;
			speed += t;
			if (Andyposition.y > 10) { Andyposition.y = Andyposition.y - 3 * speed;	App->render->camera.y = App->render->camera.y - speed; }
			else { Andyposition.y = Andyposition.y - 3 * speed / 2; App->render->camera.y = App->render->camera.y + speed; }
			if (Andyposition.y <= 30) currentstate = ST_TOP;
		}
		if (currentstate == ST_TOP)
		{
			if(!gmode) colj->rect.y = Andyposition.y + 50;

			t += 0.005;
			speed -= t;
			Andyposition.y = Andyposition.y - 3 * speed;
			App->render->camera.y = App->render->camera.y + speed;
			if (Andyposition.y <= -40) currentstate = ST_GOING_DOWN;
		}
		if (currentstate == ST_GOING_DOWN)
		{
			if (mirror) current_animation = &AndyGoingDownM;
			else current_animation = &AndyGoingDown;

			AndyGoingUp.resetLoops(0);
			AndyGoingUpM.resetLoops(0);

			if(!gmode) colj->rect.y = Andyposition.y + 85;

			t += 0.002;
			speed -= t;
			Andyposition.y = Andyposition.y - 3 * speed;
			if (Andyposition.y > 20) { Andyposition.y = Andyposition.y - 3 * speed; App->render->camera.y = App->render->camera.y + speed; }
			else { Andyposition.y = Andyposition.y - 3 * speed / 2; App->render->camera.y = App->render->camera.y + speed; }
			if (App->render->camera.y <= -10)
				App->render->camera.y = -10;

			if (Andyposition.y >= 50)
			{
				Andyposition.y = 50;
				if (inputTerry.J_LEFT || App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
				{
					currentstate = ST_WALK_BACKWARD;
					if (mirror)current_animation = &AndyForwardM;
					else current_animation = &AndyBackwards;
				}
				else if (inputTerry.J_RIGHT || App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
				{
					currentstate = ST_WALK_FORWARD;
					if (mirror)current_animation = &AndyBackwardsM;
					else current_animation = &AndyForward;
				}
				else if (inputTerry.J_DOWN || App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
				{
					currentstate = ST_CROUCH;
					if (mirror)current_animation = &AndyCrouchM;
					else current_animation = &AndyCrouch;
				}
				else currentstate = ST_IDLE;

				AndyGoingDown.resetLoops(0);
				AndyGoingDownM.resetLoops(0);
				speed = 2.0;
				t = 0;
				colj->rect.y = 10000;
				if (!gmode) col->rect.y = Andyposition.y + 50;
			}
		}
	}

	//JUMP FORWARD				PENDIENTE
	{
		if ((SDL_GameControllerGetAxis(App->input->gController1, SDL_CONTROLLER_AXIS_LEFTY) > -10000 && SDL_GameControllerGetAxis(App->input->gController1, SDL_CONTROLLER_AXIS_LEFTY) < -4000 || App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_DOWN) && currentstate == ST_WALK_FORWARD)
		{
			currentstate = ST_GOING_UP_FORWARD;
			col->rect.y = 10000;
			if (gmode != true) colj->rect.y = Andyposition.y + 50;
		}
		if (currentstate == ST_GOING_UP_FORWARD)
		{
			colj->rect.y = Andyposition.y + 13;
			current_animation = &AndyGoingUpForward;
			Andyposition.x += 2;
			t += 0.0005;
			speed -= t;
			if (Andyposition.y > 50) Andyposition.y = Andyposition.y - 3 * speed;
			else Andyposition.y = Andyposition.y - 3 * speed / 2;
			App->render->camera.y = App->render->camera.y + speed;
			if (Andyposition.y <= 5) currentstate = ST_TOP_FORWARD;
		}
		if (currentstate == ST_TOP_FORWARD)
		{
			Andyposition.x += 2;
			colj->rect.y = Andyposition.y + 43;
			current_animation = &AndyTopForward;
			AndyGoingUpForward.resetLoops(0);
			t = 0;
			t += 0.0005;
			speed += 0.01*t;
			Andyposition.y -= speed * 1.5;
			if (AndyTopForward.Finished())
				currentstate = ST_GOING_DOWN_FORWARD;
		}
		if (currentstate == ST_GOING_DOWN_FORWARD)
		{
			current_animation = &AndyGoingDownForward;
			AndyTopForward.resetLoops(0);

			Andyposition.x += 2;
			colj->rect.y = Andyposition.y + 53;
			t = 0;
			t += 0.0005;
			speed += 3 * t;
			if (Andyposition.y > 25 && Andyposition.y < 99)
				Andyposition.y += 4 * speed;
			else
				Andyposition.y += 3 * speed / 2;
			App->render->camera.y = App->render->camera.y - speed;
			if (App->render->camera.y <= -10) App->render->camera.y = -10;
			if (Andyposition.y >= 100)
			{
				Andyposition.y = 100;
				if (inputTerry.J_LEFT || App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
				{
					currentstate = ST_WALK_BACKWARD;
					if (mirror)current_animation = &AndyForwardM;
					else current_animation = &AndyBackwards;
				}
				else if (inputTerry.J_RIGHT || App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
				{
					currentstate = ST_WALK_FORWARD;
					if (mirror)current_animation = &AndyBackwardsM;
					else current_animation = &AndyForward;
				}
				else if (inputTerry.J_DOWN || App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
				{
					currentstate = ST_CROUCH;
					if (mirror)current_animation = &AndyCrouchM;
					else current_animation = &AndyCrouch;
				}
				else currentstate = ST_IDLE;

				AndyGoingDownForward.resetLoops(0);
				speed = 2.0;
				t = 0;
				colj->rect.y = 10000;
				if (!gmode) col->rect.y = Andyposition.y + 50;
			}
		}
	}

	//JUMP BACKWARDS  PENDIENTE
	{
		if ((SDL_GameControllerGetAxis(App->input->gController1, SDL_CONTROLLER_AXIS_LEFTY) > -10000 && SDL_GameControllerGetAxis(App->input->gController1, SDL_CONTROLLER_AXIS_LEFTY) < -4000 || App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_DOWN) && currentstate == ST_WALK_BACKWARD)
		{
			currentstate = ST_GOING_UP_BACKWARD;
			col->rect.y = 10000;
			if (gmode != true) colj->rect.y = Andyposition.y + 50;
		}
		if (currentstate == ST_GOING_UP_BACKWARD)
		{
			colj->rect.y = Andyposition.y + 13;
			if (mirror)current_animation = &AndyGoingUpBackwardsM;
			else current_animation = &AndyGoingUpBackwards;
			Andyposition.x -= 2;
			t += 0.0005;
			speed -= t;
			if (Andyposition.y > 50) Andyposition.y = Andyposition.y - 3 * speed;
			else Andyposition.y = Andyposition.y - 3 * speed / 2;
			App->render->camera.y = App->render->camera.y + speed;
			if (Andyposition.y <= 5) currentstate = ST_TOP_BACKWARD;
		}
		if (currentstate == ST_TOP_BACKWARD)
		{
			Andyposition.x -= 2;		
			colj->rect.y = Andyposition.y + 43;
			current_animation = &AndyTopBackwards;
			AndyGoingUpBackwards.resetLoops(0);
			t = 0;
			t += 0.0005;
			speed += 0.01*t;
			Andyposition.y -= speed * 1.5;
			if (AndyTopBackwards.Finished())
				currentstate = ST_GOING_DOWN_BACKWARD;
		}
		if (currentstate == ST_GOING_DOWN_BACKWARD)
		{
			current_animation = &AndyGoingDownBackwards;
			AndyTopBackwards.resetLoops(0);

			Andyposition.x -= 2;
			colj->rect.y = Andyposition.y + 53;
			t = 0;
			t += 0.0005;
			speed += 3 * t;
			if (Andyposition.y > 25 && Andyposition.y < 99)
				Andyposition.y += 4 * speed;
			else
				Andyposition.y += 3 * speed / 2;
			App->render->camera.y = App->render->camera.y - speed;
			if (App->render->camera.y <= -10) App->render->camera.y = -10;
			if (Andyposition.y >= 100)
			{
				Andyposition.y = 100;
				if (inputTerry.J_LEFT || App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
				{
					currentstate = ST_WALK_BACKWARD;
					if (mirror)current_animation = &AndyForwardM;
					else current_animation = &AndyBackwards;
				}
				else if (inputTerry.J_RIGHT || App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
				{
					currentstate = ST_WALK_FORWARD;
					if (mirror)current_animation = &AndyBackwardsM;
					else current_animation = &AndyForward;
				}
				else if (inputTerry.J_DOWN || App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
				{
					currentstate = ST_CROUCH;
					if (mirror)current_animation = &AndyCrouchM;
					else current_animation = &AndyCrouch;
				}
				else currentstate = ST_IDLE;

				AndyGoingDownBackwards.resetLoops(0);
				speed = 2.0;
				t = 0;
				colj->rect.y = 10000;
				if (!gmode) col->rect.y = Andyposition.y + 50;
			}
		}
	}

	//PUNCH
	{
		if ((inputTerry.J_B || App->input->keyboard[SDL_SCANCODE_F] == KEY_STATE::KEY_DOWN) && ((currentstate == ST_IDLE) || (currentstate == ST_WALK_FORWARD) || (currentstate == ST_WALK_BACKWARD)) && (current_animation != &AndyPunch) && (current_animation != &AndyPunchM))
		{
			currentstate = ST_PUNCH_STANDING;
			if (mirror)
			{
				Andyposition.x -= 38;
				current_animation = &AndyPunchM;
				colp = App->collisions->AddCollider({ Andyposition.x + 10, Andyposition.y + 65, 43, 20 }, COLLIDER_PLAYER_SHOT, App->player);
			}
			else
			{
				current_animation = &AndyPunch;
				colp = App->collisions->AddCollider({ Andyposition.x + 45, Andyposition.y + 65, 43, 20 }, COLLIDER_PLAYER_SHOT, App->player);
			}
			App->audio->PlayFX("Assets/FX/punch.wav");
		}
		if (AndyPunch.Finished() || AndyPunchM.Finished())
		{
			if (mirror)Andyposition.x += 38;
			colp->to_delete = true;
			AndyPunch.resetLoops(0);
			AndyPunchM.resetLoops(0);
			if (inputTerry.J_RIGHT || App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
			{
				currentstate = ST_WALK_FORWARD;
				current_animation = &AndyForward;
			}
			else if (inputTerry.J_LEFT || App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
			{
				currentstate = ST_WALK_BACKWARD;
				current_animation = &AndyBackwards;
			}
			else
			{
				currentstate = ST_IDLE;
				current_animation = &AndyIdle;
			}
			App->player2->collided = false;
		}
	}

	//KICK
	{
		if ((inputTerry.J_A || App->input->keyboard[SDL_SCANCODE_G] == KEY_STATE::KEY_DOWN) && ((currentstate == ST_IDLE) || (currentstate == ST_WALK_FORWARD) || (currentstate == ST_WALK_BACKWARD)))
		{
			currentstate = ST_KICK_STANDING;
			if (mirror)
			{
				Andyposition.x -= 60;
				current_animation = &AndyKickM;
				colk = App->collisions->AddCollider({ Andyposition.x + 16, Andyposition.y + 88, 55, 20 }, COLLIDER_PLAYER_SHOT, App->player);
			}
			else
			{
				current_animation = &AndyKick;
				colk = App->collisions->AddCollider({ Andyposition.x + 45, Andyposition.y + 88, 55, 20 }, COLLIDER_PLAYER_SHOT, App->player);
			}
			App->audio->PlayFX("Assets/FX/Voice/Attacks/FX_Attack4/FX_Attack4.wav");
		}
		if (AndyKickM.Finished())Andyposition.x += 60;
		if (AndyKick.Finished() == true || AndyKickM.Finished() == true)
		{
			if (mirror) Andyposition.x -= 10;
			else Andyposition.x += 10;
			colk->to_delete = true;
			AndyKickM.resetLoops(0);
			AndyKick.resetLoops(0);

			if (inputTerry.J_RIGHT || App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
			{
				currentstate = ST_WALK_FORWARD;
				if (mirror2)current_animation = &AndyBackwardsM;
				else current_animation = &AndyForward;
			}
			else if (inputTerry.J_LEFT || App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
			{
				currentstate = ST_WALK_BACKWARD;
				if (mirror2)current_animation = &AndyForwardM;
				else current_animation = &AndyBackwards;
			}
			else currentstate = ST_IDLE;
			App->player2->collided = false;
		}
	}

	//CROUCH
	{
		if ((inputTerry.J_DOWN || App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_DOWN) && (currentstate == ST_IDLE || currentstate == ST_WALK_FORWARD || currentstate == ST_WALK_BACKWARD))
		{
			currentstate = ST_CROUCH;
			current_animation = &AndyCrouch;
			col->rect.y = 10000;
			if (gmode != true)	colc->rect.y = Andyposition.y + 91;
		}
		if ((SDL_GameControllerGetAxis(App->input->gController1, SDL_CONTROLLER_AXIS_LEFTY) < 14000 && SDL_GameControllerGetAxis(App->input->gController1, SDL_CONTROLLER_AXIS_LEFTY) > 4000 || App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_UP) && currentstate == ST_CROUCH)
		{
			if (inputTerry.J_RIGHT || App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
			{
				currentstate = ST_WALK_FORWARD;
				current_animation = &AndyForward;
			}
			else if (inputTerry.J_LEFT || App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
			{
				currentstate = ST_WALK_BACKWARD;
				current_animation = &AndyBackwards;
			}
			else
			{
				currentstate = ST_IDLE;
				current_animation = &AndyIdle;
			}
			AndyCrouch.Reset();
			colc->rect.y = 10000;
			if (gmode != true) col->rect.y = Andyposition.y + 50;
		}
	}

	//CROUCHPUNCH
	{
		if ((inputTerry.J_B || App->input->keyboard[SDL_SCANCODE_F] == KEY_STATE::KEY_DOWN) && currentstate == ST_CROUCH)
		{
			currentstate = ST_PUNCH_CROUCH;
			current_animation = &AndyCrouchPunch;
			App->audio->PlayFX("Assets/FX/Voice/Attacks/FX_Attack4/FX_Attack4.wav");
			colcp = App->collisions->AddCollider({ Andyposition.x + 50, Andyposition.y + 55, 25, 20 }, COLLIDER_PLAYER_SHOT, App->player);
			colcp->rect.x = Andyposition.x + 50;
			colcp->rect.y = Andyposition.y + 55;
		}
		if (AndyCrouchPunch.Finished() == true)
		{
			colcp->to_delete = true;
			AndyCrouchPunch.resetLoops(0);
			App->player2->collided = false;

			if (inputTerry.J_DOWN || App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
			{
				currentstate = ST_CROUCH;
				current_animation = &AndyCrouch;
			}
			else
			{
				currentstate = ST_IDLE;
				current_animation = &AndyIdle;
				colc->rect.y = 10000;
				if (!gmode)col->rect.y = Andyposition.y + 50;
			}
		}
	}

	//CROUCHKICK
	{
		if ((inputTerry.J_A || App->input->keyboard[SDL_SCANCODE_G] == KEY_STATE::KEY_DOWN) && currentstate == ST_CROUCH)
		{
			currentstate = ST_KICK_CROUCH;
			colck->rect.x = Andyposition.x + 50;
			colck->rect.y = Andyposition.y + 90;
			if (mirror)
			{
				current_animation = &AndyCrouchKickM;
			}
			else
			{
				current_animation = &AndyCrouchKick;
				Andyposition.x -= 30;
				colc->rect.x -= 50;
				colck->rect.x = Andyposition.x + 20;
				colck->rect.y = Andyposition.y + 90;
			}
			App->audio->PlayFX("Assets/FX/Voice/Attacks/FX_Attack4/FX_Attack4.wav");
		}
		if (AndyCrouchKick.Finished() == true)
		{
			Andyposition.x += 30;
			colc->rect.x += 30;
			colck->to_delete = true;
			AndyCrouchKick.resetLoops(0);
			AndyCrouchKickM.resetLoops(0);

			if (inputTerry.J_DOWN || App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
			{
				currentstate = ST_CROUCH;
				current_animation = &AndyCrouch;
			}
			else
			{
				currentstate = ST_IDLE;
				colc->rect.y = 10000;
				if (!gmode)col->rect.y = Andyposition.y + 50;
			}
			App->player2->collided = false;
			colck = App->collisions->AddCollider({ 0, 0, 40, 20 }, COLLIDER_PLAYER_SHOT, App->player);
		}

		if (currentstate == ST_CROUCH && (inputTerry.J_RIGHT || App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_DOWN))
		{
			currentstate = ST_SD;
			current_animation = &AndyCrouch;
		}
		if (currentstate == ST_SD && (inputTerry.J_RIGHT || App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_UP))	currentstate = ST_CROUCH;
		if (currentstate == ST_SD && (SDL_GameControllerGetAxis(App->input->gController1, SDL_CONTROLLER_AXIS_LEFTY) < 14000 && SDL_GameControllerGetAxis(App->input->gController1, SDL_CONTROLLER_AXIS_LEFTY) > 4000 || App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_UP))
		{
			currentstate = ST_WALK_FORWARD;
			current_animation = &AndyForward;
			colc->rect.y = 10000;
			col->rect.y = Andyposition.y + 50;
		}
	}

	//POWER WAVE
	{
		if (currentstate == ST_SD && App->input->keyboard[SDL_SCANCODE_F] == KEY_STATE::KEY_DOWN)
		{
			currentstate = ST_POWER_WAVE;
			current_animation = &AndyPW;
			App->audio->PlayFX("Assets/FX/Voice/Special Attacks/FX_PowerWaveAttackTerryBogardVoice/FX_PowerWaveAttackTerryBogardVoice.wav");
			colc->rect.y = 10000;
			if(!gmode)
			col->rect.y = Andyposition.y + 50;
		}
		if (AndyPW.Finished() == true)
		{
			Uint32 inittime = 200;
			if (SDL_GetTicks() >= inittime)
			{
				App->particles->AddParticle(App->particles->terryenergy, Andyposition.x + 60, Andyposition.y + 12);
				App->particles->AddParticle(App->particles->terryenergy, Andyposition.x + 76, Andyposition.y + 12, 200);
				App->particles->AddParticle(App->particles->terryenergy, Andyposition.x + 92, Andyposition.y + 12, 400);
				App->particles->AddParticle(App->particles->terryenergy, Andyposition.x + 108, Andyposition.y + 12, 600);
				App->particles->AddParticle(App->particles->terryenergy, Andyposition.x + 124, Andyposition.y + 12, 800);
				App->particles->terryenergy.col->to_delete == true;
			}
			AndyPW.resetLoops(0);
			if (inputTerry.J_RIGHT || App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
			{
				currentstate = ST_WALK_FORWARD;
				current_animation = &AndyForward;
			}
			else if (inputTerry.J_LEFT || App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
			{
				currentstate = ST_WALK_BACKWARD;
				current_animation = &AndyBackwards;
			}
			else
			{
				currentstate = ST_IDLE;
				current_animation = &AndyIdle;
			}
			if (inputTerry.J_DOWN || App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
			{
				col->rect.y = 10000;
				if (!gmode)
					colc->rect.y = Andyposition.y + 91;
			}
			AndyPW.resetLoops(0);
		}
	}

	//GOD MODE
	if (App->input->keyboard[SDL_SCANCODE_F5] == KEY_STATE::KEY_DOWN)
	{
		if (gmode == false)
		{
			LOG("Starting GOD MODE");
			gmode = true;
			col->rect.y = 10000;
			colj->rect.y = 10000; 
			colc->rect.y = 10000;
		}
		else
		{
			LOG("GOD MODE off");
			if (currentstate == ST_IDLE) col->rect.y = Andyposition.y + 50;
			if (currentstate == ST_CROUCH) colc->rect.y = Andyposition.y + 91;
			if (currentstate == ST_GOING_UP || currentstate == ST_GOING_UP_FORWARD || currentstate == ST_GOING_UP_BACKWARD) colj->rect.y = Andyposition.y + 50;
			else if (currentstate == ST_GOING_DOWN || currentstate == ST_GOING_DOWN_FORWARD || currentstate == ST_GOING_DOWN_BACKWARD) colj->rect.y = Andyposition.y + 50;
			else if(currentstate == ST_TOP || currentstate == ST_TOP_FORWARD || currentstate == ST_TOP_BACKWARD) colj->rect.y = Andyposition.y + 85;

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
	if (currentstate == ST_PUNCH_STANDING && mirror)
		col->rect.x = Andyposition.x + 53;
	if (currentstate == ST_KICK_STANDING && mirror)
		col->rect.x = Andyposition.x + 71;
	else col->rect.x = Andyposition.x + 14;

	colj->rect.x = Andyposition.x + 13;
	if (currentstate != ST_KICK_CROUCH)
	colc->rect.x = Andyposition.x + 13;
	if (currentstate == ST_JUMP_FORWARD || currentstate == ST_JUMP_BACKWARD)
		colj->rect.y = Andyposition.y + 50;

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	// Draw everything --------------------------------------
	if (destroyed == false)
	{
		App->render->Blit(graphics, Andyposition.x, Andyposition.y, &(current_animation->GetCurrentFrame()));
	}

	// Draw UI (score) --------------------------------------k
	App->fonts->BlitText(10, 150, font_score, "546");

	return UPDATE_CONTINUE;
}
void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (c1->type == COLLIDER_ENEMY_SHOT && c2->type == COLLIDER_PLAYER && collided == false && App->player2->currentstate == ST_PUNCH_STANDING2)
	{
		life_score -= stantardDMG;
		collided = true;
		currentstate = ST_BEING_PUNCHED;
		if(mirror) App->player2->current_animation = &AndyPunchLongM;
		else App->player2->current_animation = &AndyPunchLong;
	}
	if (c1->type == COLLIDER_ENEMY && c2->type == COLLIDER_PLAYER && collided == false)
	{

	}
}


//#endif;
