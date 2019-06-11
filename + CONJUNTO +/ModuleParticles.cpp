#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"

#include "SDL/include/SDL_timer.h"

ModuleParticles::ModuleParticles()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
		active[i] = nullptr;
}

ModuleParticles::~ModuleParticles()
{}

// Load assets
bool ModuleParticles::Start()
{
	LOG("Loading particles");
	graphics = App->textures->Load("Assets/Sprites/Sprites_AndyBogard_ok.png");

	// TODO 2: Create the template for a new particle "laser"
	//terryenergy.anim.PushBack({ 978, 695, 16, 105 });
	//terryenergy.anim.PushBack({ 956, 695, 16, 105 });
	//terryenergy.anim.PushBack({ 934, 695, 16, 105 });
	//terryenergy.anim.PushBack({ 956, 695, 16, 105 });
	//terryenergy.anim.PushBack({ 978, 695, 16, 105 });
	//terryenergy.anim.loop = false;
	//terryenergy.anim.speed = 0.05f;
	//if ((App->player->mirror && App->player->currentstate == ST_POWER_WAVE) || (App->player2->mirror2 && App->player2->currentstate == ST_POWER_WAVE2))
	//	terryenergy.speed.x = -1;
	//else
	//	terryenergy.speed.x = 1;

	andyenergy.anim.PushBack({ 263, 330, 22, 91 });
	andyenergy.anim.PushBack({ 286, 330, 35, 91 });
	andyenergy.anim.PushBack({ 322, 330, 48, 91 });
	andyenergy.anim.PushBack({ 371, 330, 61, 91 });
	andyenergy.anim.PushBack({ 433, 330, 46, 91 });
	andyenergy.anim.PushBack({ 480, 330, 61, 91 });
	andyenergy.anim.PushBack({ 542, 330, 46, 91 });
	andyenergy.anim.PushBack({ 589, 330, 60, 91 });
	andyenergy.anim.loop = false;
	andyenergy.anim.speed = 0.05f;
	andyenergy.life = 1000;
	/*if ((App->player->mirror && App->player->currentstate == ST_POWER_WAVE) || (App->player2->mirror2 && App->player2->currentstate == ST_POWER_WAVE2))
		andyenergy.speed.x = -100;
	else
		andyenergy.speed.x = 100;*/
	andyenergy.speed.x = 2;
	return true;
}

// Unload assets
bool ModuleParticles::CleanUp()
{
	LOG("Unloading particles");
	App->textures->Unload(graphics);

	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		if (active[i] != nullptr)
		{
			delete active[i];
			active[i] = nullptr;
		}
	}

	return true;
}

// Update: draw background
update_status ModuleParticles::Update()
{
	for (uint i = 0; i < MAX_ACTIVE_PARTICLES; ++i)
	{
		Particle* p = active[i];

		if (p == nullptr)
			continue;

		if (p->Update() == false)
		{
			delete p;
			active[i] = nullptr;
		}
		else if (SDL_GetTicks() >= p->born)
		{
			App->render->Blit(graphics, p->position.x, p->position.y, &(p->anim.GetCurrentFrame()));
			p->col = App->collisions->AddCollider({ p->position.x,p->position.y - 4,p->anim.GetCurrentFrame().w,p->anim.GetCurrentFrame().h }, COLLIDER_PLAYER_SHOT, this);
			p->col->to_delete = true;
			if (p->fx_played == false)
			{
				p->fx_played = true;
				// Play particle fx here
			}
		}
	}
	return UPDATE_CONTINUE;
}

void ModuleParticles::AddParticle(const Particle& particle, int x, int y, Uint32 delay)
{
	Particle* p = new Particle(particle);
	p->born = SDL_GetTicks() + delay;
	p->position.x = x;
	p->position.y = y;

	active[last_particle++] = p;
}
void ModuleParticles::AddEnemyParticle(const Particle& particle, int x, int y, Uint32 delay)
{
	Particle* p = new Particle(particle);
	p->born = SDL_GetTicks() + delay;
	p->position.x = x;
	p->position.y = y;

	p->col = App->collisions->AddCollider({ x,y - 4,p->anim.GetCurrentFrame().w,p->anim.GetCurrentFrame().h }, COLLIDER_ENEMY_SHOT, this);


	active[last_particle++] = p;
}
// -------------------------------------------------------------
// -------------------------------------------------------------

Particle::Particle()
{
	position.SetToZero();
	speed.SetToZero();
}

Particle::Particle(const Particle& p) :
	anim(p.anim), position(p.position), speed(p.speed),
	fx(p.fx), born(p.born), life(p.life)
{}

bool Particle::Update()
{
	bool ret = true;

	if (life > 0)
	{
		if ((SDL_GetTicks() - born) > life)
			ret = false;
	}
	else
		if (anim.Finished())
		{
			
			ret = false;
		}
	position.x += speed.x;
	position.y += speed.y;

	/*if (col != NULL)
		col->SetPos(position.x, position.y);*/

	return ret;
}

void ModuleParticles :: OnCollision(Collider* c1, Collider* c2)
{
	if (c1->type == COLLIDER_PLAYER_SHOT && c2->type == COLLIDER_PLAYER && App->player->collided == false)
	{

		App->player->life_score -= 16;
		App->player->collided = true;

	}
	if (c1->type == COLLIDER_PLAYER_SHOT && c2->type == COLLIDER_ENEMY && App->player2->collided == false)
	{

		App->player2->life_score -= 16;
		App->player2->collided = true;

	}
}
