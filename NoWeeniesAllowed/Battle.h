#pragma once
#include "framework.h"

int sel = 0;

#define ENEMYCOUNT 3

Enemy battleEnemy[ENEMYCOUNT];
int curEnemyCount;

void TempBattleUI();

void EnterBattle()
{
	curEnemyCount = curMapNode->info.enemyCount;
	int i = 0;

	for (i = 0; i < curEnemyCount; i++)
	{
		battleEnemy[i] = curMapNode->info.enemy[i];
	}
}

void PlayerTurn(Player *player)
{
	// TODO : 배틀 UI 띄우기
	TempBattleUI();
	// TODO : 행동 선택지
	
	
	printf("행동 선택 : ");
	scanf_s("%d",&sel);
}

void EnemyTurn()
{
	TempBattleUI();

	// TODO : 맵 노드에 존재하는 모든 적 개체가 공격
}

void ExitBattle()
{
	// TODO : 배틀 씬 퇴장시 초기화
}

void TempBattleUI()
{
	for (int i = 0; i < curEnemyCount; i++)
	{
		printf("[%d] 적 이름 : %s\n",i, battleEnemy[i].name);
	}
	printf("\n");
	printf("플레이어 이름 : %s\n", player->name);
}