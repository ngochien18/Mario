#include "Card.h"

#include "debug.h"
void CCard::Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects) {
	if (!checkObjectInCamera(this)) return;

	//DebugOutTitle(L"CARD %d", card);
	if (!isCollected) {
		if (GetTickCount64() - start_change > TIME_CHANGE_CARD) {
			if (card == CARD_MUSHROOM) card = CARD_FLOWER;
			else if (card == CARD_FLOWER) card = CARD_STAR;
			else if (card == CARD_STAR) card = CARD_MUSHROOM;
			start_change = GetTickCount64();
		}
	}

	CGameObject::Update(dt, coObjects);
	CCollision::GetInstance()->Process(this, dt, coObjects);
}
void CCard::Render()
{
	if (!checkObjectInCamera(this)) return;

	int aniId = ID_ANI_CARD_MUSHROOM;
	CAnimations* animations = CAnimations::GetInstance();
	if (card == CARD_MUSHROOM) aniId = ID_ANI_CARD_MUSHROOM;
	else if (card == CARD_FLOWER) aniId = ID_ANI_CARD_FLOWER;
	else if (card == CARD_STAR) aniId = ID_ANI_CARD_STAR;
	animations->Get(aniId)->Render(x, y);
	//RenderBoundingBox();
}

void CCard::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	l = x - CARD_BBOX_WIDTH / 2;
	t = y - CARD_BBOX_HEIGHT / 2;
	r = l + CARD_BBOX_WIDTH;
	b = t + CARD_BBOX_HEIGHT;
}

void CCard::SetState(int state) {
	switch (state) {
	case CARD_STATE_COLLECTED:
		isCollected = true;
		vy = -SPEED_CARD;
		break;
	}
	CGameObject::SetState(state);
}