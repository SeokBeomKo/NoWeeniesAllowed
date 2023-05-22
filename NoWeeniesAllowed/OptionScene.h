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
	printf("플레이어 이름을 입력하세요 : ");
	fgets(name,sizeof(char) * 20, stdin);
	name[strlen(name) - 1] = '\0';
	player->name = name;
}

void SelctDifficulty()
{
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
	GotoXY(48, 20);
	printf("hi");
	switch (difficulty)
	{
	case 0:
		player->nick = "졸렬한";
		strdifficulty = "슈퍼 겁쟁이들의 쉼터";
		break;
	case 1:
		player->nick = "옹졸한";
		strdifficulty = "겁쟁이들의 쉼터";
		break;
	case 2:
		player->nick = "사나이";
		strdifficulty = "사나이 클럽";
		break;
	default:
		break;
	}
	GotoXY(46, 21);
	printf("%s %s", player->nick, player->name);

	GotoXY(42, 26);
	printf("난이도 선택 : %s", strdifficulty);

	GotoXY(40, 30);
	printf("진행 : 1\t\t 다시 선택 : 2");
	GotoXY(50, 31);
	scanf_s("%d", &difficultySelect);
}