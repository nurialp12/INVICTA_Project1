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





// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{


	// idle animation of Terry					//spritesTerryBogard.png

	//Terryidle.PushBack({ 428, 915, 79, 109 });
	//Terryidle.PushBack({ 505, 915, 68, 105 });
	//Terryidle.speed = 0.2f;

	Terry2idle.PushBack({ 27, 914, 60, 105 });
	Terry2idle.PushBack({ 95, 916, 61, 104 });
	Terry2idle.PushBack({ 164, 916, 60, 103 });
	Terry2idle.PushBack({ 95, 916, 61, 104 });
	Terry2idle.speed = 0.1f;


	// walk forward animation of Terry					//TerryAvanzar+SaltoEstatico+Patada+Retroceder.png

	//TerryForward.frames.PushBack({/**/, /**/, /**/, /**/});

	Terry2Forward.PushBack({ 20, 277, 61, 104 });
	Terry2Forward.PushBack({ 95, 274, 61 /*71*/, 107 });
	Terry2Forward.PushBack({ 177, 275, 61, 106 });
	Terry2Forward.PushBack({ 251, 278, 61, 61 });
	Terry2Forward.speed = 0.1f;


	// walk backward animation of Terry					//TerryAvanzar+SaltoEstatico+Patada+Retroceder.png

	//TerryBackwards.frames.PushBack({/**/, /**/, /**/, /**/});

	Terry2Backwards.PushBack({ 441, 275, 57, 106 });
	Terry2Backwards.speed = 0.1f;



	// jump animation of Terry				//TerryAvanzar+SaltoEstatico+Patada+Retroceder.png

	//TerryJump.frames.PushBack({/**/, /**/, /**/, /**/});

	Terry2Jump.PushBack({ 535, 12, 53, 125 });
	Terry2Jump.PushBack({ 598, 22, 59, 105 });
	Terry2Jump.PushBack({ 667, 33, 59, 94 });
	Terry2Jump.speed = 0.1f;


	// kick animation of Terry				//TerryAvanzar+SaltoEstatico+Patada+Retroceder.png

	//TerryKick.frames.PushBack({/**/, /**/, /**/, /**/});
	Terry2Kick.PushBack({ 20, 129, 49, 95 });
	Terry2Kick.PushBack({ 73, 129, 59, 111 });
	Terry2Kick.PushBack({ 138, 129, 44, 107 });
	Terry2Kick.PushBack({ 200, 141, 118, 99 });
	Terry2Kick.PushBack({ 331, 129, 64, 111 });
	Terry2Kick.speed = 0.1f;


	// punch animation of Terry					//spritesTerryBogard.png

	//TerryPunch.frames.PushBack({/**/, /**/, /**/, /**/});
	//TerryPunch.PushBack({ 428, 915, 79, 109 });
	//TerryPunch.PushBack({ 505, 915, 68, 105 });
	//TerryPunch.PushBack({ 570, 915, 107, 109 });
	//TerryPunch.speed = 0.1f;

	Terry2Punch.PushBack({ 435, 918, 73, 100 });
	Terry2Punch.PushBack({ 507, 918, 62, 102 });
	Terry2Punch.PushBack({ 574, 917, 97, 103 });
	Terry2Punch.speed = 0.1f;


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
	//Terryposition.x = 150;
	//Terryposition.y = 115;
	Terry2position.x = 300;
	Terry2position.y = 115;
	score = 0;

	// TODO 2: Add a collider to the player
	col = App->collisions->AddCollider({ 0, 0, 60, 92 }, COLLIDER_PLAYER, App->player);
	col2 = App->collisions->AddCollider({ 0, 0, 60, 92 }, COLLIDER_ENEMY, App->player);

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
	if (col2)
		col2->to_delete = true;

	return true;
}

// Update: draw background
update_status ModulePlayer::Update()
{
	Animation* current_animation = &Terry2idle;

	int speed = 1;

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
	{
		if (Terry2position.x < 570)
		{
			current_animation = &Terry2Forward;
			Terry2position.x += speed;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
	{
		if (Terry2position.x > 0)
		{
			current_animation = &Terry2Backwards;
			Terry2position.x -= speed;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_UP] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &Terry2Jump;
		Terry2position.y -= speed;					////NO PUJA XD

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

	if (App->input->keyboard[SDL_SCANCODE_I] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &Terry2Punch;
	}

	if (App->input->keyboard[SDL_SCANCODE_O] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &Terry2Kick;
	}

	if (App->input->keyboard[SDL_SCANCODE_M] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->terryenergy, Terry2position.x - 40, Terry2position.y);
		App->audio->PlayFX("FX/Voice/Special Attacks/FX_PowerWaveAttackTerryBogardVoice/FX_PowerWaveAttackTerryBogardVoice.wav");
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
			col = App->collisions->AddCollider({ 0, 0, 60, 92 }, COLLIDER_PLAYER, App->player);
			gmode = false;
		}
	}

	// TODO 3: Update collider position to player position
	//col->rect.x = Terryposition.x;
	//col->rect.y = Terryposition.y;
	col2->rect.x = Terry2position.x;
	col2->rect.y = Terry2position.y;

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	// Draw everything --------------------------------------
	if (destroyed == false)
	{
		if ((current_animation == (&Terry2Kick)) || current_animation == (&Terry2Jump) || current_animation == (&Terry2Forward) || current_animation == (&Terry2Backwards)/*current_animation == (&TerryKick || &TerryJump || &TerryForward || &TerryBackwards)*/)
		{
			//App->render->Blit(graphics2, Terryposition.x, Terryposition.y, &(current_animation->GetCurrentFrame()));
			App->render->Blit(graphics2, Terry2position.x, Terry2position.y, &(current_animation->GetCurrentFrame()));
		}

		else
		{
			//App->render->Blit(graphics, Terryposition.x, Terryposition.y, &(current_animation->GetCurrentFrame()));
			App->render->Blit(graphics, Terry2position.x, Terry2position.y, &(current_animation->GetCurrentFrame()));
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

terry_states ModulePlayer::process_fsm(p2Qeue<terry_inputs>& inputs)
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