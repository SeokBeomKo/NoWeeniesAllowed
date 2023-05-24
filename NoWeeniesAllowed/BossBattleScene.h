#pragma once
#include "framework.h"
#include "BossBattle.h"

void BossBattleSceneUpdate()
{
	// 배틀씬 진입 시 초기화
	EnterBossBattle();

	while (!curMapNode->isClear)
	{
		// 플레이어 선 공격
		BossPlayerTurn(player);
		// 적 공격
		BossTurn();
	}
	// 배틀 씬 탈출 시 초기화
	ExitBossBattle();

	// TODO : 클리어 시 보상씬, 실패 시 메인 씬
	ChangeScene(REWARD);
}