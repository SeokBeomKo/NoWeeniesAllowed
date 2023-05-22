#pragma once

#include "framework.h"

// 모든 몹 종류
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
	string name;			// 패턴 이름
	PatternType pattern;	// 패턴 타입
}EnemyPattern;

typedef struct enemy
{
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
	EnemyPattern pattern[3];
	// 출현하는 난이도
	int difficulty;
}Enemy;

Enemy enemy[Count];


// 함수 선언
void EnemyElement(int code, string _name, string _info, int _hp, int _att, int _attcount, int _def, int _difficulty);
void EnemyPatternElemeny(int _code, int _count, string _name, int _type);

void Init()
{
	// 모든 적 생성

	// 코드, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 난이도 (0 ~ 5) 012 123 234
	EnemyElement(0, "Tom", "일반 몬스터", 10, 1, 1, 0, 0);
	// 코드, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 2, "막기", EDEFFENSE);

	// 코드, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 난이도 (0 ~ 5) 012 123 234
	EnemyElement(1, "Scooter", "일반 몬스터", 10, 1, 1, 0, 0);
	// 코드, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(1, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(1, 1, "때리기", EATTACK);
	EnemyPatternElemeny(1, 2, "막기", EDEFFENSE);

	// 코드, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 난이도 (0 ~ 5) 012 123 234
	EnemyElement(2, "Nat", "일반 몬스터", 10, 1, 1, 0, 0);
	// 코드, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(2, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(2, 1, "때리기", EATTACK);
	EnemyPatternElemeny(2, 2, "막기", EDEFFENSE);
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

