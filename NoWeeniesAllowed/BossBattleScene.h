#pragma once
#include "framework.h"
#include "BossBattle.h"

void BossBattleSceneUpdate()
{
	// ��Ʋ�� ���� �� �ʱ�ȭ
	EnterBossBattle();

	while (!curMapNode->isClear)
	{
		// �÷��̾� �� ����
		BossPlayerTurn(player);
		// �� ����
		BossTurn();
	}
	// ��Ʋ �� Ż�� �� �ʱ�ȭ
	ExitBossBattle();

	// TODO : Ŭ���� �� �����, ���� �� ���� ��
	ChangeScene(REWARD);
}