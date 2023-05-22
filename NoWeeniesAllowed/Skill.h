#pragma once
#include "framework.h"

#define GRADE 3			// 등급
#define SKILL 10		// 총 스킬 종류

typedef struct passiveskill PassiveSkill;
typedef struct activeskill ActiveSkill;

enum Buff
{
	ATTACK,
	DEFENSE,
	HEAL
};

typedef enum attacktype
{
	SINGLE,
	RANGE
}AttackType;

struct passiveskill
{
	string name;
	int coefficient;
};

struct activeskill
{
	string name;			// 이름
	string info;			// 설명
	int attcount;			// 공격 횟수
	int coefficient;		// %
	AttackType type;		// 범, 단

	int cost;				// 소모 에너지

	int isBuff;				// 버프인지
};

ActiveSkill activeSkill[GRADE][SKILL];

// 함수 선언
void SkillElement(int _code, int _grade, string _name, string _info, int _attcount, int _coefficient, AttackType _type, int _cost);
void AddSkill(ActiveSkill* _active, int _code, int _grade);

void SkillInit()
{
	// 모든 스킬 저장
	// 코드, 등급, 이름, 설명, 공격횟수, 계수, 범단, 소모비용
	SkillElement(0, 0, "때리기", "때린다", 1, 100, SINGLE, 1);
	SkillElement(1, 0, "휘두르기", "휘두른다", 1, 50, RANGE, 2);
}

void SkillElement(int _code, int _grade, string _name, string _info, int _attcount, int _coefficient, AttackType _type, int _cost)
{
	activeSkill[_grade][_code].name = _name;
	activeSkill[_grade][_code].info = _info;
	activeSkill[_grade][_code].attcount = _attcount;
	activeSkill[_grade][_code].coefficient = _coefficient;
	activeSkill[_grade][_code].type = _type;
	activeSkill[_grade][_code].cost = _cost;
}

void AddSkill(ActiveSkill *_active, int _code, int _grade)
{
	*_active = activeSkill[_grade][_code];
}


