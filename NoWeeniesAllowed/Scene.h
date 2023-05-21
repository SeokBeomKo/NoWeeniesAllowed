#pragma once
#include "framework.h"

#include "MainScene.h"
#include "MapScene.h"
#include "BattleScene.h"
#include "BossBattleScene.h"

typedef struct scene Scene;


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
		BossBattleSceneUpdate();
		ExitScene();
		break;
	default:
		break;
	}
}