#include "framework.h"

#include "MapGenerator.h"

#include "Enemy.h"

typedef struct mapInfo MapInfo;
typedef struct mapNode MapNode;
typedef enum type TYPE;

enum type
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
	TYPE type;
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

MapNode mapList[COLUMN][ROW] = {0};
MapNode enterMapNode;
MapNode exitMapNode;

void MapRender();
void MapNodeAdd(int column, int row);
void EnterRender();
void ExitRender();

int main()
{
	system("mode con:lines=150 cols=50");		// 콘솔창 크기

	MapIndexCreate();

	// TODO : 맵 인덱스 생성 자체를 이 부분에서 처리하도록
	column = 0, row = 0;

	
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
				mapList[column][row].info.enemyCount = rand() % 3 + 1;
				// 맵에 생성될 적 개체 수
				// printf("mapList[%d][%d] : %d\n", column, row, mapList[column][row].info.enemyCount);
				MapNodeAdd(column,row);
			}
		}
	}
	MapRender();

	return 0;
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
	if (mapIndex[column + 1][row + 1] == 1 && row != ROW-1)
	{
		mapList[column][row].rightNode = &mapList[column + 1][row + 1];
	}
}

void MapRender()
{
	EnterRender();

	column = 0, row = 0;
	// 맵 인덱스 생성 확인
	for (column = 0; column < COLUMN; column++)
	{
		// 맵 정보 나타낼 때
		for (row = 0; row < ROW; row++)
		{
			// TODO : 첫 시작과 마지막 예외처리
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
	ExitRender();
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