#pragma once
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

enum enemy_states
{
	ST_UNKNOWN,

	ST_IDLE,
	ST_WALK_FORWARD,
	ST_WALK_BACKWARD,
	ST_GOING_UP,
	ST_GOING_DOWN,
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
	ST_KICK_STANDING,
	ST_KICK_CROUCH,
	ST_SD
};

struct InputP1 {
	bool A_DOWN; //LEFT
	bool S_DOWN; //CROUCH
	bool D_DOWN; //RIGHT
	bool W_DOWN; //JUMP
	bool F_DOWN; //PUNCH
	bool G_DOWN; //KICK
	bool H_DOWN; //POEWER WAVE         ¡¡¡PROVISIONAL!!!
	bool SD_DOWN;
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
	float life_score = 92;
	int font_score = -1;
	char score_text[10];
	uint score = 0;
	Animation* current_animation;
	Animation Terryidle;
	Animation TerryForward;
	Animation TerryBackwards;
	Animation TerryGoingUp;
	Animation TerryTop;
	Animation TerryGoingDown;

	Animation TerryKick;
	Animation TerryPunch;
	Animation TerryPW;
	Animation TerryDP;
	Animation TerryDK;
	Animation TerryJumpPunch;
	Animation TerryJumpKick;
	Animation TerryCrouch;
	Animation TerryJumpForward;
	Animation TerryJumpBackwards;
	Animation TerryCrouchPunch;
	Animation TerryCrouchKick;
	Animation hit;

	SDL_Texture* graphicsM = nullptr;
	SDL_Texture* graphics2M = nullptr;
	Animation TerryidleM;
	Animation TerryForwardM;
	Animation TerryBackwardsM;
	Animation TerryJumpM;
	Animation TerryKickM;
	Animation TerryPunchM;
	Animation TerryPWM;
	Animation TerryDPM;
	Animation TerryDKM;
	Animation TerryJumpPunchM;
	Animation TerryJumpKickM;
	Animation TerryCrouchM;
	Animation TerryJumpForwardM;
	Animation TerryJumpBackwardsM;
	Animation TerryCrouchPunchM;
	Animation TerryCrouchKickM;
	Animation hitM;

	bool mirror = false;
	bool mirror2 = true;

	iPoint Terryposition;
	Collider* col;
	Collider* colj;
	Collider* colp;
	Collider* colk;
	Collider* colc;
	Collider* colcp;
	Collider* colck;
	Collider* coljp;
	Collider* coljk;

	bool collided = false;

	bool gmode = false;
	bool destroyed = false;

	int vy = 0;
	bool jumping = false;
	bool goingUp = false;
	bool goingDown = false;
	int t = 0;

	Uint32 jump_timer = 0;
	Uint32 punch_timer = 0;

	InputP1 inputTerry;
	terry_states currentstate;
};

#endif

