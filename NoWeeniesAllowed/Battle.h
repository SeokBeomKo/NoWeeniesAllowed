#pragma once
#include "framework.h"

int sel = 0;
int target = 0;
int isClearBattle = 0;

#define ENEMYCOUNT 3

Enemy battleEnemy[ENEMYCOUNT];
int curEnemyCount;

void EnterBattle();
void ExitBattle();

void PlayerTurn(Player* player);
void PlayerAction(int selAction);
void PlayerActionSel();

void EnemyTurn();
void EnemyAction(Enemy enemy);

void ClearCheck();

void ClearInput();
void BattleUI();
void BattleUISet();
void PlayerInfoUI();


void EnterBattle()
{
	int i = 0;

	for (i = 0; i < ENEMYCOUNT; i++)
	{
		battleEnemy[i].curhp = NULL;
	}

	curEnemyCount = curMapNode->info.enemyCount;

	for (i = 0; i < curEnemyCount; i++)
	{
		battleEnemy[i] = curMapNode->info.enemy[i];
	}
}

void PlayerTurn(Player *player)
{
	player->curCost = player->cost;

	while (curMapNode->isClear == 0)
	{
		if (player->curCost == 0)	break;
		BattleUI();

		PrintXY("\33[2K", 0, 1);
		SetConsoleTextColor(4);
		PrintXY("��", 12, 1);
		SetConsoleTextColor(15);
		PlayerActionSel();
		if (sel == 5) break;

		system("cls");
	}
}
void PlayerActionSel()
{
	while (TRUE)
	{
		GotoXY(0, 42);
		target = 0;
		for (int i = 0; i < ACTIVESKILL; i++)
		{
			if (player->askill[i].name != NULL) printf("[%d�� ��ų] [%s]\t", i + 1, player->askill[i].name);
		}
		printf("\n(���� �ѱ�� : 5)");
		printf("\n\n��ų ���� : ");
		
		scanf_s("%d", &sel);

		if (sel == 5) break;

		// �ش� �ൿ�� �ִ���
		if (player->askill[sel - 1].name != NULL)
		{
			// �������� �������
			if (player->curCost < player->askill[sel - 1].cost)
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
			printf("\n\n�׷� ��ų ����");
			_getch();
			ClearInput();
		}
	}
	if (sel != 5) PlayerAction(sel - 1);
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
				player->curCost = player->curCost - player->askill[selAction].cost;
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
				PrintXY("\33[2K", 0, 48);
				PrintXY("\33[2K", 0, 47);
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
				ClearInput();

				GotoXY(0, 42);
				printf("%s �� ����Ͽ� %s ���� %d �� �������� �־����ϴ�.", player->askill[selAction].name, battleEnemy[i].name, dmg);
				_getch();
				
				ClearCheck();
			}
		}
		player->curCost = player->curCost - player->askill[selAction].cost;
	}
}

void EnemyTurn()
{
	if (curMapNode->isClear == 1) return;
	BattleUI();
	
	for(int i = 0; i < ENEMYCOUNT; i ++)
	{
		// ���� ������ ���� ����ִٸ�
		if (battleEnemy[i].curhp != 0)
		{
			PrintXY("\33[2K", 0, 1);
			SetConsoleTextColor(4);
			PrintXY("��", (i * 16)+ 57, 1);
			SetConsoleTextColor(15);
			ClearInput();
			EnemyAction(battleEnemy[i]);
		}
	}

	ClearInput();
	system("cls");
}
void EnemyAction(Enemy enemy)
{
	// TODO : ���� �پ��� ���� ����
	int pattern = rand() % 2;
	int dmg;

	GotoXY(0, 42);
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
	PrintXY("\33[2K", 0, 47);
	PrintXY("\33[2K", 0, 48);
	PrintXY("\33[2K", 0, 49);
	PrintXY("\33[2K", 0, 50);
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
	
	PlayerInfoUI();
}

void PlayerInfoUI()
{
	// �÷��̾� UI
	FilePrintUni(player->drawData, 3, 5);

	GotoXY(10, 3);
	printf("[%s %s]", player->nick, player->name);
	GotoXY(10, 33);
	printf("ü�� : %d / %d", player->hp, player->curhp);

	GotoXY(17, 35);
	for (int i = 0; i < player->cost; i++)
	{
		printf("��");
	}
	GotoXY(10, 35);
	printf("�ܿ� �ڽ�Ʈ : ");
	for (int i = 0; i < player->curCost; i++)
	{
		printf("��");
	}
}

void BattleUISet()
{
	PrintXY("��������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������������",0,40);
}