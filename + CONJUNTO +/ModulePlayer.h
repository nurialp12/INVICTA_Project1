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

	//TERRY-------------------------------------
	Animation Terryidle;
	Animation TerryForward;
	Animation TerryBackwards;
	Animation TerryGoingUp;
	Animation TerryGoingUpForward;
	Animation TerryGoingUpBackwards;
	Animation TerryTop;
	Animation TerryTopForward;
	Animation TerryTopBackwards;
	Animation TerryGoingDown;
	Animation TerryGoingDownForward;
	Animation TerryGoingDownBackwards;
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
	//ANDY--------------------------------------
	Animation Andyidle;
	Animation AndyForward;
	Animation AndyBackwards;
	Animation AndyGoingUp;
	Animation AndyTop;
	Animation AndyGoingDown;
	Animation AndyKick;
	Animation AndyPunch;
	Animation AndyPW;
	Animation AndyDP;
	Animation AndyDK;
	Animation AndyJumpPunch;
	Animation AndyJumpKick;
	Animation AndyCrouch;
	Animation AndyJumpForward;
	Animation AndyJumpBackwards;
	Animation AndyCrouchPunch;
	Animation AndyCrouchKick;
	//-----------------------------------------
	Animation hit;

	SDL_Texture* graphicsM = nullptr;
	SDL_Texture* graphics2M = nullptr;

	//TERRY-----------------------------------
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
	//ANDY--------------------------------------
	Animation AndyidleM;
	Animation AndyForwardM;
	Animation AndyBackwardsM;
	Animation AndyJumpM;
	Animation AndyKickM;
	Animation AndyPunchM;
	Animation AndyPWM;
	Animation AndyDPM;
	Animation AndyDKM;
	Animation AndyJumpPunchM;
	Animation AndyJumpKickM;
	Animation AndyCrouchM;
	Animation AndyJumpForwardM;
	Animation AndyJumpBackwardsM;
	Animation AndyCrouchPunchM;
	Animation AndyCrouchKickM;
	//-----------------------------------------
	Animation hitM;							

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

	bool collided = false;
	bool gmode = false;
	bool destroyed = false;

	float speed = 1.0;

	Uint32 jump_timer = 0;
	Uint32 punch_timer = 0;

	InputP1 inputTerry;
	InputP1 inputAndy;
	terry_states currentstate; //Terry and Andy's states are the same

};

#endif

