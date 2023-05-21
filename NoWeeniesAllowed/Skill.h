#pragma once
#include "framework.h"

typedef struct passiveskill PassiveSkill;
typedef struct activeskill ActiveSkill;

enum Buff
{
	ATTACK,
	DEFENSE,
	HEAL
};

struct passiveskill
{
	string name;
	int coefficient;
};

struct activeskill
{
	int isBuff;

	string name;
	int count;
	int coefficient;
};
