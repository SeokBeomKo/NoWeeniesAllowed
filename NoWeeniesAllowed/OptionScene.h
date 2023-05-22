#pragma once
#include "framework.h"

static string nick;
static char name[20] = "";
static string strdifficulty;

static int difficultySelect = 0;

void InputName();
void SelctDifficulty();
void CheckDifficulty();
void WelcomePrint();

void OptionSceneUpdate()
{
	system("cls");
	InputName();
	while (difficultySelect != 1)
	{
		
		system("cls");
		SelctDifficulty();
		system("cls");

		CheckDifficulty();
	}

	MapListCreate();
	ChangeScene(MAP);
}

void InputName()
{
	GotoXY(42, 25);
	printf("�÷��̾� �̸��� �Է��ϼ��� : ");
	fgets(name,sizeof(char) * 20, stdin);
	name[strlen(name) - 1] = '\0';
	player->name = name;
}

void SelctDifficulty()
{
	GotoXY(45,15);
	printf("���̵��� �����ϼ���");

	GotoXY(27, 25);
	printf("���� �����̵��� ���� : 1\t\t  ");
	printf("�����̵��� ���� : 2\t\t  ");
	printf("�糪�� Ŭ�� : 3");

	GotoXY(45, 40);
	printf("���ϴ� ���̵� �Է� : ");
	scanf_s("%d", &difficulty);
	difficulty = difficulty - 1;
}

void CheckDifficulty()
{
	GotoXY(48, 20);
	printf("hi");
	switch (difficulty)
	{
	case 0:
		player->nick = "������";
		strdifficulty = "���� �����̵��� ����";
		break;
	case 1:
		player->nick = "������";
		strdifficulty = "�����̵��� ����";
		break;
	case 2:
		player->nick = "�糪��";
		strdifficulty = "�糪�� Ŭ��";
		break;
	default:
		break;
	}
	GotoXY(46, 21);
	printf("%s %s", player->nick, player->name);

	GotoXY(42, 26);
	printf("���̵� ���� : %s", strdifficulty);

	GotoXY(40, 30);
	printf("���� : 1\t\t �ٽ� ���� : 2");
	GotoXY(50, 31);
	scanf_s("%d", &difficultySelect);
}