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
	// 단일 공격이라면 타겟 지정
	if (player->askill[selAction].type == SINGLE)
	{
		while (TRUE)
		{
			printf("타겟을 지정하세요 :");
			scanf_s("%d", &target);
			if (battleEnemy[target - 1].curhp != 0)
			{
				ClearInput();
				battleEnemy[target - 1].curhp = battleEnemy[target - 1].curhp - dmg;
				player->cost = player->cost - player->askill[selAction].cost;
				GotoXY(0,42);
				printf("%s 을 사용하여 %s 에게 %d 의 데미지를 주었습니다.", player->askill[selAction].name ,battleEnemy[target - 1].name, dmg);
				_getch();
				ClearInput();
				ClearCheck();
				break;
			}
			else
			{
				printf("그곳엔 아무것도 없습니다.");
				_getch();
				PrintXY("\33[2K", 0, 46);
				PrintXY("\33[2K", 0, 45);
			}
			
		}
	}
	// 범위 공격이라면 모두 공격
	else
	{
		for (int i = 0; i < ENEMYCOUNT; i++)
		{
			if (battleEnemy[i].curhp != 0)
			{
				battleEnemy[i].curhp = battleEnemy[i].curhp - dmg;
				GotoXY(0, 42);
				printf("%s 을 사용하여 %s 에게 %d 의 데미지를 주었습니다.", player->askill[selAction].name, battleEnemy[i].name, dmg);
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
		if (player->askill[i].name != NULL) printf("[%d번 스킬] [%s]\t", i + 1,player->askill[i].name);
	}

	printf("남은 코스트 :  %d\n", player->cost);
	
	while (TRUE)
	{
		printf("\n스킬 선택 : ");
		scanf_s("%d", &sel);

		// 해당 행동이 있는지
		if (player->askill[sel - 1].name != NULL)
		{
			// 에너지가 충분한지
			if (player->cost < player->askill[sel - 1].cost)
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
	
	PlayerAction(sel - 1);
}

void EnemyTurn()
{
	if (curMapNode->isClear == 1) return;
	BattleUI();

	GotoXY(0, 42);
	for(int i = 0; i < ENEMYCOUNT; i ++)
	{
		// 현재 차례의 몹이 살아있다면
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
	// TODO : 몬스터의 다양한 패턴 구현
	int pattern = rand() % 2;
	int dmg;

	switch (pattern)
	{
	case 0:
		if (enemy.att - player->def < 0) dmg = 0;
		dmg = enemy.att - player->def;
		player->curhp = player->curhp - dmg;
		printf("%s 에게 공격당했습니다.\n%d 만큼 피 닳았음\n",enemy.name, dmg);
		break;
	case 1:
		printf("%s 는 아무것도 하지 않았습니다.\n", enemy.name);
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

		PrintXY("적이 모두 죽었습니다...",0,42);
		curMapNode->isClear = 1;

		_getch();
	}
}

void ExitBattle()
{
	// TODO : 배틀 씬 퇴장시 초기화
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
	
	// 적 UI
	for (int i = 0; i < curEnemyCount; i++)
	{
		// 해당 자리에 몬스터가 없다면 건너 뜀
		if (battleEnemy[i].name != NULL)
		{
			// 죽지 않았다면
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
	
	// 플레이어 UI
	FilePrintUni(player->drawData, 3, 5);

	GotoXY(10, 3);
	printf("[%s %s]",player->nick, player->name);
	GotoXY(10, 33);
	printf("체력 : %d / %d", player->hp, player->curhp);
}
void BattleUISet()
{
	PrintXY("───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────",0,40);
}