#include "SampleKeyEventHandler.h"

#include "debug.h"
#include "Game.h"

#include "Mario.h"
#include "PlayScene.h"

void CSampleKeyHandler::OnKeyDown(int KeyCode)
{
	//DebugOut(L"[INFO] KeyDown: %d\n", KeyCode);
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	if (!mario->GetIsPrepareEndScene()) {
		switch (KeyCode)
		{

		case DIK_5:
			mario->SetPosition(3340, 0); // To Hidden Map
			break;
		case DIK_6:
			mario->SetPosition(16, 300); // return start world 1-1
			break;
		case DIK_7:
			mario->SetPosition(2325, 342);// out hidden map
			break;
		case DIK_DOWN:
			mario->SetState(MARIO_STATE_SIT);
			break;
		case DIK_S:
			if (mario->GetIsOnPlatform()) {
				mario->SetState(MARIO_STATE_JUMP);
			}
			else {
				if (mario->GetLevel() == MARIO_LEVEL_TAIL) mario->SetState(MARIO_STATE_FLY);
			}

			break;
		case DIK_1:
			mario->SetLevel(MARIO_LEVEL_SMALL);
			break;
		case DIK_A:
			if (mario->GetLevel() == MARIO_LEVEL_TAIL) mario->SetState(MARIO_STATE_TAIL_ATTACK);
			else if (mario->GetLevel() == MARIO_LEVEL_FIRE) mario->SetState(MARIO_STATE_SHOOT);
			break;
		case DIK_2:
			mario->SetLevel(MARIO_LEVEL_BIG);
			break;
		case DIK_3:
			mario->SetLevel(MARIO_LEVEL_FIRE);
			break;
		case DIK_4:
			mario->SetLevel(MARIO_LEVEL_TAIL);
			break;
		case DIK_0:
			mario->SetState(MARIO_STATE_DIE);
			break;
		case DIK_UP:
			mario->SetIsPrepareUp(true);
			break;
		case DIK_RIGHT:
			if (mario->GetState() == MARIO_STATE_JUMP) mario->SetState(MARIO_STATE_WALKING_RIGHT);
			break;
		case DIK_LEFT:
			if (mario->GetState() == MARIO_STATE_JUMP) mario->SetState(MARIO_STATE_WALKING_LEFT);
			break;
		case DIK_R: // reset
			//Reload();
			break;
		}
	}
}

void CSampleKeyHandler::OnKeyUp(int KeyCode)
{
	//DebugOut(L"[INFO] KeyUp: %d\n", KeyCode);

	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	if (!mario->GetIsPrepareEndScene()) {
		switch (KeyCode)
		{
		case DIK_UP:
			mario->SetIsPrepareUp(false);
			break;
		case DIK_S:
			mario->SetState(MARIO_STATE_RELEASE_JUMP);
			break;
		case DIK_DOWN:
			if (!mario->GetIsHolding())
				mario->SetState(MARIO_STATE_SIT_RELEASE);
			break;
		case DIK_A:
			if (mario->GetIsHolding()) mario->SetIsHolding(false);
			break;
		}
	}
}

void CSampleKeyHandler::KeyState(BYTE* states)
{
	LPGAME game = CGame::GetInstance();
	CMario* mario = (CMario*)((LPPLAYSCENE)CGame::GetInstance()->GetCurrentScene())->GetPlayer();
	if (!mario->GetIsPrepareEndScene()) {
		if (game->IsKeyDown(DIK_RIGHT))
		{
			if (game->IsKeyDown(DIK_A))
				mario->SetState(MARIO_STATE_RUNNING_RIGHT);
			else if (game->IsKeyDown(DIK_S)) {
				if (mario->GetIsOnPlatform()) {
					mario->SetState(MARIO_STATE_JUMP);
				}
			}
			else if (game->IsKeyDown(DIK_DOWN)) {
				mario->SetState(MARIO_STATE_SIT);
			}
			else mario->SetState(MARIO_STATE_WALKING_RIGHT);
		}
		else if (game->IsKeyDown(DIK_LEFT))
		{
			if (game->IsKeyDown(DIK_A))
				mario->SetState(MARIO_STATE_RUNNING_LEFT);
			else if (game->IsKeyDown(DIK_S)) {
				if (mario->GetIsOnPlatform()) {
					mario->SetState(MARIO_STATE_JUMP);
				}
			}
			else if (game->IsKeyDown(DIK_DOWN)) {
				mario->SetState(MARIO_STATE_SIT);
			}
			else mario->SetState(MARIO_STATE_WALKING_LEFT);
		}
		else if (game->IsKeyDown(DIK_DOWN)) mario->SetState(MARIO_STATE_SIT);
		else mario->SetState(MARIO_STATE_IDLE);
	}
}