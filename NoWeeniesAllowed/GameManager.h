#pragma once
#include "framework.h"
#include "Player.h"
#include "Enemy.h"

// ≥≠¿Ãµµ
// 0, 1, 2

int difficulty = 0;

void GameManagerInit()
{
	SkillInit();
	PlayerInit();
	EnemyInit();
}

void GameManagerUpdate()
{
}