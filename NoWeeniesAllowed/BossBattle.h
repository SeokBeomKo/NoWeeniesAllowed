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
			if (player->askill[i].name != NULL) printf("[%d번 스킬] [%s]\t", i + 1, player->askill[i].name);
		}
		printf("\n(차례 넘기기 : 5)");
		printf("\n\n스킬 선택 : ");

		scanf_s("%d", &sel);

		if (sel == 5) break;

		// 해당 행동이 있는지
		if (player->askill[sel - 1].name != NULL)
		{
			// 에너지가 충분한지
			if (player->curCost < player->askill[sel - 1].cost)
			{
				printf("\n코스트가 부족합니다.");
				_getch();
				ClearInput();
			}
			// 실행
			else break;
		}
		else
		{
			printf("\n그런 스킬 없음");
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
	printf("%s 을 사용하여 %s 에게 %d 의 데미지를 주었습니다.", player->askill[selAction].name, battleBoss.name, dmg);
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
	// TODO : 보스의 다양한 패턴 구현
	int pattern = rand() % 2;
	int dmg;

	GotoXY(0, 42);
	switch (pattern)
	{
	case 0:
		if (boss.att - player->def < 0) dmg = 0;
		dmg = boss.att - player->def;
		player->curhp = player->curhp - dmg;
		printf("%s 에게 공격당했습니다.\n%d 만큼 피 닳았음\n", boss.name, dmg);
		break;
	case 1:
		printf("%s 는 아무것도 하지 않았습니다.\n", boss.name);
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

		PrintXY("클리어 했습니다...", 0, 42);
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