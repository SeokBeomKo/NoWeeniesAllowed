#pragma once

#include "framework.h"

// 모든 몹 종류
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

Enemy enemy[Diffi][Count];		// 모든 적 정보 저장
Enemy* enemyPtr[Count];


// 함수 선언
void EnemyElement(int _difficult, int _code, string _name, string _info, int _hp, int _att, int _attcount, int _def, int _difficulty);
void EnemyPatternElemeny(int _difficult, int _code, int _count, string _name, int _type);
void AddEnemy(Enemy* _enemy, int _difficult, int _copycode);

void EnemyInit()
{
	// 모든 적 생성

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 0, "0Tom", "일반 몬스터", 10, 1, 1, 0, 0);
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0 ,0, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0 ,0, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0 ,0, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 코드, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 난이도 (0 ~ 5) 012 123 234
	EnemyElement(0, 1, "0Scooter", "일반 몬스터", 10, 1, 1, 0, 0);
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 0, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 0, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 0, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 코드, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 난이도 (0 ~ 5) 012 123 234
	EnemyElement(0, 2, "0Nat", "일반 몬스터", 10, 1, 1, 0, 0);
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 0, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 0, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 0, 2, "막기", EDEFFENSE);


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

