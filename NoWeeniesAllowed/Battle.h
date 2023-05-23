#pragma once
#include "framework.h"

int sel = 0;
int target = 0;
int isClearBattle = 0;

#define ENEMYCOUNT 3

Enemy battleEnemy[ENEMYCOUNT];
int curEnemyCount;

void BattleUISet();
void BattleUI();
void PlayerActionSel();
void PlayerAction(int selAction);
void ClearCheck();
void EnemyAction(Enemy enemy);

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
	// TODO : ������ 1�� COST �� ����
	player->cost = 1;

	while (!curMapNode->isClear)
	{
		// TODO : ��Ʋ UI ����
		BattleUI();
		PlayerActionSel();

		ClearCheck();

		system("cls");
		if (player->cost == 0) break;
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
	BattleUI();

	for(int i = 0; i < ENEMYCOUNT; i ++)
	{
		// ���� ������ ���� ����ִٸ�
		if (battleEnemy[i].curhp != 0)
		{
			printf("%s �� �ൿ\n", battleEnemy[i].name);
			EnemyAction(battleEnemy[i]);
		}
	}
}

void EnemyAction(Enemy enemy)
{
	// TODO : ������ �پ��� ���� ����
	int pattern = rand() % 2;
	int dmg;

	switch (pattern)
	{
	case 0:
		if (enemy.att - player->def < 0) dmg = 0;
		dmg = enemy.att - player->def;
		player->curhp = player->curhp - dmg;
		printf("���� ������ %d ��ŭ �� �����\n", dmg);
		break;
	case 1:
		printf("�� ������ �ֱ�\n");
		break;
	/*case 2:
		enemy.def++;
		printf("�� ���\n");
	case 3:
		break;*/
	default:
		break;
	}
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
				ClearCheck();
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

void BattleUI()
{
	BattleUISet();

	GotoXY(0,0);
	

	for (int i = 0; i < curEnemyCount; i++)
	{
		if (battleEnemy[i].curhp < 0)
		{
			battleEnemy[i].curhp = 0;
		}
	}

	for (int i = 0; i < curEnemyCount; i++)
	{
		// TODO : �ش� �ڸ��� ���Ͱ� ���ٸ� �ǳ� ��
		printf("[%d] [%s] �� ü�� : %d\t\t",i + 1, battleEnemy[i].name, battleEnemy[i].curhp);
	}
	printf("\n\n");
	printf("[%s] �� ü�� : %d\n\n", player->name, player->curhp);

	// TODO : ���� ���� ������ ����ְ� �����
	// system("cls");
}

void BattleUISet()
{
	PrintXY("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������",0,40);
}