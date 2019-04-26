#pragma once

#include "Module.h"


struct _Mix_Music;
typedef _Mix_Music Mix_Music;

struct Mix_Chunk;

class ModuleAudio : public Module
{
public:
	bool PlayMusic(const char* path);
	bool StopMusic();
	void MuteMusic(const char* path);
	//size_t LoadFx(const char* path);
	//bool PlayFx(size_t fx);
	bool PlayFX(const char* path);

	//NÚRIA
	bool mute = false;
	bool mutefx = false;


	bool Init() override;
	bool CleanUp() override;

private:
	Mix_Music* music = nullptr;
	Mix_Chunk* fx = nullptr;
};