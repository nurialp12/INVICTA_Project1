#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include "SDL/include/SDL_rect.h"
#define MAX_FRAMES 700


////NÚRIA
//enum class FacingDirection
//{
//	None,
//	Left,
//	Right
//};


class Animation
{
public:
	bool loop = true;
	float speed = 1.0f;
	SDL_Rect frames[MAX_FRAMES];

private:
	float current_frame;
	int last_frame = 0;
	int loops = 0;

	////NÚRIA
	//FacingDirection direction;

public:
	void resetLoops(int a)
	{
		loops = a;
	}
	void PushBack(const SDL_Rect& rect)
	{
		frames[last_frame++] = rect;
	}

	SDL_Rect& GetCurrentFrame()
	{
		current_frame += speed;
		if (current_frame >= last_frame)
		{
			current_frame = (loop) ? 0.0f : last_frame - 1;
			loops++;
		}

		return frames[(int)current_frame];
	}

	bool Finished() const
	{
		return loops > 0;
	}

	void Reset()
	{
		current_frame = 0;
	}

	////NÚRIA
	//Animation(FacingDirection direction);

	//void SetDirection(FacingDirection dir);
	//FacingDirection GetDirection() const;


};

#endif