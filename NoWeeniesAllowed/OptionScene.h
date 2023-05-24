#pragma once
#include "framework.h"

static string nick;
static char name[20] = "";
static string strdifficulty;

static int difficultySelect = 0;

void OptionSceneUpdate();
void InputName();
void SelctDifficulty();
void CheckDifficulty();

void OptionSceneUpdate()
{
	system("cls");
	InputName();
	while (difficultySelect != 1)
	{
		SelctDifficulty();

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
	system("cls");
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
	system("cls");
	GotoXY(48, 20);
	switch (difficulty)
	{
	case 0:
		player->nick = "������";
		strdifficulty = "���� �����̵��� ����";
		player->drawData = L"Player\\EasyPlayer.txt";
		break;
	case 1:
		player->nick = "������";
		strdifficulty = "�����̵��� ����";
		player->drawData = L"Player\\NormalPlayer.txt";
		break;
	case 2:
		player->nick = "�糪��";
		strdifficulty = "�糪�� Ŭ��";
		player->drawData = L"Player\\HardPlayer.txt";
		break;
	default:
		break;
	}

	FilePrintUni(player->drawData, 40, 5);

	GotoXY(50, 35);
	printf("%s �� !", player->name);

	GotoXY(40, 40);
	printf("%s ���̵��� �����Ͻðڽ��ϱ� ?", strdifficulty);

	GotoXY(43, 43);
	printf("���� : 1\t\t �ٽ� ���� : 2");
	GotoXY(50, 45);
	scanf_s("%d", &difficultySelect);
}