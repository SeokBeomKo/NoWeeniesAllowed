#pragma once

#include "framework.h"

typedef struct enemy
{
	/*
	이름
	체력
	공격력
	방어력
	보상(골드)
	*/
	string	name;
	int		hp;
	int		att;
	int		def;
	int		reward;
}Enemy;