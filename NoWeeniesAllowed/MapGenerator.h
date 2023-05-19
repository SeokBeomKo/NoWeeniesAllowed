#pragma once
#include "framework.h"
#include <time.h>			// 랜덤
#include "Enemy.h"

#define COLUMN		10
#define ROW			3

typedef struct mapInfo MapInfo;
typedef struct mapNode MapNode;
typedef enum map_type MAP_TYPE;

// 구조체
enum map_type
{
	NORMALBATTLE,
	ELITEBATTLE,
	REWARD,
	TRAP
};
struct mapInfo
{
	/*
	타입 : (일반 전투맵, 엘리트 전투맵, 보상맵, 함정맵)
	소환될 적 정보 (0 ~ 3)
	소환될 적 개체수
	보상 (골드)
	*/
	MAP_TYPE type;
	Enemy enemy[3];
	int enemyCount;
	int rewards;
};
struct mapNode
{
	int isFull;			// 맵이 비어있는지 확인
	int isStay;			// 플레이어가 위치했는지 확인
	/*
	다음 맵 노드를 가지고 있음
	*/
	MapNode* leftNode;
	MapNode* straightNode;
	MapNode* rightNode;

	MapInfo info;
};

/*
	맵 생성 예시

		  ㅁ				ㅁ → ㅁ
	   ↗    ↘          ↗
	ㅁ → ㅁ → ㅁ → ㅁ	      ㅁ
	   ↘    ↗	   ↗	 ↘    ↗
		  ㅁ → ㅁ		    ㅁ → ㅁ
*/

// 변수

int				mapIndex[COLUMN][ROW];
static int		column = 0, row = 0, isFull = 0;
MapNode mapList[COLUMN][ROW] = { 0 };
MapNode enterMapNode;
MapNode exitMapNode;

// 함수


void MapIndexCreate()
{
	// TODO : 이전 노드 또는 다음 노드와 2 칸 떨어져 있는 경우
	srand(time(NULL));

	column = 0, row = 0, isFull = 0;

	// 맵 인덱스 생성 (방이 있는지 비었는지)
	for (column = 0; column < COLUMN; column++)
	{
		// 방이 비어있는지 확인 값 초기화
		isFull = 0;
		for (row = 0; row < ROW; row++)
		{
			mapIndex[column][row] = rand() % 2;

			// 예외 : 모든 방이 비어있다면 최소 한개의 방을 가운데 생성
			isFull += mapIndex[column][row];
		}
		if (isFull == 0)
		{
			mapIndex[column][(ROW / 2) + 1] = 1;
			isFull = 0;
		}
	}
}

void MapNodeAdd(int column, int row)
{
	// 다음 노드 정보 넣기
	if (mapIndex[column + 1][row - 1] == 1 && row != 0)
	{
		mapList[column][row].leftNode = &mapList[column + 1][row - 1];
	}
	if (mapIndex[column + 1][row] == 1)
	{
		mapList[column][row].straightNode = &mapList[column + 1][row];
	}
	if (mapIndex[column + 1][row + 1] == 1 && row != ROW - 1)
	{
		mapList[column][row].rightNode = &mapList[column + 1][row + 1];
	}
}

void StageRender()
{
	// 맵 인덱스 생성 확인
	for (column = 0; column < COLUMN; column++)
	{
		// 맵 정보 나타낼 때
		for (row = 0; row < ROW; row++)
		{
			if (mapList[column][row].isFull == 1)
			{
				printf("  □\t");
			}
			else
			{
				printf("  \t");
			}
		}
		printf("\n");
		// 맵의 다음 선택지 나타낼 때
		// TODO : 첫 시작과 마지막 예외처리
		for (row = 0; row < ROW; row++)
		{
			if (column == COLUMN - 1)
				break;
			if (mapList[column][row].isFull)		// 노드가 있다면
			{
				if (mapList[column][row].leftNode != NULL)	printf("↙");
				else printf("  ");
				if (mapList[column][row].straightNode != NULL)	printf("↓");
				else printf("  ");
				if (mapList[column][row].rightNode != NULL)	printf("↘");
				else printf("  ");
			}
			printf("\t");
		}
		if (column != COLUMN - 1) printf("\n");
	}
}
void EnterRender()
{
	// 시작 지점 렌더
	for (row = 0; row < ROW - 2; row++)
	{
		printf("\t  ");
	}
	// TODO : 현재 위치한 곳을 색채워서
	printf("■");
	for (row = 0; row < ROW - 2; row++)
	{
		printf("  \t");
	}
	printf("\n");
	printf("\t");
	for (row = 0; row < ROW; row++)
	{
		switch (row)
		{
		case 0:
			if (mapList[0][row].isFull)	printf("↙");
			else printf("  ");
			break;
		case 1:
			if (mapList[0][row].isFull)	printf("↓");
			else printf("  ");
			break;
		case 2:
			if (mapList[0][row].isFull)	printf("↘");
			else printf("  ");
			break;
		default:
			break;
		}
	}
	printf("\n");
}
void ExitRender()
{
	printf("\t");
	for (row = 0; row < ROW; row++)
	{
		switch (row)
		{
		case 0:
			if (mapList[9][row].isFull)	printf("↘");
			else printf("  ");
			break;
		case 1:
			if (mapList[9][row].isFull)	printf("↓");
			else printf("  ");
			break;
		case 2:
			if (mapList[9][row].isFull)	printf("↙");
			else printf("  ");
			break;
		default:
			break;
		}
	}
	printf("\n");
	// 보스 진입 렌더
	for (row = 0; row < ROW - 2; row++)
	{
		printf("\t  ");
	}
	// TODO : 현재 위치한 곳을 색채워서
	printf("☆");
	for (row = 0; row < ROW - 2; row++)
	{
		printf("  \t");
	}
}