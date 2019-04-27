#include "Application.h"
#include "ModuleWindow.h"
#include "ModuleRender.h"
#include "ModuleInput.h"
#include "ModuleTextures.h"
#include "ModuleScene1.h"
#include "ModuleScene2.h"
#include "ModulePlayer.h"
#include "ModulePlayer2.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneWinP1.h"
#include "ModuleSceneWinP2.h"
#include "ModuleSceneTie.h"
#include "ModuleSceneIni.h"
#include "ModuleParticles.h"
#include "ModuleCollision.h"
#include "ModuleAudio.h"
#include "ModuleFonts.h"


Application::Application()
{
	modules[0] = window = new ModuleWindow();
	modules[1] = render = new ModuleRender();
	modules[2] = input = new ModuleInput();
	modules[3] = audio = new ModuleAudio();
	modules[4] = textures = new ModuleTextures();
	modules[5] = scene_2 = new ModuleScene2();
	modules[6] = scene_1 = new ModuleScene1();
	modules[7] = end_game1 = new ModuleSceneWinP1();
	modules[8] = end_game2 = new ModuleSceneWinP2();
	modules[9] = tie = new ModuleSceneTie();
	modules[10] = ini = new ModuleSceneIni();
	modules[11] = player = new ModulePlayer();
	modules[12] = player2 = new ModulePlayer2();
	modules[13] = fade = new ModuleFadeToBlack();
	modules[14] = particles = new ModuleParticles();
	modules[15] = collisions = new ModuleCollision();
	modules[16] = fonts = new ModuleFonts();
}	

Application::~Application()
{
	for(int i = NUM_MODULES - 1; i >= 0; --i)
		delete modules[i];
}

bool Application::Init()
{
	bool ret = true;

	// Player will be enabled on the first update of a new scene
	player->Disable();
	player2->Disable();
	// Disable the map that you do not start with
	scene_2->Disable();
	scene_1->Disable();
	end_game1->Disable();
	end_game2->Disable();
	tie->Disable();
	collisions->Disable();

	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->Init();

	for(int i = 0; i < NUM_MODULES && ret == true; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Start() : true;

	return ret;
}

update_status Application::Update()
{
	update_status ret = UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PreUpdate() : UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->Update() : UPDATE_CONTINUE;

	for(int i = 0; i < NUM_MODULES && ret == UPDATE_CONTINUE; ++i)
		ret = modules[i]->IsEnabled() ? modules[i]->PostUpdate() : UPDATE_CONTINUE;

	return ret;
}

bool Application::CleanUp()
{
	bool ret = true;

	for(int i = NUM_MODULES - 1; i >= 0 && ret == true; --i)
		ret = modules[i]->CleanUp();

	return ret;
}