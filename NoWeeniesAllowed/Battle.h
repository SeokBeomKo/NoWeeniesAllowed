#pragma once
#include "framework.h"

int sel = 0;

void EnterBattle()
{
	// TODO : ��Ʋ �� ����� �ʱ�ȭ
}

void PlayerTurn(Player *player)
{
	// TODO : �ൿ ������
	printf("�÷��̾� �̸� : %s\n", player->name);
	
	printf("�ൿ ���� : ");
	scanf_s("%d",&sel);
}

void EnemyTurn()
{
	// TODO : �� ��忡 �����ϴ� ��� �� ��ü�� ����
}

void ExiteBattle()
{
	// TODO : ��Ʋ �� ����� �ʱ�ȭ
}