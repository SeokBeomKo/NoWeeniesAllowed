#pragma once
#include "framework.h"
#include "Battle.h"

void BattleSceneUpdate()
{
	// ��Ʋ�� ���� �� �ʱ�ȭ
	EnterBattle();

	while (TRUE)
	{
		printf("%s\n",curMapNode->info.enemy[0].name);
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

