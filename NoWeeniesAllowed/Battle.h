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
	// TODO : ��Ʋ UI ����
	TempBattleUI();
	// TODO : �ൿ ������
	
	
	printf("�ൿ ���� : ");
	scanf_s("%d",&sel);
}

void EnemyTurn()
{
	TempBattleUI();

	// TODO : �� ��忡 �����ϴ� ��� �� ��ü�� ����
}

void ExitBattle()
{
	// TODO : ��Ʋ �� ����� �ʱ�ȭ
}

void TempBattleUI()
{
	for (int i = 0; i < curEnemyCount; i++)
	{
		printf("[%d] �� �̸� : %s\n",i, battleEnemy[i].name);
	}
	printf("\n");
	printf("�÷��̾� �̸� : %s\n", player->name);
}