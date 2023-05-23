#pragma once
#include "framework.h"
#include "Battle.h"

void BattleSceneUpdate()
{
	// 배틀씬 진입 시 초기화
	EnterBattle();

	while (!curMapNode->isClear)
	{
		// 플레이어 선 공격
		PlayerTurn(player);
		// 적 공격
		EnemyTurn();
	}
	// 배틀 씬 탈출 시 초기화
	ExitBattle();

	// TODO : 클리어 시 보상씬, 실패 시 메인 씬
	ChangeScene(REWARD);
}

