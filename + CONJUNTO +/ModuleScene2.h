#ifndef __MODULESCENE2_H__
#define __MODULESCENE2_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"

struct SDL_Texture;

class ModuleScene2 : public Module
{
public:
	ModuleScene2();
	~ModuleScene2();

	bool Start();
	update_status Update();
	bool CleanUp();

public:

	bool p1won;
	bool p2won;
	bool p1won2;
	bool p2won2;

	bool reboot;
	int round;

	SDL_Texture* graphics = nullptr;
	SDL_Texture* score = nullptr;
	SDL_Texture* timer = nullptr;

	//SCORE
	SDL_Rect zero;
	SDL_Rect one;
	SDL_Rect two;
	SDL_Rect three;
	SDL_Rect four;
	SDL_Rect five;
	SDL_Rect six;
	SDL_Rect seven;
	SDL_Rect eight;
	SDL_Rect nine;
	int positionx;
	int positiony;
	int n[5];
	SDL_Rect r[5];
	int currentscore;
	int player;

	//TIMER
	SDL_Rect tzero;
	SDL_Rect tone;
	SDL_Rect ttwo;
	SDL_Rect tthree;
	SDL_Rect tfour;
	SDL_Rect tfive;
	SDL_Rect tsix;
	SDL_Rect tseven;
	SDL_Rect teight;
	SDL_Rect tnine;
	int tpositionx;
	int tpositiony;
	int tn[2];
	SDL_Rect tr[2];
	int timer_num = 90;
	int timer_counter = 0;

	Animation bus;
	Animation busT;
	Animation busN;
	//SDL_Rect ground;
	//SDL_Rect roof;
	//SDL_Rect foreground;
	SDL_Rect background;
	SDL_Rect backgroundT;
	SDL_Rect backgroundN;
	SDL_Rect shadow;
	Animation background1;
	Animation background1T;
	Animation background1N;

	Animation people1;
	Animation people2;
	Animation people3;
	Animation people4;

	Animation people1T;
	Animation people2T;
	Animation people3T;
	Animation people4T;

	Animation people1N;
	Animation people2N;
	Animation people3N;
	Animation people4N;
	//Animation water;
};

#endif // __MODULESCENE2_H__