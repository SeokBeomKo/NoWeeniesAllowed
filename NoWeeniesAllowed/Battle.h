#pragma once
#include "framework.h"

int sel = 0;
int target = 0;
int isClearBattle = 0;

#define ENEMYCOUNT 3

Enemy battleEnemy[ENEMYCOUNT];
int curEnemyCount;

void EnterBattle();

void PlayerTurn(Player* player);
void PlayerAction(int selAction);
void PlayerActionSel();

void EnemyTurn();
void EnemyAction(Enemy enemy);

void ClearCheck();

void ClearInput();
void BattleUI();
void BattleUISet();


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
		BattleUI();

		GotoXY(0, 42);
		PlayerActionSel();

		system("cls");
		if (player->cost == 0) break;
	}
}
void PlayerAction(int selAction)
{
	int dmg = (player->askill[selAction].coefficient * player->att) / 100;
	// ���� �����̶�� Ÿ�� ����
	if (player->askill[selAction].type == SINGLE)
	{
		while (TRUE)
		{
			printf("Ÿ���� �����ϼ��� :");
			scanf_s("%d", &target);
			if (battleEnemy[target - 1].curhp != 0)
			{
				ClearInput();
				battleEnemy[target - 1].curhp = battleEnemy[target - 1].curhp - dmg;
				player->cost = player->cost - player->askill[selAction].cost;
				GotoXY(0,42);
				printf("%s �� ����Ͽ� %s ���� %d �� �������� �־����ϴ�.", player->askill[selAction].name ,battleEnemy[target - 1].name, dmg);
				_getch();
				ClearInput();
				ClearCheck();
				break;
			}
			else
			{
				printf("�װ��� �ƹ��͵� �����ϴ�.");
				_getch();
				PrintXY("\33[2K", 0, 46);
				PrintXY("\33[2K", 0, 45);
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
				battleEnemy[i].curhp = battleEnemy[i].curhp - dmg;
				GotoXY(0, 42);
				printf("%s �� ����Ͽ� %s ���� %d �� �������� �־����ϴ�.", player->askill[selAction].name, battleEnemy[i].name, dmg);
				_getch();
				ClearInput();
				ClearCheck();
			}
		}
		player->cost = player->cost - player->askill[selAction].cost;
	}
}
void PlayerActionSel()
{
	target = 0;
	for (int i = 0; i < ACTIVESKILL; i++)
	{
		if (player->askill[i].name != NULL) printf("[%d�� ��ų] [%s]\t", i + 1,player->askill[i].name);
	}

	printf("���� �ڽ�Ʈ :  %d\n", player->cost);
	
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
				printf("\n�ڽ�Ʈ�� �����մϴ�.");
				_getch();
				ClearInput();
			}
			// ����
			else break;
		}
		else
		{
			printf("\n�׷� ��ų ����");
			_getch();
			ClearInput();
		}
	}
	
	PlayerAction(sel - 1);
}

void EnemyTurn()
{
	if (curMapNode->isClear == 1) return;
	BattleUI();

	GotoXY(0, 42);
	for(int i = 0; i < ENEMYCOUNT; i ++)
	{
		// ���� ������ ���� ����ִٸ�
		if (battleEnemy[i].curhp != 0)
		{
			EnemyAction(battleEnemy[i]);
		}
	}

	ClearInput();
	system("cls");
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
		printf("%s ���� ���ݴ��߽��ϴ�.\n%d ��ŭ �� �����\n",enemy.name, dmg);
		break;
	case 1:
		printf("%s �� �ƹ��͵� ���� �ʾҽ��ϴ�.\n", enemy.name);
		break;
	default:
		break;
	}
	_getch();
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
		ClearInput();

		PrintXY("���� ��� �׾����ϴ�...",0,42);
		curMapNode->isClear = 1;

		_getch();
	}
}

void ExitBattle()
{
	// TODO : ��Ʋ �� ����� �ʱ�ȭ
}

void ClearInput()
{
	PrintXY("\33[2K", 0, 42);
	PrintXY("\33[2K", 0, 43);
	PrintXY("\33[2K", 0, 44);
	PrintXY("\33[2K", 0, 45);
	PrintXY("\33[2K", 0, 46);
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
	
	// �� UI
	for (int i = 0; i < curEnemyCount; i++)
	{
		// �ش� �ڸ��� ���Ͱ� ���ٸ� �ǳ� ��
		if (battleEnemy[i].name != NULL)
		{
			// ���� �ʾҴٸ�
			if (battleEnemy[i].curhp != 0)
			{
				GotoXY((i * 16) + 55, 3);
				printf("[%s]", battleEnemy[i].name);
				FilePrintUni(battleEnemy[i].drawData, (i * 16) + 50, 5);
				GotoXY((i * 16) + 53, 33);
				printf("HP : %d / %d", battleEnemy[i].hp, battleEnemy[i].curhp);
				GotoXY((i * 16) + 55, 35);
				printf("[%d]", i + 1);
			}
			else
			{
				GotoXY((i * 16) + 55, 3);
				printf("[%s]", battleEnemy[i].name);
				GotoXY((i * 16) + 53, 33);
				printf("HP : %d / %d", battleEnemy[i].hp, battleEnemy[i].curhp);
				GotoXY((i * 16) + 55, 35);
				printf("[%d]", i + 1);
			}
		}
	}
	
	// �÷��̾� UI
	FilePrintUni(player->drawData, 3, 5);

	GotoXY(10, 3);
	printf("[%s %s]",player->nick, player->name);
	GotoXY(10, 33);
	printf("ü�� : %d / %d", player->hp, player->curhp);
}
void BattleUISet()
{
	PrintXY("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������",0,40);
}