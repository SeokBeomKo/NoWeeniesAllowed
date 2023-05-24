#pragma once

#include "framework.h"

// ��� �� ����
#define Count 12
#define Diffi 3

typedef enum enemypatterntype
{
	EATTACK,
	EHEAL,
	EDEFFENSE,
	EDEBUFF,
	EBUFF,
	EIDLE

}EnemyPatternType;

typedef struct enemypattern
{
	string name;			// ���� �̸�
	EnemyPatternType pattern;	// ���� Ÿ��
}EnemyPattern;

typedef struct enemy
{
	const wchar_t *drawData;
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


// �Լ� ����
void EnemyInit();

void EnemyElement(int _difficult, int _code, string _name, string _info, int _hp, int _att, int _attcount, int _def, int _difficulty, const wchar_t* _drawData);
void EnemyPatternElemeny(int _difficult, int _code, int _count, string _name, EnemyPatternType _type);
void AddEnemy(Enemy* _enemy, int _difficult, int _copycode);

void EnemyEasyInit();
void EnemyNormalInit();
void EnemyHardInit();

void EnemyInit()
{
	// ��� �� ����

	EnemyEasyInit();
	EnemyNormalInit();
	EnemyHardInit();
}

void EnemyElement(int _difficult, int _code, string _name, string _info, int _hp, int _att, int _attcount, int _def, int _difficulty, const wchar_t *_drawData)
{
	enemy[_difficult][_code].name = _name;
	enemy[_difficult][_code].info = _info;
	enemy[_difficult][_code].hp = _hp;
	enemy[_difficult][_code].curhp = _hp;
	enemy[_difficult][_code].att = _att;
	enemy[_difficult][_code].attcount = _attcount;
	enemy[_difficult][_code].def = _def;

	enemy[_difficult][_code].drawData = _drawData;
}
void EnemyPatternElemeny(int _difficult, int _code, int _count, string _name, EnemyPatternType _type)
{
	enemy[_difficult][_code].pattern[_count].name = _name;
	enemy[_difficult][_code].pattern[_count].pattern = _type;
}

void AddEnemy(Enemy *_enemy, int _difficult, int _copycode)
{
	*_enemy = enemy[_difficult][_copycode];
}

void EnemyEasyInit()
{
	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(0, 0, "Anchovy", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Anchovy.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(0, 0, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(0, 0, 1, "������", EATTACK);
	EnemyPatternElemeny(0, 0, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(0, 1, "Billy", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Billy.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(0, 1, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(0, 1, 1, "������", EATTACK);
	EnemyPatternElemeny(0, 1, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(0, 2, "Frankie", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Frankie.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(0, 2, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(0, 2, 1, "������", EATTACK);
	EnemyPatternElemeny(0, 2, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(0, 3, "Fred", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Fred.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(0, 3, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(0, 3, 1, "������", EATTACK);
	EnemyPatternElemeny(0, 3, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(0, 4, "Harold", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Harold.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(0, 4, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(0, 4, 1, "������", EATTACK);
	EnemyPatternElemeny(0, 4, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(0, 5, "Harv", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Harv.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(0, 5, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(0, 5, 1, "������", EATTACK);
	EnemyPatternElemeny(0, 5, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(0, 6, "Anchovy", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Marge.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(0, 6, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(0, 6, 1, "������", EATTACK);
	EnemyPatternElemeny(0, 6, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(0, 7, "Nat", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Nat.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(0, 7, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(0, 7, 1, "������", EATTACK);
	EnemyPatternElemeny(0, 7, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(0, 8, "Nazz", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Nazz.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(0, 8, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(0, 8, 1, "������", EATTACK);
	EnemyPatternElemeny(0, 8, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(0, 9, "Scooter", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Scooter.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(0, 9, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(0, 9, 1, "������", EATTACK);
	EnemyPatternElemeny(0, 9, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(0, 10, "Tom", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Tom.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(0, 10, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(0, 10, 1, "������", EATTACK);
	EnemyPatternElemeny(0, 10, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(0, 11, "Walker", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Walker.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(0, 11, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(0, 11, 1, "������", EATTACK);
	EnemyPatternElemeny(0, 11, 2, "����", EDEFFENSE);
}

void EnemyNormalInit()
{
	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(1, 0, "Bubble_Bass", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\02.Normal\\Bubble_Bass.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(1, 0, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(1, 0, 1, "������", EATTACK);
	EnemyPatternElemeny(1, 0, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(1, 1, "Crazy_Tom", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\02.Normal\\Crazy_Tom.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(1, 1, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(1, 1, 1, "������", EATTACK);
	EnemyPatternElemeny(1, 1, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(1, 2, "Dirty_Bubble", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\02.Normal\\Dirty_Bubble.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(1, 2, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(1, 2, 1, "������", EATTACK);
	EnemyPatternElemeny(1, 2, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(1, 3, "Don_Grouper", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\02.Normal\\Don_Grouper.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(1, 3, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(1, 3, 1, "������", EATTACK);
	EnemyPatternElemeny(1, 3, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(1, 4, "Flats_the_Flounder", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\02.Normal\\Flats_the_Flounder.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(1, 4, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(1, 4, 1, "������", EATTACK);
	EnemyPatternElemeny(1, 4, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(1, 5, "Jim", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\02.Normal\\Jim.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(1, 5, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(1, 5, 1, "������", EATTACK);
	EnemyPatternElemeny(1, 5, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(1, 6, "Kevin", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\02.Normal\\Kevin.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(1, 6, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(1, 6, 1, "������", EATTACK);
	EnemyPatternElemeny(1, 6, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(1, 7, "Man_Ray", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\02.Normal\\Man_Ray.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(1, 7, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(1, 7, 1, "������", EATTACK);
	EnemyPatternElemeny(1, 7, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(1, 8, "Master_Udon", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\02.Normal\\Master_Udon.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(1, 8, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(1, 8, 1, "������", EATTACK);
	EnemyPatternElemeny(1, 8, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(1, 9, "Plankton", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\02.Normal\\Plankton.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(1, 9, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(1, 9, 1, "������", EATTACK);
	EnemyPatternElemeny(1, 9, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(1, 10, "Hash_Slinging_Slasher", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\02.Normal\\Hash_Slinging_Slasher.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(1, 10, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(1, 10, 1, "������", EATTACK);
	EnemyPatternElemeny(1, 10, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(1, 11, "Strangler", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\02.Normal\\Strangler.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(1, 11, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(1, 11, 1, "������", EATTACK);
	EnemyPatternElemeny(1, 11, 2, "����", EDEFFENSE);
}

void EnemyHardInit()
{
	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(2, 0, "Bubba", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\03.Hard\\Bubba.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(2, 0, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(2, 0, 1, "������", EATTACK);
	EnemyPatternElemeny(2, 0, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(2, 1, "Dennis", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\03.Hard\\Dennis.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(2, 1, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(2, 1, 1, "������", EATTACK);
	EnemyPatternElemeny(2, 1, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(2, 2, "Don", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\03.Hard\\Don.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(2, 2, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(2, 2, 1, "������", EATTACK);
	EnemyPatternElemeny(2, 2, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(2, 3, "Finback", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\03.Hard\\Finback.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(2, 3, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(2, 3, 1, "������", EATTACK);
	EnemyPatternElemeny(2, 3, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(2, 4, "Frank", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\03.Hard\\Frank.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(2, 4, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(2, 4, 1, "������", EATTACK);
	EnemyPatternElemeny(2, 4, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(2, 5, "Gordon", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\03.Hard\\Gordon.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(2, 5, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(2, 5, 1, "������", EATTACK);
	EnemyPatternElemeny(2, 5, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(2, 6, "Larry", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\03.Hard\\Larry.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(2, 6, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(2, 6, 1, "������", EATTACK);
	EnemyPatternElemeny(2, 6, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(2, 7, "Popeye", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\03.Hard\\Popeye.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(2, 7, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(2, 7, 1, "������", EATTACK);
	EnemyPatternElemeny(2, 7, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(2, 8, "Reg", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\03.Hard\\Reg.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(2, 8, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(2, 8, 1, "������", EATTACK);
	EnemyPatternElemeny(2, 8, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(2, 9, "Roderick", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\03.Hard\\Roderick.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(2, 9, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(2, 9, 1, "������", EATTACK);
	EnemyPatternElemeny(2, 9, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(2, 10, "Sticky_Fins", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\03.Hard\\Sticky_Fins.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(2, 10, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(2, 10, 1, "������", EATTACK);
	EnemyPatternElemeny(2, 10, 2, "����", EDEFFENSE);

	// ���� ���̵� (0 ~ 2), �迭, �̸�, ����, ü��, ���ݷ�, ����Ƚ��, ����, ���� �������� (0 ~ 2)
	EnemyElement(2, 11, "Tough", "�Ϲ� ����", 10, 1, 1, 0, 0, L"Enemy\\03.Hard\\Tough.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	EnemyPatternElemeny(2, 11, 0, "�� ������", EIDLE);
	EnemyPatternElemeny(2, 11, 1, "������", EATTACK);
	EnemyPatternElemeny(2, 11, 2, "����", EDEFFENSE);
}
