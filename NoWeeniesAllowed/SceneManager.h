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
	// �� ��ȯ �� ȭ�� ����
	system("cls");
}
