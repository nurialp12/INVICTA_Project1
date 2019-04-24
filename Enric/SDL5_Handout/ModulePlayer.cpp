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

	// idle animation of Terry
	terryidle.PushBack({ 7, 14, 60, 90 });
	terryidle.PushBack({ 95, 15, 60, 89 });
	terryidle.PushBack({ 184, 14, 60, 90 });
	terryidle.PushBack({ 276, 11, 60, 93 });
	terryidle.PushBack({ 366, 12, 60, 92 });
	terryidle.speed = 0.2f;

	// TODO

	//// walk forward animation of Terry
	terryforward.PushBack({78, 131, 60, 88});
	terryforward.PushBack({162, 128, 64, 92});
	terryforward.PushBack({259, 128, 63, 90});
	terryforward.PushBack({352, 128, 54, 91});
	terryforward.PushBack({432, 131, 50, 89});
	terryforward.speed = 0.1f;


	//// walk backward animation of Terry
	terrybackward.PushBack({ 432, 131, 50, 89 });
	terrybackward.PushBack({ 352, 128, 54, 91 });
	terrybackward.PushBack({ 259, 128, 63, 90 });
	terrybackward.PushBack({ 162, 128, 64, 92 });
	terrybackward.PushBack({ 78, 131, 60, 88 });
	terrybackward.speed = 0.1f;



	//// jump animation of Terry
	////TerryJump.frames.PushBack({/**/, /**/, /**/, /**/});
	//TerryJump.PushBack({ /**/, /**/, /**/, /**/ });
	//TerryJump.PushBack({ /**/, /**/, /**/, /**/ });
	//TerryJump.PushBack({ /**/, /**/, /**/, /**/ });
	//TerryJump.speed = 0.1f;


	// kick animation of Terry
	//TerryKick.frames.PushBack({/**/, /**/, /**/, /**/});
	terrykick.PushBack({ 570, 463, 67, 110 });
	terrykick.PushBack({ 638, 463, 83, 125 });
	terrykick.PushBack({ 732, 463, 128, 117 });
	terrykick.speed = 0.05f;

	// punch animation of Terry
	//TerryPunch.frames.PushBack({/**/, /**/, /**/, /**/});
	terrypunch.PushBack({ 428, 915, 79, 109 });
	terrypunch.PushBack({ 505, 915, 68, 105 });
	terrypunch.PushBack({ 570, 915, 107, 109 });
	terrypunch.speed = 0.05f;
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");
	bool ret = true;

	graphics = App->textures->Load("spritesTerryBogard.png"); // arcade version

	destroyed = false;
	terryposition.x = 150;
	terryposition.y = 130;
	terry2position.x = 300;
	terry2position.y = 130;
	score = 0;

	// TODO 2: Add a collider to the player
	col = App->collisions->AddCollider({ 0, 0, 60, 92 }, COLLIDER_PLAYER, App->player);
	col2 = App->collisions->AddCollider({ 0, 0, 60, 92 }, COLLIDER_ENEMY, App->player);
	col3 = App->collisions->AddCollider({ 0, 0, 60, 92 }, COLLIDER_PLAYER_SHOT, App->player);

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
	Animation* current_animation = &terryidle;

	int speed = 3;

	if(App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
	{
		if (terryposition.x < 570)
		{
			current_animation = &terryforward;
			terryposition.x += speed;
		}
	}
	if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
	{
		if (terryposition.x > 0)
		{
			current_animation = &terrybackward;
			terryposition.x -= speed;
		}
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
		current_animation = &terrypunch;
	}

	if (App->input->keyboard[SDL_SCANCODE_K] == KEY_STATE::KEY_REPEAT)
	{
		current_animation = &terrykick;
	}

	if (App->input->keyboard[SDL_SCANCODE_B] == KEY_STATE::KEY_DOWN)
	{
		App->particles->AddParticle(App->particles->terryenergy, terryposition.x+40, terryposition.y);
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

	// TODO 3: Update collider position to player position
	col->rect.x = terryposition.x;
    col->rect.y = terryposition.y;
	col2->rect.x = terry2position.x;
	col2->rect.y = terry2position.y;

	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	// Draw everything --------------------------------------
	if (destroyed == false)
	{
		App->render->Blit(graphics, terryposition.x, terryposition.y, &(current_animation->GetCurrentFrame()));
		App->render->Blit(graphics, terry2position.x, terry2position.y, &(current_animation->GetCurrentFrame()));
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
