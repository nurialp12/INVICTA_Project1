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

	life = { 180, 69, 117, 80 };

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

	graphics = App->textures->Load("spritesTerryBogard.png");
	graphics2 = App->textures->Load("spritesTerryBogard2extres.png");


	graphicsM = App->textures->Load("spritesTerryBogard.png");
	graphics2M = App->textures->Load("spritesTerryBogard2extres.png");

	UI = App->textures->Load("UI.png");


	destroyed = false;
	//Terryposition.x = 150;
	//Terryposition.y = 115;
	Terry2position.x = 215 + (250);
	Terry2position.y = 100;
	score = 0;

	// TODO 2: Add a collider to the player
	col = App->collisions->AddCollider({ 0, 0, 30, 101 }, COLLIDER_ENEMY, App->player2);

	// TODO 0: Notice how a font is loaded and the meaning of all its arguments 
	font_score = App->fonts->Load("fonts/rtype_font.png", "! @,_./0123456789$;<&?abcdefghijklmnopqrstuvwxyz", 1);
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

	Animation* current_animation = &Terry2idleM;


	//NO ENTRA EN EL BUCLE DE IDLE
	if (mirror2) { Animation* current_animation = &Terry2idleM; }
	else { Animation* current_animation = &Terry2idle; }


	int speed = 1;
	

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
	{

		
		if (mirror2)
		{
			current_animation = &Terry2ForwardM;
			if (Terry2position.x < 570 && Terry2position.x * 2 - 160 < -(App->render->camera.x - App->render->camera.w)) 
			{
				Terry2position.x += speed;
			}
		}
		
		else
		{
			current_animation = &Terry2Forward;

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
			current_animation = &Terry2Backwards;
			if (Terry2position.x > 0 && Terry2position.x * 2 > -App->render->camera.x)
			{
				Terry2position.x -= speed;

			}
		}

	}


	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT)
	{
		
		if (mirror2) { current_animation = &Terry2JumpM; }
		
		else { current_animation = &Terry2Jump; }

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

		if (mirror2) { current_animation = &Terry2PunchM;}
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
		App->audio->PlayFX("FX/Voice/Special Attacks/FX_PowerWaveAttackTerryBogardVoice/FX_PowerWaveAttackTerryBogardVoice.wav");
	}


	if (App->input->keyboard[SDL_SCANCODE_P] == KEY_STATE::KEY_REPEAT)
	{

		if (mirror2) { current_animation = &Terry2PWM; }
		
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


	App->render->Blit(UI, 165, 0, &life, 0);

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

		else if ((current_animation == (&Terry2KickM)) || current_animation == (&Terry2JumpM) || current_animation == (&Terry2ForwardM) || current_animation == (&Terry2BackwardsM))
		{
			//App->render->Blit(graphics2, Terryposition.x, Terryposition.y, &(current_animation->GetCurrentFrame()));
			App->render->Blit(graphics2M, Terry2position.x, Terry2position.y, &(current_animation->GetCurrentFrame()));
		}

		else if ((current_animation == (&Terry2idleM)) || current_animation == (&Terry2PunchM) || current_animation == (&Terry2PWM))
		{
			//App->render->Blit(graphics2, Terryposition.x, Terryposition.y, &(current_animation->GetCurrentFrame()));
			App->render->Blit(graphicsM, Terry2position.x, Terry2position.y, &(current_animation->GetCurrentFrame()));
		}


		else
		{
			App->render->Blit(graphics, Terry2position.x, Terry2position.y, &(current_animation->GetCurrentFrame()));
		}
		//App->render->Blit(graphics, terry2position.x, terry2position.y, &(current_animation->GetCurrentFrame()));
	}

	// Draw UI (score) --------------------------------------
	sprintf_s(score_text, 10, "%7d", score);

	// TODO 3: Blit the text of the score in at the bottom of the screen
	App->fonts->BlitText(0, 150, font_score, "HelloWorld");

	return UPDATE_CONTINUE;
}

// TODO 4: Detect collision with a player.
void ModulePlayer2::OnCollision(Collider* c1, Collider* c2)
{
	if (c1->type == COLLIDER_PLAYER && c2->type == COLLIDER_ENEMY)
	{
		App->fade->FadeToBlack((Module*)App->scene_2, (Module*)App->end_game1);
	}
}

//bool ModulePlayer2::external_input(p2Qeue<terry2_inputs>& inputs)
//{
//	static bool left = false;
//	static bool right = false;
//	static bool down = false;
//	static bool up = false;
//
//	SDL_Event event;
//
//	while (SDL_PollEvent(&event) != 0)
//	{
//		if (event.type == SDL_KEYUP && event.key.repeat == 0)
//		{
//			switch (event.key.keysym.sym)
//			{
//			case SDLK_ESCAPE:
//				return false;
//				break;
//			case SDLK_DOWN:
//				inputs.Push(IN_CROUCH_UP);
//				down = false;
//				break;
//			case SDLK_UP:
//				up = false;
//				break;
//			case SDLK_LEFT:
//				inputs.Push(IN_LEFT_UP);
//				left = false;
//				break;
//			case SDLK_RIGHT:
//				inputs.Push(IN_RIGHT_UP);
//				right = false;
//				break;
//			}
//		}
//		if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
//		{
//			switch (event.key.keysym.sym)
//			{
//			case SDLK_SPACE:
//				inputs.Push(IN_X);
//				break;
//			case SDLK_UP:
//				up = true;
//				break;
//			case SDLK_DOWN:
//				down = true;
//				break;
//			case SDLK_LEFT:
//				left = true;
//				break;
//			case SDLK_RIGHT:
//				right = true;
//				break;
//			}
//		}
//	}
//
//	if (left && right)
//		inputs.Push(IN_LEFT_AND_RIGHT);
//	{
//		if (left)
//			inputs.Push(IN_LEFT_DOWN);
//		if (right)
//			inputs.Push(IN_RIGHT_DOWN);
//	}
//
//	if (up && down)
//		inputs.Push(IN_JUMP_AND_CROUCH);
//	else
//	{
//		if (down)
//			inputs.Push(IN_CROUCH_DOWN);
//		if (up)
//			inputs.Push(IN_JUMP);
//	}
//
//	return true;
//}
//
//void ModulePlayer2::internal_input(p2Qeue<terry2_inputs>& inputs)
//{
//	if (jump_timer > 0)
//	{
//		if (SDL_GetTicks() - jump_timer > JUMP_TIME)
//		{
//			inputs.Push(IN_JUMP_FINISH);
//			jump_timer = 0;
//		}
//	}
//
//	if (punch_timer > 0)
//	{
//		if (SDL_GetTicks() - punch_timer > PUNCH_TIME)
//		{
//			inputs.Push(IN_PUNCH_FINISH);
//			punch_timer = 0;
//		}
//	}
//}
//
//ModulePlayer2::terry2_states ModulePlayer2::process_fsm(p2Qeue<terry2_inputs>& inputs)
//{
//	static terry2_states state = ST_IDLE;
//	terry2_inputs last_input;
//
//	while (inputs.Pop(last_input))
//	{
//		switch (state)
//		{
//		case ST_IDLE:
//		{
//			switch (last_input)
//			{
//			case IN_RIGHT_DOWN: state = ST_WALK_FORWARD; break;
//			case IN_LEFT_DOWN: state = ST_WALK_BACKWARD; break;
//			case IN_JUMP: state = ST_JUMP_NEUTRAL; jump_timer = SDL_GetTicks();  break;
//			case IN_CROUCH_DOWN: state = ST_CROUCH; break;
//			case IN_X: state = ST_PUNCH_STANDING; punch_timer = SDL_GetTicks();  break;
//			}
//		}
//		break;
//
//		case ST_WALK_FORWARD:
//		{
//			switch (last_input)
//			{
//			case IN_RIGHT_UP: state = ST_IDLE; break;
//			case IN_LEFT_AND_RIGHT: state = ST_IDLE; break;
//			case IN_JUMP: state = ST_JUMP_FORWARD; jump_timer = SDL_GetTicks();  break;
//			case IN_CROUCH_DOWN: state = ST_CROUCH; break;
//			}
//		}
//		break;
//
//		case ST_WALK_BACKWARD:
//		{
//			switch (last_input)
//			{
//			case IN_LEFT_UP: state = ST_IDLE; break;
//			case IN_LEFT_AND_RIGHT: state = ST_IDLE; break;
//			case IN_JUMP: state = ST_JUMP_BACKWARD; jump_timer = SDL_GetTicks();  break;
//			case IN_CROUCH_DOWN: state = ST_CROUCH; break;
//			}
//		}
//		break;
//
//		case ST_JUMP_NEUTRAL:
//		{
//			switch (last_input)
//			{
//			case IN_JUMP_FINISH: state = ST_IDLE; break;
//			case IN_X: state = ST_PUNCH_NEUTRAL_JUMP; punch_timer = SDL_GetTicks(); break;
//			}
//		}
//		break;
//
//		case ST_JUMP_FORWARD:
//		{
//			switch (last_input)
//			{
//				// TODO: Add links
//			case IN_JUMP_FINISH: state = ST_IDLE; break;
//			case IN_X: state = ST_PUNCH_FORWARD_JUMP; punch_timer = SDL_GetTicks(); break;
//			}
//		}
//		break;
//
//		case ST_JUMP_BACKWARD:
//		{
//			switch (last_input)
//			{
//				// TODO: Add Links
//			case IN_JUMP_FINISH: state = ST_IDLE; break;
//			case IN_X: state = ST_PUNCH_BACKWARD_JUMP; punch_timer = SDL_GetTicks(); break;
//			}
//		}
//		break;
//
//		case ST_PUNCH_NEUTRAL_JUMP:
//		{
//			switch (last_input)
//			{
//				// TODO: Add Links
//			case IN_JUMP_FINISH: state = ST_IDLE; break;
//			}
//		}
//		break;
//
//		case ST_PUNCH_FORWARD_JUMP:
//		{
//			switch (last_input)
//			{
//				// TODO: Add Links
//			case IN_JUMP_FINISH: state = ST_IDLE; break;
//			}
//		}
//		break;
//
//		case ST_PUNCH_BACKWARD_JUMP:
//		{
//			switch (last_input)
//			{
//				// TODO: Add Links
//			case IN_JUMP_FINISH: state = ST_IDLE; break;
//			}
//		}
//		break;
//
//		case ST_PUNCH_STANDING:
//		{
//			switch (last_input)
//			{
//				// TODO: Add Links
//			case IN_PUNCH_FINISH: state = ST_IDLE; break;
//			}
//		}
//		break;
//
//		case ST_CROUCH:
//		{
//			switch (last_input)
//			{
//				// TODO: Add Links
//
//			}
//		}
//		break;
//		case ST_PUNCH_CROUCH:
//		{
//			switch (last_input)
//			{
//				// TODO: Add Links
//			}
//		}
//		break;
//		}
//	}
//
//	return state;
//}