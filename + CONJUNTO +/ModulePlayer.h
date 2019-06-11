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
	ST_WALK_RIGHT,
	ST_WALK_LEFT,
	ST_GOING_UP,
	ST_GOING_UP_FORWARD,
	ST_GOING_UP_BACKWARD,
	ST_TOP,
	ST_TOP_FORWARD,
	ST_TOP_BACKWARD,
	ST_GOING_DOWN,
	ST_GOING_DOWN_FORWARD,
	ST_GOING_DOWN_BACKWARD,
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
	ST_SD,
	ST_BEING_PUNCHED,
	ST_BEING_KICKED,
	ST_THROW,
	ST_THROWING,
	ST_BEING_THROWN,

	ST_DOWN
	
};

struct InputP1 {
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
	bool H_DOWN; //POEWER WAVE         ¡¡¡PROVISIONAL!!!
	bool SD_DOWN;
};

class ModulePlayer : public Module
{
public:
	ModulePlayer();
	~ModulePlayer();

	bool Start();
	int Score();
	update_status PreUpdate();
	update_status Update();
	bool CleanUp();
	void OnCollision(Collider* c1, Collider* c2);

public:
	SDL_Texture* graphics = nullptr;
	SDL_Texture* UI = nullptr;
	SDL_Texture* score = nullptr;
	SDL_Rect lifebar;
	SDL_Rect life1;
	SDL_Rect life2;
	SDL_Rect lifered;
	Animation ball;
	iPoint position;
	int n[5];
	SDL_Rect r[5];
	int pastscore;
	int player;
	float life_score = 92;
	int font_score = -1;
	char score_text[10];
	int p_score = 0;
	Animation* current_animation;
	bool punched = false;
	bool kicked = false;
	bool thrown = false;
	int counterdown = 0;
	int counterdownleft = 0;
	int counterdownright = 0;
	int abs(int v) {
		if (v < 0)return -v;
	}


	//TERRY-------------------------------------
	/*Animation TerryidleM;
	Animation TerryForwardM;
	Animation TerryBackwardsM;
	Animation AndyGoingUpM;
	Animation TerryGoingUpForwardM;
	Animation TerryGoingUpBackwardsM;
	Animation TerryTopM;
	Animation TerryTopForwardM;
	Animation TerryTopBackwardsM;
	Animation TerryGoingDownM;
	Animation TerryGoingDownForwardM;
	Animation TerryGoingDownBackwardsM;
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
	Animation TerryCrouchKickM;*/
	//-----------------------------------------
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
	Animation AndyPWLong;
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



	//-----------------------------------------------


	Animation hit;

	//TERRY-----------------------------------
/*Animation TerryidleM;
	Animation TerryForwardM;
	Animation TerryBackwardsM;
	Animation AndyGoingUpM;
	Animation TerryGoingUpForwardM;
	Animation TerryGoingUpBackwardsM;
	Animation TerryTopM;
	Animation TerryTopForwardM;
	Animation TerryTopBackwardsM;
	Animation TerryGoingDownM;
	Animation TerryGoingDownForwardM;
	Animation TerryGoingDownBackwardsM;
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
	Animation TerryCrouchKickM;*/
	//-----------------------------------------
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


	//-----------------------------------------------


	bool mirror = false;
	bool mirror2 = true;

	iPoint Terryposition;
	iPoint Andyposition;

	Collider* col;
	Collider* colj;
	Collider* colp;
	Collider* colk;
	Collider* colc;
	Collider* colcp;
	Collider* colck;
	Collider* coljp;
	Collider* coljk;
	Collider* colt;
	Collider* colb;

	bool collided = false;
	bool gmode = false;
	bool destroyed = false;

	float t = 0;
	float speed = 2;

	Uint32 jump_timer = 0;
	Uint32 punch_timer = 0;
	bool invencible = false;
	int tick = 0;

	InputP1 inputAndy;
	terry_states currentstate; //Terry and Andy's states are the same
	int countpw = 0;
};

#endif

