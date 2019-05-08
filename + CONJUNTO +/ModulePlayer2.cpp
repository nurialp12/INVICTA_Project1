#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
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

	Terryidle.PushBack({ 28, 909, 58, 112 });
	Terryidle.PushBack({ 96, 910, 59, 112 });
	Terryidle.PushBack({ 28, 909, 58, 112 });
	Terryidle.PushBack({ 166, 909, 58, 112 });
	Terryidle.speed = 0.1f;


	// WALK FORWARD animation of Terry2				//Terry2Avanzar+SaltoEstatico+Patada+Retroceder.png

	//Terry2Forward.frames.PushBack({/**/, /**/, /**/, /**/});

	TerryForward.PushBack({ 20, 269, 61, 112 });
	TerryForward.PushBack({ 95, 269, 71, 112 });
	TerryForward.PushBack({ 177, 269, 61, 112 });
	TerryForward.PushBack({ 251, 269, 61, 112 });
	TerryForward.speed = 0.1f;


	// WALK BACKWARD animation of Terry					//TerryAvanzar+SaltoEstatico+Patada+Retroceder.png

	//Terry2Backwards.frames.PushBack({/**/, /**/, /**/, /**/});

	TerryBackwards.PushBack({ 382, 266, 60, 112 });
	TerryBackwards.PushBack({ 442, 268, 55, 112 });
	TerryBackwards.PushBack({ 497, 270, 56, 112 });
	TerryBackwards.PushBack({ 553, 268, 57, 112 });
	TerryBackwards.speed = 0.1f;



	// JUMP animation of Terry				//TerryAvanzar+SaltoEstatico+Patada+Retroceder.png

	//Terry2Jump.frames.PushBack({/**/, /**/, /**/, /**/});

	TerryJump.PushBack({ 535, 12, 53, 125 });
	TerryJump.PushBack({ 598, 22, 59, 105 });
	TerryJump.PushBack({ 667, 33, 59, 94 });
	TerryJump.speed = 0.1f;


	// KICK animation of Terry				//TerryAvanzar+SaltoEstatico+Patada+Retroceder.png

	//Terry2Kick.frames.PushBack({/**/, /**/, /**/, /**/});
	TerryKick.PushBack({ 20, 122, 49, 112 });
	TerryKick.PushBack({ 73, 138, 59, 112 });
	TerryKick.PushBack({ 138, 134, 44, 112 });
	TerryKick.PushBack({ 200, 138, 118, 112 });
	TerryKick.PushBack({ 331, 138, 64, 112 });
	TerryKick.speed = 0.1f;


	// PUNCH animation of Terry					//spritesTerryBogard.png

	//Terry2Punch.frames.PushBack({/**/, /**/, /**/, /**/});
	//Terry2Punch.PushBack({ 428, 915, 79, 109 });
	//Terry2Punch.PushBack({ 505, 915, 68, 105 });
	//Terry2Punch.PushBack({ 570, 915, 107, 109 });
	//Terry2Punch.speed = 0.1f;

	TerryPunch.PushBack({ 435, 910, 71, 112 });
	TerryPunch.PushBack({ 507, 912, 62, 112 });
	TerryPunch.PushBack({ 574, 912, 97, 112 });
	TerryPunch.speed = 0.1f;

	// POWER WAVE animation of Terrry

	TerryPW.PushBack({ 623, 683, 51, 112 });
	TerryPW.PushBack({ 550, 683, 54, 112 });
	TerryPW.PushBack({ 485, 683, 60, 112 });
	TerryPW.PushBack({ 402, 682, 79, 112 });
	TerryPW.PushBack({ 330, 682, 67, 112 });
	TerryPW.PushBack({ 262, 683, 65, 112 });
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


	//MIRROR -----------------------------------------------------------------------------------------

		// idle animation of Terry							//spritesTerryBogardMIRROR.png

	/*Terry2idleM.PushBack({ 27, 910, 30, 112 });
	Terry2idleM.PushBack({ 95, 911, 31, 112 });
	Terry2idleM.PushBack({ 164, 910, 30, 112 });
	Terry2idleM.PushBack({ 95, 911, 31, 112 });
	Terry2idleM.speed = 0.1f;
*/
	Terry2idleM.PushBack({ 28, 918, 58, 103 });
	Terry2idleM.PushBack({ 96, 920, 59, 102 });
	Terry2idleM.PushBack({ 28, 918, 58, 103 });
	Terry2idleM.PushBack({ 166, 920, 58, 101 });
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

	Terry2PWM.PushBack({ 623, 683, 31, 112 });
	Terry2PWM.PushBack({ 550, 683, 44, 112 });
	Terry2PWM.PushBack({ 485, 683, 30, 112 });
	Terry2PWM.PushBack({ 402, 682, 49, 112 });
	Terry2PWM.PushBack({ 330, 682, 37, 112 });
	Terry2PWM.PushBack({ 262, 683, 35, 112 });
	Terry2PWM.PushBack({ 198, 683, 30, 112 });
	Terry2PWM.speed = 0.1f;



}


ModulePlayer2::~ModulePlayer2()
{}

// Load assets
bool ModulePlayer2::Start()
{
	LOG("Loading player");
	bool ret = true;

	graphics = App->textures->Load("Assets/Sprites/spritesTerryBogard.png");
	graphics2 = App->textures->Load("Assets/Sprites/spritesTerryBogard2extres.png");


	graphicsM = App->textures->Load("Assets/Sprites/spritesTerryBogardMIRROR.png"); //spritesTerryBogardMIRROR
	graphics2M = App->textures->Load("Assets/Sprites/spritesTerryBogard2extresMIRROR.png"); //spritesTerryBogard2extresMIRROR

	UI = App->textures->Load("Assets/Sprites/UI.png");


	destroyed = false;
	//Terryposition.x = 150;
	//Terryposition.y = 115;
	Terry2position.x = 215 + (250);
	Terry2position.y = 100;
	col = App->collisions->AddCollider({ 0, 0, 30, 101 }, COLLIDER_ENEMY, App->player);
	colj = App->collisions->AddCollider({ 1000, 1000, 36, 60 }, COLLIDER_ENEMY);
	colcp = App->collisions->AddCollider({ 1000, 1000, 25, 20 }, COLLIDER_ENEMY_SHOT, App->player);
	colck = App->collisions->AddCollider({ 1000, 1000, 40, 20 }, COLLIDER_ENEMY_SHOT, App->player);
	score = 0;

	current_animation = &Terryidle;			// ESTO ESTÁ EN ModulePlayer.cpp --> va conjuntamente 


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

// Update: draw background
update_status ModulePlayer2::Update()
{
	// MIRROR
	if (Terry2position.x < App->player->Terryposition.x) { mirror2 = false; }
	else { mirror2 = true; }

	//Animation* current_animation = NULL;


	if (true)
	{

		if (mirror2) { current_animation = &Terry2idleM; }

		else { current_animation = &Terryidle; }


	}


	int speed = 1;


	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
	{


		if (mirror2)
		{
			current_animation = &Terry2ForwardM;
			if (Terry2position.x < 700 && Terry2position.x * 2 - 160 < -(App->render->camera.x - App->render->camera.w))
			{
				Terry2position.x += speed;
			}
		}

		else
		{
			current_animation = &TerryForward;

			if (Terry2position.x < 570 && Terry2position.x * 2 - 260 < -(App->render->camera.x - App->render->camera.w))
			{
				Terry2position.x += speed;

			}

		}

	}


	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
	{

		if (mirror2)
		{
			current_animation = &Terry2BackwardsM;
			if (Terry2position.x > 0 && Terry2position.x * 2 > -App->render->camera.x)
			{
				Terry2position.x -= speed;
			}

		}

		else
		{
			current_animation = &TerryBackwards;
			if (Terry2position.x > 0 && Terry2position.x * 2 > -App->render->camera.x)
			{
				Terry2position.x -= speed;

			}
		}

	}


	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT)
	{

		if (mirror2) { current_animation = &Terry2JumpM; }

		else { current_animation = &TerryJump; }

		/*FER QUE PER LES DUES PRIEMERES ANIMACIONS PUGI X PÍXELS I LES DUES ÚLTIMES QUE ELS BAIXI*/


	}

	//if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
	//{
	//	if (terry2position.x < 570)
	//	{
	//		current_animation = &terryforward;
	//		terryposition.x += speed;
	//	}
	//}
	//if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
	//{
	//	if (terry2position.x > 0)
	//	{
	//		current_animation = &terrybackward;
	//		terry2position.x -= speed;
	//	}
	//}

		//PUNCH
	if (App->input->keyboard[SDL_SCANCODE_I] == KEY_STATE::KEY_DOWN)
	{
		colp = App->collisions->AddCollider({ Terry2position.x + 45, Terry2position.y + 20, 43, 20 }, COLLIDER_ENEMY_SHOT, App->player2);

	}

	if (App->input->keyboard[SDL_SCANCODE_I] == KEY_STATE::KEY_REPEAT)
	{

		if (mirror2) { current_animation = &Terry2PunchM; }
		else { current_animation = &TerryPunch; }

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
		else { current_animation = &TerryKick; }

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

		if (mirror2) { current_animation = &Terry2PWM; }

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
		if ((current_animation == (&TerryKick)) || current_animation == (&TerryJump) || current_animation == (&TerryForward) || current_animation == (&TerryBackwards) /*current_animation == (&TerryKick || &TerryJump || &TerryForward || &TerryBackwards)*/)
		{
			App->render->Blit(graphics2M, Terry2position.x, Terry2position.y, &(current_animation->GetCurrentFrame()));
		}

		else if ((current_animation == (&Terry2KickM)) || current_animation == (&Terry2JumpM) || current_animation == (&Terry2ForwardM) || current_animation == (&Terry2BackwardsM))
		{
			//App->render->Blit(graphics2, Terryposition.x, Terryposition.y, &(current_animation->GetCurrentFrame()));
			App->render->Blit(graphics2M, Terry2position.x, Terry2position.y, &(current_animation->GetCurrentFrame()));
		}

		else if ((current_animation == (&Terryidle)) || current_animation == (&Terry2PunchM) || current_animation == (&Terry2PWM))
		{
			//App->render->Blit(graphics2, Terryposition.x, Terryposition.y, &(current_animation->GetCurrentFrame()));
			App->render->Blit(graphicsM, Terry2position.x, Terry2position.y, &(current_animation->GetCurrentFrame()));
		}
		else
		{
			App->render->Blit(graphics2M, Terry2position.x, Terry2position.y, &(current_animation->GetCurrentFrame()));
		}
		//App->render->Blit(graphics, terry2position.x, terry2position.y, &(current_animation->GetCurrentFrame()));
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

