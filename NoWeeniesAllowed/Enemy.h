#pragma once

#include "framework.h"

// 모든 몹 종류
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
	string name;			// 패턴 이름
	EnemyPatternType pattern;	// 패턴 타입
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


// 함수 선언
void EnemyInit();

void EnemyElement(int _difficult, int _code, string _name, string _info, int _hp, int _att, int _attcount, int _def, int _difficulty, const wchar_t* _drawData);
void EnemyPatternElemeny(int _difficult, int _code, int _count, string _name, EnemyPatternType _type);
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
	EnemyElement(1, 0, "Bubble_Bass", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\02.Normal\\Bubble_Bass.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(1, 0, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(1, 0, 1, "때리기", EATTACK);
	EnemyPatternElemeny(1, 0, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(1, 1, "Crazy_Tom", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\02.Normal\\Crazy_Tom.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(1, 1, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(1, 1, 1, "때리기", EATTACK);
	EnemyPatternElemeny(1, 1, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(1, 2, "Dirty_Bubble", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\02.Normal\\Dirty_Bubble.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(1, 2, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(1, 2, 1, "때리기", EATTACK);
	EnemyPatternElemeny(1, 2, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(1, 3, "Don_Grouper", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\02.Normal\\Don_Grouper.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(1, 3, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(1, 3, 1, "때리기", EATTACK);
	EnemyPatternElemeny(1, 3, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(1, 4, "Flats_the_Flounder", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\02.Normal\\Flats_the_Flounder.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(1, 4, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(1, 4, 1, "때리기", EATTACK);
	EnemyPatternElemeny(1, 4, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(1, 5, "Jim", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\02.Normal\\Jim.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(1, 5, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(1, 5, 1, "때리기", EATTACK);
	EnemyPatternElemeny(1, 5, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(1, 6, "Kevin", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\02.Normal\\Kevin.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(1, 6, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(1, 6, 1, "때리기", EATTACK);
	EnemyPatternElemeny(1, 6, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(1, 7, "Man_Ray", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\02.Normal\\Man_Ray.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(1, 7, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(1, 7, 1, "때리기", EATTACK);
	EnemyPatternElemeny(1, 7, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(1, 8, "Master_Udon", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\02.Normal\\Master_Udon.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(1, 8, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(1, 8, 1, "때리기", EATTACK);
	EnemyPatternElemeny(1, 8, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(1, 9, "Plankton", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\02.Normal\\Plankton.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(1, 9, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(1, 9, 1, "때리기", EATTACK);
	EnemyPatternElemeny(1, 9, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(1, 10, "Hash_Slinging_Slasher", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\02.Normal\\Hash_Slinging_Slasher.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(1, 10, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(1, 10, 1, "때리기", EATTACK);
	EnemyPatternElemeny(1, 10, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(1, 11, "Strangler", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\02.Normal\\Strangler.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(1, 11, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(1, 11, 1, "때리기", EATTACK);
	EnemyPatternElemeny(1, 11, 2, "막기", EDEFFENSE);
}

void EnemyHardInit()
{
	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(2, 0, "Bubba", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\03.Hard\\Bubba.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(2, 0, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(2, 0, 1, "때리기", EATTACK);
	EnemyPatternElemeny(2, 0, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(2, 1, "Dennis", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\03.Hard\\Dennis.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(2, 1, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(2, 1, 1, "때리기", EATTACK);
	EnemyPatternElemeny(2, 1, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(2, 2, "Don", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\03.Hard\\Don.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(2, 2, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(2, 2, 1, "때리기", EATTACK);
	EnemyPatternElemeny(2, 2, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(2, 3, "Finback", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\03.Hard\\Finback.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(2, 3, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(2, 3, 1, "때리기", EATTACK);
	EnemyPatternElemeny(2, 3, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(2, 4, "Frank", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\03.Hard\\Frank.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(2, 4, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(2, 4, 1, "때리기", EATTACK);
	EnemyPatternElemeny(2, 4, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(2, 5, "Gordon", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\03.Hard\\Gordon.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(2, 5, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(2, 5, 1, "때리기", EATTACK);
	EnemyPatternElemeny(2, 5, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(2, 6, "Larry", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\03.Hard\\Larry.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(2, 6, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(2, 6, 1, "때리기", EATTACK);
	EnemyPatternElemeny(2, 6, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(2, 7, "Popeye", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\03.Hard\\Popeye.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(2, 7, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(2, 7, 1, "때리기", EATTACK);
	EnemyPatternElemeny(2, 7, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(2, 8, "Reg", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\03.Hard\\Reg.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(2, 8, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(2, 8, 1, "때리기", EATTACK);
	EnemyPatternElemeny(2, 8, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(2, 9, "Roderick", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\03.Hard\\Roderick.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(2, 9, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(2, 9, 1, "때리기", EATTACK);
	EnemyPatternElemeny(2, 9, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(2, 10, "Sticky_Fins", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\03.Hard\\Sticky_Fins.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(2, 10, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(2, 10, 1, "때리기", EATTACK);
	EnemyPatternElemeny(2, 10, 2, "막기", EDEFFENSE);

	// 등장 난이도 (0 ~ 2), 배열, 이름, 설명, 체력, 공격력, 공격횟수, 방어력, 출현 스테이지 (0 ~ 2)
	EnemyElement(2, 11, "Tough", "일반 몬스터", 10, 1, 1, 0, 0, L"Enemy\\03.Hard\\Tough.txt");
	// 등장 난이도 (0 ~ 2), 배열, 행동패턴 번호, 이름, 타입
	EnemyPatternElemeny(2, 11, 0, "멍 때리기", EIDLE);
	EnemyPatternElemeny(2, 11, 1, "때리기", EATTACK);
	EnemyPatternElemeny(2, 11, 2, "막기", EDEFFENSE);
}
