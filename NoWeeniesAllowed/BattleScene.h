#pragma once
#include "framework.h"
#include "Battle.h"

void BattleSceneUpdate()
{
	// ��Ʋ�� ���� �� �ʱ�ȭ
	EnterBattle();

	while (TRUE)
	{
		// �÷��̾� �� ����
		PlayerTurn(player);

		// �� ����
		EnemyTurn();
	}
	// ��Ʋ �� Ż�� �� �ʱ�ȭ
	ExitBattle();

	// TODO : Ŭ���� �� �����, ���� �� ���� ��
	ChangeScene(MAP);
}

