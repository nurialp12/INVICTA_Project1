#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"
#include "ModuleFonts.h"
#include "p2Qeue.h"

#include "SDL\include\SDL.h"
#include <stdio.h>


// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{


	// IDLE animation of Terry					//spritesTerryBogard.png

	//Terryidle.PushBack({ 428, 915, 79, 109 });
	//Terryidle.PushBack({ 505, 915, 68, 105 });
	//Terryidle.speed = 0.2f;

	Terryidle.PushBack({ 27, 910, 60, 112 });
	Terryidle.PushBack({ 95, 911, 61, 112 });
	Terryidle.PushBack({ 164, 910, 60, 112 });
	Terryidle.PushBack({ 95, 911, 61, 112 });
	Terryidle.speed = 0.1f;


	// WALK FORWARD animation of Terry					//TerryAvanzar+SaltoEstatico+Patada+Retroceder.png

	//TerryForward.frames.PushBack({/**/, /**/, /**/, /**/});

	TerryForward.PushBack({ 20, 269, 61, 112 });
	TerryForward.PushBack({ 95, 269, 71, 112 });
	TerryForward.PushBack({ 177, 269, 61, 112 });
	TerryForward.PushBack({ 251, 269, 61, 112 });
	TerryForward.speed = 0.1f;


	// WALK BACKWARD animation of Terry					//TerryAvanzar+SaltoEstatico+Patada+Retroceder.png

	//TerryBackwards.frames.PushBack({/**/, /**/, /**/, /**/});

	TerryBackwards.PushBack({ 382, 266, 60, 112 });
	TerryBackwards.PushBack({ 442, 268, 55, 112 });
	TerryBackwards.PushBack({ 497, 270, 56, 112 });
	TerryBackwards.PushBack({ 553, 268, 57, 112 });
	TerryBackwards.speed = 0.1f;



	// JUMP animation of Terry				//TerryAvanzar+SaltoEstatico+Patada+Retroceder.png

	//TerryJump.frames.PushBack({/**/, /**/, /**/, /**/});

	TerryJump.PushBack({ 535, 12, 53, 125 });
	TerryJump.PushBack({ 598, 22, 59, 105 });
	TerryJump.PushBack({ 667, 33, 59, 94 });
	TerryJump.speed = 0.1f;


	// KICK animation of Terry				//TerryAvanzar+SaltoEstatico+Patada+Retroceder.png

	//TerryKick.frames.PushBack({/**/, /**/, /**/, /**/});
	TerryKick.PushBack({ 20, 122, 49, 112 });
	TerryKick.PushBack({ 73, 138, 59, 112 });
	TerryKick.PushBack({ 138, 134, 44, 112 });
	TerryKick.PushBack({ 200, 138, 118, 112 });
	TerryKick.PushBack({ 331, 138, 64, 112 });
	TerryKick.speed = 0.1f;


	// PUNCH animation of Terry					//spritesTerryBogard.png

	//TerryPunch.frames.PushBack({/**/, /**/, /**/, /**/});
	//TerryPunch.PushBack({ 428, 915, 79, 109 });
	//TerryPunch.PushBack({ 505, 915, 68, 105 });
	//TerryPunch.PushBack({ 570, 915, 107, 109 });
	//TerryPunch.speed = 0.1f;

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
	TerryPW.speed=0.1f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");
	bool ret = true;

	graphics = App->textures->Load("spritesTerryBogard.png");
	graphics2 = App->textures->Load("spritesTerryBogard2extres.png");

	destroyed = false;
	Terryposition.x = 150;
	Terryposition.y = 100;
	score = 0;

	// TODO 2: Add a collider to the player
	col = App->collisions->AddCollider({ 0, 0, 30, 103 }, COLLIDER_PLAYER, App->player);

	// TODO 0: Notice how a font is loaded and the meaning of all its arguments 
	font_score = App->fonts->Load("fonts/rtype_font.png", "! @,_./0123456789$;<&?abcdefghijklmnopqrstuvwxyz", 1);
	return ret;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);
	App->textures->Unload(graphics2);
	App->fonts->UnLoad(font_score);
	if (col)
		col->to_delete = true;

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	p2Qeue<terry_inputs> inputs;
	terry_states current_state = ST_UNKNOWN;

	Animation* current_animation = &Terryidle;

	/*while (external_input(inputs))
	{

		internal_input(inputs);

		terry_states state = process_fsm(inputs);

		if (state != current_state)
		{
			switch (state)
			{
			case ST_IDLE:
				current_animation = &Terryidle;
				break;
			case ST_WALK_FORWARD:
				break;
			case ST_WALK_BACKWARD:
				break;
			case ST_JUMP_NEUTRAL:
				break;
			case ST_JUMP_FORWARD:
				break;
			case ST_JUMP_BACKWARD:
				break;
			case ST_CROUCH:
				break;
			case ST_PUNCH_CROUCH:
				break;
			case ST_PUNCH_STANDING:
				break;
			case ST_PUNCH_NEUTRAL_JUMP:
				break;
			case ST_PUNCH_FORWARD_JUMP:;
				break;
			case ST_PUNCH_BACKWARD_JUMP:
				break;
			}
		}
		current_state = state;
	}*/


	int speed = 1;

	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &TerryForward;
		if (Terryposition.x < 570)
			Terryposition.x += speed;
	}
	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &TerryBackwards;
		if (Terryposition.x > 0)
			Terryposition.x -= speed;
	}

	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &TerryJump;


		/*Terryposition.y = 100;*/
		//if (Terryposition.y == 100)
		//{
		//	Terryposition.y = 85;
		//}

		//if (Terryposition.y == 85)
		//{
		//	Terryposition.y = 115;
		//}
		/*Terryposition.y -= speed;*/					////NO PUJA XD


		//if ()
		//{
		//	Terryposition.y = Terryposition.y + 15;
		//}

		//else if ()
		//{
		//	Terryposition.y = Terryposition.y - 15;
		//}



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

	if (App->input->keyboard[SDL_SCANCODE_P] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &TerryPunch;
	}

	if (App->input->keyboard[SDL_SCANCODE_P] == KEY_STATE::KEY_DOWN)
	{
		colp = App->collisions->AddCollider({ Terryposition.x + 45, Terryposition.y+20, 43, 20 }, COLLIDER_PLAYER_SHOT, App->player);
	}

	if (App->input->keyboard[SDL_SCANCODE_P] == KEY_STATE::KEY_UP)
	{
		if (colp)
			colp->to_delete = true;
	}

	if (App->input->keyboard[SDL_SCANCODE_K] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &TerryKick;
	}

	if (App->input->keyboard[SDL_SCANCODE_K] == KEY_STATE::KEY_DOWN)
	{
		colk = App->collisions->AddCollider({ Terryposition.x + 45, Terryposition.y + 48, 55, 20 }, COLLIDER_PLAYER_SHOT, App->player);
	}

	if (App->input->keyboard[SDL_SCANCODE_K] == KEY_STATE::KEY_UP)
	{
		if (colk)
			colk->to_delete = true;
	}

	if (App->input->keyboard[SDL_SCANCODE_B] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->terryenergy, Terryposition.x + 40, Terryposition.y + 12);
		App->audio->PlayFX("FX/Voice/Special Attacks/FX_PowerWaveAttackTerryBogardVoice/FX_PowerWaveAttackTerryBogardVoice.wav");
	}
	if (App->input->keyboard[SDL_SCANCODE_B] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &TerryPW;
	}

	if (App->input->keyboard[SDL_SCANCODE_F5] == KEY_STATE::KEY_DOWN)
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
			col = App->collisions->AddCollider({ 0, 0, 60, 92 }, COLLIDER_PLAYER, App->player);
			gmode = false;
		}
	}

	// TODO 3: Update collider position to player position
	col->rect.x = Terryposition.x+15;
	col->rect.y = Terryposition.y+10;
	

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	// Draw everything --------------------------------------
	if (destroyed == false)
	{
		if ((current_animation == (&TerryKick)) || current_animation == (&TerryJump) || current_animation == (&TerryForward) || current_animation == (&TerryBackwards)/*current_animation == (&TerryKick || &TerryJump || &TerryForward || &TerryBackwards)*/)
		{
			App->render->Blit(graphics2, Terryposition.x, Terryposition.y, &(current_animation->GetCurrentFrame()));
		}

		else
		{
			App->render->Blit(graphics, Terryposition.x, Terryposition.y, &(current_animation->GetCurrentFrame()));
		}

		if (current_animation == (&TerryJump))
		{
			if (Terryposition.y == 115)
			{
				Terryposition.y = 85;
			}

			else if (Terryposition.y == 85)
			{
				Terryposition.y = 55;
			}

			else if (Terryposition.y == 55)
			{
				Terryposition.y = 115;
			}

		}
		//App->render->Blit(graphics, terryposition.x, terryposition.y, &(current_animation->GetCurrentFrame()));
		//App->render->Blit(graphics, terry2position.x, terry2position.y, &(current_animation->GetCurrentFrame()));
	}

	// Draw UI (score) --------------------------------------
	sprintf_s(score_text, 10, "%7d", score);

	// TODO 3: Blit the text of the score in at the bottom of the screen
	App->fonts->BlitText(0, 150, font_score, "HelloWorld");

	return UPDATE_CONTINUE;
}

// TODO 4: Detect collision with a player.
void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (c1->type == COLLIDER_PLAYER && c2->type == COLLIDER_ENEMY)
	{
		App->fade->FadeToBlack((Module*)App->scene_2, (Module*)App->end_game);
	}
}

bool ModulePlayer::external_input(p2Qeue<terry_inputs>& inputs)
{
	static bool left = false;
	static bool right = false;
	static bool down = false;
	static bool up = false;

	SDL_Event event;

	while (SDL_PollEvent(&event) != 0)
	{
		if (event.type == SDL_KEYUP && event.key.repeat == 0)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				return false;
				break;
			case SDLK_DOWN:
				inputs.Push(IN_CROUCH_UP);
				down = false;
				break;
			case SDLK_UP:
				up = false;
				break;
			case SDLK_LEFT:
				inputs.Push(IN_LEFT_UP);
				left = false;
				break;
			case SDLK_RIGHT:
				inputs.Push(IN_RIGHT_UP);
				right = false;
				break;
			}
		}
		if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_SPACE:
				inputs.Push(IN_X);
				break;
			case SDLK_UP:
				up = true;
				break;
			case SDLK_DOWN:
				down = true;
				break;
			case SDLK_LEFT:
				left = true;
				break;
			case SDLK_RIGHT:
				right = true;
				break;
			}
		}
	}

	if (left && right)
		inputs.Push(IN_LEFT_AND_RIGHT);
	{
		if (left)
			inputs.Push(IN_LEFT_DOWN);
		if (right)
			inputs.Push(IN_RIGHT_DOWN);
	}

	if (up && down)
		inputs.Push(IN_JUMP_AND_CROUCH);
	else
	{
		if (down)
			inputs.Push(IN_CROUCH_DOWN);
		if (up)
			inputs.Push(IN_JUMP);
	}

	return true;
}

void ModulePlayer::internal_input(p2Qeue<terry_inputs>& inputs)
{
	if (jump_timer > 0)
	{
		if (SDL_GetTicks() - jump_timer > JUMP_TIME)
		{
			inputs.Push(IN_JUMP_FINISH);
			jump_timer = 0;
		}
	}

	if (punch_timer > 0)
	{
		if (SDL_GetTicks() - punch_timer > PUNCH_TIME)
		{
			inputs.Push(IN_PUNCH_FINISH);
			punch_timer = 0;
		}
	}
}

ModulePlayer::terry_states ModulePlayer::process_fsm(p2Qeue<terry_inputs>& inputs)
{
	static terry_states state = ST_IDLE;
	terry_inputs last_input;

	while (inputs.Pop(last_input))
	{
		switch (state)
		{
		case ST_IDLE:
		{
			switch (last_input)
			{
			case IN_RIGHT_DOWN: state = ST_WALK_FORWARD; break;
			case IN_LEFT_DOWN: state = ST_WALK_BACKWARD; break;
			case IN_JUMP: state = ST_JUMP_NEUTRAL; jump_timer = SDL_GetTicks();  break;
			case IN_CROUCH_DOWN: state = ST_CROUCH; break;
			case IN_X: state = ST_PUNCH_STANDING; punch_timer = SDL_GetTicks();  break;
			}
		}
		break;

		case ST_WALK_FORWARD:
		{
			switch (last_input)
			{
			case IN_RIGHT_UP: state = ST_IDLE; break;
			case IN_LEFT_AND_RIGHT: state = ST_IDLE; break;
			case IN_JUMP: state = ST_JUMP_FORWARD; jump_timer = SDL_GetTicks();  break;
			case IN_CROUCH_DOWN: state = ST_CROUCH; break;
			}
		}
		break;

		case ST_WALK_BACKWARD:
		{
			switch (last_input)
			{
			case IN_LEFT_UP: state = ST_IDLE; break;
			case IN_LEFT_AND_RIGHT: state = ST_IDLE; break;
			case IN_JUMP: state = ST_JUMP_BACKWARD; jump_timer = SDL_GetTicks();  break;
			case IN_CROUCH_DOWN: state = ST_CROUCH; break;
			}
		}
		break;

		case ST_JUMP_NEUTRAL:
		{
			switch (last_input)
			{
			case IN_JUMP_FINISH: state = ST_IDLE; break;
			case IN_X: state = ST_PUNCH_NEUTRAL_JUMP; punch_timer = SDL_GetTicks(); break;
			}
		}
		break;

		case ST_JUMP_FORWARD:
		{
			switch (last_input)
			{
				// TODO: Add links
			case IN_JUMP_FINISH: state = ST_IDLE; break;
			case IN_X: state = ST_PUNCH_FORWARD_JUMP; punch_timer = SDL_GetTicks(); break;
			}
		}
		break;

		case ST_JUMP_BACKWARD:
		{
			switch (last_input)
			{
				// TODO: Add Links
			case IN_JUMP_FINISH: state = ST_IDLE; break;
			case IN_X: state = ST_PUNCH_BACKWARD_JUMP; punch_timer = SDL_GetTicks(); break;
			}
		}
		break;

		case ST_PUNCH_NEUTRAL_JUMP:
		{
			switch (last_input)
			{
				// TODO: Add Links
			case IN_JUMP_FINISH: state = ST_IDLE; break;
			}
		}
		break;

		case ST_PUNCH_FORWARD_JUMP:
		{
			switch (last_input)
			{
				// TODO: Add Links
			case IN_JUMP_FINISH: state = ST_IDLE; break;
			}
		}
		break;

		case ST_PUNCH_BACKWARD_JUMP:
		{
			switch (last_input)
			{
				// TODO: Add Links
			case IN_JUMP_FINISH: state = ST_IDLE; break;
			}
		}
		break;

		case ST_PUNCH_STANDING:
		{
			switch (last_input)
			{
				// TODO: Add Links
			case IN_PUNCH_FINISH: state = ST_IDLE; break;
			}
		}
		break;

		case ST_CROUCH:
		{
			switch (last_input)
			{
				// TODO: Add Links

			}
		}
		break;
		case ST_PUNCH_CROUCH:
		{
			switch (last_input)
			{
				// TODO: Add Links
			}
		}
		break;
		}
	}

	return state;
}
