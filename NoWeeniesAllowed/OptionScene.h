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
	printf("플레이어 이름을 입력하세요 : ");
	fgets(name,sizeof(char) * 20, stdin);
	name[strlen(name) - 1] = '\0';
	player->name = name;
}

void SelctDifficulty()
{
	system("cls");
	GotoXY(45,15);
	printf("난이도를 선택하세요");

	GotoXY(27, 25);
	printf("슈퍼 겁쟁이들의 쉼터 : 1\t\t  ");
	printf("겁쟁이들의 쉼터 : 2\t\t  ");
	printf("사나이 클럽 : 3");

	GotoXY(45, 40);
	printf("원하는 난이도 입력 : ");
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
		player->nick = "졸렬한";
		strdifficulty = "슈퍼 겁쟁이들의 쉼터";
		player->drawData = L"Player\\EasyPlayer.txt";
		break;
	case 1:
		player->nick = "옹졸한";
		strdifficulty = "겁쟁이들의 쉼터";
		player->drawData = L"Player\\NormalPlayer.txt";
		break;
	case 2:
		player->nick = "사나이";
		strdifficulty = "사나이 클럽";
		player->drawData = L"Player\\HardPlayer.txt";
		break;
	default:
		break;
	}

	FilePrintUni(player->drawData, 40, 5);

	GotoXY(50, 35);
	printf("%s 님 !", player->name);

	GotoXY(40, 40);
	printf("%s 난이도로 진행하시겠습니까 ?", strdifficulty);

	GotoXY(43, 43);
	printf("진행 : 1\t\t 다시 선택 : 2");
	GotoXY(50, 45);
	scanf_s("%d", &difficultySelect);
}