#pragma once
#include "framework.h"
#include "Player.h"
#include "Enemy.h"

// ���̵�
// 0, 1, 2

int difficulty = 0;

void GameManagerInit()
{
	PlayerInit();
	EnemyInit();
}

void GameManagerUpdate()
{
}