
//#if 0;
//
//#ifndef __ModulePlayer_H__
//#define __ModulePlayer_H__
//
//#include "Module.h"
//#include "Animation.h"
//#include "Globals.h"
//#include "p2Point.h"
//
//struct SDL_Texture;
//
//class ModulePlayer : public Module
//{
//public:
//	ModulePlayer();
//	~ModulePlayer();
//
//	bool Start();
//	update_status Update();
//	bool CleanUp();
//	void OnCollision(Collider* c1, Collider* c2);
//
//public:
//
//	SDL_Texture* graphics = nullptr;
//	int font_score = -1;
//	char score_text[10];
//	uint score = 0;
//	Animation terryidle;
//	Animation terryforward;
//	Animation terrybackward;
//	Animation terrykick;
//	Animation terrypunch;
//	iPoint terryposition;
//	iPoint terry2position;
//	Collider* col;
//	Collider* col2;
//	bool gmode = false;
//	bool destroyed = false;
//};
//
//#endif
//
//
//#endif;


////////#ifndef __ModulePlayer_H__
////////#define __ModulePlayer_H__
////////
////////#include "Module.h"
////////#include "Animation.h"
////////#include "Globals.h"
////////#include "p2Point.h"
////////
////////struct SDL_Texture;
////////
////////class ModulePlayer : public Module
////////{
////////public:
////////	ModulePlayer();
////////	~ModulePlayer();
////////
////////	bool Start();
////////	update_status Update();
////////
////////public:
////////
////////	SDL_Texture* graphics = nullptr;
////////	SDL_Texture* graphics2 = nullptr;
////////	Animation idle;
////////	Animation forward;
////////	Animation backward;
////////	iPoint position;
////////
////////	//////////////////// HERE ////////////////////
////////
////////	Animation TerryPunch;
////////	Animation TerryKick;
////////	Animation TerryJump;
////////	Animation TerryForward;
////////	Animation TerryBackwards;
////////	Animation Terryidle;
////////	iPoint Terryposition;
////////
////////};
////////
////////#endif


#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"

struct SDL_Texture;

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

public:

	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphics2 = nullptr;
	int font_score = -1;
	char score_text[10];
	uint score = 0;
	Animation Terryidle;
	Animation TerryForward;
	Animation TerryBackwards;
	Animation TerryJump;
	Animation TerryKick;
	Animation TerryPunch;
	Animation TerryPW;
	iPoint Terryposition;
	iPoint Terry2position;
	Collider* col;
	Collider* col2;
	bool gmode = false;
	bool destroyed = false;
};

#endif
