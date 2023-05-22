#pragma once

#include "framework.h"

// ��� �� ����
#define Count 20

typedef enum patterntype
{
	EATTACK,
	EDEFFENSE,
	EHEAL,
	EDEBUFF,
	EBUFF,
	EIDLE
}PatternType;

typedef struct enemypattern
{
	string name;			// ���� �̸�
	PatternType pattern;	// ���� Ÿ��
}EnemyPattern;

typedef struct enemy
{
	/*
	�̸�
	ü��
	���� ü��
	���ݷ�
	���� Ƚ��
	����
	*/
	string	name;
	string	info;
	int		hp;
	int     curhp;
	int		att;
	int		attcount;
	int		def;
	// �ൿ ����
	EnemyPattern pattern[3];
	// �����ϴ� ���̵�
	int difficulty;
}Enemy;

Enemy enemy[Count];


// �Լ� ����
void EnemyElement(int code, string _name, string _info, int _hp, int _att, int _attcount, int _def, int _difficulty);
void EnemyPatternElemeny(int _code, int _count, string _name, int _type);

void Init()
{
	// ��� �� ����

	// �ڵ�, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� ���̵� (0 ~ 5) 012 123 234
	EnemyElement(0, "Tom", "�Ϲ� ����", 10, 1, 1, 0, 0);
	// �ڵ�, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(0, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(0, 1, "������", EATTACK);
	EnemyPatternElemeny(0, 2, "����", EDEFFENSE);

	// �ڵ�, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� ���̵� (0 ~ 5) 012 123 234
	EnemyElement(1, "Scooter", "�Ϲ� ����", 10, 1, 1, 0, 0);
	// �ڵ�, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(1, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(1, 1, "������", EATTACK);
	EnemyPatternElemeny(1, 2, "����", EDEFFENSE);

	// �ڵ�, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� ���̵� (0 ~ 5) 012 123 234
	EnemyElement(2, "Nat", "�Ϲ� ����", 10, 1, 1, 0, 0);
	// �ڵ�, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(2, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(2, 1, "������", EATTACK);
	EnemyPatternElemeny(2, 2, "����", EDEFFENSE);
}

void EnemyElement(int code, string _name, string _info, int _hp, int _att, int _attcount, int _def, int _difficulty)
{
	enemy[code].name = _name;
	enemy[code].info = _info;
	enemy[code].hp = _hp;
	enemy[code].att = _att;
	enemy[code].attcount = _attcount;
	enemy[code].def = _def;
}
void EnemyPatternElemeny(int _code, int _count, string _name, int _type)
{
	enemy[_code].pattern[_count].name = _name;
	enemy[_code].pattern[_count].pattern = _type;
}

void CreateEnemy(Enemy _enemy, int copycode)
{
	_enemy = enemy[copycode];
}

