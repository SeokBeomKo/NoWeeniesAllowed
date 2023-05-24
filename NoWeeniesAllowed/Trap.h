#pragma once
#include "framework.h"

static int dmg;

void SetDamage();
void DrawTrap();

void Trap()
{
	SetDamage();

	DrawTrap();

	player->curhp = player->curhp - dmg;

	_getch();
	curMapNode->isClear = 1;
}

void SetDamage()
{
	dmg = (difficulty + 1) * (rand() % 10 + 1);
}

void DrawTrap()
{
	FilePrint("Trap.txt", 45, 20);
	GotoXY(49, 15);
	printf("¥��");
	GotoXY(47, 34);
	printf("������ �ɷ�");
	GotoXY(44, 35);
	printf("%d �������� �Ծ����ϴ�.", dmg);

	GotoXY(50,38);
	
}