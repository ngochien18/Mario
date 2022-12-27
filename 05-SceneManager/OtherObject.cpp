#include "OtherObject.h"


void COtherObject::Render()
{
	CAnimations* animations = CAnimations::GetInstance();
	if (model == CARD_WORLD_MAP) {
		animations->Get(ID_ANI_CARD)->Render(x, y);
	}
	//RenderBoundingBox();
}

void COtherObject::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - OBJECT_BBOX_WIDTH / 2;
	t = y - OBJECT_BBOX_HEIGHT / 2;
	r = l + OBJECT_BBOX_WIDTH;
	b = t + OBJECT_BBOX_HEIGHT;
}