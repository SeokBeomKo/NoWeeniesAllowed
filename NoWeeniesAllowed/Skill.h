#pragma once
#include "framework.h"

#define GRADE 3			// ���
#define SKILL 10		// �� ��ų ����

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
	string name;			// �̸�
	string info;			// ����
	int attcount;			// ���� Ƚ��
	int coefficient;		// %
	AttackType type;		// ��, ��

	int cost;				// �Ҹ� ������

	int isBuff;				// ��������
};

ActiveSkill activeSkill[GRADE][SKILL];

// �Լ� ����
void SkillElement(int _code, int _grade, string _name, string _info, int _attcount, int _coefficient, AttackType _type, int _cost);
void AddSkill(ActiveSkill* _active, int _code, int _grade);

void SkillInit()
{
	// ��� ��ų ����
	// �ڵ�, ���, �̸�, ����, ����Ƚ��, ���, ����, �Ҹ���
	SkillElement(0, 0, "������", "������", 1, 100, SINGLE, 1);
	SkillElement(1, 0, "�ֵθ���", "�ֵθ���", 1, 50, RANGE, 2);
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


