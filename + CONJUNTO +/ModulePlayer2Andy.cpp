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
#include "ModulePlayer.h"


// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer2::ModulePlayer2()
{

	lifebar = { 180, 69, 117, 80 };
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
		AndyPW.PushBack({ 0, 300, 65, 150 });
		AndyPW.PushBack({ 65, 300, 48, 150 });
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
		AndyDP.PushBack({ 585, 450, 62, 150 });
		AndyDP.PushBack({ 647, 450, 65, 150 });
		AndyDP.speed = 0.1f;
	}

	//DAMAGED BY KICK						 //!!!
	{
		AndyDK.PushBack({ 712, 450, 54, 150 });
		AndyDK.PushBack({ 766, 450, 64, 150 }); //830
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
		AndyCrouchPunch.PushBack({ 624, 600, 49, 150 }); //Charge
		AndyCrouchPunch.PushBack({ 673, 600, 78, 150 }); //Riposte //751
		AndyCrouchPunch.speed = 0.1f;
	}


	//CROUCHKICK
	{
		AndyCrouchKick.PushBack({ 0, 600,  79, 150 });   //Charge
		AndyCrouchKick.PushBack({ 79, 600,  79, 150 });  //Riposte
		AndyCrouchKick.PushBack({ 158, 600, 119, 150 }); //Punch
		AndyCrouchKick.PushBack({ 79, 600,  79, 150 });
		AndyCrouchKick.PushBack({ 0, 600,  79, 150 });
		AndyCrouchKick.speed = 0.1f;
	}
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
	{
		//IDLE
		AndyIdleM.PushBack({ 1748, 150, 60, 150 });
		AndyIdleM.PushBack({ 1808, 150, 60, 150 });
		AndyIdleM.PushBack({ 1868, 150, 60, 150 });
		AndyIdleM.PushBack({ 1928, 150, 60, 150 });
		AndyIdleM.PushBack({ 1988, 150, 60, 150 });
		AndyIdleM.speed = 0.1f;

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
		{
			//LAUNCH AND UP
			TerryGoingUpM.PushBack({ 557, 0, 57, 123 });
			TerryGoingUpM.PushBack({ 614, 0, 51, 123 });
			TerryGoingUpM.PushBack({ 614, 0, 51, 123 });
			TerryGoingUpM.PushBack({ 614, 0, 51, 123 });
			TerryGoingUpM.PushBack({ 614, 0, 51, 123 });
			TerryGoingUpM.PushBack({ 614, 0, 51, 123 });
			TerryGoingUpM.PushBack({ 614, 0, 51, 123 });
			TerryGoingUpM.PushBack({ 614, 0, 51, 123 });
			TerryGoingUpM.PushBack({ 614, 0, 51, 123 });
			TerryGoingUpM.PushBack({ 614, 0, 51, 123 });
			TerryGoingUpM.PushBack({ 614, 0, 51, 123 });
			TerryGoingUpM.PushBack({ 614, 0, 51, 123 });
			TerryGoingUpM.PushBack({ 614, 0, 51, 123 });
			TerryGoingUpM.PushBack({ 614, 0, 51, 123 });
			TerryGoingUpM.PushBack({ 614, 0, 51, 123 });
			TerryGoingUpM.PushBack({ 614, 0, 51, 123 });
			TerryGoingUpM.PushBack({ 614, 0, 51, 123 });
			TerryGoingUpM.PushBack({ 614, 0, 51, 123 });
			TerryGoingUpM.PushBack({ 614, 0, 51, 123 });
			TerryGoingUpM.PushBack({ 614, 0, 51, 123 });
			TerryGoingUpM.speed = 0.1f;

			TerryTopM.PushBack({ 665, 0, 53, 123 });

			//GOING DOWN AND LAND
			TerryGoingDownM.PushBack({ 722, 0, 57, 123 });
			TerryGoingDownM.PushBack({ 722, 0, 57, 123 });
			TerryGoingDownM.PushBack({ 722, 0, 57, 123 });
			TerryGoingDownM.PushBack({ 722, 0, 57, 123 });
			TerryGoingDownM.PushBack({ 722, 0, 57, 123 });
			TerryGoingDownM.PushBack({ 722, 0, 57, 123 });
			TerryGoingDownM.PushBack({ 557, 0, 57, 123 });
			TerryGoingDownM.speed = 0.1f;
		}
		// KICK animation of Terry							//spritesTerryBogard2extres.png
		TerryKickM.PushBack({ 0, 137, 116, 112 });
		TerryKickM.PushBack({ 116, 137, 116, 112 });
		TerryKickM.PushBack({ 232, 137, 116, 112 });
		TerryKickM.PushBack({ 348, 137, 116, 112 });
		TerryKickM.PushBack({ 464, 137, 116, 112 });
		TerryKickM.speed = 0.1f;

		//PUNCH
		{
			TerryPunchM.PushBack({ 453, 910, 95, 112 });
			TerryPunchM.PushBack({ 358, 911, 95, 112 });
			TerryPunchM.PushBack({ 263, 911, 95, 112 });
			TerryPunchM.speed = 0.1f;
		}

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
}


ModulePlayer2::~ModulePlayer2()
{}

// Load assets
bool ModulePlayer2::Start()
{
	LOG("Loading player 2");
	bool ret = true;
	graphics = App->textures->Load("Assets/Sprites/Sprites_AndyBogard_ok.png");

	UI = App->textures->Load("Assets/Sprites/UI.png");

	destroyed = false;
	Andy2position.x = 215 + (250);
	Andy2position.y = 60;
	score = 0;
	col   = App->collisions->AddCollider({    0, 1000, 31, 101 }, COLLIDER_ENEMY, App->player2);
	colc  = App->collisions->AddCollider({    0, 1000, 36, 60 }, COLLIDER_ENEMY, App->player2);
	colj  = App->collisions->AddCollider({    0, 1000, 36, 60 }, COLLIDER_ENEMY, App->player2);
	colcp = App->collisions->AddCollider({ 1000, 1000, 25, 20 }, COLLIDER_ENEMY_SHOT, App->player2);
	colck = App->collisions->AddCollider({ 1000, 1000, 40, 20 }, COLLIDER_ENEMY_SHOT, App->player2);

	currentstate = ST_IDLE2;
	current_animation = &AndyIdleM;

	font_score = App->fonts->Load("Assets/Sprites/fonts/scorenums.png", "1234567890", 1);
	return ret;
}

// Unload assets
bool ModulePlayer2::CleanUp()
{
	LOG("Unloading player 2");

	App->textures->Unload(graphics);

	App->fonts->UnLoad(font_score);
	if (col)
		col->to_delete = true;
	if (colj)
		colj->to_delete = true;
	if (colc)
		colc->to_delete = true;
	return true;
}

update_status ModulePlayer2::PreUpdate()
{
	inputAndy.A_DOWN = App->input->keyboard[SDL_SCANCODE_A] == KEY_REPEAT;
	inputAndy.D_DOWN = App->input->keyboard[SDL_SCANCODE_D] == KEY_REPEAT;
	inputAndy.S_DOWN = App->input->keyboard[SDL_SCANCODE_S] == KEY_REPEAT;
	inputAndy.W_DOWN = App->input->keyboard[SDL_SCANCODE_W] == KEY_REPEAT;
	inputAndy.F_DOWN = App->input->keyboard[SDL_SCANCODE_F] == KEY_DOWN;
	inputAndy.G_DOWN = App->input->keyboard[SDL_SCANCODE_G] == KEY_DOWN;
	inputAndy.H_DOWN = App->input->keyboard[SDL_SCANCODE_H] == KEY_DOWN;
	inputAndy.SD_DOWN = (App->input->keyboard[SDL_SCANCODE_S] == KEY_DOWN) && (App->input->keyboard[SDL_SCANCODE_D] == KEY_DOWN);

	SDL_Event event;

	while (SDL_PollEvent(&event) != 0)
	{
		if (mirror2) { current_animation = &TerryidleM; }
		else { current_animation = &Terryidle; }
	}


	int speed = 1;


	/*if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
	{
		if (mirror2)
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
			current_animation = &TerryForward;

			if (Terry2position.x < 570 && Terry2position.x * 2 - 260 < -(App->render->camera.x - App->render->camera.w))
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
	}*/
	return UPDATE_CONTINUE;
}

update_status ModulePlayer2::Update()
{
	// MIRROR
	if (App->player2->col->rect.x < App->player->col->rect.x ||
		App->player2->colc->rect.x < App->player->col->rect.x ||
		App->player2->colj->rect.x < App->player->col->rect.x ||
		App->player2->col->rect.x < App->player->colc->rect.x ||
		App->player2->colj->rect.x < App->player->colc->rect.x ||
		App->player2->col->rect.x < App->player->colj->rect.x ||
		App->player2->colc->rect.x < App->player->colj->rect.x ||
		App->player2->colj->rect.x < App->player->colj->rect.x)
		mirror2 = false;
	else mirror2 = true;

	//IDLE
	if (currentstate == ST_IDLE2)
	{
		if (mirror2)current_animation = &TerryidleM;
		else current_animation = &Terryidle;
	}

	//MOVE BACKWARD							CAMERA FIX NEEDED	
	{
		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_DOWN && currentstate == ST_IDLE2)
			currentstate = ST_WALK_BACKWARD2;
		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && currentstate == ST_WALK_BACKWARD2)
		{
			if (mirror2)
			{
				if (Andy2position.x < 700) Andy2position.x++;
				current_animation = &TerryBackwardsM;
			}
			else 
			{
				if (Andy2position.x < 700) Andy2position.x += 2;
				current_animation = &TerryForward;
			}
		}
		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_UP && currentstate == ST_WALK_BACKWARD2)
		{
			TerryForward.resetLoops(0);
			TerryBackwardsM.resetLoops(0);
			if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
				currentstate = ST_WALK_FORWARD2;
			else
				currentstate = ST_IDLE2;
		}
	}

	//MOVE FORWARD							CAMERA FIX NEEDED
	{
		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_DOWN && currentstate == ST_IDLE2)
			currentstate = ST_WALK_FORWARD2;
		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && currentstate == ST_WALK_FORWARD2)
		{
			if (mirror2) current_animation = &TerryForwardM;
			else current_animation = &TerryBackwards;
			if (Andy2position.x < 700 /*&& Terry2position.x * 2 - 160 < -(App->render->camera.x - App->render->camera.w)*/)
				Andy2position.x -= speed;
		}
		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_UP && currentstate == ST_WALK_FORWARD2)
		{
			TerryBackwards.resetLoops(0);
			TerryForwardM.resetLoops(0);
			if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
				currentstate = ST_WALK_BACKWARD2;
			else
				currentstate = ST_IDLE2;
		}
	}

	//PUNCH
	{
		if (App->input->keyboard[SDL_SCANCODE_J] == KEY_STATE::KEY_DOWN && ((currentstate == ST_IDLE2) || (currentstate == ST_WALK_FORWARD2) || (currentstate == ST_WALK_BACKWARD2)))
		{
			currentstate = ST_PUNCH_STANDING2;
			if (mirror2)
			{
				Andy2position.x -= 38;
				current_animation = &TerryPunchM;
				colp = App->collisions->AddCollider({ Andy2position.x - 28 + 38, Andy2position.y + 20, 43, 20 }, COLLIDER_ENEMY_SHOT, App->player2);
			}
			else
			{
				current_animation = &TerryPunch;
				colp = App->collisions->AddCollider({ Andy2position.x + 45, Andy2position.y + 20, 43, 20 }, COLLIDER_ENEMY_SHOT, App->player2);
			}
			App->audio->PlayFX("Assets/FX/punch.wav");
		}
		if (TerryPunchM.Finished())Andy2position.x += 38;
		if (TerryPunch.Finished() || TerryPunchM.Finished())
		{
			colp->to_delete = true;
			App->player->collided = false;
			TerryPunch.resetLoops(0);
			TerryPunchM.resetLoops(0);
			if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
			{
				currentstate = ST_WALK_FORWARD2;
				if (mirror2)current_animation = &TerryForwardM;
				else current_animation = &TerryBackwards;
			}
			else if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
			{
				currentstate = ST_WALK_BACKWARD2;
				if (mirror2)current_animation = &TerryBackwardsM;
				else current_animation = &TerryForward;
			}
			else
				currentstate = ST_IDLE2;
			App->player2->collided = false;
		}
	}

	//KICK
	{
		if (App->input->keyboard[SDL_SCANCODE_H] == KEY_STATE::KEY_DOWN && ((currentstate == ST_IDLE2) || (currentstate == ST_WALK_FORWARD2) || (currentstate == ST_WALK_BACKWARD2)))
		{
			currentstate = ST_KICK_STANDING2;
			if (mirror2)
			{
				Andy2position.x -= 63;
				current_animation = &TerryKickM;
				colk = App->collisions->AddCollider({ Andy2position.x + 16, Andy2position.y + 48, 55, 20 }, COLLIDER_ENEMY_SHOT, App->player2);
			}
			else
			{
				current_animation = &TerryKick;
				colk = App->collisions->AddCollider({ Andy2position.x + 45, Andy2position.y + 48, 55, 20 }, COLLIDER_ENEMY_SHOT, App->player2);
			}
			App->audio->PlayFX("Assets/FX/Voice/Attacks/FX_Attack4/FX_Attack4.wav");
		}
		if (TerryKickM.Finished())Andy2position.x += 63;
		if (TerryKick.Finished() == true || TerryKickM.Finished() == true)
		{
			if (mirror2) Andy2position.x -= 10;
			else Andy2position.x += 10;
			colk->to_delete = true;
			TerryKick.resetLoops(0);
			TerryKickM.resetLoops(0);
			if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
			{
				currentstate = ST_WALK_BACKWARD2;
				if (mirror2)current_animation = &TerryBackwardsM;
				else current_animation = &TerryForward;
			}
			else if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
			{
				currentstate = ST_WALK_FORWARD2;
				if (mirror2)current_animation = &TerryForwardM;
				else current_animation = &TerryBackwards;
			}
			else currentstate = ST_IDLE2;
			App->player2->collided = false;
		}
	}

	//JUMP
	{
		if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_DOWN && currentstate == ST_IDLE2)
		{
			currentstate = ST_GOING_UP2;
			col->to_delete = true;
			if (!gmode) colj = App->collisions->AddCollider({ Andy2position.x + 13, Andy2position.y + 50, 36, 60 }, COLLIDER_ENEMY);
		}
		if (currentstate == ST_GOING_UP2)
		{
			colj->rect.y = Andy2position.y + 13;
			if (mirror2)current_animation = &TerryGoingUpM;
			else current_animation = &TerryGoingUp;
			speed -= 0.01;
			Andy2position.y = Andy2position.y - 3 * speed;
			App->render->camera.y = App->render->camera.y + speed;
			if (Andy2position.y <= 45)
			{
				currentstate = ST_TOP2;
				speed = 1.0;
			}
		}
		if (currentstate == ST_TOP2)
		{
			colj->rect.y = Andy2position.y + 43;
			if (mirror2)current_animation = &TerryTopM;
			else current_animation = &TerryTop;
			TerryGoingUp.resetLoops(0);
			TerryGoingUpM.resetLoops(0);
			speed += 0.01;
			Andy2position.y = Andy2position.y - 3 * speed;
			if (Andy2position.y <= 25)
				currentstate = ST_GOING_DOWN2;
		}
		if (currentstate == ST_GOING_DOWN2)
		{
			if (mirror2) current_animation = &TerryGoingDownM;
			else current_animation = &TerryGoingDown;

			colj->rect.y = Andy2position.y + 53;
			Andy2position.y = Andy2position.y + 3 * (speed + 0.6);
			App->render->camera.y = App->render->camera.y - speed;
			if (App->render->camera.y <= -10)
				App->render->camera.y = -10;

			if (Andy2position.y >= 100)
			{
				Andy2position.y = 100;
				if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
				{
					currentstate = ST_WALK_FORWARD2;
					if (mirror2)current_animation = &TerryForwardM;
					else current_animation = &TerryBackwards;
				}
				else if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
				{
					currentstate = ST_WALK_BACKWARD2;
					if (mirror2)current_animation = &TerryBackwardsM;
					else current_animation = &TerryForward;
				}
				else if (App->input->keyboard[SDL_SCANCODE_DOWN] == KEY_STATE::KEY_REPEAT)
				{
					currentstate = ST_CROUCH2;
					if (mirror2)current_animation = &TerryCrouchM;
					else current_animation = &TerryCrouch;
				}
				else currentstate = ST_IDLE2;

				TerryGoingDown.resetLoops(0);
				TerryGoingDownM.resetLoops(0);
				speed = 1.0;
				colj->to_delete = true;
				if (!gmode) col = App->collisions->AddCollider({ 0, 0, 31, 101 }, COLLIDER_ENEMY, App->player2);
			}
		}
	}

	//POWER WAVE
	if (App->input->keyboard[SDL_SCANCODE_P] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddEnemyParticle(App->particles->terryenergy, Andy2position.x + 40, Andy2position.y + 12);
		App->audio->PlayFX("Assets/FX/Voice/Special Attacks/FX_PowerWaveAttackTerryBogardVoice/FX_PowerWaveAttackTerryBogardVoice.wav");
	}


	if (App->input->keyboard[SDL_SCANCODE_P] == KEY_STATE::KEY_REPEAT)
	{
		if (mirror2) { current_animation = &TerryPWM; }
		else { current_animation = &TerryPW; }
	}

	if (App->input->keyboard[SDL_SCANCODE_F8] == KEY_STATE::KEY_DOWN)
	{
		if (gmode == false)
		{
			LOG("Starting GOD MODE");
			gmode = true;
			col->to_delete = true;
		}
		else
		{
			LOG("GOD MODE off");
			col = App->collisions->AddCollider({ 0, 0, 30, 103 }, COLLIDER_ENEMY, App->player2);
			gmode = false;
		}
	}


	App->render->Blit(UI, 165, 0, &lifebar, 0);
	if (life_score >= 4)
	{
		App->render->Blit(UI, 263, 26, &life1, 0);
		App->render->Blit(UI, 259, 26, &life2, 0);
	}
	if (life_score >= 8)
		App->render->Blit(UI, 255, 26, &life2, 0);
	if (life_score >= 12)
		App->render->Blit(UI, 251, 26, &life2, 0);
	if (life_score >= 16)
		App->render->Blit(UI, 247, 26, &life2, 0);
	if (life_score >= 20)
		App->render->Blit(UI, 243, 26, &life2, 0);
	if (life_score >= 24)
		App->render->Blit(UI, 239, 26, &life2, 0);
	if (life_score >= 28)
		App->render->Blit(UI, 235, 26, &life2, 0);
	if (life_score >= 32)
		App->render->Blit(UI, 231, 26, &life2, 0);
	if (life_score >= 36)
		App->render->Blit(UI, 227, 26, &life2, 0);
	if (life_score >= 40)
		App->render->Blit(UI, 223, 26, &life2, 0);
	if (life_score >= 44)
		App->render->Blit(UI, 219, 26, &life2, 0);
	if (life_score >= 48)
		App->render->Blit(UI, 215, 26, &life2, 0);
	if (life_score >= 52)
		App->render->Blit(UI, 211, 26, &life2, 0);
	if (life_score >= 56)
		App->render->Blit(UI, 207, 26, &life2, 0);
	if (life_score >= 60)
		App->render->Blit(UI, 203, 26, &life2, 0);
	if (life_score >= 64)
		App->render->Blit(UI, 199, 26, &life2, 0);
	if (life_score >= 68)
		App->render->Blit(UI, 195, 26, &life2, 0);
	if (life_score >= 72)
		App->render->Blit(UI, 191, 26, &life2, 0);
	if (life_score >= 76)
		App->render->Blit(UI, 187, 26, &life2, 0);
	if (life_score >= 80)
		App->render->Blit(UI, 183, 26, &life2, 0);
	if (life_score >= 84)
		App->render->Blit(UI, 179, 26, &life2, 0);
	if (life_score >= 88)
		App->render->Blit(UI, 175, 26, &life2, 0);
	if (life_score >= 92)
	{
		App->render->Blit(UI, 171, 26, &life2, 0);
		App->render->Blit(UI, 170, 26, &life1, 0);
	}
	if (currentstate == ST_PUNCH_STANDING2 && mirror2)
		col->rect.x = Andy2position.x + 53;
	else if (currentstate == ST_KICK_STANDING2 && mirror2)
		col->rect.x = Andy2position.x + 71;
	else
	{
		col->rect.x = Andy2position.x + 14;
		col->rect.y = Andy2position.y + 10;
	}
	if (currentstate != ST_PUNCH_STANDING2 && currentstate != ST_KICK_STANDING2)
	{
		colj->rect.x = Andy2position.x + 13;
		colc->rect.x = Andy2position.x + 13;
	}

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	// Draw everything --------------------------------------
	if (destroyed == false)
	{
		App->render->Blit(graphics, Andy2position.x, Andy2position.y, &(current_animation->GetCurrentFrame()));
	}

	// Draw UI (score) --------------------------------------
	sprintf_s(score_text, 10, "%7d", score);
	return UPDATE_CONTINUE;
}

void ModulePlayer2::OnCollision(Collider* c1, Collider* c2)
{
	if (c1->type == COLLIDER_ENEMY && c2->type == COLLIDER_PLAYER_SHOT && collided == false)
	{
		life_score -= 12;
		collided = false;
	}
}
//#endif;