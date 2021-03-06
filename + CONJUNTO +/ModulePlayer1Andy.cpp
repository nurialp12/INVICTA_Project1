//#if 0;

#include "Globals.h"
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModuleFadeToBlack.h"
#include "ModuleAudio.h"
#include "ModuleFonts.h"
#include "ModuleScene2.h"
#include "p2Qeue.h"
#include "SDL\include\SDL.h"
#include <stdio.h>

float stantardDMG = 11.5;
int jumpspeed = 60;
int cameraspeed = 20;
bool airkick = true;

bool up = false;
bool down = false;
bool nothing = true;

ModulePlayer::ModulePlayer()
{
	lifebar = { 15, 69, 166, 75 };
	life1 = { 10, 77, 1, 6 };
	life2 = { 11, 77, 4, 6 };
	lifered = { 42, 149, 94, 5 };

	ball.PushBack({ 86, 161, 16, 16 });
	ball.PushBack({ 54, 161, 16, 16 });
	ball.PushBack({ 86, 161, 16, 16 });
	ball.PushBack({ 70, 161, 16, 16 });
	ball.speed = 0.07f;

	//LIFE BLINK
	{
		LifeBlink.PushBack(lifered);
		LifeBlink.PushBack({ 0, 0, 1, 1 });
		LifeBlink.speed = 0.1f;
	}

	//IDLE
	{
		AndyIdle.PushBack({   0, 150, 59, 150 });
		AndyIdle.PushBack({  59, 150, 59, 150 });
		AndyIdle.PushBack({ 118, 150, 60, 150 });
		AndyIdle.PushBack({ 178, 150, 59, 150 });
		AndyIdle.PushBack({ 237, 150, 59, 150 });
		AndyIdle.speed = 0.1f;
	}
		AndyIdleB.PushBack({ 720, 0, 53, 150 });

	// WALK FORWARD animation of Andy					
	{
		AndyForward.PushBack({ 784, 150, 55, 150 });//2
		AndyForward.PushBack({ 839, 150, 60, 150 });//4
		AndyForward.PushBack({ 899, 150, 63, 150 });//3
		AndyForward.PushBack({ 962, 150, 62, 150 });//1
		AndyForward.speed = 0.05f;
	}

	// WALK BACKWARD animation of Andy					
	{
		AndyBackwards.PushBack({ 543, 150, 53, 150 });
		AndyBackwards.PushBack({ 596, 150, 61, 150 });
		AndyBackwards.PushBack({ 657, 150, 48, 150 });
		AndyBackwards.PushBack({ 705, 150, 49, 150 });
		AndyBackwards.speed = 0.05f;
	}

	// JUMP animation 						
	{
		//LAUNCH AND UP
		AndyGoingUp.PushBack({ 296, 150, 53, 150 });
		AndyGoingUp.PushBack({ 349, 150, 42, 150 });
		AndyGoingUp.speed = 0.1f;
		AndyGoingUp.loop = false;

		//AndyTop.PushBack({ 349, 150, 42, 150 });
		//AndyTop.PushBack({ 349, 150, 42, 150 });
		//AndyTop.PushBack({ 349, 150, 42, 150 });
		//AndyTop.PushBack({ 349, 150, 42, 150 });
		//AndyTop.PushBack({ 349, 150, 42, 150 });
		//AndyTop.PushBack({ 349, 150, 42, 150 });
		//AndyTop.PushBack({ 391, 150, 51, 150 });
		//AndyTop.speed = 0.1f;
		//AndyTop.loop = false;

		//GOING DOWN AND LAND
		AndyGoingDown.PushBack({ 391, 150, 51, 150 });
		AndyGoingDown.PushBack({ 442, 150, 48, 150 });
		AndyGoingDown.PushBack({ 442, 150, 48, 150 });
		AndyGoingDown.PushBack({ 442, 150, 48, 150 });
		AndyGoingDown.PushBack({ 442, 150, 48, 150 });
		AndyGoingDown.PushBack({ 442, 150, 48, 150 });
		AndyGoingDown.PushBack({ 442, 150, 48, 150 });

		AndyGoingDown.speed = 0.08f;
	}

	// KICK animation of Andy
	{
		AndyKick.PushBack({ 129, 0,  44, 150 });
		AndyKick.PushBack({ 173, 0,  56, 150 });
		AndyKick.PushBack({ 229, 0,  52, 150 });
		AndyKick.PushBack({ 281, 0, 113, 150 });
		AndyKick.PushBack({ 394, 0,  83, 150 });
		AndyKick.PushBack({ 477, 0,  53, 150 });
		AndyKick.speed = 0.1f;
	}

	//PUNCH
	{
		AndyPunch.PushBack({ 530, 0, 49, 150 });
		AndyPunch.PushBack({ 579, 0, 48, 150 });
		AndyPunch.PushBack({ 627, 0, 93, 150 });//
		AndyPunch.PushBack({ 627, 0, 93, 150 });//
		AndyPunch.PushBack({ 627, 0, 93, 150 });//
		AndyPunch.PushBack({ 579, 0, 48, 150 });
		AndyPunch.PushBack({ 579, 0, 48, 150 });
		AndyPunch.speed = 0.15f;
	}

	//CROUCH
	{
		AndyCrouch.PushBack({ 917, 0, 59, 150 });
		AndyCrouch.PushBack({ 976, 0, 48, 150 });
		AndyCrouch.speed = 0.1f;
		AndyCrouch.loop = false;
	}

	// POWER WAVE animation of Andy        ///HISHOKEN
	{
		AndyPW.PushBack({   0, 300, 65, 150 });
		AndyPW.PushBack({  65, 300, 48, 150 });
		AndyPW.PushBack({ 113, 300, 48, 150 });
		AndyPW.PushBack({ 161, 300, 98, 150 });
		AndyPW.PushBack({ 161, 300, 98, 150 });
		AndyPW.PushBack({ 161, 300, 98, 150 });
		AndyPW.PushBack({ 161, 300, 98, 150 });
		AndyPW.PushBack({ 161, 300, 98, 150 });
		AndyPW.PushBack({ 161, 300, 98, 150 });

		AndyPW.speed = 0.07f;
	}

	// HELIPUNCH        ///SHORYUDAN
	{
		AndyHeliPunch.PushBack({ 297, 0,  61, 150 });
		AndyHeliPunch.PushBack({ 358, 0,  88, 150 });
		AndyHeliPunch.PushBack({ 446, 0,  92, 150 });
		AndyHeliPunch.PushBack({ 538, 0, 110, 150 });
		AndyHeliPunch.PushBack({ 648, 0,  86, 150 });
		AndyHeliPunch.PushBack({ 734, 0,  62, 150 });
		AndyHeliPunch.PushBack({ 796, 0,  53, 150 });
		AndyHeliPunch.speed = 0.1f;
	}

	//DAMAGED BY PUNCH						 //!!!   moved
	{
		AndyDP.PushBack({ 585, 450, 62, 150 });
		AndyDP.PushBack({ 647, 450, 65, 150 });
		AndyDP.speed = 0.1f;
	}

	//DAMAGED BY KICK						 //!!!   moved
	{
		AndyDK.PushBack({ 712, 450, 54, 150 });
		AndyDK.PushBack({ 766, 450, 64, 150 }); //830
		AndyDK.speed = 0.1f;
	}

	
	//JUMPFORWARD
	{
		AndyGoingUpForward.PushBack({ 592, 900, 53, 150 });//CROUNCH				!!!
		AndyGoingUpForward.PushBack({ 645, 900, 55, 150 });//GOING UP
		AndyGoingUpForward.speed = 0.08f;
		AndyGoingUpForward.loop = false;

		AndyGoingDownForward.PushBack({ 700, 900, 67, 150 });//GOING DOWN
		AndyGoingDownForward.PushBack({ 767, 900, 67, 150 });//GOING DOWN
		AndyGoingDownForward.PushBack({ 834, 900, 67, 150 });//GOING DOWN
		AndyGoingDownForward.PushBack({ 901, 900, 48, 150 });//CROUCH				!!!
		AndyGoingDownForward.speed = 0.1f;
		//AndyGoingDownForward.loop = false;
	}
	/*
	//JUMP BACKWARDS
	{
		AndyJumpBackwards.PushBack({ 901, 900, 48, 150 });//949
		AndyJumpBackwards.PushBack({ 834, 900, 67, 150 });
		AndyJumpBackwards.PushBack({ 767, 900, 67, 150 });
		AndyJumpBackwards.PushBack({ 700, 900, 67, 150 });
		AndyJumpBackwards.PushBack({ 645, 900, 55, 150 });
		AndyJumpBackwards.speed = 0.1f;
	}*/
	//JUMPBACKWARDS
	{
		AndyGoingUpBackwards.PushBack({ 592, 900, 53, 150 });
		AndyGoingUpBackwards.PushBack({ 901, 900, 48, 150 });//CROUCH				!!!
		AndyGoingUpBackwards.speed = 0.08f;
		AndyGoingUpBackwards.loop = false;

		AndyGoingDownBackwards.PushBack({ 834, 900, 67, 150 });//GOING DOWN
		AndyGoingDownBackwards.PushBack({ 767, 900, 67, 150 });//GOING DOWN
		AndyGoingDownBackwards.PushBack({ 700, 900, 67, 150 });//GOING DOWN
		AndyGoingDownBackwards.PushBack({ 645, 900, 55, 150 });//GOING UP
		AndyGoingDownBackwards.speed = 0.1f;
		//AndyGoingDownBackwards.loop = false;
	}

	//CROUCHPUNCH
	{
		AndyCrouchPunch.PushBack({ 624, 600, 49, 150 }); //Charge
		AndyCrouchPunch.PushBack({ 673, 600, 78, 150 }); //Riposte //751
		AndyCrouchPunch.speed = 0.1f;
	}

	//CROUCHKICK
	{
		AndyCrouchKick.PushBack({   0, 600,  79, 150 });   //Charge
		AndyCrouchKick.PushBack({  79, 600,  79, 150 });  //Riposte
		AndyCrouchKick.PushBack({ 158, 600, 119, 150 }); //Punch
		AndyCrouchKick.PushBack({  79, 600,  79, 150 });
		AndyCrouchKick.PushBack({   0, 600,  79, 150 });
		AndyCrouchKick.speed = 0.1f;
	}
	////JUMPPUNCH
	//AndyJumpPunch.PushBack({ 488, 789, 44, 112 }); //Charge
	//AndyJumpPunch.PushBack({ 544, 805, 68,  96 });   //Punch
	//AndyJumpPunch.PushBack({ 802,   0, 57, 123 });     //Land

	////JUMPKICK
	//AndyJumpKick.PushBack({ 304, 830, 56,  70 });  //Charge
	//AndyJumpKick.PushBack({ 376, 789, 78, 111 }); //Kick
	//AndyJumpKick.PushBack({ 304, 830, 56,  70 });  //Discharge
	//AndyJumpKick.PushBack({ 802,   0, 57, 123 });   //Land

		//hit particle animation
	hit.PushBack({ 671, 263, 22, 33 });
	hit.PushBack({ 690, 263, 24, 33 });
	hit.PushBack({ 721, 263, 32, 33 });
	hit.PushBack({ 757, 263, 32, 33 });
	hit.speed = 0.5f;



	//N�RIA -----------------------------------------------

	//FLYING KICK        ///KUHADAN
	{
		AndyFK.PushBack({ 0, 0,  61, 150 });
		AndyFK.PushBack({ 86, 0,  88, 150 });
		AndyFK.PushBack({ 166, 0,  92, 150 });
		AndyFK.PushBack({ 224, 0, 110, 150 });
		AndyFK.PushBack({ 311, 0,  86, 150 });
		AndyFK.PushBack({ 430, 0,  62, 150 });
		AndyFK.PushBack({ 555, 0,  53, 150 });
		AndyFK.PushBack({ 555, 0,  53, 150 });
		AndyFK.speed = 0.1f;
	}



	//THROW ---- SPRITES NEEDED KAWWAKS
	{
		AndyThrow.PushBack({ 105, 1200, 58, 150 });
		AndyThrow.PushBack({ 163, 1200, 72, 150 });
		AndyThrow.PushBack({ 163, 1200, 72, 150 });
		AndyThrow.PushBack({ 105, 1200, 58, 150 });
		AndyThrow.speed = 0.01f;
	}

	//THROWING ---- SPRITES NEEDED KAWWAKS
	{
		AndyThrowing.PushBack({ 0, 0, 0, 0 });
		AndyThrowing.speed = 0.1f;
	}

	//BEING THROWN ---- SPRITES NEEDED KAWWAKS
	{
		AndyBeingThrown.PushBack({ 0, 0, 0, 0 });
		AndyBeingThrown.speed = 0.1f;
	}
	//WIN ---- SPRITES NEEDED KAWWAKS
	{
		AndyWin.PushBack({ 0, 0, 0, 0 });
		AndyWin.speed = 0.1f;
	}

	//GET UP ---- SPRITES NEEDED KAWWAKS
	{
		AndyGetUp.PushBack({ 0, 0, 0, 0 });
		AndyGetUp.speed = 0.1f;
	}

	//JUMP + PUNCH
	{
		AndyJumpPunch.PushBack({ 170, 750, 62, 150 });
		AndyJumpPunch.PushBack({ 232, 750, 79, 150 });//311
		AndyJumpPunch.speed = 0.1f;
	}

	//KICK + JUMP
	{
		AndyKickJump.PushBack({ 277, 600,  50, 150 });
		AndyKickJump.PushBack({ 327, 600,  56, 150 });
		AndyKickJump.PushBack({ 383, 600,  94, 150 });//477
		AndyKickJump.speed = 0.1f;
	}

	//JUMP + KICK
	{
		AndyJumpKick.PushBack({ 477, 600,  55, 150 });
		AndyJumpKick.PushBack({ 532, 600,  92, 150 });//624
		AndyJumpKick.speed = 0.1f;
	}

	//PUNCH + JUMP
	{
		AndyPunchJump.PushBack({   0, 750, 50, 150 });
		AndyPunchJump.PushBack({  50, 750, 66, 150 });
		AndyPunchJump.PushBack({ 116, 750, 54, 150 });//170
		AndyPunchJump.speed = 0.1f;
	}

	//HURT
	{
		AndyHurt.PushBack({ 311, 750,  91, 150 });
		AndyHurt.PushBack({ 402, 750,  98, 150 });
		AndyHurt.PushBack({ 500, 750,  88, 150 });
		AndyHurt.PushBack({ 588, 750,  99, 150 });
		AndyHurt.PushBack({ 687, 750, 111, 150 });
		AndyHurt.PushBack({ 798, 750, 108, 150 });//906
		AndyHurt.speed = 0.1f;
	}

	//RUNNING        ///ZAINEKEN
	{
		AndyRunning.PushBack({   0, 450,  53, 150 });
		AndyRunning.PushBack({  53, 450,  59, 150 });
		AndyRunning.PushBack({ 112, 450,  55, 150 });
		AndyRunning.PushBack({ 167, 450,  57, 150 });
		AndyRunning.PushBack({ 224, 450,  57, 150 });//SE SUPERPONEN
		AndyRunning.PushBack({ 281, 450,  75, 150 });
		AndyRunning.PushBack({ 356, 450,  89, 150 });
		AndyRunning.PushBack({ 445, 450,  87, 150 });
		AndyRunning.PushBack({ 532, 450,  53, 150 });//585
		AndyRunning.speed = 0.1f;
	}

	//BLOCK ---- SPRITES NEEDED KAWWAKS
	{
		AndyBlock.PushBack({ 0, 0,  61, 50 });
		AndyBlock.speed = 0.1f;
	}

	//DODGE ---- SPRITES NEEDED KAWWAKS
	{
		AndyDodgeM.PushBack({ 1207, 1200,  61, 150 });
		AndyDodgeM.PushBack({ 1146, 1200,  61, 150 });
		AndyDodgeM.PushBack({ 1024, 1200,  61, 150 });
		AndyDodgeM.speed = 0.1f;
	}

	//------------------------------------------------------------


//MIRROR -----------------------------------------------------------------------------------------				
	{
		//IDLE--------------------------IMPL 
		AndyIdleM.PushBack({ 1748, 150, 60, 150 });
		AndyIdleM.PushBack({ 1808, 150, 60, 150 });
		AndyIdleM.PushBack({ 1868, 150, 60, 150 });
		AndyIdleM.PushBack({ 1928, 150, 60, 150 });
		AndyIdleM.PushBack({ 1988, 150, 60, 150 });
		AndyIdleM.speed = 0.1f;

		AndyIdleBM.PushBack({ 1025, 150, 60, 150 });

		// WALK FORWARD--------------------------IMPL 
		AndyForwardM.PushBack({ 1441, 150, 63, 150 });
		AndyForwardM.PushBack({ 1378, 150, 63, 150 });
		AndyForwardM.PushBack({ 1315, 150, 63, 150 });
		AndyForwardM.PushBack({ 1252, 150, 63, 150 });
		AndyForwardM.speed = 0.05f;

		// WALK BACKWARDS--------------------------IMPL 
		AndyBackwardsM.PushBack({ 1504, 150, 61, 150 });
		AndyBackwardsM.PushBack({ 1565, 150, 61, 150 });
		AndyBackwardsM.PushBack({ 1626, 150, 61, 150 });
		AndyBackwardsM.PushBack({ 1687, 150, 61, 150 });
		AndyBackwardsM.speed = 0.05f;

		// JUMP 
		{
			//LAUNCH AND UP
			AndyGoingUpM.PushBack({ 1331/*1716*/, 300/*800*/, 53, 150 });
			AndyGoingUpM.PushBack({ 1278/*1663*/, 300/*800*/, 53, 150 });
			AndyGoingUpM.speed = 0.1f/*0.05f*/;
			AndyGoingUpM.loop = false;

			//GOING DOWN AND LAND
			AndyGoingDownM.PushBack({ 1225/*1610*/, 300/*800*/, 53, 150 });
			AndyGoingDownM.PushBack({ 1172/*1557*/, 300/*800*/, 53, 150 });
			AndyGoingDownM.PushBack({ 1172/*1557*/, 300/*800*/, 53, 150 });
			AndyGoingDownM.PushBack({ 1172/*1557*/, 300/*800*/, 53, 150 });
			AndyGoingDownM.PushBack({ 1172/*1557*/, 300/*800*/, 53, 150 });
			AndyGoingDownM.PushBack({ 1172/*1557*/, 300/*800*/, 53, 150 });
			AndyGoingDownM.PushBack({ 1172/*1557*/, 300/*800*/, 53, 150 });
			AndyGoingDownM.speed = 0.08f/*0.05f*/;
		}

		//KICK--------------------------IMPL 
		{
			AndyKickM.PushBack({ 1709, 0, 113, 150 });
			AndyKickM.PushBack({ 1596, 0, 113, 150 });
			AndyKickM.PushBack({ 1483, 0, 113, 150 });
			AndyKickM.PushBack({ 1370, 0, 113, 150 });
			AndyKickM.PushBack({ 1257, 0, 113, 150 });
			AndyKickM.PushBack({ 1144, 0, 113, 150 });
			AndyKickM.speed = 0.1f;
		}

		//PUNCH--------------------------IMPL 
		{
			AndyPunchM.PushBack({ 1955, 1800, 93, 150 });
			AndyPunchM.PushBack({ 1862, 1800, 93, 150 });
			AndyPunchM.PushBack({ 1769, 1800, 93, 150 });//
			AndyPunchM.PushBack({ 1769, 1800, 93, 150 });//
			AndyPunchM.PushBack({ 1769, 1800, 93, 150 });//
			AndyPunchM.PushBack({ 1862, 1800, 93, 150 });
			AndyPunchM.PushBack({ 1862, 1800, 93, 150 });
			AndyPunchM.speed = 0.15f;
		}


		// POWER WAVE animation of Andy        ///HISHOKEN--------------------------IMPL 
		{
			AndyPWM.PushBack({ 1876, 300, 98, 150 });
			AndyPWM.PushBack({ 1778, 300, 98, 150 });
			AndyPWM.PushBack({ 1680, 300, 98, 150 });
			AndyPWM.PushBack({ 1582, 300, 98, 150 });
			AndyPWM.speed = 0.07f;
		}

		//DAMAGED BY PUNCH--------------------------IMPL 
		AndyDPM.PushBack({ 1983, 1650, 65, 150 });
		AndyDPM.PushBack({ 1918, 1650, 65, 150 });
		AndyDPM.speed = 0.1f;

		//DAMAGED BY KICK--------------------------IMPL 
		AndyDKM.PushBack({ 1854, 1650, 64, 150 });
		AndyDKM.PushBack({ 1790, 1650, 64, 150 });
		AndyDKM.speed = 0.1f;

		//CROUCH--------------------------IMPL 
		AndyCrouchM.PushBack({ 1083, 0, 59, 150 });
		AndyCrouchM.PushBack({ 1024, 0, 59, 150 });
		AndyCrouchM.speed = 0.2f;
		AndyCrouchM.loop = false;

		//JUMPFORWARD
	

		//JUMPBACKWARDS
		

		//CROUCHPUNCH
		{
			AndyCrouchPunchM.PushBack({ 1102, 600, 78, 150 }); //Charge
			AndyCrouchPunchM.PushBack({ 1024, 600, 78, 150 }); //Riposte //751
			AndyCrouchPunchM.speed = 0.1f;
		}

		//CROUCHKICK--------------------------IMPL 
		AndyCrouchKickM.PushBack({ 1884, 600, 119, 150 });   //Charge
		AndyCrouchKickM.PushBack({ 1765, 600, 119, 150 });  //Riposte
		AndyCrouchKickM.PushBack({ 1246, 600, 119, 150 }); //Punch
		AndyCrouchKickM.PushBack({ 1765, 600, 119, 150 });
		AndyCrouchKickM.PushBack({ 1884, 600, 119, 150 });
		AndyCrouchKickM.speed = 0.1f;

		//JUMPPUNCH
		AndyJumpPunchM.PushBack({ 488, 789, 44, 112 }); //Charge
		AndyJumpPunchM.PushBack({ 544, 805, 68,  96 }); //Punch
		AndyJumpPunchM.PushBack({ 802,   0, 57, 123 }); //Land

		//JUMPKICK
		AndyJumpKickM.PushBack({ 304, 830, 56,  70 });  //Charge
		AndyJumpKickM.PushBack({ 376, 789, 78, 111 });  //Kick
		AndyJumpKickM.PushBack({ 304, 830, 56,  70 });  //Discharge
		AndyJumpKickM.PushBack({ 802,   0, 57, 123 });  //Land

				//hit particle animation
		hitM.PushBack({ 671, 263, 22, 33 });
		hitM.PushBack({ 690, 263, 24, 33 });
		hitM.PushBack({ 721, 263, 32, 33 });
		hitM.PushBack({ 757, 263, 32, 33 });
		hitM.speed = 0.5f;

		//N�RIA -----------------------------------------------

		//FLYING KICK        ///KUHADAN
		{
			AndyFKM.PushBack({   0, 0,  61, 150 });
			AndyFKM.PushBack({  86, 0,  88, 150 });
			AndyFKM.PushBack({ 166, 0,  92, 150 });
			AndyFKM.PushBack({ 224, 0, 110, 150 });
			AndyFKM.PushBack({ 311, 0,  86, 150 });
			AndyFKM.PushBack({ 430, 0,  62, 150 });
			AndyFKM.PushBack({ 555, 0,  53, 150 });
			AndyFKM.PushBack({ 555, 0,  53, 150 });
			AndyFKM.speed = 0.1f;
		}

		//THROW ---- SPRITES NEEDED KAWWAKS
		{
			AndyThrowM.PushBack({ 1977, 0, 71, 150 });
			AndyThrowM.PushBack({ 1864, 0, 71, 150 });
			AndyThrowM.PushBack({ 1977, 0, 71, 150 });
			AndyThrowM.speed = 0.1f;
		}

		//THROWING ---- SPRITES NEEDED KAWWAKS
		{
			AndyThrowingM.PushBack({ 0, 0, 0, 0 });
			AndyThrowingM.speed = 0.1f;
		}

		//BEING THROWN ---- SPRITES NEEDED KAWWAKS
		{
			AndyBeingThrownM.PushBack({ 0, 0, 0, 0 });
			AndyBeingThrownM.speed = 0.1f;
		}
		//WIN ---- SPRITES NEEDED KAWWAKS ------------------ IMPL
		{
			AndyWinM.PushBack({ 1993, 1200, 55, 150 });
			AndyWinM.PushBack({ 1938, 1200, 55, 150 });
			AndyWinM.speed = 0.1f;
		}

		//GET UP ---- SPRITES NEEDED KAWWAKS --------------- IMPL
		{
			AndyGetUpM.PushBack({ 1285, 1350, 87, 150 });
			AndyGetUpM.PushBack({ 1198, 1350, 87, 150 });
			AndyGetUpM.PushBack({ 1111, 1350, 87, 150 });
			AndyGetUpM.PushBack({ 1058, 1350, 87, 150 });
			AndyGetUpM.speed = 0.1f;
		}

		//JUMP + PUNCH
		{
			AndyJumpPunchM.PushBack({ 170, 750, 62, 150 });
			AndyJumpPunchM.PushBack({ 232, 750, 79, 150 });//311
			AndyJumpPunchM.speed = 0.1f;
		}

		//KICK + JUMP
		{
			AndyKickJumpM.PushBack({ 277, 600,  50, 150 });
			AndyKickJumpM.PushBack({ 327, 600,  56, 150 });
			AndyKickJumpM.PushBack({ 383, 600,  94, 150 });//477
			AndyKickJumpM.speed = 0.1f;
		}

		//JUMP + KICK
		{
			AndyJumpKickM.PushBack({ 477, 600,  55, 150 });
			AndyJumpKickM.PushBack({ 532, 600,  92, 150 });//624
			AndyJumpKickM.speed = 0.1f;
		}

		//PUNCH + JUMP
		{
			AndyPunchJumpM.PushBack({ 0, 750, 50, 150 });
			AndyPunchJumpM.PushBack({ 50, 750, 66, 150 });
			AndyPunchJumpM.PushBack({ 116, 750, 54, 150 });//170
			AndyPunchJumpM.speed = 0.1f;
		}

		//HURT
		{
			AndyHurtM.PushBack({ 311, 750,  91, 150 });
			AndyHurtM.PushBack({ 402, 750,  98, 150 });
			AndyHurtM.PushBack({ 500, 750,  88, 150 });
			AndyHurtM.PushBack({ 588, 750,  99, 150 });
			AndyHurtM.PushBack({ 687, 750, 111, 150 });
			AndyHurtM.PushBack({ 798, 750, 108, 150 });//906
			AndyHurtM.speed = 0.1f;
		}

		//RUNNING        ///ZAINEKEN--------------------------IMPL 
		{
			AndyRunningM.PushBack({ 1921, 450,  89, 150 });
			AndyRunningM.PushBack({ 1832, 450,  89, 150 });
			AndyRunningM.PushBack({ 1743, 450,  89, 150 });
			AndyRunningM.PushBack({ 1654, 450,  89, 150 });
			AndyRunningM.PushBack({ 1565, 450,  89, 150 });//SE SUPERPONEN
			AndyRunningM.PushBack({ 1476, 450,  89, 150 });
			AndyRunningM.PushBack({ 1387, 450,  89, 150 });
			AndyRunningM.PushBack({ 1298, 450,  89, 150 });
			AndyRunningM.PushBack({ 1209, 450,  89, 150 });//585
			AndyRunningM.speed = 0.1f;
		}

		//BLOCK ---- SPRITES NEEDED KAWWAKS
		{
			AndyBlockM.PushBack({ 0, 0,  61, 50 });
			AndyBlockM.speed = 0.1f;
		}

		//DODGE--------------------------IMPL 
		{
			AndyDodgeM.PushBack({ 1207, 449,  61, 150 });
			AndyDodgeM.PushBack({ 1146, 449,  61, 150 });
			AndyDodgeM.PushBack({ 1024, 449,  61, 150 });
			AndyDodgeM.speed = 0.1f;
		}

		//------------------------------------------------------------


	}
}

ModulePlayer::~ModulePlayer()
{}

// Load assets
bool ModulePlayer::Start()
{
	LOG("Loading player");
	bool ret = true;
	graphics = App->textures->Load("Assets/Sprites/Sprites_AndyBogard_ok.png");

	UI = App->textures->Load("Assets/Sprites/UI.png");

	destroyed = false;
	Andyposition.x = 5 + (250)								/*uncomment for full screen*/-100;
	Andyposition.y = 60;
	score = 0;
	col   = App->collisions->AddCollider({  -30, Andyposition.y + 50, 31, 101 }, COLLIDER_PLAYER, App->player);
	colc  = App->collisions->AddCollider({    0, 10000, 31, 60 }, COLLIDER_PLAYER, App->player);
	colj  = App->collisions->AddCollider({    0, 10000, 31, 60 }, COLLIDER_PLAYER, App->player);
	colcp = App->collisions->AddCollider({ 1000, 10000, 25, 20 }, COLLIDER_PLAYER_SHOT, App->player);
	colck = App->collisions->AddCollider({ 1000, 10000, 40, 20 }, COLLIDER_PLAYER_SHOT, App->player);
	colt  = App->collisions->AddCollider({ 1000, 10000, 50, 50 }, COLLIDER_PLAYER_SHOT, App->player);
	currentstate = ST_IDLE;
	current_animation = &AndyIdle;

	font_score = App->fonts->Load("Assets/Sprites/fonts/scorenums.png", "1234567890", 1);
	return ret;
}

// Unload assets
bool ModulePlayer::CleanUp()
{
	LOG("Unloading player");

	App->textures->Unload(graphics);

	App->fonts->UnLoad(font_score);
	if (col)
		col->to_delete = true;
	if(colj)
		colj->to_delete = true;
	if(colc)
		colc->to_delete = true;
	return true;
}

update_status ModulePlayer::PreUpdate()
{
	inputAndy.J_RIGHT = SDL_GameControllerGetAxis(App->input->gController1, SDL_CONTROLLER_AXIS_LEFTX) > JOYSTICK_DEAD_ZONE;
	inputAndy.J_LEFT = SDL_GameControllerGetAxis(App->input->gController1, SDL_CONTROLLER_AXIS_LEFTX) < -JOYSTICK_DEAD_ZONE;
	inputAndy.J_UP = SDL_GameControllerGetAxis(App->input->gController1, SDL_CONTROLLER_AXIS_LEFTY) < -JOYSTICK_DEAD_ZONE;
	inputAndy.J_DOWN = SDL_GameControllerGetAxis(App->input->gController1, SDL_CONTROLLER_AXIS_LEFTY) > JOYSTICK_DEAD_ZONE;
	inputAndy.J_B = App->input->gpad[SDL_CONTROLLER_BUTTON_B][1] == KEY_DOWN;
	inputAndy.J_A = App->input->gpad[SDL_CONTROLLER_BUTTON_A][1] == KEY_DOWN;
	

	SDL_Event event;
	while (SDL_PollEvent(&event) != 0)
	{
		if (event.type == SDL_KEYUP && event.key.repeat == 0)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				break;
			case SDLK_DOWN:
				break;
			case SDLK_UP:
				break;
			case SDLK_LEFT:
				break;
			case SDLK_RIGHT:
				break;
			}
		}
		if (event.type == SDL_KEYDOWN && event.key.repeat == 0)
		{
			switch (event.key.keysym.sym)
			{
			case SDLK_SPACE:
				break;
			case SDLK_UP:
				break;
			case SDLK_DOWN:
				break;
			case SDLK_LEFT:
				break;
			case SDLK_RIGHT:
				break;
			}
		}
	}
	return UPDATE_CONTINUE;
}

update_status ModulePlayer::Update()
{
	// MIRROR
	if (App->player2->col->rect.x < App->player->col->rect.x ||
		App->player2->colc->rect.x < App->player->col->rect.x ||
		App->player2->colj->rect.x < App->player->col->rect.x ||
		App->player2->col->rect.x < App->player->colc->rect.x ||
		App->player2->colj->rect.x < App->player->colc->rect.x ||
		App->player2->col->rect.x < App->player->colj->rect.x ||
		App->player2->colc->rect.x < App->player->colj->rect.x ||
		App->player2->colj->rect.x < App->player->colj->rect.x)
		mirror = true;
	else mirror = false;

	//HADOUKEN
	if (counterdown < 0)
		counterdown = 0;
	if (counterdownleft < 0)
		counterdownleft = 0;
	if (counterdownright < 0)
		counterdownright = 0;

	if (currentstate == ST_IDLE)
		if (inputAndy.J_DOWN || App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_DOWN)
			counterdown = 20;
	counterdown--;
	if (currentstate == ST_CROUCH && mirror && counterdown > 0)
	{
		if ((inputAndy.J_DOWN && inputAndy.J_LEFT) || (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN))
		{
			counterdownleft = 20;
		}
	}
	else if (currentstate == ST_CROUCH && counterdown > 0)
	{
		if ((inputAndy.J_DOWN && inputAndy.J_RIGHT) || (App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT && App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_DOWN))
		{
			counterdownright = 20;
		}
	}
	counterdownleft--;
	counterdownright--;

	if ((currentstate == ST_CROUCH && counterdownleft > 0 || counterdownright > 0) && (App->input->keyboard[SDL_SCANCODE_F] == KEY_STATE::KEY_REPEAT || inputAndy.J_B))
	{
		currentstate = ST_POWER_WAVE;
		current_animation = &AndyPW;
		App->audio->PlayFX("Assets/FX/Voice/Special Attacks/FX_HishokenAttackAndyBogardVoice/FX_HishokenAttackAndyBogardVoice.wav");
		colc->rect.y = 10000;
		if (!gmode)
			col->rect.y = Andyposition.y + 50;
	}
	if (AndyPW.Finished() == true)
	{
		Uint32 inittime = 200;
		if (SDL_GetTicks() >= inittime && counterdownright && !mirror)
		{
			App->particles->AddParticle(App->particles->andyenergy, Andyposition.x + 60, Andyposition.y + 12);
			App->particles->andyenergy.speed.x = 2;
		}
		else if (SDL_GetTicks() >= inittime && counterdownleft && mirror)
		{
			App->particles->AddParticle(App->particles->andyenergy, Andyposition.x - 10, Andyposition.y + 12);
			App->particles->andyenergy.speed.x = -2;
		}
		AndyPW.resetLoops(0);
		if (inputAndy.J_RIGHT || App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
		{
			currentstate = ST_WALK_RIGHT;
			current_animation = &AndyForward;
		}
		else if (inputAndy.J_LEFT || App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
		{
			currentstate = ST_WALK_LEFT;
			current_animation = &AndyBackwards;
		}
		else
		{
			currentstate = ST_IDLE;
			current_animation = &AndyIdle;
		}
		if (inputAndy.J_DOWN || App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
		{
			col->rect.y = 10000;
			if (!gmode)
				colc->rect.y = Andyposition.y + 91;
		}
		AndyPW.resetLoops(0);
	}


	//IDLE
	if (currentstate == ST_IDLE)
	{
		if (mirror) 
		{
			if (Andyposition.x - App->player2->Andy2position.x <= 70) current_animation = &AndyIdleBM;
			else current_animation = &AndyIdleM;
		}
		else
		{
			if (App->player2->Andy2position.x - Andyposition.x <= 70) current_animation = &AndyIdleB;
			else current_animation = &AndyIdle;
		}
	}

	//MOVE RIGHT						CAMERA FIX NEEDED
	{
		if ((inputAndy.J_RIGHT || App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_DOWN) && currentstate == ST_IDLE)
		{
			currentstate = ST_WALK_RIGHT;
			if(mirror) colb = App->collisions->AddCollider({ Andyposition.x + 31, Andyposition.y + 50, 10, 70 }, COLLIDER_WALL, App->player);
		}
		if ((inputAndy.J_RIGHT || App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT) && currentstate == ST_WALK_RIGHT)
		{
			if (mirror)
			{
				current_animation = &AndyBackwardsM;
				if (Andyposition.x < 700 && App->player2->Andy2position.x + SCREEN_WIDTH - 60 > Andyposition.x) Andyposition.x ++;
			}
			else
			{
				current_animation = &AndyForward;
				if (Andyposition.x < 700 && App->player2->Andy2position.x + SCREEN_WIDTH - 60 > Andyposition.x)	Andyposition.x += 2;
			}
		}
	
		if (App->input->gController1 != NULL)
		{
			if ((!inputAndy.J_RIGHT || App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_UP) && currentstate == ST_WALK_RIGHT)
			{
				if (colb) colb->to_delete = true;
				AndyForward.resetLoops(0);
				AndyForwardM.resetLoops(0);
				if (inputAndy.J_LEFT || App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
				{
					currentstate = ST_WALK_LEFT;
					if (!mirror) colb = App->collisions->AddCollider({ Andyposition.x + 31, Andyposition.y + 50, 10, 70 }, COLLIDER_WALL, App->player);
				}
				else
					currentstate = ST_IDLE;
			}
		}
		else
		{
			if (App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_UP && currentstate == ST_WALK_RIGHT)
			{
				if(colb) colb->to_delete = true;
				AndyForward.resetLoops(0);
				AndyForwardM.resetLoops(0);
				if (inputAndy.J_LEFT || App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
				{
					currentstate = ST_WALK_LEFT;
					if (!mirror) colb = App->collisions->AddCollider({ Andyposition.x + 31, Andyposition.y + 50, 10, 70 }, COLLIDER_WALL, App->player);
				}
				else
					currentstate = ST_IDLE;
			}
		}
	}

	//MOVE LEFT						CAMERA FIX NEEDED
	{
		if ((inputAndy.J_LEFT || App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_DOWN) && currentstate == ST_IDLE)
		{
			currentstate = ST_WALK_LEFT;
			if (!mirror) colb = App->collisions->AddCollider({ Andyposition.x + 31, Andyposition.y + 50, 10, 70 }, COLLIDER_WALL, App->player);
		}
		if ((inputAndy.J_LEFT || App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT) && currentstate == ST_WALK_LEFT)
		{
			if (mirror)
			{
				current_animation = &AndyForwardM;
				if (Andyposition.x > 0 && App->player2->Andy2position.x - SCREEN_WIDTH + 60 < Andyposition.x) Andyposition.x -= 2;
			}
			else
			{
				current_animation = &AndyBackwards;
				if (Andyposition.x > 0 && App->player2->Andy2position.x - SCREEN_WIDTH + 60 < Andyposition.x)
					Andyposition.x--;
			}
		}

		if (App->input->gController1 != NULL)
		{
			if ((!inputAndy.J_LEFT || App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_UP) && currentstate == ST_WALK_LEFT)
			{
				if (colb) colb->to_delete = true;
				AndyForward.resetLoops(0);
				AndyForwardM.resetLoops(0);
				if (inputAndy.J_RIGHT || App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
					currentstate = ST_WALK_RIGHT;
				else
					currentstate = ST_IDLE;
			}
		}
		else
		{
			if (App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_UP && currentstate == ST_WALK_LEFT)
			{
				if (colb) colb->to_delete = true;
				AndyForward.resetLoops(0);
				AndyForwardM.resetLoops(0);
				if (inputAndy.J_RIGHT || App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
				{
					currentstate = ST_WALK_RIGHT;
					if (mirror) colb = App->collisions->AddCollider({ Andyposition.x + 31, Andyposition.y + 50, 10, 70 }, COLLIDER_WALL, App->player);
				}
				else
					currentstate = ST_IDLE;
			}
		}
		
	}

	//JUMP
	{
		if ((inputAndy.J_UP || App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_DOWN) && currentstate == ST_IDLE)
		{
			currentstate = ST_GOING_UP;
			col->rect.y = Andyposition.y + 10000;
			if (!gmode) colj->rect.y = Andyposition.y + 50;
		}
		if (currentstate == ST_GOING_UP)
		{
			if(!gmode) colj->rect.y = Andyposition.y + 50;
			if (mirror)current_animation = &AndyGoingUpM;
			else current_animation = &AndyGoingUp;
			t += 0.002;
			speed += t;
			if (Andyposition.y > 10) { Andyposition.y = Andyposition.y - 3 * speed;	App->render->camera.y = App->render->camera.y - speed; }
			else { Andyposition.y = Andyposition.y - 3 * speed / 2; App->render->camera.y = App->render->camera.y + speed; }
			if (Andyposition.y <= 30) currentstate = ST_TOP;
		}
		if (currentstate == ST_TOP)
		{
			if(!gmode) colj->rect.y = Andyposition.y + 50;

			t += 0.005;
			speed -= t;
			Andyposition.y = Andyposition.y - 3 * speed;
			App->render->camera.y = App->render->camera.y + speed;
			if (Andyposition.y <= -40) currentstate = ST_GOING_DOWN;
		}
		if (currentstate == ST_GOING_DOWN)
		{
			if (mirror) current_animation = &AndyGoingDownM;
			else current_animation = &AndyGoingDown;

			AndyGoingUp.resetLoops(0);
			AndyGoingUpM.resetLoops(0);

			if(!gmode) colj->rect.y = Andyposition.y + 85;

			t += 0.002;
			speed -= t;
			Andyposition.y = Andyposition.y - 3 * speed;
			if (Andyposition.y > 20) { Andyposition.y = Andyposition.y - 3 * speed; App->render->camera.y = App->render->camera.y + speed; }
			else { Andyposition.y = Andyposition.y - 3 * speed / 2; App->render->camera.y = App->render->camera.y + speed; }
			if (App->render->camera.y <= -10)
				App->render->camera.y = -10;

			if (Andyposition.y >= 60)
			{
				Andyposition.y = 60;
				if (inputAndy.J_LEFT || App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
				{
					currentstate = ST_WALK_LEFT;
					if (!mirror) colb = App->collisions->AddCollider({ Andyposition.x + 31, Andyposition.y + 50, 10, 70 }, COLLIDER_WALL, App->player);
					if (mirror)current_animation = &AndyForwardM;
					else current_animation = &AndyBackwards;
				}
				else if (inputAndy.J_RIGHT || App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
				{
					currentstate = ST_WALK_RIGHT;
					if (mirror) colb = App->collisions->AddCollider({ Andyposition.x + 31, Andyposition.y + 50, 10, 70 }, COLLIDER_WALL, App->player);
					if (mirror)current_animation = &AndyBackwardsM;
					else current_animation = &AndyForward;
				}
				else if (inputAndy.J_DOWN || App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
				{
					currentstate = ST_CROUCH;
					if (mirror)current_animation = &AndyCrouchM;
					else current_animation = &AndyCrouch;
				}
				else currentstate = ST_IDLE;

				AndyGoingDown.resetLoops(0);
				AndyGoingDownM.resetLoops(0);
				speed = 2.0;
				t = 0;
				colj->rect.y = 10000;
				if (!gmode) col->rect.y = Andyposition.y + 50;
			}
		}
	}

	//JUMP RIGHT				PENDIENTE
	{
		if ((inputAndy.J_UP || App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_DOWN) && currentstate == ST_WALK_RIGHT)
		{
			currentstate = ST_GOING_UP_FORWARD;
			col->rect.y = 10000;
			if (gmode != true) colj->rect.y = Andyposition.y + 50;
		}
		if (currentstate == ST_GOING_UP_FORWARD)
		{
			if(!gmode) colj->rect.y = Andyposition.y + 50;
			if (mirror) current_animation = &AndyGoingUpBackwardsM;
			else current_animation = &AndyGoingUpForward;
			Andyposition.x += 2;
			t += 0.002;
			speed += t;
			if (Andyposition.y > 10) { Andyposition.y = Andyposition.y - 3 * speed; App->render->camera.y = App->render->camera.y - speed; }
			else { Andyposition.y = Andyposition.y - 3 * speed / 2; App->render->camera.y = App->render->camera.y + speed; }
			if (Andyposition.y <= 30) currentstate = ST_TOP_FORWARD;
		}
		if (currentstate == ST_TOP_FORWARD)
		{
			Andyposition.x += 2;
			if(!gmode) colj->rect.y = Andyposition.y + 43;
			t += 0.005;
			speed -= t;
			Andyposition.y = Andyposition.y - 3 * speed;
			App->render->camera.y = App->render->camera.y + speed;
			if (Andyposition.y <= -40) currentstate = ST_GOING_DOWN_FORWARD; 
		}
		if (currentstate == ST_GOING_DOWN_FORWARD)
		{
			current_animation = &AndyGoingDownForward;
			AndyGoingUpForward.resetLoops(0);
			if(!gmode) colj->rect.y = Andyposition.y + 60;
			Andyposition.x += 2;
			t += 0.002;
			speed -= t;
			Andyposition.y = Andyposition.y - 3 * speed;
			if (Andyposition.y > 20) { Andyposition.y = Andyposition.y - 3 * speed; App->render->camera.y = App->render->camera.y + speed; }
			else { Andyposition.y = Andyposition.y - 3 * speed / 2; App->render->camera.y = App->render->camera.y + speed; }
			if (App->render->camera.y <= -10) App->render->camera.y = -10;

			if (Andyposition.y >= 60)
			{
				Andyposition.y = 60;
				if (inputAndy.J_LEFT || App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
				{
					currentstate = ST_WALK_LEFT;
					if (!mirror) colb = App->collisions->AddCollider({ Andyposition.x + 31, Andyposition.y + 50, 10, 70 }, COLLIDER_WALL, App->player);
					if (mirror)current_animation = &AndyForwardM;
					else current_animation = &AndyBackwards;
				}
				else if (inputAndy.J_RIGHT || App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
				{
					currentstate = ST_WALK_RIGHT;
					if (mirror) colb = App->collisions->AddCollider({ Andyposition.x + 31, Andyposition.y + 50, 10, 70 }, COLLIDER_WALL, App->player);
					if (mirror)current_animation = &AndyBackwardsM;
					else current_animation = &AndyForward;
				}
				else if (inputAndy.J_DOWN || App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
				{
					currentstate = ST_CROUCH;
					if (mirror)current_animation = &AndyCrouchM;
					else current_animation = &AndyCrouch;
				}
				else currentstate = ST_IDLE;

				AndyGoingDownForward.resetLoops(0);
				speed = 2.0;
				t = 0;
				colj->rect.y = 10000;
				if (!gmode) col->rect.y = Andyposition.y + 50;
			}
		}
	}

	//JUMP LEFT  PENDIENTE
	{
		if ((inputAndy.J_UP || App->input->keyboard[SDL_SCANCODE_W] == KEY_STATE::KEY_DOWN) && currentstate == ST_WALK_LEFT)
		{
			currentstate = ST_GOING_UP_BACKWARD;
			if (colb)colb->to_delete = true;
			col->rect.y = 10000;
			if (gmode != true) colj->rect.y = Andyposition.y + 50;
		}
		if (currentstate == ST_GOING_UP_BACKWARD)
		{
			if(!gmode) colj->rect.y = Andyposition.y + 50;
			current_animation = &AndyGoingUpBackwards;
			Andyposition.x -= 2;
			t += 0.002;
			speed += t;
			if (Andyposition.y > 10) { Andyposition.y = Andyposition.y - 3 * speed; App->render->camera.y = App->render->camera.y - speed; }
			else { Andyposition.y = Andyposition.y - 3 * speed / 2; App->render->camera.y = App->render->camera.y + speed; }
			if (Andyposition.y <= 30) currentstate = ST_TOP_BACKWARD;
		}
		if (currentstate == ST_TOP_BACKWARD)
		{
			Andyposition.x -= 2;		
			if(!gmode) colj->rect.y = Andyposition.y + 43;
			t += 0.005;
			speed -= t;
			Andyposition.y = Andyposition.y - 3 * speed;
			App->render->camera.y = App->render->camera.y + speed;
			if (Andyposition.y <= -40) currentstate = ST_GOING_DOWN_BACKWARD;
			if (AndyTopBackwards.Finished())
				currentstate = ST_GOING_DOWN_BACKWARD; 
		}
		if (currentstate == ST_GOING_DOWN_BACKWARD)
		{
			current_animation = &AndyGoingDownBackwards;
			AndyTopBackwards.resetLoops(0);
			if(!gmode) colj->rect.y = Andyposition.y + 60;
			Andyposition.x -= 2;
			
			t += 0.002;
			speed -= t;
			Andyposition.y = Andyposition.y - 3 * speed;
			if (Andyposition.y > 20) { Andyposition.y = Andyposition.y - 3 * speed; App->render->camera.y = App->render->camera.y + speed; }
			else { Andyposition.y = Andyposition.y - 3 * speed / 2; App->render->camera.y = App->render->camera.y + speed; }
			if (App->render->camera.y <= -10) App->render->camera.y = -10;
			if (Andyposition.y >= 60)
			{
				Andyposition.y = 60;
				if (inputAndy.J_LEFT || App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
				{
					currentstate = ST_WALK_LEFT;
					if (!mirror) colb = App->collisions->AddCollider({ Andyposition.x + 31, Andyposition.y + 50, 10, 70 }, COLLIDER_WALL, App->player);
					if (mirror)current_animation = &AndyForwardM;
					else current_animation = &AndyBackwards;
				}
				else if (inputAndy.J_RIGHT || App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
				{
					currentstate = ST_WALK_RIGHT;
					if (mirror)current_animation = &AndyBackwardsM;
					else current_animation = &AndyForward;
				}
				else if (inputAndy.J_DOWN || App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
				{
					currentstate = ST_CROUCH;
					if (mirror)current_animation = &AndyCrouchM;
					else current_animation = &AndyCrouch;
				}
				else currentstate = ST_IDLE;

				AndyGoingDownBackwards.resetLoops(0);
				speed = 2.0;
				t = 0;
				colj->rect.y = 10000;
				if (!gmode) col->rect.y = Andyposition.y + 50;
			}
		}
	}

	//PUNCH
	{
		if (punched && !((inputAndy.J_B || App->input->keyboard[SDL_SCANCODE_F] == KEY_STATE::KEY_DOWN) && ((currentstate == ST_IDLE) || (currentstate == ST_WALK_RIGHT) 
			|| (currentstate == ST_WALK_LEFT)) && (current_animation != &AndyPunch) && (current_animation != &AndyPunchM))) 
		{
			punched = false;
		}

		if (!punched && (inputAndy.J_B || App->input->keyboard[SDL_SCANCODE_F] == KEY_STATE::KEY_DOWN) && ((currentstate == ST_IDLE) || (currentstate == ST_WALK_RIGHT) || (currentstate == ST_WALK_LEFT)) && (current_animation != &AndyPunch) && (current_animation != &AndyPunchM))
		{
			currentstate = ST_PUNCH_STANDING;
			if (mirror)
			{
				Andyposition.x -= 38;
				current_animation = &AndyPunchM;
				colp = App->collisions->AddCollider({ Andyposition.x + 10, Andyposition.y + 65, 43, 20 }, COLLIDER_PLAYER_SHOT, App->player);
			}
			else
			{
				current_animation = &AndyPunch;
				colp = App->collisions->AddCollider({ Andyposition.x + 40, Andyposition.y + 65, 43, 20 }, COLLIDER_PLAYER_SHOT, App->player);
			}
			App->audio->PlayFX("Assets/FX/punch.wav");
		}
		if (AndyPunch.Finished() || AndyPunchM.Finished())
		{
			punched = true;
			if (mirror)Andyposition.x += 38;
			colp->to_delete = true;
			AndyPunch.resetLoops(0);
			AndyPunchM.resetLoops(0);
			if (inputAndy.J_RIGHT || App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
			{
				currentstate = ST_WALK_RIGHT;
				if (mirror) colb = App->collisions->AddCollider({ Andyposition.x + 31, Andyposition.y + 50, 10, 70 }, COLLIDER_WALL, App->player);
				current_animation = &AndyForward;
			}
			else if (inputAndy.J_LEFT || App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
			{
				currentstate = ST_WALK_LEFT;
				if (!mirror) colb = App->collisions->AddCollider({ Andyposition.x + 31, Andyposition.y + 50, 10, 70 }, COLLIDER_WALL, App->player);
				current_animation = &AndyBackwards;
			}
			else
				currentstate = ST_IDLE;
			App->player2->collided = false;
		}
	}

	//KICK
	{
		if (kicked && !((inputAndy.J_A || App->input->keyboard[SDL_SCANCODE_G] == KEY_STATE::KEY_DOWN) && ((currentstate == ST_IDLE) || (currentstate == ST_WALK_RIGHT) || (currentstate == ST_WALK_LEFT)))) {
			kicked = false;
		}
		if (!kicked && (inputAndy.J_A || App->input->keyboard[SDL_SCANCODE_G] == KEY_STATE::KEY_DOWN) && ((currentstate == ST_IDLE) || (currentstate == ST_WALK_RIGHT) || (currentstate == ST_WALK_LEFT)))
		{
			currentstate = ST_KICK_STANDING;
			if (mirror)
			{
				Andyposition.x -= 50;
				current_animation = &AndyKickM;
				colk = App->collisions->AddCollider({ Andyposition.x + 16, Andyposition.y + 48, 55, 40 }, COLLIDER_PLAYER_SHOT, App->player);
			}
			else
			{
				current_animation = &AndyKick;
				colk = App->collisions->AddCollider({ Andyposition.x + 40, Andyposition.y + 45, 55, 40 }, COLLIDER_PLAYER_SHOT, App->player);
			}
			App->audio->PlayFX("Assets/FX/Voice/Attacks/FX_Attack4/FX_Attack4.wav");
		}
		if (AndyKick.Finished() == true || AndyKickM.Finished() == true)
		{
			kicked = true;
			if(mirror) Andyposition.x += 50;
			colk->to_delete = true;
			AndyKickM.resetLoops(0);
			AndyKick.resetLoops(0);
			if (inputAndy.J_LEFT || App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
			{
				currentstate = ST_WALK_RIGHT;
				if (mirror) colb = App->collisions->AddCollider({ Andyposition.x + 31, Andyposition.y + 50, 10, 70 }, COLLIDER_WALL, App->player);
				if (mirror2)current_animation = &AndyBackwardsM;
				else current_animation = &AndyForward;
			}
			else if (inputAndy.J_RIGHT || App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
			{
				currentstate = ST_WALK_LEFT;
				if (!mirror) colb = App->collisions->AddCollider({ Andyposition.x + 31, Andyposition.y + 50, 10, 70 }, COLLIDER_WALL, App->player);
				if (mirror2)current_animation = &AndyForwardM;
				else current_animation = &AndyBackwards;
			}
			else if (inputAndy.J_DOWN || App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
			{
				currentstate = ST_CROUCH;
				if (mirror2)current_animation = &AndyCrouchM;
				else current_animation = &AndyCrouch;
			}
			else currentstate = ST_IDLE;
			App->player2->collided = false;
		}
	}

	//CROUCH
	{
		if ((inputAndy.J_DOWN || App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_DOWN) && (currentstate == ST_IDLE || currentstate == ST_WALK_RIGHT || currentstate == ST_WALK_LEFT))
		{
			currentstate = ST_CROUCH;
			if (mirror)current_animation = &AndyCrouchM;
			else current_animation = &AndyCrouch;
			col->rect.y = 10000;
			if (gmode != true)	colc->rect.y = Andyposition.y + 91;
		}

		if (App->input->gController1 != NULL)
		{
			if (inputAndy.J_LEFT || App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
			{
				currentstate = ST_WALK_LEFT;
				if (!mirror) colb = App->collisions->AddCollider({ Andyposition.x + 31, Andyposition.y + 50, 10, 70 }, COLLIDER_WALL, App->player);
				if (mirror2)current_animation = &AndyForwardM;
				else current_animation = &AndyBackwards;
			}
			else if (inputAndy.J_RIGHT || App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
			{
				currentstate = ST_WALK_RIGHT;
				if (mirror) colb = App->collisions->AddCollider({ Andyposition.x + 31, Andyposition.y + 50, 10, 70 }, COLLIDER_WALL, App->player);
				if (mirror2)current_animation = &AndyBackwardsM;
				else current_animation = &AndyForward;
			}
			else currentstate = ST_IDLE;

			AndyCrouch.Reset();
			colc->rect.y = 10000;
			if (gmode != true) col->rect.y = Andyposition.y + 50;
		}
	}

	//CROUCHPUNCH
	{
		if ((inputAndy.J_B || App->input->keyboard[SDL_SCANCODE_F] == KEY_STATE::KEY_DOWN) && currentstate == ST_CROUCH)
		{
			currentstate = ST_PUNCH_CROUCH;
			current_animation = &AndyCrouchPunch;
			App->audio->PlayFX("Assets/FX/Voice/Attacks/FX_Attack4/FX_Attack4.wav");
			colcp = App->collisions->AddCollider({ Andyposition.x + 50, Andyposition.y + 55, 25, 20 }, COLLIDER_PLAYER_SHOT, App->player);
			colcp->rect.x = Andyposition.x + 50;
			colcp->rect.y = Andyposition.y + 55;
		}
		if (AndyCrouchPunch.Finished() == true)
		{
			colcp->to_delete = true;
			AndyCrouchPunch.resetLoops(0);
			App->player2->collided = false;

			if (inputAndy.J_DOWN || App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
			{
				currentstate = ST_CROUCH;
				current_animation = &AndyCrouch;
			}
			else
			{
				currentstate = ST_IDLE;
				current_animation = &AndyIdle;
				colc->rect.y = 10000;
				if (!gmode)col->rect.y = Andyposition.y + 50;
			}
		}
	}

	//CROUCHKICK
	{
		if ((inputAndy.J_A || App->input->keyboard[SDL_SCANCODE_G] == KEY_STATE::KEY_DOWN) && currentstate == ST_CROUCH)
		{
			currentstate = ST_KICK_CROUCH;
			colck->rect.x = Andyposition.x + 50;
			colck->rect.y = Andyposition.y + 90;
			if (mirror)
			{
				current_animation = &AndyCrouchKickM;
			}
			else
			{
				current_animation = &AndyCrouchKick;
				Andyposition.x -= 30;
				colc->rect.x -= 50;
				colck->rect.x = Andyposition.x + 20;
				colck->rect.y = Andyposition.y + 90;
			}
			App->audio->PlayFX("Assets/FX/Voice/Attacks/FX_Attack4/FX_Attack4.wav");
		}
		if (AndyCrouchKick.Finished() == true)
		{
			Andyposition.x += 30;
			colc->rect.x += 30;
			colck->to_delete = true;
			AndyCrouchKick.resetLoops(0);
			AndyCrouchKickM.resetLoops(0);

			if (inputAndy.J_DOWN || App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
			{
				currentstate = ST_CROUCH;
				current_animation = &AndyCrouch;
			}
			else
			{
				currentstate = ST_IDLE;
				colc->rect.y = 10000;
				if (!gmode)col->rect.y = Andyposition.y + 50;
			}
			App->player2->collided = false;
			colck = App->collisions->AddCollider({ 0, 0, 40, 20 }, COLLIDER_PLAYER_SHOT, App->player);
		}

		if (currentstate == ST_CROUCH && (inputAndy.J_RIGHT || App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_DOWN))
		{
			currentstate = ST_SD;
			current_animation = &AndyCrouch;
		}
		if (currentstate == ST_SD && (inputAndy.J_RIGHT || App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_UP))	currentstate = ST_CROUCH;
		if (currentstate == ST_SD && (SDL_GameControllerGetAxis(App->input->gController1, SDL_CONTROLLER_AXIS_LEFTY) < 14000 && SDL_GameControllerGetAxis(App->input->gController1, SDL_CONTROLLER_AXIS_LEFTY) > 4000 || App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_UP))
		{
			currentstate = ST_WALK_RIGHT;
			if (mirror) colb = App->collisions->AddCollider({ Andyposition.x + 31, Andyposition.y + 50, 10, 70 }, COLLIDER_WALL, App->player);
			current_animation = &AndyForward;
			colc->rect.y = 10000;
			col->rect.y = Andyposition.y + 50;
		}
	}

	//POWER WAVE
	/*{
		if (currentstate == ST_SD && App->input->keyboard[SDL_SCANCODE_F] == KEY_STATE::KEY_DOWN)
		{
			currentstate = ST_POWER_WAVE;
			current_animation = &AndyPW;
			App->audio->PlayFX("Assets/FX/Voice/Special Attacks/FX_PowerWaveAttackTerryBogardVoice/FX_PowerWaveAttackTerryBogardVoice.wav");
			colc->rect.y = 10000;
			if(!gmode)
			col->rect.y = Andyposition.y + 50;
		}
		if (AndyPW.Finished() == true)
		{
			Uint32 inittime = 200;
			if (SDL_GetTicks() >= inittime)
			{
				App->particles->AddParticle(App->particles->terryenergy, Andyposition.x + 60, Andyposition.y + 12);
				App->particles->AddParticle(App->particles->terryenergy, Andyposition.x + 76, Andyposition.y + 12, 200);
				App->particles->AddParticle(App->particles->terryenergy, Andyposition.x + 92, Andyposition.y + 12, 400);
				App->particles->AddParticle(App->particles->terryenergy, Andyposition.x + 108, Andyposition.y + 12, 600);
				App->particles->AddParticle(App->particles->terryenergy, Andyposition.x + 124, Andyposition.y + 12, 800);
				App->particles->terryenergy.col->to_delete == true;
			}
			AndyPW.resetLoops(0);
			if (inputAndy.J_RIGHT || App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
			{
				currentstate = ST_WALK_RIGHT;
				current_animation = &AndyForward;
				if (mirror) colb = App->collisions->AddCollider({ Andyposition.x + 31, Andyposition.y + 50, 10, 70 }, COLLIDER_WALL, App->player);
			}
			else if (inputAndy.J_LEFT || App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
			{
				currentstate = ST_WALK_LEFT;
				if (!mirror) colb = App->collisions->AddCollider({ Andyposition.x + 31, Andyposition.y + 50, 10, 70 }, COLLIDER_WALL, App->player);
				current_animation = &AndyBackwards;
			}
			else
			{
				currentstate = ST_IDLE;
				current_animation = &AndyIdle;
			}
			if (inputAndy.J_DOWN || App->input->keyboard[SDL_SCANCODE_S] == KEY_STATE::KEY_REPEAT)
			{
				col->rect.y = 10000;
				if (!gmode)
					colc->rect.y = Andyposition.y + 91;
			}
			AndyPW.resetLoops(0);
		}
	}*/

	//THROW
	{
		if (App->input->keyboard[SDL_SCANCODE_H] == KEY_STATE::KEY_DOWN && (currentstate == ST_WALK_RIGHT || currentstate == ST_WALK_LEFT || currentstate == ST_IDLE))
		{
			if (currentstate != ST_IDLE) colt = App->collisions->AddCollider({ Andyposition.x + 65, Andyposition.y + 65, 16, 55 }, COLLIDER_PLAYER_SHOT, App->player);
			Andyposition.x += 25;
			currentstate = ST_THROWING;
			if (mirror) current_animation = &AndyThrowM;
			else current_animation = &AndyThrow;
		}
		if (AndyThrow.Finished())
		{
			Andyposition.x -= 25;

			AndyThrow.resetLoops(0);
			colt->to_delete = true;
			if (inputAndy.J_RIGHT || App->input->keyboard[SDL_SCANCODE_D] == KEY_STATE::KEY_REPEAT)
			{
				currentstate = ST_WALK_RIGHT;
				current_animation = &AndyForward;
				if (mirror) colb = App->collisions->AddCollider({ Andyposition.x + 31, Andyposition.y + 50, 10, 70 }, COLLIDER_WALL, App->player);
			}
			else if (inputAndy.J_LEFT || App->input->keyboard[SDL_SCANCODE_A] == KEY_STATE::KEY_REPEAT)
			{
				currentstate = ST_WALK_LEFT;
				if (!mirror) colb = App->collisions->AddCollider({ Andyposition.x + 31, Andyposition.y + 50, 10, 70 }, COLLIDER_WALL, App->player);
				current_animation = &AndyBackwards;
			}
			else
				currentstate = ST_IDLE;
			App->player2->collided = false;
		}
	}


	//THROWING
	{
		if (currentstate == ST_THROWING)
		{
			if (AndyThrow.Finished() || AndyThrowM.Finished())
			{
				if (mirror) current_animation = &AndyThrowingM;
				else current_animation = &AndyThrowing;
			}
		}
	}


	//VOLANDING
	{
		if (currentstate == ST_BEING_THROWN)
		{
			if (mirror)
			{
				current_animation = &AndyBeingThrownM;			
				Andyposition.x += 3;
			}
			else
			{
				current_animation = &AndyBeingThrown;
				Andyposition.x -= 3;
			}
			if (AndyBeingThrown.Finished() || AndyBeingThrownM.Finished())
			{
				AndyBeingThrown.resetLoops(0); AndyBeingThrownM.resetLoops(0);
				currentstate = ST_DOWN;
			}
		}
	}

	//GETTING UP
	{
		if (currentstate == ST_DOWN)
		{
			cold = App->collisions->AddCollider({ Andyposition.x, Andyposition.y, 50, 10 }, COLLIDER_PLAYER, App->player);
			if (mirror) current_animation = &AndyGetUpM;
			else current_animation = &AndyGetUp;
		}
		if (AndyGetUp.Finished() || AndyGetUpM.Finished())
		{
			currentstate = ST_IDLE;
			cold->to_delete = true;
		}
	}

	//GETTING PUNCHED
	{
		if (currentstate == ST_BEING_PUNCHED)
		{
			if (mirror)
			{
				current_animation = &AndyDPM;
				Andyposition.x++;
			}
			else
			{
				current_animation = &AndyDP;
				Andyposition.x--;
			}
		}
		if (AndyDP.Finished() || AndyDPM.Finished())
			currentstate = ST_IDLE;
	}

	//GETTING KICKED
	{
		if (currentstate == ST_BEING_KICKED)
		{
			if (mirror) current_animation = &AndyDKM;
			else current_animation = &AndyDK;
		}
		if (AndyDK.Finished() || AndyDKM.Finished())
			currentstate = ST_IDLE;
	}

	//INVENCIBLE
	if (invencible)
	{
		tick++;
		if (tick > 20)
		{
			invencible = false;
			tick = 0;
		}
	}


	//GOD MODE
	if (App->input->keyboard[SDL_SCANCODE_F5] == KEY_STATE::KEY_DOWN)
	{
		if (gmode == false)
		{
			LOG("Starting GOD MODE");
			gmode = true;
			col->rect.y = 10000;
			colj->rect.y = 10000; 
			colc->rect.y = 10000;
		}
		else
		{
			LOG("GOD MODE off");
			if (currentstate == ST_IDLE) col->rect.y = Andyposition.y + 50;
			if (currentstate == ST_CROUCH) colc->rect.y = Andyposition.y + 91;
			if (currentstate == ST_GOING_UP || currentstate == ST_GOING_UP_FORWARD || currentstate == ST_GOING_UP_BACKWARD) colj->rect.y = Andyposition.y + 50;
			else if (currentstate == ST_GOING_DOWN || currentstate == ST_GOING_DOWN_FORWARD || currentstate == ST_GOING_DOWN_BACKWARD) colj->rect.y = Andyposition.y + 50;
			else if(currentstate == ST_TOP || currentstate == ST_TOP_FORWARD || currentstate == ST_TOP_BACKWARD) colj->rect.y = Andyposition.y + 85;

			gmode = false;
		}
	}


	//VIDA
	{
		App->render->Blit(UI, 0, 0, &lifebar, 0);
		if (life_score <= 24)
			App->render->Blit(UI, 27, 27, &(LifeBlink.GetCurrentFrame()), 0);

		if (life_score >= 4)
		{
			App->render->Blit(UI, 26, 26, &life1, 0);
			App->render->Blit(UI, 27, 26, &life2, 0);
		}
		if (life_score >= 8)
			App->render->Blit(UI, 31, 26, &life2, 0);
		if (life_score >= 12)
			App->render->Blit(UI, 35, 26, &life2, 0);
		if (life_score >= 16)
			App->render->Blit(UI, 39, 26, &life2, 0);
		if (life_score >= 20)
			App->render->Blit(UI, 43, 26, &life2, 0);
		if (life_score >= 24)
			App->render->Blit(UI, 47, 26, &life2, 0);
		if (life_score >= 28)
			App->render->Blit(UI, 51, 26, &life2, 0);
		if (life_score >= 32)
			App->render->Blit(UI, 55, 26, &life2, 0);
		if (life_score >= 36)
			App->render->Blit(UI, 59, 26, &life2, 0);
		if (life_score >= 40)
			App->render->Blit(UI, 63, 26, &life2, 0);
		if (life_score >= 44)
			App->render->Blit(UI, 67, 26, &life2, 0);
		if (life_score >= 48)
			App->render->Blit(UI, 71, 26, &life2, 0);
		if (life_score >= 52)
			App->render->Blit(UI, 75, 26, &life2, 0);
		if (life_score >= 56)
			App->render->Blit(UI, 79, 26, &life2, 0);
		if (life_score >= 60)
			App->render->Blit(UI, 83, 26, &life2, 0);
		if (life_score >= 64)
			App->render->Blit(UI, 87, 26, &life2, 0);
		if (life_score >= 68)
			App->render->Blit(UI, 91, 26, &life2, 0);
		if (life_score >= 72)
			App->render->Blit(UI, 95, 26, &life2, 0);
		if (life_score >= 76)
			App->render->Blit(UI, 99, 26, &life2, 0);
		if (life_score >= 80)
			App->render->Blit(UI, 103, 26, &life2, 0);
		if (life_score >= 84)
			App->render->Blit(UI, 107, 26, &life2, 0);
		if (life_score >= 88)
			App->render->Blit(UI, 111, 26, &life2, 0);
		if (life_score >= 92)
		{
			App->render->Blit(UI, 115, 26, &life2, 0);
			App->render->Blit(UI, 119, 26, &life1, 0);
		}

		if (App->scene_2->p1won)
		{
			App->render->Blit(UI, 9, 49, &(ball.GetCurrentFrame()), 0);
		}
	}
	if (App->scene_2->p1won2)
	{
		App->render->Blit(UI, 25, 49, &(ball.GetCurrentFrame()), 0);
	}

	if (currentstate == ST_PUNCH_STANDING && mirror)
		col->rect.x = Andyposition.x + 58;
	else if (currentstate == ST_KICK_STANDING && mirror)
		col->rect.x = Andyposition.x + 70;
	else 
	{
		if (mirror) col->rect.x = Andyposition.x + 20;
		else col->rect.x = Andyposition.x + 9;
	}

	colj->rect.x = Andyposition.x + 13;
	if (colb)
	{
		if (mirror) colb->rect.x = Andyposition.x +10;
		else colb->rect.x = Andyposition.x + 40;
	}
	if (currentstate != ST_KICK_CROUCH)	colc->rect.x = Andyposition.x + 13;
	else colc->rect.x = Andyposition.x + 30;


	// Draw everything --------------------------------------
	SDL_Rect r = current_animation->GetCurrentFrame();

	// Draw everything --------------------------------------
	if (destroyed == false)
	{
		App->render->Blit(graphics, Andyposition.x, Andyposition.y, &(current_animation->GetCurrentFrame()));
	}

	// Draw UI (score) --------------------------------------k
	App->fonts->BlitText(10, 150, font_score, "546");

	return UPDATE_CONTINUE;
}

int ModulePlayer::Score()
{
	return p_score;
}

void ModulePlayer::OnCollision(Collider* c1, Collider* c2)
{
	if (!invencible && c1->type == COLLIDER_PLAYER && c2->type == COLLIDER_ENEMY_SHOT && !collided && App->player2->currentstate == ST_PUNCH_STANDING2)
	{
		//if (ST_WALK_LEFT && !mirror)
		//{
		//	//block
		//}
		//else if (ST_WALK_RIGHT && mirror)
		//{
		//	//block
		//}
		//else
		{
			life_score -= 14;
			App->player2->p_score += 100;
		}
		collided = true;
		//currentstate = ST_BEING_PUNCHED;
		//if(mirror) App->player2->current_animation = &AndyPunchLongM;
		//else App->player2->current_animation = &AndyPunchLong;
	}

	if (c1->type == COLLIDER_PLAYER && c2->type == COLLIDER_ENEMY_SHOT && !collided && App->player2->currentstate == ST_PUNCH_CROUCH2)
	{
		if (ST_WALK_LEFT && !mirror)
		{
			//block
		}
		else if (ST_WALK_RIGHT && mirror)
		{
			//block
		}
		else
		{
			life_score -= 14;
		}
		collided = true;
		invencible = true;
		currentstate = ST_BEING_PUNCHED;
		//if(mirror) App->player2->current_animation = &AndyPunchLongM;
		//else App->player2->current_animation = &AndyPunchLong;
	}

	if (!invencible && c1->type == COLLIDER_PLAYER && c2->type == COLLIDER_ENEMY_SHOT && !collided && App->player2->currentstate == ST_KICK_STANDING2)
	{
		if (ST_WALK_LEFT && !mirror)
		{
			//block
		}
		else if (ST_WALK_RIGHT && mirror)
		{
			//block
		}
		else
		{
			life_score -= 16;
		}
		collided = true;
		//currentstate = ST_BEING_PUNCHED;
		//if(mirror) App->player2->current_animation = &AndyPunchLongM;
		//else App->player2->current_animation = &AndyPunchLong;
	}

	if (c1->type == COLLIDER_PLAYER && c2->type == COLLIDER_ENEMY_SHOT && !collided && App->player2->currentstate == ST_KICK_CROUCH2)
	{
		if (ST_WALK_LEFT && !mirror)
		{
			//block
		}
		else if (ST_WALK_RIGHT && mirror)
		{
			//block
		}
		else
		{
			life_score -= 16;
		}
		collided = true;
		invencible = true;
		currentstate = ST_BEING_KICKED;
		//if(mirror) App->player2->current_animation = &AndyPunchLongM;
		//else App->player2->current_animation = &AndyPunchLong;
	}

	if (c1->type == COLLIDER_PLAYER && c2->type == COLLIDER_ENEMY)
	{
		if (currentstate == ST_WALK_RIGHT && App->player2->currentstate == ST_WALK_RIGHT)
		{
			Andyposition.x -= 2;
			App->player2->Andy2position.x += 2;
		}
		else if (currentstate == ST_WALK_LEFT && App->player2->currentstate == ST_WALK_LEFT)
		{
			Andyposition.x += 2;
			App->player2->Andy2position.x -= 2;
		}
		else if (Andyposition.x < App->player2->Andy2position.x)
		{
			Andyposition.x --;
			App->player2->Andy2position.x++;
		}
		else if (Andyposition.x < App->player2->Andy2position.x)
		{
			Andyposition.x++;
			App->player2->Andy2position.x--;
		}
		
	}
	
}
//#endwaaif;
