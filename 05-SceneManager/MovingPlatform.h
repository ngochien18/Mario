#pragma once

#include "Platform.h"

class MovingPlatform :public CPlatform
{
protected:
	float mTop;
	float mBot;

public:
	MovingPlatform(float mTop, float mBot, float x, float y,
		float cell_width, float cell_height, int length,
		int sprite_id_begin, int sprite_id_middle, int sprite_id_end) : CPlatform(x,y,
		cell_width, cell_height, length,
		sprite_id_begin, sprite_id_middle, sprite_id_end)
	{
		this->mTop = mTop;
		this->mBot = mBot;
	}

	void Render();
	void Update(DWORD dt) {}
	void GetBoundingBox(float& l, float& t, float& r, float& b);
	void RenderBoundingBox();
};

typedef MovingPlatform* LPPLATFORM;