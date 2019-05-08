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

//----------------------------------------------------------------------------------------------
enum terry2_states							// ESTO ESTÁ EN ModulePlayer.h
{
	ST_UNKNOWN2,

	ST_IDLE2,
	ST_WALK_FORWARD2,
	ST_WALK_BACKWARD2,
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
	ST_KICK_CROUCH2
};

struct InputP2 {							// ESTO ESTÁ EN ModulePlayer.h
	bool LEFT_DOWN; //LEFT
	bool DOWN_DOWN; //CROUCH
	bool RIGHT_DOWN; //RIGHT
	bool UP_DOWN; //JUMP
	bool I_DOWN; //PUNCH
	bool O_DOWN; //KICK
	bool P_DOWN; //POEWER WAVE                             ¡¡¡PROVISIONAL!!!
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
//----------------------------------------------------------------------------------------------

class ModulePlayer2 : public Module
{
public:
	ModulePlayer2();
	~ModulePlayer2();

	bool Start();

	//----------------------------------------------------------------------------------------------
	update_status PreUpdate();					// ESTO ESTÁ EN ModulePlayer.h
	//----------------------------------------------------------------------------------------------

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


	//Animation* current_animation = NULL;			// ESTO ESTÁ EN ModulePlayer.h

	Animation* current_animation;


	Animation Terry2idle;
	Animation Terry2Forward;
	Animation Terry2Backwards;
	Animation Terry2Jump;
	Animation Terry2Kick;
	Animation Terry2Punch;
	Animation Terry2PW;
	Animation Terry2DP;
	Animation Terry2DK;

	//----------------------------------------------------------------------------------------------
	Animation Terry2Crouch;
	Animation Terry2JumpForward;
	Animation Terry2JumpBackwards;
	Animation Terry2CrouchPunch;
	Animation Terry2CrouchKick;
	//----------------------------------------------------------------------------------------------

	SDL_Texture* graphicsM = nullptr;
	SDL_Texture* graphics2M = nullptr;
	Animation Terry2idleM;
	Animation Terry2ForwardM;
	Animation Terry2BackwardsM;
	Animation Terry2JumpM;
	Animation Terry2KickM;
	Animation Terry2PunchM;
	Animation Terry2PWM;
	bool mirror2 = true;


	iPoint Terry2position;
	Collider* col;
	Collider* colp;
	Collider* colk;

	//----------------------------------------------------------------------------------------------
	Collider* colc;
	Collider* colcp;
	Collider* colck;
	//----------------------------------------------------------------------------------------------

	bool collided = false;
	bool gmode = false;
	bool destroyed = false;

	//----------------------------------------------------------------------------------------------
	//enum terry2_states
	//{
	//	ST_UNKNOWN,
	//
	//	ST_IDLE,
	//	ST_WALK_FORWARD,
	//	ST_WALK_BACKWARD,
	//	ST_JUMP_NEUTRAL,
	//	ST_JUMP_FORWARD,
	//	ST_JUMP_BACKWARD,
	//	ST_CROUCH,
	//	ST_PUNCH_STANDING,
	//	ST_PUNCH_NEUTRAL_JUMP,
	//	ST_PUNCH_FORWARD_JUMP,
	//	ST_PUNCH_BACKWARD_JUMP,
	//	ST_PUNCH_CROUCH
	//};

	//enum terry2_inputs
	//{
	//	IN_LEFT_DOWN,
	//	IN_LEFT_UP,
	//	IN_RIGHT_DOWN,
	//	IN_RIGHT_UP,
	//	IN_LEFT_AND_RIGHT,
	//	IN_JUMP,
	//	IN_CROUCH_UP,
	//	IN_CROUCH_DOWN,
	//	IN_JUMP_AND_CROUCH,
	//	IN_X,
	//	IN_JUMP_FINISH,
	//	IN_PUNCH_FINISH
	//};
	//----------------------------------------------------------------------------------------------

	Uint32 jump_timer = 0;
	Uint32 punch_timer = 0;

	//----------------------------------------------------------------------------------------------
	InputP2 inputTerry2;
	terry2_states currentstate;
	//----------------------------------------------------------------------------------------------

	/*bool external_input(p2Qeue<terry2_inputs>& inputs);
	void internal_input(p2Qeue<terry2_inputs>& inputs);
	terry2_states process_fsm(p2Qeue<terry2_inputs>& inputs);*/
};

#endif
