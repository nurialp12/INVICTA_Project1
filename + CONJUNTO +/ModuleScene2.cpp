#include "Globals.h"
#include "Application.h"
#include "ModuleScene2.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneWinP1.h"
#include "ModuleSceneWinP2.h"
#include "ModuleSceneTie.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModuleAudio.h"

#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )



ModuleScene2::ModuleScene2()
{
	// ground
	//ground = {8, 376, 848, 64};

	// roof
	//roof = {91, 7, 765, 49};

	// foreground
	//foreground = {164, 66, 336, 51};

	//// Background / sky
	//background.PushBack({ 40, 34, 619, 224 });
	//background.PushBack({ 40, 300, 619, 224 });
	//background.speed = 0.05f;

	// flag animation
	/*water.PushBack({8, 447, 283, 9});
	water.PushBack({296, 447, 283, 12});
	water.PushBack({588, 447, 283, 18});
	water.speed = 0.02f;*/

	//score
	one = { 0, 0, 8, 8 };
	two = { 8, 0, 8, 8 };
	three = { 16, 0, 8, 8 };
	four = { 24, 0, 8, 8 };
	five = { 32, 0, 8, 8 };
	six = { 40, 0, 8, 8 };
	seven = { 48, 0, 8, 8 };
	eight = { 56, 0, 8, 8 };
	nine = { 64, 0, 8, 8 };
	zero = { 72, 0, 8, 8 };
	positionx = 72;
	positiony = 17;
	if (player == 0)
		this->player = 0;
	if (player == 1)
		this->player = 1;
	currentscore = 0;

	//bus
	bus.PushBack({ 480, 525, 145, 73 });
	bus.PushBack({ 480, 524, 145, 74 });
	bus.speed = 0.05f;

	busT.PushBack({ 480, 1026, 145, 73 });
	busT.PushBack({ 480, 1025, 145, 74 });
	busT.speed = 0.05f;

	busN.PushBack({ 480, 1526, 145, 73 });
	busN.PushBack({ 480, 1525, 145, 74 });
	busN.speed = 0.05f;

	// Background / sky
	background.x = 1349;
	background.y = 631;
	background.w = 469;
	background.h = 107;

	backgroundT.x = 1349;
	backgroundT.y = 1132;
	backgroundT.h = 107;
	backgroundT.w = 469;

	backgroundN.x = 1349;
	backgroundN.y = 1632;
	backgroundN.w = 469;
	backgroundN.h = 107;

	//Shadow
	shadow.x = 522;
	shadow.y = 478;
	shadow.w = 66;
	shadow.h = 12;

	// flag animation
	background1.PushBack({ 718, 379, 619, 235 });
	background1.PushBack({ 1349, 379 , 619, 235 });
	background1.PushBack({ 718, 631, 619, 235 });
	background1.speed = 0.05f;

	background1T.PushBack({ 718, 880, 619, 235 });
	background1T.PushBack({ 1349, 880 , 619, 235 });
	background1T.PushBack({ 718, 1132, 619, 235 });
	background1T.speed = 0.05f;

	background1N.PushBack({ 718, 1380, 619, 235 });
	background1N.PushBack({ 1349, 1380 , 619, 235 });
	background1N.PushBack({ 718, 1632, 619, 235 });
	background1N.speed = 0.05f;


	//{ /*x*/, /*y*/, /*w*/, /*h*/ });  


	people1.PushBack({ 39, 403, 64, 100 });  
	people1.PushBack({ 39, 512, 64, 100 });
	people1.speed = 0.05f;

	people2.PushBack({ 143, 411, 65, 97 });  
	people2.PushBack({ 143, 518, 65, 97 });
	people2.speed = 0.05f;

	people3.PushBack({ 246, 404, 62, 99 }); 
	people3.PushBack({ 246, 512, 62, 99 });
	people3.speed = 0.05f;

	people4.PushBack({ 347, 402, 69, 95 }); 
	people4.PushBack({ 347, 514, 69, 95 });
	people4.speed = 0.05f;

	people1T.PushBack({ 39, 904, 64, 100 });
	people1T.PushBack({ 39, 1013, 64, 100 });
	people1T.speed = 0.05f;

	people2T.PushBack({ 143, 912, 65, 97 });
	people2T.PushBack({ 143, 1019, 65, 97 });
	people2T.speed = 0.05f;

	people3T.PushBack({ 246, 905, 62, 99 });
	people3T.PushBack({ 246, 1013, 62, 99 });
	people3T.speed = 0.05f;

	people4T.PushBack({ 347, 903, 69, 95 });
	people4T.PushBack({ 347, 1015, 69, 95 });
	people4T.speed = 0.05f;

	people1N.PushBack({ 39, 1404, 64, 100 });
	people1N.PushBack({ 39, 1513, 64, 100 });
	people1N.speed = 0.05f;
		   
	people2N.PushBack({ 143, 1412, 65, 97 });
	people2N.PushBack({ 143, 1519, 65, 97 });
	people2N.speed = 0.05f;
		   
	people3N.PushBack({ 246, 1405, 62, 99 });
	people3N.PushBack({ 246, 1513, 62, 99 });
	people3N.speed = 0.05f;
		   
	people4N.PushBack({ 347, 1403, 69, 95 });
	people4N.PushBack({ 347, 1515, 69, 95 });
	people4N.speed = 0.05f;

}

ModuleScene2::~ModuleScene2()
{}

// Load assets
bool ModuleScene2::Start()
{
	LOG("Loading background assets");
	bool ret = true;
	//graphics = App->textures->Load("Assets/Sprites/Pao_Pao_Cafe.png");

	App->render->camera.x = -245;
	App->render->camera.y = -10;

	round = 1;

	graphics = App->textures->Load("Assets/Sprites/Sound_Beach1.png");
	score = App->textures->Load("Assets/Fonts/scorenums.png");

	App->player->Enable();
	App->player2->Enable();
	App->particles->Enable();
	App->collisions->Enable();
	App->player->life_score = 94;
	App->player2->life_score = 94;
	p1won = false;
	p2won = false;

	// TODO 1: Add colliders for the first columns of the level
	

	// TODO 1: Add colliders for the first columns of the level
	

	App->audio->PlayMusic("Assets/music/The ocean knows/The ocean knows.ogg", -1);


	return ret;
}

// Load assets
bool ModuleScene2::CleanUp()
{
	// TODO 4: Remove all memory leaks
	graphics = nullptr;
	SDL_DestroyTexture(App->textures->Load("Assets/Sprites/Sound_Beach1.png"));
	SDL_DestroyTexture(App->textures->Load("Assets/Fonts/scorenums.png"));

	LOG("Unloading stage");
	App->player->Disable();
	return true;
}

// Update: draw background
update_status ModuleScene2::Update()
{
	// Draw everything --------------------------------------	
	//App->render->Blit(graphics, 0, 160, &ground);
	if (reboot && (p1won || p2won))
	{
		App->player->Disable();
		App->player2->Disable();

		App->player->Enable();
		App->player2->Enable();
		App->collisions->Enable();
		App->render->camera.x = -245;
		App->render->camera.y = -10;
		App->player->life_score = 94;
		App->player2->life_score = 94;
		reboot = false;
	}
	
	if (round == 1)
	{
		App->render->Blit(graphics, 0, -5, &background, 0.35f);
		App->render->Blit(graphics, 0, -11, &(background1.GetCurrentFrame()), 0.60f); // back of the room


		App->render->Blit(graphics, 27, 100, &(people1.GetCurrentFrame()), 0.60f);
		App->render->Blit(graphics, 92, 100, &(people3.GetCurrentFrame()), 0.60f);
		App->render->Blit(graphics, 153, 100, &(people2.GetCurrentFrame()), 0.60f);
		App->render->Blit(graphics, 217, 100, &(people4.GetCurrentFrame()), 0.60f);

		App->render->Blit(graphics, 282, 100, &(people1.GetCurrentFrame()), 0.60f);
		App->render->Blit(graphics, 348, 100, &(people3.GetCurrentFrame()), 0.60f);
		App->render->Blit(graphics, 409, 100, &(people2.GetCurrentFrame()), 0.60f);
		/*App->render->Blit(graphics, 200, 100, &(people4.GetCurrentFrame()), 0.60f);*/

		App->render->Blit(graphics, 474, 110, &(bus.GetCurrentFrame()), 0.60f);
	}

	else if (round == 2)
	{
		App->render->Blit(graphics, 0, -5, &backgroundT, 0.35f);
		App->render->Blit(graphics, 0, -11, &(background1T.GetCurrentFrame()), 0.60f); // back of the room


		App->render->Blit(graphics, 27, 100, &(people1T.GetCurrentFrame()), 0.60f);
		App->render->Blit(graphics, 92, 100, &(people3T.GetCurrentFrame()), 0.60f);
		App->render->Blit(graphics, 153, 100, &(people2T.GetCurrentFrame()), 0.60f);
		App->render->Blit(graphics, 217, 100, &(people4T.GetCurrentFrame()), 0.60f);

		App->render->Blit(graphics, 282, 100, &(people1T.GetCurrentFrame()), 0.60f);
		App->render->Blit(graphics, 348, 100, &(people3T.GetCurrentFrame()), 0.60f);
		App->render->Blit(graphics, 409, 100, &(people2T.GetCurrentFrame()), 0.60f);
		/*App->render->Blit(graphics, 200, 100, &(people4.GetCurrentFrame()), 0.60f);*/

		App->render->Blit(graphics, 474, 110, &(busT.GetCurrentFrame()), 0.60f);
	}

	else if (round == 3)
	{
		App->render->Blit(graphics, 0, -5, &backgroundN, 0.35f);
		App->render->Blit(graphics, 0, -11, &(background1N.GetCurrentFrame()), 0.60f); // back of the room


		App->render->Blit(graphics, 27, 100, &(people1N.GetCurrentFrame()), 0.60f);
		App->render->Blit(graphics, 92, 100, &(people3N.GetCurrentFrame()), 0.60f);
		App->render->Blit(graphics, 153, 100, &(people2N.GetCurrentFrame()), 0.60f);
		App->render->Blit(graphics, 217, 100, &(people4N.GetCurrentFrame()), 0.60f);

		App->render->Blit(graphics, 282, 100, &(people1N.GetCurrentFrame()), 0.60f);
		App->render->Blit(graphics, 348, 100, &(people3N.GetCurrentFrame()), 0.60f);
		App->render->Blit(graphics, 409, 100, &(people2N.GetCurrentFrame()), 0.60f);
		/*App->render->Blit(graphics, 200, 100, &(people4.GetCurrentFrame()), 0.60f);*/

		App->render->Blit(graphics, 474, 110, &(busN.GetCurrentFrame()), 0.60f);
	}
	
	


	if(App->player->mirror) App->render->Blit(graphics, App->player->Andyposition.x, 202, &shadow);
	else App->render->Blit(graphics, App->player->Andyposition.x - 10, 202, &shadow);
	if(App->player2->mirror2)App->render->Blit(graphics, App->player2->Andy2position.x, 202, &shadow);
	else App->render->Blit(graphics, App->player2->Andy2position.x - 10, 202, &shadow);
	




	


	if (App->input->keyboard[SDL_SCANCODE_F9] == 1)
	{
		App->audio->MuteMusic("Assets/music/The ocean knows/The ocean knows.ogg", -1);
	}

	
	


	
	if (App->input->keyboard[SDL_SCANCODE_F2] == 1)
	{
		
		App->fade->FadeToBlack(App->scene_2, App->end_game1, 2.5);  
	}
	if (App->input->keyboard[SDL_SCANCODE_F3] == 1)
	{
		App->fade->FadeToBlack(App->scene_2, App->end_game2, 2.5);
	}
	if (App->input->keyboard[SDL_SCANCODE_F4] == 1)
	{
		App->fade->FadeToBlack(App->scene_2, App->end_game1, 2.5);
	}
	if (App->input->keyboard[SDL_SCANCODE_F6] == 1)
	{
		App->fade->FadeToBlack(App->scene_2, App->end_game2, 2.5);
	}
	if (App->input->keyboard[SDL_SCANCODE_F7] == 1)
	{
		App->fade->FadeToBlack(App->scene_2, App->end_game1, 2.5);
	}

	if (App->player->life_score <= 0 && !p2won)
	{
		p2won = true;
		App->collisions->Disable();
		if (round == 3)
		{
			round = 1;
		}
		else
		{
			++round;
		}
		App->fade->Reboot(2.5);
		
		
		
	}
	else if (App->player2->life_score <= 0 && !p1won)
	{
		p1won = true;
		App->collisions->Disable();
		if (round == 3)
		{
			round = 1;
		}
		else
		{
			++round;
		}
		App->fade->Reboot(1.5);
	}
	else if (App->player->life_score <= 0 && p2won)
	{
		App->fade->FadeToBlack(App->scene_2, App->end_game2, 2.5);
	}
	else if (App->player2->life_score <= 0 && p1won)
	{
	
		App->fade->FadeToBlack(App->scene_2, App->end_game1, 2.5);
	}
	else if (App->player2->life_score <= 0 && App->player->life_score <= 0)
	{
		if (round == 3)
		{
			round = 1;
		}
		else
		{
			++round;
		}
		App->fade->Reboot(1.5);
	}

	//SCORE
	positionx = (-App->render->camera.x / SCREEN_SIZE) + 72;
	int i;
	SDL_Rect none = { 0,0,0,0 };

	if (player == 0)
		i= App->player->Score();
	if (player == 1)
		i = App->player2->Score();


	if (i > 99999)
	{
		i = 99999;
	}

	if (currentscore != i) {
		n[4] = (int)i / 10000;
		n[3] = (int)(i - n[4] * 10000) / 1000;
		n[2] = (int)(i- n[4] * 10000 - n[3] * 1000) / 100;
		n[1] = (int)(i - n[4] * 10000 - n[3] * 1000 - n[2] * 100) / 10;
		n[0] = i - n[4] * 10000 - n[3] * 1000 - n[2] * 100 - n[1] * 10;

		for (int i = 0; i < 5; i++)
		{
			switch (n[i])
			{
			case 0:
				if (i == 0)
					r[i] = zero;
				else
				{
					for (int y = i + 1; y < 5; y++)
					{
						if (n[y] != 0)
						{
							r[i] = zero;
							break;
						}
						r[i] = none;
					}
				}
				break;
			case 1:
				r[i] = one;
				break;
			case 2:
				r[i] = two;
				break;
			case 3:
				r[i] = three;
				break;
			case 4:
				r[i] = four;
				break;
			case 5:
				r[i] = five;
				break;
			case 6:
				r[i] = six;
				break;
			case 7:
				r[i] = seven;
				break;
			case 8:
				r[i] = eight;
				break;
			case 9:
				r[i] = nine;
				break;
			}
		}
	}
	currentscore = i;

	App->render->Blit(graphics, positionx /*+ (88 * player) + HUD_X*/, positiony, &r[4], 0);
	App->render->Blit(graphics, positionx, positiony, &r[3], 0);
	App->render->Blit(graphics, positionx, positiony, &r[2], 0);
	App->render->Blit(graphics, positionx, positiony, &r[1], 0);
	App->render->Blit(graphics, positionx, positiony, &r[0], 0);


	return UPDATE_CONTINUE;
}