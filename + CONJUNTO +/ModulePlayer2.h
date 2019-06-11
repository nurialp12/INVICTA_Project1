#ifndef __ModulePlayer2_H__
#define __ModulePlayer2_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "p2Point.h"
#include "p2Qeue.h"

#define JUMP_TIME 3000
#define PUNCH_TIME 1000

struct SDL_Texture;

enum Andy2_states
{
	ST_UNKNOWN2,

	ST_IDLE2,
	ST_WALK_LEFT2,
	ST_WALK_RIGHT2,
	ST_GOING_UP2,
	ST_GOING_UP_FORWARD2,
	ST_GOING_UP_BACKWARD2,
	ST_TOP2,
	ST_TOP_FORWARD2,
	ST_TOP_BACKWARD2,
	ST_GOING_DOWN2,
	ST_GOING_DOWN_FORWARD2,
	ST_GOING_DOWN_BACKWARD2,
	ST_JUMP_NEUTRAL2,
	ST_JUMP_FORWARD2,
	ST_JUMP_BACKWARD2,
	ST_CROUCH2,
	ST_POWER_WAVE2,
	ST_PUNCH_STANDING2,
	ST_PUNCH_NEUTRAL_JUMP2,
	ST_PUNCH_FORWARD_JUMP2,
	ST_PUNCH_BACKWARD_JUMP2,
	ST_PUNCH_CROUCH2,
	ST_KICK_STANDING2,
	ST_KICK_CROUCH2,
	ST_SD2,
	ST_BEING_PUNCHED2,
	ST_BEING_KICKED2,
	ST_BEING_THROWN2,
	ST_THROWING2
};

struct InputP2 {
	bool J_UP;
	bool J_DOWN;
	bool J_LEFT;
	bool J_RIGHT;
	bool J_B;
	bool J_A;
	bool J_X;
	bool A_DOWN; //LEFT
	bool S_DOWN; //CROUCH
	bool D_DOWN; //RIGHT
	bool W_DOWN; //JUMP
	bool F_DOWN; //PUNCH
	bool G_DOWN; //KICK
	bool H_DOWN; //POWER WAVE         ¡¡¡PROVISIONAL!!!
	bool SD_DOWN;
};
class ModulePlayer2 : public Module 
{
public:
	ModulePlayer2();
	~ModulePlayer2();

	bool Start();
	int Score();
	update_status PreUpdate();				
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

public:
	SDL_Texture* graphics = nullptr;
	SDL_Texture* UI = nullptr;
	SDL_Rect lifebar;
	SDL_Rect life1;
	SDL_Rect life2;
	SDL_Rect lifered;
	Animation ball;
	float life_score = 92; 
	int font_score = -1;
	char score_text[10];
	int p_score = 0;
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
	bool punched = false;
	bool kicked = false;
	bool thrown = false;
	int counterdown = 0;
	int counterdownleft = 0;
	int counterdownright = 0;

	Animation LifeBlink;
	Animation AndyIdle;
	Animation AndyIdleB;
	Animation AndyForward;
	Animation AndyBackwards;
	Animation AndyGoingUp;
	Animation AndyGoingUpForward;
	Animation AndyGoingUpBackwards;
	Animation AndyTop;
	Animation AndyTopForward;
	Animation AndyTopBackwards;
	Animation AndyGoingDown;
	Animation AndyGoingDownForward;
	Animation AndyGoingDownBackwards;
	Animation AndyKick;
	Animation AndyPunch;
	Animation AndyPunchLong;
	Animation AndyPW;
	Animation AndyHeliPunch;
	Animation AndyDP;
	Animation AndyDK;
	Animation AndyJumpPunch;
	Animation AndyPunchJump;
	Animation AndyJumpKick;
	Animation AndyKickJump;
	Animation AndyCrouch;
	Animation AndyCrouchPunch;
	Animation AndyCrouchKick;
	Animation AndyFK;
	Animation AndyJumpForward;
	Animation AndyJumpBackwards;
	Animation AndyThrow;
	Animation AndyThrowing;
	Animation AndyBeingThrown;
	Animation AndyWin;
	Animation AndyGetUp;
	Animation AndyHurt;
	Animation AndyRunning;
	Animation AndyBlock;
	Animation AndyDodge;

	Animation hit;



	Animation TerryidleM;
	Animation TerryForwardM;
	Animation TerryBackwardsM;
	Animation TerryGoingUpM;
	Animation TerryTopM;
	Animation TerryGoingDownM;
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

	//-------ANDY
	Animation AndyIdleM;
	Animation AndyIdleBM;
	Animation AndyForwardM;
	Animation AndyBackwardsM;
	Animation AndyGoingUpM;
	Animation AndyGoingUpForwardM;
	Animation AndyGoingUpBackwardsM;
	Animation AndyTopM;
	Animation AndyTopForwardM;
	Animation AndyTopBackwardsM;
	Animation AndyGoingDownM;
	Animation AndyGoingDownForwardM;
	Animation AndyGoingDownBackwardsM;
	Animation AndyKickM;
	Animation AndyPunchM;
	Animation AndyPunchLongM;
	Animation AndyPWM;
	Animation AndyDPM;
	Animation AndyDKM;
	Animation AndyJumpPunchM;
	Animation AndyPunchJumpM;
	Animation AndyJumpKickM;
	Animation AndyKickJumpM;
	Animation AndyCrouchM;
	Animation AndyCrouchPunchM;
	Animation AndyCrouchKickM;
	Animation hitM;
	Animation AndyFKM;
	Animation AndyJumpForwardM;
	Animation AndyJumpBackwardsM;
	Animation AndyThrowM;
	Animation AndyThrowingM;
	Animation AndyBeingThrownM;
	Animation AndyWinM;
	Animation AndyGetUpM;
	Animation AndyHurtM;
	Animation AndyRunningM;
	Animation AndyBlockM;
	Animation AndyDodgeM;
	Animation AndyHeliPunchM;
	bool mirror2 = true;

	iPoint Andy2position;
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

	float t = 0;
	float speed = 2.0;

	Uint32 jump_timer = 0;
	Uint32 punch_timer = 0;

	InputP2 inputAndy;
	Andy2_states currentstate;
};

#endif