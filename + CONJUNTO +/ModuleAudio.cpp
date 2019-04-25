#include "ModuleAudio.h"
#include "SDL_mixer/include/SDL_mixer.h"
#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL_mixer/libx86/SDL2_mixer.lib" )

bool ModuleAudio::PlayMusic(const char* path)
{
	if (music)
	{
		Mix_FreeMusic(music);
	}

	music = Mix_LoadMUS(path);

	if (!music)
	{
		LOG("Music %s could not load. Mix_Error: %s\n", path, Mix_GetError());
		return false;
	}

	if (Mix_PlayMusic(music, -1) < 0)
	{
		LOG("Music %s could not play. Mix_Error: %s\n", path, Mix_GetError());
		return false;
	}

	LOG("Succesfully playing %s\n", path);
	return true;
}

bool ModuleAudio::PlayFX(const char* path)
{
	if (fx)
	{
		Mix_FreeChunk(fx);
	}
	fx = Mix_LoadWAV(path);
	if (!fx)
	{
		LOG("Fx %s could not load. Mix_Error: %s\n", path, Mix_GetError());
		return false;
	}

	Mix_PlayChannel(-1, fx, 0);
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

	if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
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
	}
	if (fx)
	{
		Mix_FreeChunk(fx);
	}

	Mix_CloseAudio();
	Mix_Quit();
	SDL_QuitSubSystem(SDL_INIT_AUDIO);
	return true;
}