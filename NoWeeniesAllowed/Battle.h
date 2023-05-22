#pragma once
#include "framework.h"

int sel = 0;

#define ENEMYCOUNT 3

Enemy battleEnemy[ENEMYCOUNT];
int curEnemyCount;

void EnterBattle()
{
	// TODO : 배틀 씬 입장시 초기화
	curEnemyCount = curMapNode->info.enemyCount;
	int i = 0;

	for (i = 0; i < curEnemyCount; i++)
	{
		
	}
}

void PlayerTurn(Player *player)
{
	// TODO : 행동 선택지
	printf("플레이어 이름 : %s\n", player->name);
	
	printf("행동 선택 : ");
	scanf_s("%d",&sel);
}

void EnemyTurn()
{
	// TODO : 맵 노드에 존재하는 모든 적 개체가 공격
}

void ExitBattle()
{
	// TODO : 배틀 씬 퇴장시 초기화
}