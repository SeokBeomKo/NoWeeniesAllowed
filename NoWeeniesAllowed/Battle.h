#pragma once
#include "framework.h"

int sel = 0;

#define ENEMYCOUNT 3

Enemy battleEnemy[ENEMYCOUNT];
int curEnemyCount;

void EnterBattle()
{
	// TODO : ��Ʋ �� ����� �ʱ�ȭ
	curEnemyCount = curMapNode->info.enemyCount;
	int i = 0;

	for (i = 0; i < curEnemyCount; i++)
	{
		
	}
}

void PlayerTurn(Player *player)
{
	// TODO : �ൿ ������
	printf("�÷��̾� �̸� : %s\n", player->name);
	
	printf("�ൿ ���� : ");
	scanf_s("%d",&sel);
}

void EnemyTurn()
{
	// TODO : �� ��忡 �����ϴ� ��� �� ��ü�� ����
}

void ExitBattle()
{
	// TODO : ��Ʋ �� ����� �ʱ�ȭ
}