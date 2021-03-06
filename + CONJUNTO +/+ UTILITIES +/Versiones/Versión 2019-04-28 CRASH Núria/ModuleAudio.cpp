#include "ModuleAudio.h"
#include "SDL_mixer/include/SDL_mixer.h"
#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )

//N�RIA
#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"



bool ModuleAudio::PlayMusic(const char* path, const int times)
{

	//N�RIA
	//if (App->input->keyboard[SDL_SCANCODE_F9] == KEY_STATE::KEY_DOWN)
	//{
	//	if (mute == false)
	//	{
	//		LOG("MUTE");
	//		mute = true;
	//	}
	//	else
	//	{
	//		LOG("UNMUTE");
	//		mute = false;
	//		
	//	}

	//}


	if (music)
	{
		while (!Mix_FadeOutMusic(3000) && Mix_PlayingMusic()) {
			// wait for any fades to complete
			SDL_Delay(90);
		}
		Mix_FreeMusic(music);
	}

	music = Mix_LoadMUS(path);

	if (!music)
	{
		LOG("Music %s could not load. Mix_Error: %s\n", path, Mix_GetError());
		return false;
	}

	if (Mix_FadeInMusic(music, times, 2000) < 0) {
		LOG("Mix_FadeInMusic: %s\n", Mix_GetError());
		return false;
	}

	LOG("Succesfully playing %s\n", path);
	return true;
}

bool ModuleAudio::StopMusic()
{
	if (music)
	{
		while (!Mix_FadeOutMusic(3000) && Mix_PlayingMusic()) {
			// wait for any fades to complete
			SDL_Delay(90);
		}
		Mix_FreeMusic(music);
		music = nullptr;
	}
	return true;
}

void ModuleAudio::MuteMusic(const char* path, const int times)
{
	if (!mute)
	{
		Mix_FreeMusic(music);
		music = nullptr;
		mute = true;
	}
	else
	{
		App->audio->PlayMusic(path, times);
		mute = false;
	}
}

bool ModuleAudio::PlayFX(const char* path)
{

	//N�RIA
	/*if (App->input->keyboard[SDL_SCANCODE_F10] == KEY_STATE::KEY_DOWN)
	{
		if (mutefx == false)
		{
			LOG("MUTE FX");
			mutefx = true;
		}
		else
		{
			LOG("UNMUTE FX");
			mutefx = false;
		}

	}*/



	if (fx[cont])
	{
		Mix_FreeChunk(fx[cont]);
	}
	fx[cont] = Mix_LoadWAV(path);
	if (!fx)
	{
		LOG("Fx %s could not load. Mix_Error: %s\n", path, Mix_GetError());
		return false;
	}

	Mix_PlayChannel(-1, fx[cont], 0);
	++cont;
	if (cont == 10)
	{
		cont = 0;
	}
	return true;
}

bool ModuleAudio::Init()
{
	LOG("Init SDL audio mixer");
	SDL_Init(0);

	if (SDL_InitSubSystem(SDL_INIT_AUDIO) < 0)
	{
		LOG("SDL_INIT_AUDIO could not initialize! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	int flags = MIX_INIT_OGG;
	int init = Mix_Init(flags);

	if ((init & flags) != flags)
	{
		LOG("SDL_INIT_AUDIO could not initialize mixer lib! Mix_Error: %s\n", Mix_GetError());
		return false;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		LOG("SDL_MIXER could not initialize! SDL_MIXER Error: %s\n", Mix_GetError());
		return false;
	}

	return true;
}
bool ModuleAudio::CleanUp()
{
	if (music)
	{
		Mix_FreeMusic(music);
		music = nullptr;
	}
	for (int i = 0; i < 10; ++i)
	{
		if (fx[i])
		{
			Mix_FreeChunk(fx[i]);
			fx[i] = nullptr;
		}
	}
	

	Mix_CloseAudio();
	Mix_Quit();
	SDL_QuitSubSystem(SDL_INIT_AUDIO);
	return true;
}