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
		Terryidle.PushBack({ 28, 909, 58, 112 });
		Terryidle.PushBack({ 96, 910, 59, 112 });
		Terryidle.PushBack({ 165, 909, 58, 112 });
		Terryidle.PushBack({ 96, 910, 59, 112 });
		Terryidle.speed = 0.1f;
	}

	// WALK FORWARD animation of Terry					//TerryAvanzar+SaltoEstatico+Patada+Retroceder.png
	{
		TerryForward.PushBack({ 21, 268, 59, 112 });
		TerryForward.PushBack({ 96, 268, 69, 112 });
		TerryForward.PushBack({ 178, 268, 59, 112 });
		TerryForward.PushBack({ 252, 268, 59, 112 });
		TerryForward.speed = 0.1f;
	}

	// WALK BACKWARD animation of Terry					//spritesTerryBogard2extres.png
	{
		TerryBackwards.PushBack({ 382, 270, 59, 112 });
		TerryBackwards.PushBack({ 442, 270, 55, 112 });
		TerryBackwards.PushBack({ 497, 270, 56, 112 });
		TerryBackwards.PushBack({ 553, 270, 57, 112 });
		TerryBackwards.speed = 0.1f;
	}

	// JUMP animation of Terry							//spritesTerryBogard2extres.png
	{
		//LAUNCH AND UP
		TerryGoingUp.PushBack({ 802, 0, 57, 123 });
		TerryGoingUp.PushBack({ 859, 0, 51, 123 });
		TerryGoingUp.PushBack({ 859, 0, 51, 123 });
		TerryGoingUp.PushBack({ 859, 0, 51, 123 });
		TerryGoingUp.PushBack({ 859, 0, 51, 123 });
		TerryGoingUp.PushBack({ 859, 0, 51, 123 });
		TerryGoingUp.PushBack({ 859, 0, 51, 123 });
		TerryGoingUp.PushBack({ 859, 0, 51, 123 });
		TerryGoingUp.PushBack({ 859, 0, 51, 123 });
		TerryGoingUp.PushBack({ 859, 0, 51, 123 });
		TerryGoingUp.PushBack({ 859, 0, 51, 123 });
		TerryGoingUp.PushBack({ 859, 0, 51, 123 });
		TerryGoingUp.PushBack({ 859, 0, 51, 123 });
		TerryGoingUp.PushBack({ 859, 0, 51, 123 });
		TerryGoingUp.PushBack({ 859, 0, 51, 123 });
		TerryGoingUp.PushBack({ 859, 0, 51, 123 });
		TerryGoingUp.PushBack({ 859, 0, 51, 123 });
		TerryGoingUp.PushBack({ 859, 0, 51, 123 });
		TerryGoingUp.PushBack({ 859, 0, 51, 123 });
		TerryGoingUp.PushBack({ 859, 0, 51, 123 });
		TerryGoingUp.PushBack({ 859, 0, 51, 123 });
		TerryGoingUp.PushBack({ 859, 0, 51, 123 });
		TerryGoingUp.speed = 0.1f;

		TerryTop.PushBack({ 910, 0, 53, 123 });

		//GOING DOWN AND LAND
		TerryGoingDown.PushBack({ 967, 0, 57, 123 });
		TerryGoingDown.PushBack({ 967, 0, 57, 123 });
		TerryGoingDown.PushBack({ 967, 0, 57, 123 });
		TerryGoingDown.PushBack({ 967, 0, 57, 123 });
		TerryGoingDown.PushBack({ 967, 0, 57, 123 });
		TerryGoingDown.PushBack({ 967, 0, 57, 123 });
		TerryGoingDown.PushBack({ 802, 0, 57, 123 });
		TerryGoingDown.speed = 0.1f;
	}

	// KICK animation of Terry							//spritesTerryBogard2extres.png
	{
		TerryKick.PushBack({ 0, 134,  47, 112 });
		TerryKick.PushBack({ 47, 134,  57, 112 });
		TerryKick.PushBack({ 104, 134,  42, 112 });
		TerryKick.PushBack({ 146, 134, 116, 112 });
		TerryKick.PushBack({ 261, 134,  62, 112 });
		TerryKick.speed = 0.1f;
	}

	//PUNCH
	{
		TerryPunch.PushBack({ 435, 910, 71, 112 });
		TerryPunch.PushBack({ 507, 911, 61, 112 });
		TerryPunch.PushBack({ 575, 911, 95, 112 });
		TerryPunch.speed = 0.1f;
	}

	// POWER WAVE animation of Terrry
	{
		TerryPW.PushBack({ 623, 683, 51, 112 });
		TerryPW.PushBack({ 550, 683, 54, 112 });
		TerryPW.PushBack({ 485, 683, 60, 112 });
		TerryPW.PushBack({ 402, 683, 79, 112 });
		TerryPW.PushBack({ 330, 683, 67, 112 });
		TerryPW.PushBack({ 263, 683, 65, 112 });
		TerryPW.PushBack({ 198, 683, 60, 112 });
		TerryPW.speed = 0.1f;
	}

	//DAMAGED BY PUNCH
	{
		TerryDP.PushBack({ 0, 912, 59, 112 });
		TerryDP.PushBack({ 64, 912, 67, 112 });
		TerryDP.speed = 0.1f;
	}

	//DAMAGED BY KICK
	{
		TerryDK.PushBack({ 136, 912, 63, 112 });
		TerryDK.PushBack({ 211, 912, 68, 112 });
		TerryDK.speed = 0.1f;
	}

	//CROUCH
	{
		TerryCrouch.PushBack({ 488, 912, 57, 112 });
		TerryCrouch.PushBack({ 545, 912, 52, 112 });
		TerryCrouch.speed = 0.2f;
		TerryCrouch.loop = false;
	}

	//JUMPFORWARD
	{
		TerryJumpForward.PushBack({ 624, 912, 57, 112 });
		TerryJumpForward.PushBack({ 681, 912, 56, 112 });
		TerryJumpForward.PushBack({ 737, 912, 87, 112 });
		TerryJumpForward.PushBack({ 824, 912, 53, 112 });
		TerryJumpForward.PushBack({ 877, 912, 87, 112 });
		TerryJumpForward.PushBack({ 964, 912, 60, 112 });
		TerryJumpForward.PushBack({ 624, 912, 57, 112 });
		TerryJumpForward.speed = 0.1f;
	}

	//JUMPBACKWARDS
	{
		TerryJumpBackwards.PushBack({ 624, 912, 57, 112 });
		TerryJumpBackwards.PushBack({ 964, 912, 60, 112 });
		TerryJumpBackwards.PushBack({ 877, 912, 87, 112 });
		TerryJumpBackwards.PushBack({ 824, 912, 53, 112 });
		TerryJumpBackwards.PushBack({ 737, 912, 87, 112 });
		TerryJumpBackwards.PushBack({ 681, 912, 56, 112 });
		TerryJumpBackwards.PushBack({ 624, 912, 57, 112 });
		TerryJumpBackwards.speed = 0.1f;
	}

	//CROUCHPUNCH
	{
		TerryCrouchPunch.PushBack({ 279, 912, 56, 112 }); //Charge
		TerryCrouchPunch.PushBack({ 416, 912, 49, 112 }); //Riposte
		TerryCrouchPunch.PushBack({ 335, 912, 81, 112 }); //Punch
		TerryCrouchPunch.PushBack({ 416, 912, 49, 112 }); //Riposte x2
		TerryCrouchPunch.speed = 0.1f;
	}

	//CROUCHKICK
	{
		TerryCrouchKick.PushBack({ 0, 788, 56, 112 });   //Charge
		TerryCrouchKick.PushBack({ 56, 788, 58, 112 });  //Riposte
		TerryCrouchKick.PushBack({ 114, 788, 92, 112 }); //Punch
		TerryCrouchKick.PushBack({ 206, 788, 58, 112 }); //Riposte x2
		TerryCrouchKick.speed = 0.1f;
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
		TerryKickM.PushBack({   0, 137, 116, 112 });
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
	if (Terry2position.x <= App->player->Terryposition.x) mirror2 = false;
	else mirror2 = true;

	LOG("Loading player");
	bool ret = true;

	graphics = App->textures->Load("Assets/Sprites/spritesTerryBogard.png");
	graphics2 = App->textures->Load("Assets/Sprites/spritesTerryBogard2extres.png");
	graphicsM = App->textures->Load("Assets/Sprites/spritesTerryBogardMIRROR.png");
	graphics2M = App->textures->Load("Assets/Sprites/spritesTerryBogard2extresMIRROR.png");

	UI = App->textures->Load("Assets/Sprites/UI.png");

	destroyed = false;
	//Terryposition.x = 150;
	//Terryposition.y = 115;
	Terry2position.x = 215 + (250);
	Terry2position.y = 100;
	score = 0;

	currentstate = ST_IDLE2;

	// TODO 2: Add a collider to the player
	col = App->collisions->AddCollider({ 0, 0, 30, 101 }, COLLIDER_ENEMY, App->player2);
	colc= App->collisions->AddCollider({ 0, 0, 36, 60 }, COLLIDER_ENEMY, App->player2);
	colj = App->collisions->AddCollider({ 0, 0, 36, 60 }, COLLIDER_ENEMY, App->player2);
	colcp = App->collisions->AddCollider({ 1000, 1000, 25, 20 }, COLLIDER_ENEMY_SHOT, App->player2);
	colck = App->collisions->AddCollider({ 1000, 1000, 40, 20 }, COLLIDER_ENEMY_SHOT, App->player2);

	// TODO 0: Notice how a font is loaded and the meaning of all its arguments 
	font_score = App->fonts->Load("Assets/Sprites/fonts/rtype_font.png", "! @,_./0123456789$;<&?abcdefghijklmnopqrstuvwxyz", 1);
	return ret;
}

// Unload assets
bool ModulePlayer2::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);
	App->textures->Unload(graphics2);

	App->textures->Unload(graphicsM);
	App->textures->Unload(graphics2M);


	App->fonts->UnLoad(font_score);
	if (col)
		col->to_delete = true;
	if (colj)
		colj->to_delete = true;
	if(colc)
		colc->to_delete=true;
	return true;
}
update_status ModulePlayer2::PreUpdate()
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

// Update: draw background
update_status ModulePlayer2::Update()
{
	// MIRROR
	if (App->player2->col->rect.x < App->player->col->rect.x   ||
		App->player2->colc->rect.x < App->player->col->rect.x  ||
		App->player2->colj->rect.x < App->player->col->rect.x  ||
		App->player2->col->rect.x < App->player->colc->rect.x  ||
		App->player2->colj->rect.x < App->player->colc->rect.x ||
		App->player2->col->rect.x < App->player->colj->rect.x  ||
		App->player2->colc->rect.x < App->player->colj->rect.x ||
		App->player2->colj->rect.x < App->player->colj->rect.x)
		mirror2 = true;
	else mirror2 = false;

	//IDLE
	if (currentstate == ST_IDLE2)
		if (mirror2)current_animation = &TerryidleM;
		else current_animation = &Terryidle;
	
	//MOVE BACKWARD							CAMERA FIX NEEDED	
	{
		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_DOWN && currentstate == ST_IDLE2)
			currentstate = ST_WALK_BACKWARD2;
		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && currentstate == ST_WALK_BACKWARD2)
		{
			if (mirror2) current_animation = &TerryBackwardsM;
			else current_animation = &TerryForward;
			if (Terry2position.x < 700 /*&& Terry2position.x * 2 - 160 < -(App->render->camera.x - App->render->camera.w)*/)
				Terry2position.x += speed;
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
			if (Terry2position.x < 700 /*&& Terry2position.x * 2 - 160 < -(App->render->camera.x - App->render->camera.w)*/)
				Terry2position.x -= speed;
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
				Terry2position.x -= 38;
				current_animation = &TerryPunchM;
				colp = App->collisions->AddCollider({ Terry2position.x - 28+38, Terry2position.y + 20, 43, 20 }, COLLIDER_ENEMY_SHOT, App->player2);
			}
			else
			{
				current_animation = &TerryPunch;
				colp = App->collisions->AddCollider({ Terry2position.x + 45, Terry2position.y + 20, 43, 20 }, COLLIDER_ENEMY_SHOT, App->player2);
			}
			App->audio->PlayFX("Assets/FX/punch.wav");
		}
		if (TerryPunchM.Finished())Terry2position.x += 38;
		if (TerryPunch.Finished() || TerryPunchM.Finished())
		{
			colp->to_delete = true;
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
				Terry2position.x -= 68;
				current_animation = &TerryKickM;
				colk = App->collisions->AddCollider({ Terry2position.x + 45, Terry2position.y + 48, 55, 20 }, COLLIDER_ENEMY_SHOT, App->player);
			}
			else
			{
				current_animation = &TerryKick;
				colk = App->collisions->AddCollider({ Terry2position.x + 45, Terry2position.y + 48, 55, 20 }, COLLIDER_ENEMY_SHOT, App->player);
				Terry2position.x += 10;
			}
			App->audio->PlayFX("Assets/FX/Voice/Attacks/FX_Attack4/FX_Attack4.wav");
		}
		if(TerryKickM.Finished())Terry2position.x += 68;
		if (TerryKick.Finished() == true || TerryKickM.Finished() == true)
		{
			Terry2position.x -= 10;
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
			else
				currentstate = ST_IDLE2;
			App->player2->collided = false;
		}
	}

	//PPWER WAVE
	if (App->input->keyboard[SDL_SCANCODE_P] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddEnemyParticle(App->particles->terryenergy, Terry2position.x + 40, Terry2position.y + 12);
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

	// TODO 3: Update collider position to player position
	//col->rect.x = Terryposition.x;
	//col->rect.y = Terryposition.y;
	if (currentstate == ST_PUNCH_STANDING2 && mirror2)
		col->rect.x = Terry2position.x + 53;
	else if (currentstate == ST_KICK_STANDING2)
		col->rect.x = Terry2position.x + 53;
	else
	{
		col->rect.x = Terry2position.x + 15;
		col->rect.y = Terry2position.y + 10;
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
			App->render->Blit(graphics2, Terry2position.x, Terry2position.y, &(current_animation->GetCurrentFrame()));
		}

		else if (current_animation == &TerryKickM || current_animation == &TerryJumpM || current_animation == &TerryForwardM
			|| current_animation == &TerryBackwardsM || current_animation == &TerryDPM || current_animation == &TerryDKM || current_animation == &TerryCrouchPunchM
			|| current_animation == &TerryCrouchKickM || current_animation == &TerryJumpForwardM || current_animation == &TerryJumpBackwardsM || current_animation == &TerryCrouchM)
		{
			App->render->Blit(graphics2M, Terry2position.x, Terry2position.y, &(current_animation->GetCurrentFrame()));
		}

		else if (current_animation == &TerryidleM || current_animation == &TerryPunchM || current_animation == &TerryPWM || current_animation == &TerryJumpPunchM
			|| current_animation == &TerryJumpKickM || current_animation == &hitM)
		{
			App->render->Blit(graphicsM, Terry2position.x, Terry2position.y, &(current_animation->GetCurrentFrame()));
		}

		else
		{
			App->render->Blit(graphics, Terry2position.x, Terry2position.y, &(current_animation->GetCurrentFrame()));
		}

		/*else if()
		else if()*/
	}

	// Draw UI (score) --------------------------------------
	sprintf_s(score_text, 10, "%7d", score);

	// TODO 3: Blit the text of the score in at the bottom of the screen
	//App->fonts->BlitText(0, 150, font_score, "1");

	return UPDATE_CONTINUE;
}

// TODO 4: Detect collision with a player.
void ModulePlayer2::OnCollision(Collider* c1, Collider* c2)
{
	if (c1->type == COLLIDER_ENEMY && c2->type == COLLIDER_PLAYER_SHOT && collided == true)
	{
		life_score -= 12;
		collided = true;
	}
}