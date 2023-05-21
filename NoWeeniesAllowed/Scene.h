#pragma once
#include "framework.h"

#include "MainScene.h"
#include "MapScene.h"
#include "BattleScene.h"
#include "RewardScene.h"
#include "TrapScene.h"
#include "BossBattleScene.h"

int curScene = 0;

void EnterScene();
void ExitScene();

void SceneUpdate()
{
	switch (curScene)
	{
	case 0:
		EnterScene();
		MainSceneUpdate();
		ExitScene();
		break;
	case 1:
		EnterScene();
		MapSceneUpdate();
		ExitScene();
		break;
	case 2:
		EnterScene();
		BattleSceneUpdate();
		ExitScene();
		break;
	case 3:
		EnterScene();
		RewardSceneUpdate();
		ExitScene();
		break;
	case 4:
		EnterScene();
		TrapSceneUpdate();
		ExitScene();
		break;
	case 5:
		EnterScene();
		BossBattleSceneUpdate();
		ExitScene();
		break;
	default:
		break;
	}
}