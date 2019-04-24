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

#include <stdio.h>


// Reference at https://www.youtube.com/watch?v=OEhmUuehGOA

ModulePlayer::ModulePlayer()
{


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
	LOG("Loading player");
	bool ret = true;

	graphics = App->textures->Load("spritesTerryBogard.png");
	graphics2 = App->textures->Load("TerryAvanzar+SaltoEstatico+Patada+Retroceder.png");

	/////TODO NOW/////

	destroyed = false;
	Terryposition.x = 150;
	Terryposition.y = 130;
	Terry2position.x = 300;
	Terry2position.y = 130;
	score = 0;

	// TODO 2: Add a collider to the player
	col = App->collisions->AddCollider({ 0, 0, 60, 92 }, COLLIDER_PLAYER, App->player);
	col2 = App->collisions->AddCollider({ 0, 0, 60, 92 }, COLLIDER_ENEMY, App->player);
	col3 = App->collisions->AddCollider({ 0, 0, 20, 20 }, COLLIDER_PLAYER_SHOT, App->player);

	// TODO 0: Notice how a font is loaded and the meaning of all its arguments 
	font_score = App->fonts->Load("fonts/rtype_font.png", "! @,_./0123456789$;<&?abcdefghijklmnopqrstuvwxyz", 1);
	return ret;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);
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
	Animation* current_animation = &Terryidle;

	int speed = 3;

	if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{
		if (Terryposition.x < 570)
		{
			current_animation = &TerryForward;
			Terryposition.x += speed;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		if (Terryposition.x > 0)
		{
			current_animation = &TerryBackwards;
			Terryposition.x -= speed;
		}
	}

	if (App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_DOWN)
	{
		current_animation = &TerryJump;
		Terryposition.y += speed;					////NO PUJA XD

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

	if (App->input->keyboard[SDL_SCANCODE_K] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &TerryKick;
	}

	if (App->input->keyboard[SDL_SCANCODE_B] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->terryenergy, Terryposition.x + 40, Terryposition.y);
		App->audio->PlayFX("FX/Voice/Special Attacks/FX_PowerWaveAttackTerryBogardVoice/FX_PowerWaveAttackTerryBogardVoice.wav");
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
	if (App->input->keyboard[SDL_SCANCODE_P] == KEY_STATE::KEY_UP)
	{
		if (col3)
			col3->to_delete = true;
	}
	// TODO 3: Update collider position to player position
	col->rect.x = Terryposition.x;
	col->rect.y = Terryposition.y;
	col2->rect.x = Terry2position.x;
	col2->rect.y = Terry2position.y;

	//collider punch position
	col3->rect.x = Terryposition.x-20;
	col3->rect.y = Terryposition.y-20;

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	// Draw everything --------------------------------------
	if (destroyed == false)
	{

		if ((current_animation == (&TerryKick)) || current_animation == (&TerryJump) || current_animation == (&TerryForward) || current_animation == (&TerryBackwards)/*current_animation == (&TerryKick || &TerryJump || &TerryForward || &TerryBackwards)*/)
		{
			App->render->Blit(graphics2, Terryposition.x, Terryposition.y - r.h, &r);
			App->render->Blit(graphics2, Terry2position.x, Terry2position.y, &(current_animation->GetCurrentFrame()));

		}


		else
		{
			App->render->Blit(graphics, Terryposition.x, Terryposition.y - r.h, &r);
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


