#include "Globals.h"
#include "Application.h"
#include "ModuleScene1.h"
#include "ModuleScene2.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneIntro.h"
#include "SDL/include/SDL.h"
#include "ModuleAudio.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib" )
#pragma comment( lib, "SDL/libx86/SDL2main.lib" )



ModuleSceneIntro::ModuleSceneIntro()
{
	background1.PushBack({ 0, 0, 303, 224 });
	background1.PushBack({ 304, 0, 303, 224 });
	background1.PushBack({ 608, 0, 303, 224 });
	background1.PushBack({ 912, 0, 303, 224 });
	background1.PushBack({ 1216, 0, 303, 224 });
	background1.PushBack({ 0, 224, 303, 224 });
	background1.PushBack({ 304, 224, 303, 224 });
	background1.PushBack({ 608, 224, 303, 224 });
	background1.PushBack({ 912, 224, 303, 224 });
	background1.PushBack({ 1216, 224, 303, 224 });
	background1.PushBack({ 0, 448, 303, 224 });
	background1.PushBack({ 304, 448, 303, 224 });
	background1.PushBack({ 608, 448, 303, 224 });
	background1.PushBack({ 912, 448, 303, 224 });
	background1.PushBack({ 1216, 448, 303, 224 });
	background1.PushBack({ 0, 672, 303, 224 });
	background1.PushBack({ 304, 672, 303, 224 });
	background1.PushBack({ 608, 672, 303, 224 });
	background1.PushBack({ 912, 672, 303, 224 });
	background1.PushBack({ 1216, 672, 303, 224 });
	background1.PushBack({ 0, 896, 303, 224 });
	background1.PushBack({ 304, 896, 303, 224 });
	background1.PushBack({ 608, 896, 303, 224 });
	background1.PushBack({ 912, 896, 303, 224 });
	background1.PushBack({ 1216, 896, 303, 224 });
	background1.PushBack({ 0, 1120, 303, 224 });
	background1.PushBack({ 304, 1120, 303, 224 });
	background1.PushBack({ 608, 1120, 303, 224 });
	background1.PushBack({ 912, 1120, 303, 224 });
	background1.PushBack({ 1216, 1120, 303, 224 });
	background1.PushBack({ 0, 1344, 303, 224 });
	background1.PushBack({ 304, 1344, 303, 224 });
	background1.PushBack({ 608, 1344, 303, 224 });
	background1.PushBack({ 912, 1344, 303, 224 });
	background1.PushBack({ 1216, 1344, 303, 224 });
	background1.PushBack({ 0, 1568, 303, 224 });
	background1.PushBack({ 304, 1568, 303, 224 });
	background1.PushBack({ 608, 1568, 303, 224 });
	background1.PushBack({ 912, 1568, 303, 224 });
	background1.PushBack({ 1216, 1568, 303, 224 });
	background1.PushBack({ 0, 1792, 303, 224 });
	background1.PushBack({ 304, 1792, 303, 224 });
	background1.PushBack({ 608, 1792, 303, 224 });
	background1.PushBack({ 912, 1792, 303, 224 });
	background1.PushBack({ 1216, 1792, 303, 224 });
	background1.PushBack({ 0, 2016, 303, 224 });
	background1.PushBack({ 304, 2016, 303, 224 });
	background1.PushBack({ 608, 2016, 303, 224 });
	background1.PushBack({ 912, 2016, 303, 224 });
	background1.PushBack({ 1216, 2016, 303, 224 });
	background1.PushBack({ 0, 2240, 303, 224 });
	background1.PushBack({ 304, 2240, 303, 224 });
	background1.PushBack({ 608, 2240, 303, 224 });
	background1.PushBack({ 912, 2240, 303, 224 });
	background1.PushBack({ 1216, 2240, 303, 224 });
	background1.PushBack({ 0, 2464, 303, 224 });
	background1.PushBack({ 304, 2464, 303, 224 });
	background1.PushBack({ 608, 2464, 303, 224 });
	background1.PushBack({ 912, 2464, 303, 224 });
	background1.PushBack({ 1216, 2464, 303, 224 });
	background1.PushBack({ 0, 2688, 303, 224 });
	background1.PushBack({ 304, 2688, 303, 224 });
	background1.PushBack({ 608, 2688, 303, 224 });
	background1.PushBack({ 912, 2688, 303, 224 });
	background1.PushBack({ 1216, 2688, 303, 224 });
	background1.PushBack({ 0, 2912, 303, 224 });
	background1.PushBack({ 304, 2912, 303, 224 });
	background1.PushBack({ 608, 2912, 303, 224 });
	background1.PushBack({ 912, 2912, 303, 224 });
	background1.PushBack({ 1216, 2912, 303, 224 });
	background1.PushBack({ 0, 3136, 303, 224 });
	background1.PushBack({ 304, 3136, 303, 224 });
	background1.PushBack({ 608, 3136, 303, 224 });
	background1.PushBack({ 912, 3136, 303, 224 });
	background1.PushBack({ 1216, 3136, 303, 224 });
	background1.PushBack({ 0, 3360, 303, 224 });
	background1.PushBack({ 304, 3360, 303, 224 });
	background1.PushBack({ 608, 3360, 303, 224 });
	background1.PushBack({ 912, 3360, 303, 224 });
	background1.PushBack({ 1216, 3360, 303, 224 });
	background1.PushBack({ 0, 3584, 303, 224 });
	background1.PushBack({ 304, 3584, 303, 224 });
	background1.PushBack({ 608, 3584, 303, 224 });
	background1.PushBack({ 912, 3584, 303, 224 });
	background1.PushBack({ 1216, 3584, 303, 224 });
	background1.PushBack({ 0, 3808, 303, 224 });
	background1.PushBack({ 304, 3808, 303, 224 });
	background1.PushBack({ 608, 3808, 303, 224 });
	background1.PushBack({ 912, 3808, 303, 224 });
	background1.PushBack({ 1216, 3808, 303, 224 });
	background1.PushBack({ 0, 4032, 303, 224 });
	background1.PushBack({ 304, 4032, 303, 224 });
	background1.PushBack({ 608, 4032, 303, 224 });
	background1.PushBack({ 912, 4032, 303, 224 });
	background1.PushBack({ 1216, 4032, 303, 224 });

	background1.PushBack({ 0, 4256, 303, 224 });
	background1.PushBack({ 304, 4256, 303, 224 });
	background1.PushBack({ 608, 4256, 303, 224 });
	background1.PushBack({ 912, 4256, 303, 224 });
	background1.PushBack({ 1216, 4256, 303, 224 });

	background1.PushBack({ 1520, 0, 303, 224 });
	background1.PushBack({ 1824, 0, 303, 224 });
	background1.PushBack({ 2128, 0, 303, 224 });
	background1.PushBack({ 2432, 0, 303, 224 });
	background1.PushBack({ 2736, 0, 303, 224 });
	background1.PushBack({ 1520, 224, 303, 224 });
	background1.PushBack({ 1824, 224, 303, 224 });
	background1.PushBack({ 2128, 224, 303, 224 });
	background1.PushBack({ 2432, 224, 303, 224 });
	background1.PushBack({ 2736, 224, 303, 224 });
	background1.PushBack({ 1520, 448, 303, 224 });
	background1.PushBack({ 1824, 448, 303, 224 });
	background1.PushBack({ 2128, 448, 303, 224 });
	background1.PushBack({ 2432, 448, 303, 224 });
	background1.PushBack({ 2736, 448, 303, 224 });
	background1.PushBack({ 1520, 672, 303, 224 });
	background1.PushBack({ 1824, 672, 303, 224 });
	background1.PushBack({ 2128, 672, 303, 224 });
	background1.PushBack({ 2432, 672, 303, 224 });
	background1.PushBack({ 2736, 672, 303, 224 });
	background1.PushBack({ 1520, 896, 303, 224 });
	background1.PushBack({ 1824, 896, 303, 224 });
	background1.PushBack({ 2128, 896, 303, 224 });
	background1.PushBack({ 2432, 896, 303, 224 });
	background1.PushBack({ 2736, 896, 303, 224 });
	background1.PushBack({ 1520, 1120, 303, 224 });
	background1.PushBack({ 1824, 1120, 303, 224 });
	background1.PushBack({ 2128, 1120, 303, 224 });
	background1.PushBack({ 2432, 1120, 303, 224 });
	background1.PushBack({ 2736, 1120, 303, 224 });
	background1.PushBack({ 1520, 1344, 303, 224 });
	background1.PushBack({ 1824, 1344, 303, 224 });
	background1.PushBack({ 2128, 1344, 303, 224 });
	background1.PushBack({ 2432, 1344, 303, 224 });
	background1.PushBack({ 2736, 1344, 303, 224 });
	background1.PushBack({ 1520, 1568, 303, 224 });
	background1.PushBack({ 1824, 1568, 303, 224 });
	background1.PushBack({ 2128, 1568, 303, 224 });
	background1.PushBack({ 2432, 1568, 303, 224 });
	background1.PushBack({ 2736, 1568, 303, 224 });
	background1.PushBack({ 1520, 1792, 303, 224 });
	background1.PushBack({ 1824, 1792, 303, 224 });
	background1.PushBack({ 2128, 1792, 303, 224 });
	background1.PushBack({ 2432, 1792, 303, 224 });
	background1.PushBack({ 2736, 1792, 303, 224 });
	background1.PushBack({ 1520, 2016, 303, 224 });
	background1.PushBack({ 1824, 2016, 303, 224 });
	background1.PushBack({ 2128, 2016, 303, 224 });
	background1.PushBack({ 2432, 2016, 303, 224 });
	background1.PushBack({ 2736, 2016, 303, 224 });
	background1.PushBack({ 1520, 2240, 303, 224 });
	background1.PushBack({ 1824, 2240, 303, 224 });
	background1.PushBack({ 2128, 2240, 303, 224 });
	background1.PushBack({ 2432, 2240, 303, 224 });
	background1.PushBack({ 2736, 2240, 303, 224 });
	background1.PushBack({ 1520, 2464, 303, 224 });
	background1.PushBack({ 1824, 2464, 303, 224 });
	background1.PushBack({ 2128, 2464, 303, 224 });
	background1.PushBack({ 2432, 2464, 303, 224 });
	background1.PushBack({ 2736, 2464, 303, 224 });
	background1.PushBack({ 1520, 2688, 303, 224 });
	background1.PushBack({ 1824, 2688, 303, 224 });
	background1.PushBack({ 2128, 2688, 303, 224 });
	background1.PushBack({ 2432, 2688, 303, 224 });
	background1.PushBack({ 2736, 2688, 303, 224 });
	background1.PushBack({ 1520, 2912, 303, 224 });
	background1.PushBack({ 1824, 2912, 303, 224 });
	background1.PushBack({ 2128, 2912, 303, 224 });
	background1.PushBack({ 2432, 2912, 303, 224 });
	background1.PushBack({ 2736, 2912, 303, 224 });
	background1.PushBack({ 1520, 3136, 303, 224 });
	background1.PushBack({ 1824, 3136, 303, 224 });
	background1.PushBack({ 2128, 3136, 303, 224 });
	background1.PushBack({ 2432, 3136, 303, 224 });
	background1.PushBack({ 2736, 3136, 303, 224 });
	background1.PushBack({ 1520, 3360, 303, 224 });
	background1.PushBack({ 1824, 3360, 303, 224 });
	background1.PushBack({ 2128, 3360, 303, 224 });
	background1.PushBack({ 2432, 3360, 303, 224 });
	background1.PushBack({ 2736, 3360, 303, 224 });
	background1.PushBack({ 1520, 3584, 303, 224 });
	background1.PushBack({ 1824, 3584, 303, 224 });
	background1.PushBack({ 2128, 3584, 303, 224 });
	background1.PushBack({ 2432, 3584, 303, 224 });
	background1.PushBack({ 2736, 3584, 303, 224 });
	background1.PushBack({ 1520, 3808, 303, 224 });
	background1.PushBack({ 1824, 3808, 303, 224 });
	background1.PushBack({ 2128, 3808, 303, 224 });
	background1.PushBack({ 2432, 3808, 303, 224 });
	background1.PushBack({ 2736, 3808, 303, 224 });
	background1.PushBack({ 1520, 4032, 303, 224 });
	background1.PushBack({ 1824, 4032, 303, 224 });
	background1.PushBack({ 2128, 4032, 303, 224 });
	background1.PushBack({ 2432, 4032, 303, 224 });
	background1.PushBack({ 2736, 4032, 303, 224 });

	background1.PushBack({ 1520, 4256, 303, 224 });
	background1.PushBack({ 1824, 4256, 303, 224 });
	background1.PushBack({ 2128, 4256, 303, 224 });
	background1.PushBack({ 2432, 4256, 303, 224 });
	background1.PushBack({ 2736, 4256, 303, 224 });
	
	background1.PushBack({ 3040, 0, 303, 224 });
	background1.PushBack({ 3344, 0, 303, 224 });
	background1.PushBack({ 3648, 0, 303, 224 });
	background1.PushBack({ 3952, 0, 303, 224 });
	background1.PushBack({ 4256, 0, 303, 224 });
	background1.PushBack({ 3040, 224, 303, 224 });
	background1.PushBack({ 3344, 224, 303, 224 });
	background1.PushBack({ 3648, 224, 303, 224 });
	background1.PushBack({ 3952, 224, 303, 224 });
	background1.PushBack({ 4256, 224, 303, 224 });
	background1.PushBack({ 3040, 448, 303, 224 });
	background1.PushBack({ 3344, 448, 303, 224 });
	background1.PushBack({ 3648, 448, 303, 224 });
	background1.PushBack({ 3952, 448, 303, 224 });
	background1.PushBack({ 4256, 448, 303, 224 });
	background1.PushBack({ 3040, 672, 303, 224 });
	background1.PushBack({ 3344, 672, 303, 224 });
	background1.PushBack({ 3648, 672, 303, 224 });
	background1.PushBack({ 3952, 672, 303, 224 });
	background1.PushBack({ 4256, 672, 303, 224 });
	background1.PushBack({ 3040, 896, 303, 224 });
	background1.PushBack({ 3344, 896, 303, 224 });
	background1.PushBack({ 3648, 896, 303, 224 });
	background1.PushBack({ 3952, 896, 303, 224 });
	background1.PushBack({ 4256, 896, 303, 224 });
	background1.PushBack({ 3040, 1120, 303, 224 });
	background1.PushBack({ 3344, 1120, 303, 224 });
	background1.PushBack({ 3648, 1120, 303, 224 });
	background1.PushBack({ 3952, 1120, 303, 224 });
	background1.PushBack({ 4256, 1120, 303, 224 });
	background1.PushBack({ 3040, 1344, 303, 224 });
	background1.PushBack({ 3344, 1344, 303, 224 });
	background1.PushBack({ 3648, 1344, 303, 224 });
	background1.PushBack({ 3952, 1344, 303, 224 });
	background1.PushBack({ 4256, 1344, 303, 224 });
	background1.PushBack({ 3040, 1568, 303, 224 });
	background1.PushBack({ 3344, 1568, 303, 224 });
	background1.PushBack({ 3648, 1568, 303, 224 });
	background1.PushBack({ 3952, 1568, 303, 224 });
	background1.PushBack({ 4256, 1568, 303, 224 });
	background1.PushBack({ 3040, 1792, 303, 224 });
	background1.PushBack({ 3344, 1792, 303, 224 });
	background1.PushBack({ 3648, 1792, 303, 224 });
	background1.PushBack({ 3952, 1792, 303, 224 });
	background1.PushBack({ 4256, 1792, 303, 224 });
	background1.PushBack({ 3040, 2016, 303, 224 });
	background1.PushBack({ 3344, 2016, 303, 224 });
	background1.PushBack({ 3648, 2016, 303, 224 });
	background1.PushBack({ 3952, 2016, 303, 224 });
	background1.PushBack({ 4256, 2016, 303, 224 });
	background1.PushBack({ 3040, 2240, 303, 224 });
	background1.PushBack({ 3344, 2240, 303, 224 });
	background1.PushBack({ 3648, 2240, 303, 224 });
	background1.PushBack({ 3952, 2240, 303, 224 });
	background1.PushBack({ 4256, 2240, 303, 224 });
	background1.PushBack({ 3040, 2464, 303, 224 });
	background1.PushBack({ 3344, 2464, 303, 224 });
	background1.PushBack({ 3648, 2464, 303, 224 });
	background1.PushBack({ 3952, 2464, 303, 224 });
	background1.PushBack({ 4256, 2464, 303, 224 });
	background1.PushBack({ 3040, 2688, 303, 224 });
	background1.PushBack({ 3344, 2688, 303, 224 });
	background1.PushBack({ 3648, 2688, 303, 224 });
	background1.PushBack({ 3952, 2688, 303, 224 });
	background1.PushBack({ 4256, 2688, 303, 224 });
	background1.PushBack({ 3040, 2912, 303, 224 });
	background1.PushBack({ 3344, 2912, 303, 224 });
	background1.PushBack({ 3648, 2912, 303, 224 });
	background1.PushBack({ 3952, 2912, 303, 224 });
	background1.PushBack({ 4256, 2912, 303, 224 });
	background1.PushBack({ 3040, 3136, 303, 224 });
	background1.PushBack({ 3344, 3136, 303, 224 });
	background1.PushBack({ 3648, 3136, 303, 224 });
	background1.PushBack({ 3952, 3136, 303, 224 });
	background1.PushBack({ 4256, 3136, 303, 224 });
	background1.PushBack({ 3040, 3360, 303, 224 });
	background1.PushBack({ 3344, 3360, 303, 224 });
	background1.PushBack({ 3648, 3360, 303, 224 });
	background1.PushBack({ 3952, 3360, 303, 224 });
	background1.PushBack({ 4256, 3360, 303, 224 });
	background1.PushBack({ 3040, 3584, 303, 224 });
	background1.PushBack({ 3344, 3584, 303, 224 });
	background1.PushBack({ 3648, 3584, 303, 224 });
	background1.PushBack({ 3952, 3584, 303, 224 });
	background1.PushBack({ 4256, 3584, 303, 224 });
	background1.PushBack({ 3040, 3808, 303, 224 });
	background1.PushBack({ 3344, 3808, 303, 224 });
	background1.PushBack({ 3648, 3808, 303, 224 });
	background1.PushBack({ 3952, 3808, 303, 224 });
	background1.PushBack({ 4256, 3808, 303, 224 });
	background1.PushBack({ 3040, 4032, 303, 224 });
	background1.PushBack({ 3344, 4032, 303, 224 });
	background1.PushBack({ 3648, 4032, 303, 224 });
	background1.PushBack({ 3952, 4032, 303, 224 });
	background1.PushBack({ 4256, 4032, 303, 224 });

	background1.PushBack({ 3040, 4256, 303, 224 });
	background1.PushBack({ 3344, 4256, 303, 224 });
	background1.PushBack({ 3648, 4256, 303, 224 });
	background1.PushBack({ 3952, 4256, 303, 224 });
	background1.PushBack({ 4256, 4256, 303, 224 });

	background1.speed = 0.8f;




	background2.PushBack({ 0, 0, 303, 224 });
	background2.PushBack({ 304, 0, 303, 224 });
	background2.PushBack({ 608, 0, 303, 224 });
	background2.PushBack({ 912, 0, 303, 224 });
	background2.PushBack({ 1216, 0, 303, 224 });
	background2.PushBack({ 0, 224, 303, 224 });
	background2.PushBack({ 304, 224, 303, 224 });
	background2.PushBack({ 608, 224, 303, 224 });
	background2.PushBack({ 912, 224, 303, 224 });
	background2.PushBack({ 1216, 224, 303, 224 });
	background2.PushBack({ 0, 448, 303, 224 });
	background2.PushBack({ 304, 448, 303, 224 });
	background2.PushBack({ 608, 448, 303, 224 });
	background2.PushBack({ 912, 448, 303, 224 });
	background2.PushBack({ 1216, 448, 303, 224 });
	background2.PushBack({ 0, 672, 303, 224 });
	background2.PushBack({ 304, 672, 303, 224 });
	background2.PushBack({ 608, 672, 303, 224 });
	background2.PushBack({ 912, 672, 303, 224 });
	background2.PushBack({ 1216, 672, 303, 224 });
	background2.PushBack({ 0, 896, 303, 224 });
	background2.PushBack({ 304, 896, 303, 224 });
	background2.PushBack({ 608, 896, 303, 224 });
	background2.PushBack({ 912, 896, 303, 224 });
	background2.PushBack({ 1216, 896, 303, 224 });
	background2.PushBack({ 0, 1120, 303, 224 });
	background2.PushBack({ 304, 1120, 303, 224 });
	background2.PushBack({ 608, 1120, 303, 224 });
	background2.PushBack({ 912, 1120, 303, 224 });
	background2.PushBack({ 1216, 1120, 303, 224 });
	background2.PushBack({ 0, 1344, 303, 224 });
	background2.PushBack({ 304, 1344, 303, 224 });
	background2.PushBack({ 608, 1344, 303, 224 });
	background2.PushBack({ 912, 1344, 303, 224 });
	background2.PushBack({ 1216, 1344, 303, 224 });
	background2.PushBack({ 0, 1568, 303, 224 });
	background2.PushBack({ 304, 1568, 303, 224 });
	background2.PushBack({ 608, 1568, 303, 224 });
	background2.PushBack({ 912, 1568, 303, 224 });
	background2.PushBack({ 1216, 1568, 303, 224 });
	background2.PushBack({ 0, 1792, 303, 224 });
	background2.PushBack({ 304, 1792, 303, 224 });
	background2.PushBack({ 608, 1792, 303, 224 });
	background2.PushBack({ 912, 1792, 303, 224 });
	background2.PushBack({ 1216, 1792, 303, 224 });
	background2.PushBack({ 0, 2016, 303, 224 });
	background2.PushBack({ 304, 2016, 303, 224 });
	background2.PushBack({ 608, 2016, 303, 224 });
	background2.PushBack({ 912, 2016, 303, 224 });
	background2.PushBack({ 1216, 2016, 303, 224 });
	background2.PushBack({ 0, 2240, 303, 224 });
	background2.PushBack({ 304, 2240, 303, 224 });
	background2.PushBack({ 608, 2240, 303, 224 });
	background2.PushBack({ 912, 2240, 303, 224 });
	background2.PushBack({ 1216, 2240, 303, 224 });
	background2.PushBack({ 0, 2464, 303, 224 });
	background2.PushBack({ 304, 2464, 303, 224 });
	background2.PushBack({ 608, 2464, 303, 224 });
	background2.PushBack({ 912, 2464, 303, 224 });
	background2.PushBack({ 1216, 2464, 303, 224 });
	background2.PushBack({ 0, 2688, 303, 224 });
	background2.PushBack({ 304, 2688, 303, 224 });
	background2.PushBack({ 608, 2688, 303, 224 });
	background2.PushBack({ 912, 2688, 303, 224 });
	background2.PushBack({ 1216, 2688, 303, 224 });
	background2.PushBack({ 0, 2912, 303, 224 });
	background2.PushBack({ 304, 2912, 303, 224 });
	background2.PushBack({ 608, 2912, 303, 224 });
	background2.PushBack({ 912, 2912, 303, 224 });
	background2.PushBack({ 1216, 2912, 303, 224 });
	background2.PushBack({ 0, 3136, 303, 224 });
	background2.PushBack({ 304, 3136, 303, 224 });
	background2.PushBack({ 608, 3136, 303, 224 });
	background2.PushBack({ 912, 3136, 303, 224 });
	background2.PushBack({ 1216, 3136, 303, 224 });
	background2.PushBack({ 0, 3360, 303, 224 });
	background2.PushBack({ 304, 3360, 303, 224 });
	background2.PushBack({ 608, 3360, 303, 224 });
	background2.PushBack({ 912, 3360, 303, 224 });
	background2.PushBack({ 1216, 3360, 303, 224 });
	background2.PushBack({ 0, 3584, 303, 224 });
	background2.PushBack({ 304, 3584, 303, 224 });
	background2.PushBack({ 608, 3584, 303, 224 });
	background2.PushBack({ 912, 3584, 303, 224 });
	background2.PushBack({ 1216, 3584, 303, 224 });
	background2.PushBack({ 0, 3808, 303, 224 });
	background2.PushBack({ 304, 3808, 303, 224 });
	background2.PushBack({ 608, 3808, 303, 224 });
	background2.PushBack({ 912, 3808, 303, 224 });
	background2.PushBack({ 1216, 3808, 303, 224 });
	background2.PushBack({ 0, 4032, 303, 224 });
	background2.PushBack({ 304, 4032, 303, 224 });
	background2.PushBack({ 608, 4032, 303, 224 });
	background2.PushBack({ 912, 4032, 303, 224 });
	background2.PushBack({ 1216, 4032, 303, 224 });

	background2.PushBack({ 1520, 0, 303, 224 });
	background2.PushBack({ 1824, 0, 303, 224 });
	background2.PushBack({ 2128, 0, 303, 224 });
	background2.PushBack({ 2432, 0, 303, 224 });
	background2.PushBack({ 2736, 0, 303, 224 });
	background2.PushBack({ 1520, 224, 303, 224 });
	background2.PushBack({ 1824, 224, 303, 224 });
	background2.PushBack({ 2128, 224, 303, 224 });
	background2.PushBack({ 2432, 224, 303, 224 });
	background2.PushBack({ 2736, 224, 303, 224 });
	background2.PushBack({ 1520, 448, 303, 224 });
	background2.PushBack({ 1824, 448, 303, 224 });
	background2.PushBack({ 2128, 448, 303, 224 });
	background2.PushBack({ 2432, 448, 303, 224 });
	background2.PushBack({ 2736, 448, 303, 224 });
	background2.PushBack({ 1520, 672, 303, 224 });
	background2.PushBack({ 1824, 672, 303, 224 });
	background2.PushBack({ 2128, 672, 303, 224 });
	background2.PushBack({ 2432, 672, 303, 224 });
	background2.PushBack({ 2736, 672, 303, 224 });
	background2.PushBack({ 1520, 896, 303, 224 });
	background2.PushBack({ 1824, 896, 303, 224 });
	background2.PushBack({ 2128, 896, 303, 224 });
	background2.PushBack({ 2432, 896, 303, 224 });
	background2.PushBack({ 2736, 896, 303, 224 });
	background2.PushBack({ 1520, 1120, 303, 224 });
	background2.PushBack({ 1824, 1120, 303, 224 });
	background2.PushBack({ 2128, 1120, 303, 224 });
	background2.PushBack({ 2432, 1120, 303, 224 });
	background2.PushBack({ 2736, 1120, 303, 224 });
	background2.PushBack({ 1520, 1344, 303, 224 });
	background2.PushBack({ 1824, 1344, 303, 224 });
	background2.PushBack({ 2128, 1344, 303, 224 });
	background2.PushBack({ 2432, 1344, 303, 224 });
	background2.PushBack({ 2736, 1344, 303, 224 });
	background2.PushBack({ 1520, 1568, 303, 224 });
	background2.PushBack({ 1824, 1568, 303, 224 });
	background2.PushBack({ 2128, 1568, 303, 224 });
	background2.PushBack({ 2432, 1568, 303, 224 });
	background2.PushBack({ 2736, 1568, 303, 224 });
	background2.PushBack({ 1520, 1792, 303, 224 });
	background2.PushBack({ 1824, 1792, 303, 224 });
	background2.PushBack({ 2128, 1792, 303, 224 });
	background2.PushBack({ 2432, 1792, 303, 224 });
	background2.PushBack({ 2736, 1792, 303, 224 });
	background2.PushBack({ 1520, 2016, 303, 224 });
	background2.PushBack({ 1824, 2016, 303, 224 });
	background2.PushBack({ 2128, 2016, 303, 224 });
	background2.PushBack({ 2432, 2016, 303, 224 });
	background2.PushBack({ 2736, 2016, 303, 224 });
	background2.PushBack({ 1520, 2240, 303, 224 });
	background2.PushBack({ 1824, 2240, 303, 224 });
	background2.PushBack({ 2128, 2240, 303, 224 });
	background2.PushBack({ 2432, 2240, 303, 224 });
	background2.PushBack({ 2736, 2240, 303, 224 });
	background2.PushBack({ 1520, 2464, 303, 224 });
	background2.PushBack({ 1824, 2464, 303, 224 });
	background2.PushBack({ 2128, 2464, 303, 224 });
	background2.PushBack({ 2432, 2464, 303, 224 });
	background2.PushBack({ 2736, 2464, 303, 224 });
	background2.PushBack({ 1520, 2688, 303, 224 });
	background2.PushBack({ 1824, 2688, 303, 224 });
	background2.PushBack({ 2128, 2688, 303, 224 });
	background2.PushBack({ 2432, 2688, 303, 224 });
	background2.PushBack({ 2736, 2688, 303, 224 });
	background2.PushBack({ 1520, 2912, 303, 224 });
	background2.PushBack({ 1824, 2912, 303, 224 });
	background2.PushBack({ 2128, 2912, 303, 224 });
	background2.PushBack({ 2432, 2912, 303, 224 });
	background2.PushBack({ 2736, 2912, 303, 224 });
	background2.PushBack({ 1520, 3136, 303, 224 });
	background2.PushBack({ 1824, 3136, 303, 224 });
	background2.PushBack({ 2128, 3136, 303, 224 });
	background2.PushBack({ 2432, 3136, 303, 224 });
	background2.PushBack({ 2736, 3136, 303, 224 });
	background2.PushBack({ 1520, 3360, 303, 224 });
	background2.PushBack({ 1824, 3360, 303, 224 });
	background2.PushBack({ 2128, 3360, 303, 224 });
	background2.PushBack({ 2432, 3360, 303, 224 });
	background2.PushBack({ 2736, 3360, 303, 224 });
	background2.PushBack({ 1520, 3584, 303, 224 });
	background2.PushBack({ 1824, 3584, 303, 224 });
	background2.PushBack({ 2128, 3584, 303, 224 });
	background2.PushBack({ 2432, 3584, 303, 224 });
	background2.PushBack({ 2736, 3584, 303, 224 });
	background2.PushBack({ 1520, 3808, 303, 224 });
	background2.PushBack({ 1824, 3808, 303, 224 });
	background2.PushBack({ 2128, 3808, 303, 224 });
	background2.PushBack({ 2432, 3808, 303, 224 });
	background2.PushBack({ 2736, 3808, 303, 224 });
	background2.PushBack({ 1520, 4032, 303, 224 });
	background2.PushBack({ 1824, 4032, 303, 224 });
	background2.PushBack({ 2128, 4032, 303, 224 });
	background2.PushBack({ 2432, 4032, 303, 224 });
	background2.PushBack({ 2736, 4032, 303, 224 });

	background2.PushBack({ 3040, 0, 303, 224 });
	background2.PushBack({ 3344, 0, 303, 224 });
	background2.PushBack({ 3648, 0, 303, 224 });
	background2.PushBack({ 3952, 0, 303, 224 });
	background2.PushBack({ 4256, 0, 303, 224 });
	background2.PushBack({ 3040, 224, 303, 224 });
	background2.PushBack({ 3344, 224, 303, 224 });
	background2.PushBack({ 3648, 224, 303, 224 });
	background2.PushBack({ 3952, 224, 303, 224 });
	background2.PushBack({ 4256, 224, 303, 224 });
	background2.PushBack({ 3040, 448, 303, 224 });
	background2.PushBack({ 3344, 448, 303, 224 });
	background2.PushBack({ 3648, 448, 303, 224 });
	background2.PushBack({ 3952, 448, 303, 224 });
	background2.PushBack({ 4256, 448, 303, 224 });
	background2.PushBack({ 3040, 672, 303, 224 });
	background2.PushBack({ 3344, 672, 303, 224 });
	background2.PushBack({ 3648, 672, 303, 224 });
	background2.PushBack({ 3952, 672, 303, 224 });
	background2.PushBack({ 4256, 672, 303, 224 });
	background2.PushBack({ 3040, 896, 303, 224 });
	background2.PushBack({ 3344, 896, 303, 224 });
	background2.PushBack({ 3648, 896, 303, 224 });
	background2.PushBack({ 3952, 896, 303, 224 });
	background2.PushBack({ 4256, 896, 303, 224 });
	background2.PushBack({ 3040, 1120, 303, 224 });
	background2.PushBack({ 3344, 1120, 303, 224 });
	background2.PushBack({ 3648, 1120, 303, 224 });
	background2.PushBack({ 3952, 1120, 303, 224 });
	background2.PushBack({ 4256, 1120, 303, 224 });
	background2.PushBack({ 3040, 1344, 303, 224 });
	background2.PushBack({ 3344, 1344, 303, 224 });
	background2.PushBack({ 3648, 1344, 303, 224 });
	background2.PushBack({ 3952, 1344, 303, 224 });
	background2.PushBack({ 4256, 1344, 303, 224 });
	background2.PushBack({ 3040, 1568, 303, 224 });
	background2.PushBack({ 3344, 1568, 303, 224 });
	background2.PushBack({ 3648, 1568, 303, 224 });
	background2.PushBack({ 3952, 1568, 303, 224 });
	background2.PushBack({ 4256, 1568, 303, 224 });
	background2.PushBack({ 3040, 1792, 303, 224 });
	background2.PushBack({ 3344, 1792, 303, 224 });
	background2.PushBack({ 3648, 1792, 303, 224 });
	background2.PushBack({ 3952, 1792, 303, 224 });
	background2.PushBack({ 4256, 1792, 303, 224 });
	background2.PushBack({ 3040, 2016, 303, 224 });
	background2.PushBack({ 3344, 2016, 303, 224 });
	background2.PushBack({ 3648, 2016, 303, 224 });
	background2.PushBack({ 3952, 2016, 303, 224 });
	background2.PushBack({ 4256, 2016, 303, 224 });
	background2.PushBack({ 3040, 2240, 303, 224 });
	background2.PushBack({ 3344, 2240, 303, 224 });
	background2.PushBack({ 3648, 2240, 303, 224 });
	background2.PushBack({ 3952, 2240, 303, 224 });
	background2.PushBack({ 4256, 2240, 303, 224 });
	background2.PushBack({ 3040, 2464, 303, 224 });
	background2.PushBack({ 3344, 2464, 303, 224 });
	background2.PushBack({ 3648, 2464, 303, 224 });
	background2.PushBack({ 3952, 2464, 303, 224 });
	background2.PushBack({ 4256, 2464, 303, 224 });
	background2.PushBack({ 3040, 2688, 303, 224 });
	background2.PushBack({ 3344, 2688, 303, 224 });
	background2.PushBack({ 3648, 2688, 303, 224 });
	background2.PushBack({ 3952, 2688, 303, 224 });
	background2.PushBack({ 4256, 2688, 303, 224 });
	background2.PushBack({ 3040, 2912, 303, 224 });
	background2.PushBack({ 3344, 2912, 303, 224 });
	background2.PushBack({ 3648, 2912, 303, 224 });
	background2.PushBack({ 3952, 2912, 303, 224 });
	background2.PushBack({ 4256, 2912, 303, 224 });
	background2.PushBack({ 3040, 3136, 303, 224 });
	background2.PushBack({ 3344, 3136, 303, 224 });
	background2.PushBack({ 3648, 3136, 303, 224 });
	background2.PushBack({ 3952, 3136, 303, 224 });
	background2.PushBack({ 4256, 3136, 303, 224 });
	background2.PushBack({ 3040, 3360, 303, 224 });
	background2.PushBack({ 3344, 3360, 303, 224 });
	background2.PushBack({ 3648, 3360, 303, 224 });
	background2.PushBack({ 3952, 3360, 303, 224 });
	background2.PushBack({ 4256, 3360, 303, 224 });
	background2.PushBack({ 3040, 3584, 303, 224 });
	background2.PushBack({ 3344, 3584, 303, 224 });
	background2.PushBack({ 3648, 3584, 303, 224 });
	background2.PushBack({ 3952, 3584, 303, 224 });
	background2.PushBack({ 4256, 3584, 303, 224 });
	background2.PushBack({ 3040, 3808, 303, 224 });
	background2.PushBack({ 3344, 3808, 303, 224 });
	background2.PushBack({ 3648, 3808, 303, 224 });
	background2.PushBack({ 3952, 3808, 303, 224 });
	background2.PushBack({ 4256, 3808, 303, 224 });
	background2.PushBack({ 3040, 4032, 303, 224 });
	background2.PushBack({ 3344, 4032, 303, 224 });
	background2.PushBack({ 3648, 4032, 303, 224 });
	background2.PushBack({ 3952, 4032, 303, 224 });
	background2.PushBack({ 4256, 4032, 303, 224 });
	background2.speed = 0.8f;




	background.PushBack({ 0, 0, 303, 224 });
	background.PushBack({ 304, 0, 303, 224 });
	background.PushBack({ 608, 0, 303, 224 });
	background.PushBack({ 912, 0, 303, 224 });
	background.PushBack({ 1216, 0, 303, 224 });
	background.PushBack({ 0, 224, 303, 224 });
	background.PushBack({ 304, 224, 303, 224 });
	background.PushBack({ 608, 224, 303, 224 });
	background.PushBack({ 912, 224, 303, 224 });
	background.PushBack({ 1216, 224, 303, 224 });
	background.PushBack({ 0, 448, 303, 224 });
	background.PushBack({ 304, 448, 303, 224 });
	background.PushBack({ 608, 448, 303, 224 });
	background.PushBack({ 912, 448, 303, 224 });
	background.PushBack({ 1216, 448, 303, 224 });
	background.PushBack({ 0, 672, 303, 224 });
	background.PushBack({ 304, 672, 303, 224 });
	background.PushBack({ 608, 672, 303, 224 });
	background.PushBack({ 912, 672, 303, 224 });
	background.PushBack({ 1216, 672, 303, 224 });
	background.PushBack({ 0, 896, 303, 224 });
	background.PushBack({ 304, 896, 303, 224 });
	background.PushBack({ 608, 896, 303, 224 });
	background.PushBack({ 912, 896, 303, 224 });
	background.PushBack({ 1216, 896, 303, 224 });
	background.PushBack({ 0, 1120, 303, 224 });
	background.PushBack({ 304, 1120, 303, 224 });
	background.PushBack({ 608, 1120, 303, 224 });
	background.PushBack({ 912, 1120, 303, 224 });
	background.PushBack({ 1216, 1120, 303, 224 });
	background.PushBack({ 0, 1344, 303, 224 });
	background.PushBack({ 304, 1344, 303, 224 });
	background.PushBack({ 608, 1344, 303, 224 });
	background.PushBack({ 912, 1344, 303, 224 });
	background.PushBack({ 1216, 1344, 303, 224 });
	background.PushBack({ 0, 1568, 303, 224 });
	background.PushBack({ 304, 1568, 303, 224 });
	background.PushBack({ 608, 1568, 303, 224 });
	background.PushBack({ 912, 1568, 303, 224 });
	background.PushBack({ 1216, 1568, 303, 224 });
	background.PushBack({ 0, 1792, 303, 224 });
	background.PushBack({ 304, 1792, 303, 224 });
	background.PushBack({ 608, 1792, 303, 224 });
	background.PushBack({ 912, 1792, 303, 224 });
	background.PushBack({ 1216, 1792, 303, 224 });
	background.PushBack({ 0, 2016, 303, 224 });
	background.PushBack({ 304, 2016, 303, 224 });
	background.PushBack({ 608, 2016, 303, 224 });
	background.PushBack({ 912, 2016, 303, 224 });
	background.PushBack({ 1216, 2016, 303, 224 });
	background.PushBack({ 0, 2240, 303, 224 });
	background.PushBack({ 304, 2240, 303, 224 });
	background.PushBack({ 608, 2240, 303, 224 });
	background.PushBack({ 912, 2240, 303, 224 });
	background.PushBack({ 1216, 2240, 303, 224 });
	background.PushBack({ 0, 2464, 303, 224 });
	background.PushBack({ 304, 2464, 303, 224 });
	background.PushBack({ 608, 2464, 303, 224 });
	background.PushBack({ 912, 2464, 303, 224 });
	background.PushBack({ 1216, 2464, 303, 224 });
	background.PushBack({ 0, 2688, 303, 224 });
	background.PushBack({ 304, 2688, 303, 224 });
	background.PushBack({ 608, 2688, 303, 224 });
	background.PushBack({ 912, 2688, 303, 224 });
	background.PushBack({ 1216, 2688, 303, 224 });
	background.PushBack({ 0, 2912, 303, 224 });
	background.PushBack({ 304, 2912, 303, 224 });
	background.PushBack({ 608, 2912, 303, 224 });
	
	background.speed = 0.8f;

}




ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading background assets");

	bool ret = true;
	

	graphics1 = App->textures->Load("Assets/Sprites/Intro_1.png");
	graphics2 = App->textures->Load("Assets/Sprites/Intro_2.png");
	graphics = App->textures->Load("Assets/Sprites/Intro7.png");
	App->audio->PlayMusic("Assets/music/Fatal_Fury_Intro/Fatal_Fury_Intro.ogg", 0);

	// TODO 1: Enable (and properly disable) the player module
	App->render->camera.x = 0;
	App->render->camera.y = -10;
	App->player->destroyed = true;
	App->player2->destroyed = true;
	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{

	graphics = nullptr;
	graphics1 = nullptr;
	graphics2 = nullptr;

	
	SDL_DestroyTexture(App->textures->Load("Assets/Sprites/Intro_1.png"));
	SDL_DestroyTexture(App->textures->Load("Assets/Sprites/Intro_2.png"));
	SDL_DestroyTexture(App->textures->Load("Assets/Sprites/Intro7.png"));

	//App->audio->CleanUp();
	LOG("Unloading intro stage");


	return true;
}

// Update: draw background
update_status ModuleSceneIntro::Update()
{
	if (!finish1)
	{
		App->render->Blit(graphics1, -7, -6, &(background1.GetCurrentFrame()), 0.70f);
	}
	if (background1.Finished())
	{
		finish1 = true;
	}
	if (finish1 && !finish2)
	{
		App->render->Blit(graphics2, -7, -6, &(background2.GetCurrentFrame()), 0.70f);
	}
	if (background2.Finished())
	{
		finish2 = true;
	}
	if (finish2)
	{
		App->render->Blit(graphics, -7, -6, &(background.GetCurrentFrame()), 0.70f);
	}
		

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack(App->intro, App->scene_2, 2.5);
	}



	return UPDATE_CONTINUE;
}
