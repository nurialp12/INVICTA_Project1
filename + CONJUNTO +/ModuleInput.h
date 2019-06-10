#ifndef __ModuleInput_H__
#define __ModuleInput_H__

#include "Module.h"
#include "Globals.h"
#include "SDL\include\SDL_scancode.h"
#include "SDL/include/SDL.h"

#define MAX_KEYS 300
#define MAX_BUTTONS 15
#define MAX_GAMEPADS 2
#define MAX_COMMAND_FRAMES 180

enum class InputCommandTypes {
	special_attack,
	punch,
	max
};

struct InputCommand {
	InputCommandTypes type = InputCommandTypes::max;

	InputCommand(InputCommandTypes type) :type(type) {}
	virtual bool Check(uint past_frames) const = 0;
};

struct CommandPunch :public InputCommand {
	CommandPunch() :InputCommand(InputCommandTypes::punch) {}
	bool Check(uint frames_past) const override;
};

struct CommandSpecialAttack : public InputCommand {
	CommandSpecialAttack() :InputCommand(InputCommandTypes::special_attack) {}
	bool Check(uint frames_past) const override;
};

struct History {
	uint frame = 0u;
	KEY_STATE keyboard[MAX_KEYS];
	Uint8 gpad[MAX_GAMEPADS];
};

enum KEY_STATE
{
	KEY_IDLE = 0,
	KEY_DOWN,
	KEY_REPEAT,
	KEY_UP
};

enum BUTTON_STATE
{
	BUT_IDLE = 0,
	BUT_DOWN,
	BUT_REPEAT,
	BUT_UP
};

class ModuleInput : public Module
{
public:

	ModuleInput();
	~ModuleInput();

	bool Init();
	update_status PreUpdate();
	bool CleanUp();

public:
	KEY_STATE keyboard[MAX_KEYS];
	Uint8 gpad[MAX_BUTTONS][MAX_GAMEPADS];
	SDL_GameController* gController1 = NULL;
	SDL_GameController* gController2 = NULL;
};

#endif // __ModuleInput_H__