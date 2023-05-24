#pragma once
#include "framework.h"
#include "Scene.h"

void SceneManagerInit();
void SceneManagerUpdate();
void ChangeScene(SCENE_TYPE scene);
void EnterScene();
void ExitScene();

void SceneManagerInit()
{
}

void SceneManagerUpdate()
{
	SceneUpdate();
}

void ChangeScene(SCENE_TYPE scene)
{
	curScene = scene;
}

void EnterScene()
{

}

void ExitScene()
{
	// �� ��ȯ �� ȭ�� ����
	system("cls");
}
