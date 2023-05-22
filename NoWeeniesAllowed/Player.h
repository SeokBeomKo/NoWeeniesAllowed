#pragma once
#include "framework.h"
#include "Skill.h"

#define COST 3
#define ACTIVESKILL 4

typedef struct player Player;

struct player
{
	string nick;
	string name;
	PassiveSkill pskill[4];
	ActiveSkill askill[ACTIVESKILL];

	int cost;

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
	// TODO : ���� �о����
	player = &playerdata;

	playerdata.name = "������";

	playerdata.cost = COST;

	playerdata.att = 10;
	playerdata.def = 1;
	playerdata.hp = 10;

	playerdata.curhp = playerdata.hp;

	playerdata.gold = 0;

	AddSkill(&playerdata.askill[0], 0, 0);
	AddSkill(&playerdata.askill[1], 1, 0);
}