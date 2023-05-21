#pragma once
#include "framework.h"
#include <time.h>			// 랜덤
#include "Enemy.h"


// TODO : 값 변경값에 맞게 자동 맞춤
#define COLUMN		10
#define ROW			3

typedef struct mapInfo MapInfo;
typedef struct mapNode MapNode;
typedef enum map_type MAP_TYPE;

// 열거형

enum map_type
{
	BATTLE,
	REWARD,
	TRAP
};

// 구조체

struct mapInfo
{
	/*
	타입 : (일반 전투맵, 엘리트 전투맵, 보상맵, 함정맵)
	소환될 적 정보 (0 ~ 3)
	소환될 적 개체수
	보상 (골드)
	*/
	Enemy enemy[3];
	int type;
	int enemyCount;
	int rewards;
};
struct mapNode
{
	int isFull;			// 맵이 비어있는지 확인
	int isStay;			// 플레이어가 위치했는지 확인
	int isClear;		// 클리어한 장소인지
	int isColumn;		// 몇번째 열인지
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
MapNode *curMapNode;

// 함수

void SetConsoleTextColor(int color_number);

void MapDoubleCheck();
void MapNodeAdd(int column, int row);
void CurRender(MapNode node, int column);

// 맵 생성 기능
void MapIndexCreate()
{
	srand(time(NULL));
	isFull = 0;

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
	MapDoubleCheck();
}
void MapDoubleCheck()
{
	for (column = 0; column < COLUMN - 1; column++)
	{
		if (mapIndex[column][0] == 1 && mapIndex[column + 1][0] == 0 && mapIndex[column + 1][1] == 0)
		{
			mapIndex[column + 1][rand() % 2] = 1;
		}
		if (mapIndex[column][2] == 1 && mapIndex[column + 1][1] == 0 && mapIndex[column + 1][2] == 0)
		{
			mapIndex[column + 1][rand() % 2 + 1] = 1;
		}
	}
}

void MapListCreate()
{
	int type = 0;

	// 시작 지점 설정
	curMapNode = &enterMapNode;
	curMapNode->isStay = 1;
	curMapNode->isColumn = -1;

	enterMapNode.leftNode = &mapList[0][0];
	enterMapNode.straightNode = &mapList[0][1];
	enterMapNode.rightNode = &mapList[0][2];

	for (column = 0; column < COLUMN; column++)
	{
		for (row = 0; row < ROW; row++)
		{
			if (mapIndex[column][row] == 1)
			{
				mapList[column][row].isFull = 1;
				mapList[column][row].isClear = 0;
				mapList[column][row].isColumn = column;

				// 맵 타입 결정 0 : 전투, 1 : 보물, 2 : 함정
				// 전투 60 보물 20 함정 20
				type = rand() % 10;

				// 전투 맵
				if (type > 6)		
				{
					mapList[column][row].info.type = (int)BATTLE;
					mapList[column][row].info.enemyCount = rand() % 3 + 1;
				}
				// 보물 맵
				else if (type > 8)
				{
					mapList[column][row].info.type = (int)REWARD;
				}
				// 함정 맵
				else if (type > 10)
				{
					mapList[column][row].info.type = (int)TRAP;
				}
				
				// 맵에 생성될 적 개체 수
				// printf("mapList[%d][%d] : %d\n", column, row, mapList[column][row].info.enemyCount);
				MapNodeAdd(column, row);
			}
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


// 맵 그리기 기능
void EnterRender()
{
	// 시작 지점 렌더
	for (row = 0; row < ROW - 2; row++)
	{
		printf("\t  ");
	}
	CurRender(enterMapNode, -1);
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
				printf("  ");
				CurRender(mapList[column][row],column);
				printf("\t");
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
	printf("\n");
}

// 현재 위치 그리기 기능
void CurRender(MapNode node, int column)
{
	/*
	01. 현재 있는 곳
	02. 지나온 길
	03. 돌아갈 수 없는 길
	04. 가야할 길
	*/
	int clearcolumn = curMapNode->isColumn;

	// 현재 있는 노드
	if (node.isStay == 1)
	{
		SetConsoleTextColor(12);
		printf("■");
		SetConsoleTextColor(15);
	}

	// 지나온 노드
	else if (node.isClear)
	{
		SetConsoleTextColor(4);
		printf("■");
		SetConsoleTextColor(15);
	}

	// 돌아갈 수 없는 노드
	else if (node.isColumn < clearcolumn)
	{
		SetConsoleTextColor(8);
		printf("□");
		SetConsoleTextColor(15);
	}

	// 가야할 노드
	else
	{
		printf("□");
	}

}