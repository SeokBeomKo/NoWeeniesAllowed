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
	string name;			// 패턴 이름
	BossPatternType pattern;	// 패턴 타입
}BossPattern;

typedef struct boss
{
	const wchar_t* drawData;
	/*
	이름
	체력
	현재 체력
	공격력
	공격 횟수
	방어력
	*/
	string	name;
	string	info;

	int		hp;
	int     curhp;
	int		att;
	int		attcount;
	int		def;
	// 행동 패턴
	BossPattern pattern[3];
	// 출현하는 난이도
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
	BossElement(0, 0, "King_Jellyfish", "보스 몬스터", 1000, 10, 1, 0, 0, L"Boss\\King_Jellyfish.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	BossPatternElemeny(0, 0, 0, "멍 때리기", BIDLE);
	BossPatternElemeny(0, 0, 1, "때리기", BATTACK);
	BossPatternElemeny(0, 0, 2, "막기", BDEFFENSE);
}

