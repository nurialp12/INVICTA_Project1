#include "Globals.h"
#include "Application.h"
#include "ModuleRender.h"
#include "ModuleWindow.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"

ModuleRender::ModuleRender() : Module()
{
	camera.x = -480 /*0*/;
	camera.y = -10;
	camera.w = SCREEN_WIDTH;
	camera.h = SCREEN_HEIGHT;
}

// Destructor
ModuleRender::~ModuleRender()
{}

// Called before render is available
bool ModuleRender::Init()
{
	LOG("Creating Renderer context");
	bool ret = true;
	Uint32 flags = 0;

	if(REN_VSYNC == true)
	{
		flags |= SDL_RENDERER_PRESENTVSYNC;
	}

	

	renderer = SDL_CreateRenderer(App->window->window, -1, flags);


	
	if(renderer == NULL)
	{
		LOG("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}
	SDL_RenderSetLogicalSize(renderer, App->window->width, App->window->height);
	return ret;
}

// Called every draw update
update_status ModuleRender::PreUpdate()
{
	SDL_RenderClear(renderer);

	

	return update_status::UPDATE_CONTINUE;
}


update_status ModuleRender::Update()	
{
	float speed = 1.7;

	if(App->input->keyboard[SDL_SCANCODE_COMMA] == KEY_STATE::KEY_REPEAT)
		camera.y += speed;

	if(App->input->keyboard[SDL_SCANCODE_PERIOD] == KEY_STATE::KEY_REPEAT)
		camera.y -= speed;

	if(App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT )
		if (camera.x < 0 && App->player->destroyed == false &&
			(App->player2->Terry2position.x * 2 - 160) < (-(camera.x-camera.w)) &&
			App->input->keyboard[SDL_SCANCODE_LEFT] != KEY_STATE::KEY_REPEAT &&
			App->player->currentstate == ST_WALK_BACKWARD)
		{
			camera.x += speed;
		}

	if(App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
		if (camera.x > -900 /*-490*/ && App->player->destroyed == false &&
			App->player2->Terry2position.x*2 > -camera.x &&
			App->input->keyboard[SDL_SCANCODE_RIGHT] != KEY_STATE::KEY_REPEAT &&
			App->player->currentstate == ST_WALK_FORWARD)
		{
			camera.x -= speed;
		}

	if (App->input->keyboard[SDL_SCANCODE_LEFT] == KEY_STATE::KEY_REPEAT)
		if (camera.x < 0 && App->player->destroyed == false &&
			(App->player->Terryposition.x * 2 - 160) < (-(camera.x - camera.w)) &&
			App->player->currentstate != ST_IDLE &&
			App->player->currentstate != ST_CROUCH &&
			App->player->currentstate != ST_KICK_CROUCH &&
			App->player->currentstate != ST_PUNCH_CROUCH &&
			App->player->currentstate != ST_PUNCH_STANDING &&
			App->player->currentstate != ST_KICK_STANDING &&
			App->player->currentstate != ST_JUMP_NEUTRAL)
		{
			camera.x += speed;
		}

	if (App->input->keyboard[SDL_SCANCODE_RIGHT] == KEY_STATE::KEY_REPEAT)
		if (camera.x > -900 /*-490*/ && App->player->destroyed == false &&
			App->player->Terryposition.x * 2 > -camera.x &&
			App->player->currentstate != ST_IDLE &&
			App->player->currentstate != ST_CROUCH &&
			App->player->currentstate != ST_KICK_CROUCH &&
			App->player->currentstate != ST_PUNCH_CROUCH &&
			App->player->currentstate != ST_PUNCH_STANDING &&
			App->player->currentstate != ST_KICK_STANDING &&
			App->player->currentstate != ST_JUMP_NEUTRAL)
		{
			camera.x -= speed;
		}
	return update_status::UPDATE_CONTINUE;
}

update_status ModuleRender::PostUpdate()
{
	SDL_RenderPresent(renderer);
	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleRender::CleanUp()
{
	LOG("Destroying renderer");

	//Destroy window
	if(renderer != NULL)
	{
		SDL_DestroyRenderer(renderer);
	}

	return true;
}

// Blit to screen
bool ModuleRender::Blit(SDL_Texture* texture, int x, int y, SDL_Rect* section, float speed)
{
	bool ret = true;
	SDL_Rect rect;
	rect.x = (int)(camera.x * speed) + x * SCREEN_SIZE;
	rect.y = (int)(camera.y * speed) + y * SCREEN_SIZE;

	if(section != NULL)
	{
		rect.w = section->w;
		rect.h = section->h;
	}
	else
	{
		SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
	}

	rect.w *= SCREEN_SIZE;
	rect.h *= SCREEN_SIZE;

	if(SDL_RenderCopy(renderer, texture, section, &rect) != 0)
	{
		LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
		ret = false;
	}

	return ret;
}

bool ModuleRender::DrawQuad(const SDL_Rect& rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a, bool use_camera)
{
	bool ret = true;

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, r, g, b, a);

	SDL_Rect rec(rect);
	if (use_camera)
	{
		rec.x = (int)(camera.x + rect.x * SCREEN_SIZE);
		rec.y = (int)(camera.y + rect.y * SCREEN_SIZE);
		rec.w *= SCREEN_SIZE;
		rec.h *= SCREEN_SIZE;
	}

	if (SDL_RenderFillRect(renderer, &rec) != 0)
	{
		LOG("Cannot draw quad to screen. SDL_RenderFillRect error: %s", SDL_GetError());
		ret = false;
	}

	return ret;
}

