#include "Globals.h"
#include "Application.h"
#include "ModuleInput.h"
#include "SDL/include/SDL.h"

ModuleInput::ModuleInput() : Module()
{
	for (uint i = 0; i < MAX_KEYS; ++i)
		keyboard[i] = KEY_IDLE;
	for (uint i = 0; i < MAX_BUTTONS; ++i) 
		for (int j = 0; j < 2; ++j) 
			gpad[i][j] = KEY_IDLE;
}

// Destructor
ModuleInput::~ModuleInput()
{
}

// Called before render is available
bool ModuleInput::Init()
{
	LOG("Init SDL input event system");
	bool ret = true;
	SDL_Init(0);

	if (SDL_Init(SDL_INIT_GAMECONTROLLER) < 0)
	{
		LOG("SDL_GAMECONTROLLER could not initialize! SDL_Error:\n");
		ret = false;
	}

	if (SDL_InitSubSystem(SDL_INIT_EVENTS) < 0)
	{
		LOG("SDL_EVENTS could not initialize! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}

	return ret;
}

// Called every draw update
update_status ModuleInput::PreUpdate()
{
	SDL_PumpEvents();

	if (SDL_NumJoysticks() >= 1)
	{
		gController1 = SDL_GameControllerOpen(0);
		if (gController1 == NULL)
		{
			LOG("Game controller 1 wasn't initialized")
		}
	}

	if (SDL_NumJoysticks() >= 2)
	{
		gController2 = SDL_GameControllerOpen(1);
		if (gController2 == NULL)
		{
			LOG("Game controller 2 wasn't initialized")
		}
	}

	const Uint8* keys = SDL_GetKeyboardState(NULL);

	for (int i = 0; i < MAX_KEYS; ++i)
	{
		if (keys[i] == 1)
		{
			if (keyboard[i] == KEY_IDLE)
				keyboard[i] = KEY_DOWN;
			else
				keyboard[i] = KEY_REPEAT;
		}
		else
		{
			if (keyboard[i] == KEY_REPEAT || keyboard[i] == KEY_DOWN)
				keyboard[i] = KEY_UP;
			else
				keyboard[i] = KEY_IDLE;
		}
	}

	for (int i = 0; i < MAX_BUTTONS; ++i) {
		gpad[i][1] = SDL_GameControllerGetButton(gController1, (SDL_GameControllerButton)i);
		gpad[i][2] = SDL_GameControllerGetButton(gController2, (SDL_GameControllerButton)i);
	}

	for (int i = 0; i < MAX_BUTTONS; ++i) {

		for (int j = 0; j < MAX_GAMEPADS; ++j) {
			if (gpad[i][j] == KEY_IDLE) {
				gpad[i][j] == KEY_DOWN;
				break;
			}
			else {
				gpad[i][j] == KEY_REPEAT;
				break;
			}

			if (gpad[i][j] == KEY_REPEAT || gpad[i][j] == KEY_DOWN) {
				gpad[i][j] == KEY_UP;
				break;
			}
			else {
				gpad[i][j] == KEY_IDLE;
				break;
			}
		}

	}

	if (keyboard[SDL_SCANCODE_ESCAPE])
		return update_status::UPDATE_STOP;

	return update_status::UPDATE_CONTINUE;
}

// Called before quitting
bool ModuleInput::CleanUp()
{
	LOG("Quitting SDL input event subsystem");
	SDL_QuitSubSystem(SDL_INIT_EVENTS);
	LOG("Closing Gamepads");
	SDL_GameControllerClose(gController1);
	gController1 = NULL;
	return true;
}

bool CommandSpecialAttack::Check(uint frames_past)const {
	int count = 0;
	uint frame = 0u;

	for (uint i = 1u; i < frames_past; ++i)
	{
		if (count > 0 && (i - frame) > MAX_COMMAND_FRAMES)
			return false;

		/*const History* history = App->input->GetPrevious(i);
		if (!history)
			break;
		const GamePad* pad = &(history->pads[0]);
		switch (count){
		case 0: { if (pad->a){ ++count; frame = i;}} break;
		case 1: { if (pad->right && !pad->down) { ++count; frame = i; }} break;
		case 2: { if (pad->right && pad->down) { ++count; frame = i; }} break;
		case 3: {if (pad->down) return true; } break;
		}
		*/
	}
	return false;
}