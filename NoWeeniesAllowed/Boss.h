#pragma once
#include "framework.h"

typedef enum bosspatterntype
{
	BATTACK,
	BHEAL,
	BDEFFENSE,
	BDEBUFF,
	BBUFF,
	BIDLE

}BossPatternType;

typedef struct bosspattern
{
	string name;			// ���� �̸�
	BossPatternType pattern;	// ���� Ÿ��
}BossPattern;

typedef struct boss
{
	const wchar_t* drawData;
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
	BossPattern pattern[3];
	// �����ϴ� ���̵�
	int difficulty;
}Boss;

Boss boss[Diffi][Count];

void BossInit();
void BossEasyInit();

void BossElement(int _difficult, int _code, string _name, string _info, int _hp, int _att, int _attcount, int _def, int _difficulty, const wchar_t* _drawData);
void BossPatternElemeny(int _difficult, int _code, int _count, string _name, BossPatternType _type);

void BossInit()
{
	BossEasyInit();
}

void BossPatternElemeny(int _difficult, int _code, int _count, string _name, BossPatternType _type)
{
	boss[_difficult][_code].pattern[_count].name = _name;
	boss[_difficult][_code].pattern[_count].pattern = _type;
}

void BossElement(int _difficult, int _code, string _name, string _info, int _hp, int _att, int _attcount, int _def, int _difficulty, const wchar_t* _drawData)
{
	boss[_difficult][_code].name = _name;
	boss[_difficult][_code].info = _info;
	boss[_difficult][_code].hp = _hp;
	boss[_difficult][_code].curhp = _hp;
	boss[_difficult][_code].att = _att;
	boss[_difficult][_code].attcount = _attcount;
	boss[_difficult][_code].def = _def;
	
	boss[_difficult][_code].drawData = _drawData;
}

void BossEasyInit()
{
	BossElement(0, 0, "King_Jellyfish", "���� ����", 1000, 10, 1, 0, 0, L"Boss\\King_Jellyfish.txt");
	// ���� ���̵� (0 ~ 2), �迭, �ൿ���� ��ȣ, �̸�, Ÿ��
	BossPatternElemeny(0, 0, 0, "�� ������", BIDLE);
	BossPatternElemeny(0, 0, 1, "������", BATTACK);
	BossPatternElemeny(0, 0, 2, "����", BDEFFENSE);
}

