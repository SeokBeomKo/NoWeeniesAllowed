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
	// TODO : 끝나고 1을 COST 로 변경
	player->cost = 1;

	while (!curMapNode->isClear)
	{
		// TODO : 배틀 UI 수정
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
		// 현재 차례의 몹이 살아있다면
		if (battleEnemy[i].curhp != 0)
		{
			printf("%s 의 행동\n", battleEnemy[i].name);
			EnemyAction(battleEnemy[i]);
		}
	}
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
		printf("적이 때려서 %d 만큼 피 닳았음\n", dmg);
		break;
	case 1:
		printf("적 가만히 있기\n");
		break;
	/*case 2:
		enemy.def++;
		printf("적 방어\n");
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
		if (player->askill[i].name != NULL) printf("[%d번 스킬] [%s]\t", i + 1,player->askill[i].name);
	}

	printf("남은 에너지 :  %d\n", player->cost);
	
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
				printf("\n에너지 부족 ㅠㅠ");
			}
			// 실행
			else break;
		}
		else printf("\n그런 행동 없음");
	}
	
	PlayerAction(sel - 1);
}

void PlayerAction(int selAction)
{
	// 단일 공격이라면 타겟 지정
	if (player->askill[selAction].type == SINGLE)
	{
		while (TRUE)
		{
			printf("타겟을 지정하세요 :");
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
				printf("아무것도 없습니다.");
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
				battleEnemy[i].curhp = battleEnemy[i].curhp - (player->askill[selAction].coefficient  * player->att) / 100;
			}
		}
		player->cost = player->cost - player->askill[selAction].cost;
	}
}

void ExitBattle()
{
	// TODO : 배틀 씬 퇴장시 초기화
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
		// TODO : 해당 자리에 몬스터가 없다면 건너 뜀
		printf("[%d] [%s] 의 체력 : %d\t\t",i + 1, battleEnemy[i].name, battleEnemy[i].curhp);
	}
	printf("\n\n");
	printf("[%s] 의 체력 : %d\n\n", player->name, player->curhp);

	// TODO : 몬스터 차례 끝나면 띄워주고 지우기
	// system("cls");
}

void BattleUISet()
{
	PrintXY("───────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────",0,40);
}