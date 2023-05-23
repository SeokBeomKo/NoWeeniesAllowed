#pragma once
#include "framework.h"

#define SKILLGRADE 3			// ���
#define SKILLCODE 10			// �� ��ų ����

typedef struct passiveskill PassiveSkill;
typedef struct activeskill ActiveSkill;

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
	string grade;			// ���
	string name;			// �̸�
	string info;			// ����
	int attcount;			// ���� Ƚ��
	int coefficient;		// %
	AttackType type;		// ��, ��

	int cost;				// �Ҹ� ������

	int isBuff;				// ��������
};

ActiveSkill activeSkill[SKILLGRADE][SKILLCODE];

// �Լ� ����
void SkillEasyInit();
void SkillNormalInit();
void SkillHardInit();
void SkillElement(int _code, int _grade, string _name, string _info, int _attcount, int _coefficient, AttackType _type, int _cost);
void AddSkill(ActiveSkill* _active, int _code, int _grade);

void SkillInit()
{
	// ��� ��ų ����
	SkillEasyInit();
	SkillNormalInit();
	SkillHardInit();
}

void SkillElement(int _code, int _grade, string _name, string _info, int _attcount, int _coefficient, AttackType _type, int _cost)
{
	switch (_grade)
	{
	case 0:
		activeSkill[_grade][_code].grade = "�Ϲ�";
		break;
	case 1:
		activeSkill[_grade][_code].grade = "���";
		break;
	case 2:
		activeSkill[_grade][_code].grade = "����";
		break;
	default:
		break;
	}
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

void SkillEasyInit()
{
	// �ڵ�, ���, �̸�, ����, ����Ƚ��, ���, ����, �Ҹ���
	SkillElement(0, 0, "������", "�����´�", 1, 50, SINGLE, 1);
	SkillElement(1, 0, "������", "������", 1, 100, SINGLE, 2);
	SkillElement(2, 0, "�ֵθ���", "�ֵθ���", 1, 50, RANGE, 2);
	SkillElement(3, 0, "���", "���", 1, 100, SINGLE, 2);
	SkillElement(4, 0, "�ֵθ���", "�ֵθ���", 1, 50, RANGE, 2);
	SkillElement(5, 0, "�ֵθ���", "�ֵθ���", 1, 50, RANGE, 2);
	SkillElement(6, 0, "�ֵθ���", "�ֵθ���", 1, 50, RANGE, 2);
	SkillElement(7, 0, "�ֵθ���", "�ֵθ���", 1, 50, RANGE, 2);
	SkillElement(8, 0, "�ֵθ���", "�ֵθ���", 1, 50, RANGE, 2);
	SkillElement(9, 0, "�ֵθ���", "�ֵθ���", 1, 50, RANGE, 2);
}

void SkillNormalInit()
{
	SkillElement(0, 1, "��� ������", "��� �����´�", 1, 70, SINGLE, 1);
	SkillElement(1, 1, "��� ������", "��� ������", 1, 120, SINGLE, 2);
	SkillElement(2, 1, "��� �ֵθ���", "��� �ֵθ���", 1, 80, RANGE, 2);
	SkillElement(3, 1, "��� ���", "��� ���", 1, 120, SINGLE, 2);
	SkillElement(4, 1, "��� �ֵθ���", "��� �ֵθ���", 1, 80, RANGE, 2);
	SkillElement(5, 1, "��� �ֵθ���", "��� �ֵθ���", 1, 80, RANGE, 2);
	SkillElement(6, 1, "��� �ֵθ���", "��� �ֵθ���", 1, 80, RANGE, 2);
	SkillElement(7, 1, "��� �ֵθ���", "��� �ֵθ���", 1, 80, RANGE, 2);
	SkillElement(8, 1, "��� �ֵθ���", "��� �ֵθ���", 1, 80, RANGE, 2);
	SkillElement(9, 1, "��� �ֵθ���", "��� �ֵθ���", 1, 80, RANGE, 2);
}

void SkillHardInit()
{
	SkillElement(0, 2, "��¥ ��� ������", "��¥ ��� �����´�", 1, 100, SINGLE, 1);
	SkillElement(1, 2, "��¥ ��� ������", "��¥ ��� ������", 1, 150, SINGLE, 2);
	SkillElement(2, 2, "��¥ ��� �ֵθ���", "��¥ ��� �ֵθ���", 1, 100, RANGE, 2);
	SkillElement(3, 2, "��¥ ��� ���", "��¥ ��� ���", 1, 150, SINGLE, 2);
	SkillElement(4, 2, "��¥ ��� �ֵθ���", "��¥ ��� �ֵθ���", 1, 100, RANGE, 2);
	SkillElement(5, 2, "��¥ ��� �ֵθ���", "��¥ ��� �ֵθ���", 1, 100, RANGE, 2);
	SkillElement(6, 2, "��¥ ��� �ֵθ���", "��¥ ��� �ֵθ���", 1, 100, RANGE, 2);
	SkillElement(7, 2, "��¥ ��� �ֵθ���", "��¥ ��� �ֵθ���", 1, 100, RANGE, 2);
	SkillElement(8, 2, "��¥ ��� �ֵθ���", "��¥ ��� �ֵθ���", 1, 100, RANGE, 2);
	SkillElement(9, 2, "��¥ ��� �ֵθ���", "��¥ ��� �ֵθ���", 1, 100, RANGE, 2);
}


