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
	/*
	다음 맵 노드를 가지고 있음
	*/
	MapNode* leftNode;
	MapNode* straightNode;
	MapNode* rightNode;

	MapInfo info;
};

MapNode mapList[COLUMN][ROW] = {0};
MapNode curMap;

void MapRender();

int main()
{
	system("mode con:lines=150 cols=50");		// 콘솔창 크기

	MapIndexCreate();

	// TODO : 맵 인덱스 생성 자체를 이 부분에서 처리하도록
	column = 0, row = 0;

	
	curMap.leftNode = &mapList[0][0];
	curMap.straightNode = &mapList[0][1];
	curMap.rightNode = &mapList[0][2];


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
				// 다음 노드 정보 넣기
				if ()
			}
		}
	}
	MapRender();
}

void MapRender()
{
	// 시작 지점 렌더
	for (int i = 0; i < ROW - 2; i++)
	{
		printf("\t");
	}
	printf("■");
	for (int i = 0; i < ROW - 2; i++)
	{
		printf("\t");
	}
	printf("\n");

	column = 0, row = 0;
	// 맵 인덱스 생성 확인
	for (column = 0; column < COLUMN * 2 + 1; column++)
	{
		// 맵 정보 나타낼 때
		if (column % 2 == 1)
		{
			for (row = 0; row < ROW; row++)
			{
				// TODO : 첫 시작과 마지막 예외처리
				if (mapList[column / 2 - 1][row].isFull == 1 || column == 1)
				{
					printf("□\t");
				}
				else
				{
					printf(" \t");
				}
			}
		}
		// 맵의 다음 선택지 나타낼 때
		else
		{
			// TODO : 첫 시작과 마지막 예외처리
			for (row = 0; row < ROW; row++)
			{
				if (mapList[column / -1][row].isFull)		// 전 노드가 있다면
				{

				}

				/*
				전 3개 후 3개 비교

				*/

			}
			//printf("   ↙   ↓   ↘");
		}
		printf("\n");
	}
}
