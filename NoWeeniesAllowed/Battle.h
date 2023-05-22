#pragma once
#include "framework.h"

int sel = 0;
int target = 0;

#define ENEMYCOUNT 3

Enemy battleEnemy[ENEMYCOUNT];
int curEnemyCount;

void TempBattleUI();
void PlayerActionSel();
void PlayerAction();

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
	PlayerActionSel();
}

void EnemyTurn()
{
	TempBattleUI();

	// TODO : 맵 노드에 존재하는 모든 적 개체가 공격
}

void PlayerActionSel()
{
	// TODO : 타겟 지정 나중으로 why 공격에 따라 타겟지정이 다름
	printf("타겟 지정 :");
	scanf_s("%d",&target);

	printf("행동 선택 : ");
	scanf_s("%d", &sel);

	PlayerAction(sel, target);
}

void PlayerAction(int selAction, int target)
{
	// TODO : 행동에 따른 스킬 발동
	switch (selAction)
	{
	case 0:
		printf("0 번 행동");
		
		break;
	case 1:
		printf("1 번 행동");
		break;
	default:
		break;
	}
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