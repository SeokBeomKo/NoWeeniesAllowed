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


	// TODO : Ŭ���� �� �����, ���� �� ���� ��
	ChangeScene(MAP);
}

