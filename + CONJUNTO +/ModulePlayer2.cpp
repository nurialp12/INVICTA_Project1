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

	// idle animation of Terry2					//spritesTerry2Bogard.png

		//Terry2idle.PushBack({ 428, 915, 79, 109 });
		//Terry2idle.PushBack({ 505, 915, 68, 105 });
		//Terry2idle.speed = 0.2f;

	Terry2idle.PushBack({ 27, 910, 60, 112 });
	Terry2idle.PushBack({ 95, 911, 61, 112 });
	Terry2idle.PushBack({ 164, 910, 60, 112 });
	Terry2idle.PushBack({ 95, 911, 61, 112 });
	Terry2idle.speed = 0.1f;


	// WALK FORWARD animation of Terry2				//Terry2Avanzar+SaltoEstatico+Patada+Retroceder.png

	//Terry2Forward.frames.PushBack({/**/, /**/, /**/, /**/});

	Terry2Forward.PushBack({ 20, 269, 61, 112 });
	Terry2Forward.PushBack({ 95, 269, 71, 112 });
	Terry2Forward.PushBack({ 177, 269, 61, 112 });
	Terry2Forward.PushBack({ 251, 269, 61, 112 });
	Terry2Forward.speed = 0.1f;


	// WALK BACKWARD animation of Terry					//TerryAvanzar+SaltoEstatico+Patada+Retroceder.png

	//Terry2Backwards.frames.PushBack({/**/, /**/, /**/, /**/});

	Terry2Backwards.PushBack({ 382, 266, 60, 112 });
	Terry2Backwards.PushBack({ 442, 268, 55, 112 });
	Terry2Backwards.PushBack({ 497, 270, 56, 112 });
	Terry2Backwards.PushBack({ 553, 268, 57, 112 });
	Terry2Backwards.speed = 0.1f;



	// JUMP animation of Terry				//TerryAvanzar+SaltoEstatico+Patada+Retroceder.png

	//Terry2Jump.frames.PushBack({/**/, /**/, /**/, /**/});

	Terry2Jump.PushBack({ 535, 12, 53, 125 });
	Terry2Jump.PushBack({ 598, 22, 59, 105 });
	Terry2Jump.PushBack({ 667, 33, 59, 94 });
	Terry2Jump.speed = 0.1f;


	// KICK animation of Terry				//TerryAvanzar+SaltoEstatico+Patada+Retroceder.png

	//Terry2Kick.frames.PushBack({/**/, /**/, /**/, /**/});
	Terry2Kick.PushBack({ 20, 122, 49, 112 });
	Terry2Kick.PushBack({ 73, 138, 59, 112 });
	Terry2Kick.PushBack({ 138, 134, 44, 112 });
	Terry2Kick.PushBack({ 200, 138, 118, 112 });
	Terry2Kick.PushBack({ 331, 138, 64, 112 });
	Terry2Kick.speed = 0.1f;


	// PUNCH animation of Terry					//spritesTerryBogard.png

	//Terry2Punch.frames.PushBack({/**/, /**/, /**/, /**/});
	//Terry2Punch.PushBack({ 428, 915, 79, 109 });
	//Terry2Punch.PushBack({ 505, 915, 68, 105 });
	//Terry2Punch.PushBack({ 570, 915, 107, 109 });
	//Terry2Punch.speed = 0.1f;

	Terry2Punch.PushBack({ 435, 910, 71, 112 });
	Terry2Punch.PushBack({ 507, 912, 62, 112 });
	Terry2Punch.PushBack({ 574, 912, 97, 112 });
	Terry2Punch.speed = 0.1f;

	// POWER WAVE animation of Terrry

	Terry2PW.PushBack({ 623, 683, 51, 112 });
	Terry2PW.PushBack({ 550, 683, 54, 112 });
	Terry2PW.PushBack({ 485, 683, 60, 112 });
	Terry2PW.PushBack({ 402, 682, 79, 112 });
	Terry2PW.PushBack({ 330, 682, 67, 112 });
	Terry2PW.PushBack({ 262, 683, 65, 112 });
	Terry2PW.PushBack({ 198, 683, 60, 112 });
	Terry2PW.speed = 0.1f;


	//DAMAGED BY PUNCH
	Terry2DP.PushBack({ 0, 912, 59, 112 });
	Terry2DP.PushBack({ 64, 912, 67, 112 });
	Terry2DP.speed = 0.1f;

	//DAMAGED BY KICK
	Terry2DK.PushBack({ 136, 912, 63, 112 });
	Terry2DK.PushBack({ 211, 912, 68, 112 });
	Terry2DK.speed = 0.1f;


	//MIRROR -----------------------------------------------------------------------------------------

		// idle animation of Terry							//spritesTerryBogardMIRROR.png

	Terry2idleM.PushBack({ 27, 910, 30, 112 });
	Terry2idleM.PushBack({ 95, 911, 31, 112 });
	Terry2idleM.PushBack({ 164, 910, 30, 112 });
	Terry2idleM.PushBack({ 95, 911, 31, 112 });
	Terry2idleM.speed = 0.1f;


	// WALK FORWARD animation of Terry					//spritesTerryBogard2extresMIRROR.png

	Terry2ForwardM.PushBack({ 20, 269, 31, 112 });
	Terry2ForwardM.PushBack({ 95, 269, 31, 112 });
	Terry2ForwardM.PushBack({ 177, 269, 31, 112 });
	Terry2ForwardM.PushBack({ 251, 269, 31, 112 });
	Terry2ForwardM.speed = 0.1f;


	// WALK BACKWARD animation of Terry					//spritesTerryBogard2extresMIRROR.png

	Terry2BackwardsM.PushBack({ 382, 266, 30, 112 });
	Terry2BackwardsM.PushBack({ 442, 268, 35, 112 });
	Terry2BackwardsM.PushBack({ 497, 270, 36, 112 });
	Terry2BackwardsM.PushBack({ 553, 268, 37, 112 });
	Terry2BackwardsM.speed = 0.1f;


	// JUMP animation of Terry							//spritesTerryBogard2extresMIRROR.png

	Terry2JumpM.PushBack({ 535, 12, 33, 125 });
	Terry2JumpM.PushBack({ 598, 22, 39, 105 });
	Terry2JumpM.PushBack({ 667, 33, 39, 94 });
	Terry2JumpM.speed = 0.1f;


	// KICK animation of Terry							//spritesTerryBogard2extresMIRROR.png

	Terry2KickM.PushBack({ 20, 122, 29, 112 });
	Terry2KickM.PushBack({ 73, 138, 39, 112 });
	Terry2KickM.PushBack({ 138, 134, 24, 112 });
	Terry2KickM.PushBack({ 200, 138, 58, 112 });
	Terry2KickM.PushBack({ 331, 138, 34, 112 });
	Terry2KickM.speed = 0.1f;


	// PUNCH animation of Terry							//spritesTerryBogardMIRROR.png

	Terry2PunchM.PushBack({ 435, 910, 41, 112 });
	Terry2PunchM.PushBack({ 507, 912, 32, 112 });
	Terry2PunchM.PushBack({ 574, 912, 57, 112 });
	Terry2PunchM.speed = 0.1f;



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


ModulePlayer2::~ModulePlayer2()
{}

// Load assets
bool ModulePlayer2::Start()
{
	if (Terry2position.x <= App->player->Terryposition.x) { mirror2 = false; }
	else { mirror2 = true; }

	LOG("Loading player");
	bool ret = true;
	

	graphics = App->textures->Load("Assets/Sprites/spritesTerryBogard.png");
	graphics2 = App->textures->Load("Assets/Sprites/spritesTerryBogard2extres.png");


	graphicsM = App->textures->Load("Assets/Sprites/spritesTerryBogard.png"); //spritesTerryBogardMIRROR
	graphics2M = App->textures->Load("Assets/Sprites/spritesTerryBogard2extres.png"); //spritesTerryBogard2extresMIRROR

	UI = App->textures->Load("Assets/Sprites/UI.png");

	destroyed = false;
	//Terryposition.x = 150;
	//Terryposition.y = 115;
	Terry2position.x = 215 + (250);
	Terry2position.y = 100;
	score = 0;


	current_animation = &Terry2idle;			// ESTO EST� EN ModulePlayer.cpp --> va conjuntamente 


	// TODO 2: Add a collider to the player
	col = App->collisions->AddCollider({ 0, 0, 30, 101 }, COLLIDER_ENEMY, App->player2);

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

		if (mirror2) { current_animation = &Terry2idleM; }

		else { current_animation = &Terry2idle; }


	}


	int speed = 1;


	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
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
			current_animation = &Terry2Forward;

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
	}
	return UPDATE_CONTINUE;
}

// Update: draw background
update_status ModulePlayer2::Update()
{
	// MIRROR
	if (Terry2position.x < App->player->Terryposition.x) mirror2 = false; 
	else mirror2 = true; 

	//IDLE
	if (currentstate == ST_IDLE2)
		if (mirror2)current_animation = &TerryidleM;
		else current_animation = &Terryidle;
	
	//MOVE FORWARD
	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_DOWN && currentstate == ST_IDLE2)
	{
		currentstate = ST_WALK_FORWARD2;
		if (mirror2) current_animation = &TerryBackwardsM;
		else current_animation = &TerryForward;
	}
	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT && currentstate == ST_WALK_FORWARD2)
	{
		if (Terry2position.x < 700 &&
			Terry2position.x * 2 - 160 < -(App->render->camera.x - App->render->camera.w))
				Terry2position.x += speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_UP && currentstate == ST_WALK_FORWARD2)
	{
		TerryForward.resetLoops(0);
		TerryForwardM.resetLoops(0);
		if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
		{
			currentstate = ST_WALK_BACKWARD2;
			if (mirror2) current_animation = &TerryForwardM;
			else current_animation = &TerryBackwards;
		}
		else

		{
			current_animation = &Terry2Backwards;
			if (Terry2position.x > 0 && Terry2position.x * 2 > -App->render->camera.x)
			{
				Terry2position.x -= speed;

			}
		}

	}

	//WALK BACKWARDS
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_DOWN && currentstate == ST_IDLE2)
	{

		if (mirror2) { current_animation = &Terry2JumpM; }

		else { current_animation = &Terry2Jump; }

		/*FER QUE PER LES DUES PRIEMERES ANIMACIONS PUGI X P�XELS I LES DUES �LTIMES QUE ELS BAIXI*/

	}
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT && currentstate == ST_WALK_BACKWARD2)
	{
		if (Terry2position.x > 0 &&
			Terry2position.x * 2 > -App->render->camera.x)
			Terry2position.x -= speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_UP && currentstate == ST_WALK_BACKWARD2)
	{
		TerryForward.resetLoops(0);
		TerryForwardM.resetLoops(0);
		if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
		{
			currentstate = ST_WALK_FORWARD2;
			if (mirror2) current_animation = &TerryBackwardsM;
			else current_animation = &TerryForward;
		}
		else
			currentstate = ST_IDLE2;
	}
	
		//PUNCH
	if (App->input->keyboard[SDL_SCANCODE_I] == KEY_STATE::KEY_DOWN)
	{
		colp = App->collisions->AddCollider({ Terry2position.x + 45, Terry2position.y + 20, 43, 20 }, COLLIDER_ENEMY_SHOT, App->player2);

	}

	if (App->input->keyboard[SDL_SCANCODE_I] == KEY_STATE::KEY_REPEAT)
	{

		if (mirror2) { current_animation = &Terry2PunchM; }
		else { current_animation = &Terry2Punch; }

	}


	if (App->input->keyboard[SDL_SCANCODE_I] == KEY_STATE::KEY_UP)
	{
		if (colp)
			colp->to_delete = true;
	}

	//KICK
	if (App->input->keyboard[SDL_SCANCODE_O] == KEY_STATE::KEY_DOWN)
		colk = App->collisions->AddCollider({ Terry2position.x + 45, Terry2position.y + 48, 55, 20 }, COLLIDER_ENEMY_SHOT, App->player2);

	if (App->input->keyboard[SDL_SCANCODE_O] == KEY_STATE::KEY_REPEAT)
	{

		if (mirror2) { current_animation = &Terry2KickM; }
		else { current_animation = &Terry2Kick; }

	}

	if (App->input->keyboard[SDL_SCANCODE_O] == KEY_STATE::KEY_UP)
	{
		if (colk)
			colk->to_delete = true;
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

		else { current_animation = &Terry2PW; }
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
	{
		App->render->Blit(UI, 255, 26, &life2, 0);
	}
	if (life_score >= 12)
	{
		App->render->Blit(UI, 251, 26, &life2, 0);
	}
	if (life_score >= 16)
	{
		App->render->Blit(UI, 247, 26, &life2, 0);
	}
	if (life_score >= 20)
	{
		App->render->Blit(UI, 243, 26, &life2, 0);
	}
	if (life_score >= 24)
	{
		App->render->Blit(UI, 239, 26, &life2, 0);
	}
	if (life_score >= 28)
	{
		App->render->Blit(UI, 235, 26, &life2, 0);
	}
	if (life_score >= 32)
	{
		App->render->Blit(UI, 231, 26, &life2, 0);
	}
	if (life_score >= 36)
	{
		App->render->Blit(UI, 227, 26, &life2, 0);
	}
	if (life_score >= 40)
	{
		App->render->Blit(UI, 223, 26, &life2, 0);
	}
	if (life_score >= 44)
	{
		App->render->Blit(UI, 219, 26, &life2, 0);
	}
	if (life_score >= 48)
	{
		App->render->Blit(UI, 215, 26, &life2, 0);
	}
	if (life_score >= 52)
	{
		App->render->Blit(UI, 211, 26, &life2, 0);
	}
	if (life_score >= 56)
	{
		App->render->Blit(UI, 207, 26, &life2, 0);
	}
	if (life_score >= 60)
	{
		App->render->Blit(UI, 203, 26, &life2, 0);
	}
	if (life_score >= 64)
	{
		App->render->Blit(UI, 199, 26, &life2, 0);
	}
	if (life_score >= 68)
	{
		App->render->Blit(UI, 195, 26, &life2, 0);
	}
	if (life_score >= 72)
	{
		App->render->Blit(UI, 191, 26, &life2, 0);
	}
	if (life_score >= 76)
	{
		App->render->Blit(UI, 187, 26, &life2, 0);
	}
	if (life_score >= 80)
	{
		App->render->Blit(UI, 183, 26, &life2, 0);
	}
	if (life_score >= 84)
	{
		App->render->Blit(UI, 179, 26, &life2, 0);
	}
	if (life_score >= 88)
	{
		App->render->Blit(UI, 175, 26, &life2, 0);
	}
	if (life_score >= 92)
	{
		App->render->Blit(UI, 171, 26, &life2, 0);
		App->render->Blit(UI, 170, 26, &life1, 0);
	}

	// TODO 3: Update collider position to player position
	//col->rect.x = Terryposition.x;
	//col->rect.y = Terryposition.y;
	col->rect.x = Terry2position.x + 15;
	col->rect.y = Terry2position.y + 10;

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	// Draw everything --------------------------------------
	if (destroyed == false)
	{

		if ((current_animation == (&Terry2Kick)) || current_animation == (&Terry2Jump) || current_animation == (&Terry2Forward) || current_animation == (&Terry2Backwards) /*current_animation == (&TerryKick || &TerryJump || &TerryForward || &TerryBackwards)*/)
		{
			App->render->Blit(graphics2, Terry2position.x, Terry2position.y, &(current_animation->GetCurrentFrame()));
		}

		else if (current_animation == &TerryKickM || current_animation == &TerryJumpM || current_animation == &TerryForwardM
			|| current_animation == &TerryBackwardsM || current_animation == &TerryDPM || current_animation == &TerryDKM || current_animation == &TerryCrouchPunchM
			|| current_animation == &TerryCrouchKickM || current_animation == &TerryJumpForwardM || current_animation == &TerryJumpBackwardsM || current_animation == &TerryCrouchM)
		{
			App->render->Blit(graphics2M, Terry2position.x, Terry2position.y, &(current_animation->GetCurrentFrame()));
		}


		else if ((current_animation == (&Terry2idleM)) || current_animation == (&Terry2PunchM) || current_animation == (&Terry2PWM))
		{
			App->render->Blit(graphicsM, Terry2position.x, Terry2position.y, &(current_animation->GetCurrentFrame()));
		}
		else
		{
			App->render->Blit(graphics, Terry2position.x, Terry2position.y, &(current_animation->GetCurrentFrame()));
		}
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
	if (c1->type == COLLIDER_ENEMY && c2->type == COLLIDER_PLAYER_SHOT && collided == false)
	{
		life_score -= 4;
		collided = true;
	}
}