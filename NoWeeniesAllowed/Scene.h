#pragma once
#include "framework.h"

#include "MainScene.h"
#include "MapScene.h"
#include "BattleScene.h"
#include "RewardScene.h"
#include "TrapScene.h"
#include "BossBattleScene.h"
#include "OptionScene.h"

SCENE_TYPE curScene;

void EnterScene();
void ExitScene();

void SceneUpdate()
{
	switch (curScene)
	{
	case MAIN:
		EnterScene();
		MainSceneUpdate();
		ExitScene();
		break;
	case MAP:
		EnterScene();
		MapSceneUpdate();
		ExitScene();
		break;
	case BATTLE:
		EnterScene();
		BattleSceneUpdate();
		ExitScene();
		break;
	case REWARD:
		EnterScene();
		RewardSceneUpdate();
		ExitScene();
		break;
	case TRAP:
		EnterScene();
		TrapSceneUpdate();
		ExitScene();
		break;
	case BOSS:
		EnterScene();
		BossBattleSceneUpdate();
		ExitScene();
		break;
	case OPTION:
		EnterScene();
		OptionSceneUpdate();
		ExitScene();
		break;
	default:
		break;
	}
}