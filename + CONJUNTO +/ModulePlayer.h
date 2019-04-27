#ifndef __ModulePlayer_H__
#define __ModulePlayer_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "p2Qeue.h"

#define JUMP_TIME 3000
#define PUNCH_TIME 1000

struct SDL_Texture;

enum terry_states
{
	ST_UNKNOWN,

	ST_IDLE,
	ST_WALK_FORWARD,
	ST_WALK_BACKWARD,
	ST_JUMP_NEUTRAL,
	ST_JUMP_FORWARD,
	ST_JUMP_BACKWARD,
	ST_CROUCH,
	ST_POWER_WAVE,
	ST_PUNCH_STANDING,
	ST_PUNCH_NEUTRAL_JUMP,
	ST_PUNCH_FORWARD_JUMP,
	ST_PUNCH_BACKWARD_JUMP,
	ST_PUNCH_CROUCH,
	ST_KICK_STANDING
};

struct InputP1 {
	bool A_DOWN; //LEFT
	bool S_DOWN; //CROUCH
	bool D_DOWN; //RIGHT
	bool W_DOWN; //JUMP
	bool F_DOWN; //PUNCH
	bool G_DOWN; //KICK
	bool H_DOWN; //POEWER WAVE                             ¡¡¡PROVISIONAL!!!
	/*
	bool IN_LEFT_DOWN;
	bool IN_LEFT_UP;
	bool IN_RIGHT_DOWN;
	bool IN_RIGHT_UP;
	bool IN_LEFT_AND_RIGHT;
	bool IN_JUMP;
	bool IN_CROUCH_UP;
	bool IN_CROUCH_DOWN;
	bool IN_JUMP_AND_CROUCH;
	bool IN_X;
	bool IN_JUMP_FINISH;
	bool IN_PUNCH;
	bool IN_PUNCH_FINISH;
	bool IN_KICK;
	bool IN_KICK_FINISH;
	*/
};

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	update_status PreUpdate();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

public:

	SDL_Texture* graphics = nullptr;
	SDL_Texture* graphics2 = nullptr;
	SDL_Texture* UI = nullptr;
	SDL_Rect lifebar;
	SDL_Rect life1;
	SDL_Rect life2;
	int life_score = 92;
	int font_score = -1;
	char score_text[10];
	uint score = 0;
	Animation* current_animation;
	Animation Terryidle;
	Animation TerryForward;
	Animation TerryBackwards;
	Animation TerryJump;
	Animation TerryKick;
	Animation TerryPunch;
	Animation TerryPW;


	SDL_Texture* graphicsM = nullptr;
	SDL_Texture* graphics2M = nullptr;
	Animation TerryidleM;
	Animation TerryForwardM;
	Animation TerryBackwardsM;
	Animation TerryJumpM;
	Animation TerryKickM;
	Animation TerryPunchM;
	Animation TerryPWM;
	bool mirror = false;


	iPoint Terryposition;
	Collider* col;
	Collider* colp;
	Collider* colk;

	bool gmode = false;
	bool destroyed = false;

	Uint32 jump_timer = 0;
	Uint32 punch_timer = 0;

	InputP1 inputTerry;
	terry_states currentstate;
};

#endif
