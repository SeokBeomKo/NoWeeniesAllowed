#pragma once
#include "framework.h"

int sel = 0;
int target = 0;
int isClearBattle = 0;

#define ENEMYCOUNT 3

Enemy battleEnemy[ENEMYCOUNT];
int curEnemyCount;

void TempBattleUI();
void PlayerActionSel();
void PlayerAction(int selAction);
void ClearCheck();

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
	player->cost = COST;

	while (!curMapNode->isClear)
	{
		// TODO : ��Ʋ UI ����
		TempBattleUI();
		PlayerActionSel();

		if (player->cost == 0) break;

		ClearCheck();

		system("cls");
	}
}

void ClearCheck()
{
	isClearBattle = 0;
	for (int i = 0; i < ENEMYCOUNT;i++)
	{
		if (battleEnemy[i].curhp <= 0)
		{
			isClearBattle++;
		}
	}
	if (isClearBattle == ENEMYCOUNT)
	{
		curMapNode->isClear = 1;
	}
}

void EnemyTurn()
{
	TempBattleUI();

	// TODO : �� ��忡 �����ϴ� ��� �� ��ü�� ����
}

void PlayerActionSel()
{
	target = 0;
	for (int i = 0; i < ACTIVESKILL; i++)
	{
		if (player->askill[i].name != NULL) printf("[%d�� ��ų] [%s]\t", i + 1,player->askill[i].name);
	}

	printf("���� ������ :  %d\n", player->cost);
	
	while (TRUE)
	{
		printf("\n��ų ���� : ");
		scanf_s("%d", &sel);

		// �ش� �ൿ�� �ִ���
		if (player->askill[sel - 1].name != NULL)
		{
			// �������� �������
			if (player->cost < player->askill[sel - 1].cost)
			{
				printf("\n������ ���� �Ф�");
			}
			// ����
			else break;
		}
		else printf("\n�׷� �ൿ ����");
	}

	PlayerAction(sel - 1);
}

void PlayerAction(int selAction)
{
	// ���� �����̶�� Ÿ�� ����
	if (player->askill[selAction].type == SINGLE)
	{
		while (TRUE)
		{
			printf("Ÿ���� �����ϼ��� :");
			scanf_s("%d", &target);
			if (battleEnemy[target - 1].curhp != 0)
			{
				battleEnemy[target - 1].curhp = battleEnemy[target - 1].curhp - (player->askill[selAction].coefficient * player->att) / 100;
				player->cost = player->cost - player->askill[selAction].cost;
				break;
			}
			else
			{
				printf("�ƹ��͵� �����ϴ�.");
			}
		}
	}
	// ���� �����̶�� ��� ����
	else
	{
		for (int i = 0; i < ENEMYCOUNT; i++)
		{
			if (battleEnemy[i].curhp != 0)
			{
				battleEnemy[i].curhp = battleEnemy[i].curhp - (player->askill[selAction].coefficient  * player->att) / 100;
			}
		}
		player->cost = player->cost - player->askill[selAction].cost;
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
		if (battleEnemy[i].curhp < 0)
		{
			battleEnemy[i].curhp = 0;
		}
	}
	for (int i = 0; i < curEnemyCount; i++)
	{
		printf("[%d] [%s] �� ü�� : %d\t\t",i + 1, battleEnemy[i].name, battleEnemy[i].curhp);
	}
	printf("\n\n");
	printf("[%s] �� ü�� : %d\n\n", player->name, player->curhp);
}