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
	const wchar_t *drawData;
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
void EnemyElement(int _difficult, int _code, string _name, string _info, int _hp, int _att, int _attcount, int _def, int _difficulty, const wchar_t* _drawData);
void EnemyPatternElemeny(int _difficult, int _code, int _count, string _name, PatternType _type);
void AddEnemy(Enemy* _enemy, int _difficult, int _copycode);

void EnemyEasyInit();
void EnemyNormalInit();
void EnemyHardInit();

void EnemyInit()
{
	// 모든 적 생성

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
void EnemyPatternElemeny(int _difficult, int _code, int _count, string _name, PatternType _type)
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
	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 0, "Anchovy", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Anchovy.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 0, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 0, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 0, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 1, "Billy", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Billy.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 1, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 1, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 1, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 2, "Frankie", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Frankie.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 2, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 2, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 2, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 3, "Fred", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Fred.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 3, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 3, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 3, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 4, "Harold", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Harold.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 4, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 4, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 4, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 5, "Harv", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Harv.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 5, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 5, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 5, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 6, "Anchovy", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Marge.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 6, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 6, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 6, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 7, "Nat", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Nat.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 7, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 7, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 7, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 8, "Nazz", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Nazz.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 8, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 8, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 8, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 9, "Scooter", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Scooter.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 9, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 9, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 9, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 10, "Tom", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Tom.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 10, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 10, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 10, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 11, "Walker", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Walker.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 11, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 11, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 11, 2, "막기", EDEFFENSE);
}

void EnemyNormalInit()
{
	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 0, "Anchovy", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Anchovy.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 0, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 0, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 0, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 1, "Billy", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Billy.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 1, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 1, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 1, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 2, "Frankie", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Frankie.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 2, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 2, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 2, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 3, "Fred", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Fred.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 3, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 3, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 3, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 4, "Harold", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Harold.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 4, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 4, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 4, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 5, "Harv", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Harv.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 5, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 5, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 5, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 6, "Anchovy", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Marge.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 6, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 6, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 6, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 7, "Nat", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Nat.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 7, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 7, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 7, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 8, "Nazz", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Nazz.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 8, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 8, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 8, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 9, "Scooter", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Scooter.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 9, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 9, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 9, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 10, "Tom", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Tom.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 10, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 10, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 10, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 11, "Walker", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Walker.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 11, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 11, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 11, 2, "막기", EDEFFENSE);
}

void EnemyHardInit()
{
	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 0, "Anchovy", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Anchovy.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 0, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 0, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 0, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 1, "Billy", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Billy.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 1, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 1, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 1, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 2, "Frankie", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Frankie.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 2, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 2, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 2, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 3, "Fred", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Fred.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 3, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 3, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 3, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 4, "Harold", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Harold.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 4, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 4, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 4, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 5, "Harv", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Harv.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 5, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 5, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 5, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 6, "Anchovy", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Marge.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 6, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 6, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 6, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 7, "Nat", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Nat.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 7, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 7, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 7, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 8, "Nazz", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Nazz.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 8, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 8, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 8, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 9, "Scooter", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Scooter.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 9, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 9, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 9, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 10, "Tom", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Tom.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 10, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 10, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 10, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(0, 11, "Walker", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\01.Easy\\Walker.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(0, 11, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(0, 11, 1, "때리기", EATTACK);
	EnemyPatternElemeny(0, 11, 2, "막기", EDEFFENSE);
}
