#pragma once
#include "framework.h"

Boss battleBoss;

void EnterBossBattle();
void ExitBossBattle();

void BossPlayerTurn(Player* player);
void BossPlayerAction(int selAction);
void BossPlayerActionSel();

void BossTurn();
void BossAction(Boss boss);

void BossClearCheck();
void BossBattleUI();

void EnterBossBattle()
{
	battleBoss = boss[0][0];
}
void ExitBossBattle()
{

}

void BossPlayerTurn(Player* player)
{
	player->curCost = player->cost;

	while (player->cost != 0)
	{
		BossBattleUI();
		
		BossPlayerActionSel();
		if (sel == 5) break;

		system("cls");
	}
}
void BossPlayerActionSel()
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
			printf("\n�׷� ��ų ����");
			_getch();
			ClearInput();
		}
	}
	if (sel != 5) BossPlayerAction(sel - 1);
}

void BossPlayerAction(int selAction)
{
	int dmg = (player->askill[selAction].coefficient * player->att) / 100;

	ClearInput();
	battleBoss.curhp = battleBoss.curhp - dmg;
	player->curCost = player->curCost - player->askill[selAction].cost;
	GotoXY(0, 42);
	printf("%s �� ����Ͽ� %s ���� %d �� �������� �־����ϴ�.", player->askill[selAction].name, battleBoss.name, dmg);
	_getch();
	ClearInput();
	BossClearCheck();
}

void BossTurn()
{
	if (curMapNode->isClear == 1) return;
	ClearInput();
	BossBattleUI();

	BossAction(battleBoss);

	ClearInput();
	system("cls");
}
void BossAction(Boss boss)
{
	// TODO : ������ �پ��� ���� ����
	int pattern = rand() % 2;
	int dmg;

	GotoXY(0, 42);
	switch (pattern)
	{
	case 0:
		if (boss.att - player->def < 0) dmg = 0;
		dmg = boss.att - player->def;
		player->curhp = player->curhp - dmg;
		printf("%s ���� ���ݴ��߽��ϴ�.\n%d ��ŭ �� �����\n", boss.name, dmg);
		break;
	case 1:
		printf("%s �� �ƹ��͵� ���� �ʾҽ��ϴ�.\n", boss.name);
		break;
	default:
		break;
	}
	_getch();
}

void BossClearCheck()
{
	if (battleBoss.curhp == 0)
	{
		ClearInput();

		PrintXY("Ŭ���� �߽��ϴ�...", 0, 42);
		curMapNode->isClear = 1;

		_getch();
	}
}

void BossBattleUI()
{
	BattleUISet();

	GotoXY(0, 0);

	if (battleBoss.curhp < 0)	battleBoss.curhp = 0;

	GotoXY(16 + 53, 3);
	printf("[%s]", battleBoss.name);
	FilePrintUni(battleBoss.drawData, 55, 5);
	GotoXY(16 + 53, 36);
	printf("HP : %d / %d", battleBoss.hp, battleBoss.curhp);

	PlayerInfoUI();
}