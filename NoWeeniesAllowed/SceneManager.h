#pragma once
#include "framework.h"
#include "Scene.h"


void ChangeScene(int scene);
void EnterScene();
void ExitScene();

void SceneManagerInit()
{
}

void SceneManagerUpdate()
{
	SceneUpdate();
}

void ChangeScene(int scene)
{
	curScene = scene;
}

void EnterScene()
{

}

void ExitScene()
{
	// 씬 전환 시 화면 정리
	system("cls");
}
