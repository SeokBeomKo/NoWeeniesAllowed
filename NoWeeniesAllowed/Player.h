#pragma once
#include "framework.h"
#include "Skill.h"

#define COST 3
#define ACTIVESKILL 4

typedef struct player Player;

struct player
{
	const wchar_t* drawData;

	string nick;
	string name;
	PassiveSkill pskill[4];
	ActiveSkill askill[ACTIVESKILL];

	int cost;
	int curCost;

	int hp;
	int curhp;
	int att;
	int def;

	int gold;
};

Player playerdata;
Player* player;

void PlayerInit()
{
	// TODO : 정보 읽어오기
	player = &playerdata;

	playerdata.name = "가나다";

	playerdata.cost = COST;
	playerdata.curCost = playerdata.cost;

	playerdata.att = 10;
	playerdata.def = 0;
	playerdata.hp = 100;

	playerdata.curhp = playerdata.hp;

	playerdata.gold = 0;

	AddSkill(&playerdata.askill[0], 0, 0);
}