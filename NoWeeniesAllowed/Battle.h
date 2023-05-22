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
	// TODO : ��Ʋ UI ����
	TempBattleUI();
	// TODO : �ൿ ������
	PlayerActionSel();
}

void EnemyTurn()
{
	TempBattleUI();

	// TODO : �� ��忡 �����ϴ� ��� �� ��ü�� ����
}

void PlayerActionSel()
{
	// TODO : Ÿ�� ���� �������� why ���ݿ� ���� Ÿ�������� �ٸ�
	printf("Ÿ�� ���� :");
	scanf_s("%d",&target);

	printf("�ൿ ���� : ");
	scanf_s("%d", &sel);

	PlayerAction(sel, target);
}

void PlayerAction(int selAction, int target)
{
	// TODO : �ൿ�� ���� ��ų �ߵ�
	switch (selAction)
	{
	case 0:
		printf("0 �� �ൿ");
		
		break;
	case 1:
		printf("1 �� �ൿ");
		break;
	default:
		break;
	}
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