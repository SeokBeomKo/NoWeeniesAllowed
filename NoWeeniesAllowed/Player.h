#pragma once
#include "framework.h"
#include "Skill.h"

typedef struct player Player;

struct player
{
	string name;
	PassiveSkill pskill[4];
	ActiveSkill askill[4];
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
	player = &playerdata;

	playerdata.name = "°¡³ª´Ù";

	playerdata.att = 1;
	playerdata.def = 1;
	playerdata.hp = 1;

	playerdata.curhp = 1;

	playerdata.gold = 1;
}