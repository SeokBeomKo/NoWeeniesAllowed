#pragma once

#include "framework.h"

// ��� �� ����
#define Count 12
#define Diffi 3

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

Enemy enemy[Diffi][Count];		// ��� �� ���� ����
Enemy* enemyPtr[Count];


// �Լ� ����
void EnemyElement(int _difficult, int _code, string _name, string _info, int _hp, int _att, int _attcount, int _def, int _difficulty);
void EnemyPatternElemeny(int _difficult, int _code, int _count, string _name, int _type);
void AddEnemy(Enemy* _enemy, int _difficult, int _copycode);

void EnemyInit()
{
	// ��� �� ����

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(0, 0, "0Tom", "�Ϲ� ����", 10, 1, 1, 0, 0);
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(0 ,0, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(0 ,0, 1, "������", EATTACK);
	EnemyPatternElemeny(0 ,0, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �ڵ�, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� ���̵� (0 ~ 5) 012 123 234
	EnemyElement(0, 1, "0Scooter", "�Ϲ� ����", 10, 1, 1, 0, 0);
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(0, 0, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(0, 0, 1, "������", EATTACK);
	EnemyPatternElemeny(0, 0, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �ڵ�, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� ���̵� (0 ~ 5) 012 123 234
	EnemyElement(0, 2, "0Nat", "�Ϲ� ����", 10, 1, 1, 0, 0);
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(0, 0, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(0, 0, 1, "������", EATTACK);
	EnemyPatternElemeny(0, 0, 2, "����", EDEFFENSE);


}

void EnemyElement(int _difficult, int _code, string _name, string _info, int _hp, int _att, int _attcount, int _def, int _difficulty)
{
	enemy[_difficult][_code].name = _name;
	enemy[_difficult][_code].info = _info;
	enemy[_difficult][_code].hp = _hp;
	enemy[_difficult][_code].curhp = _hp;
	enemy[_difficult][_code].att = _att;
	enemy[_difficult][_code].attcount = _attcount;
	enemy[_difficult][_code].def = _def;
}
void EnemyPatternElemeny(int _difficult, int _code, int _count, string _name, int _type)
{
	enemy[_difficult][_code].pattern[_count].name = _name;
	enemy[_difficult][_code].pattern[_count].pattern = _type;
}

void AddEnemy(Enemy *_enemy, int _difficult, int _copycode)
{
	*_enemy = enemy[_difficult][_copycode];
}

