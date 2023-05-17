#include "framework.h"

#include "MapGenerator.h"

#include "Enemy.h"

typedef struct mapInfo MapInfo;
typedef struct mapNode MapNode;
typedef enum type TYPE;

enum type
{
	BATTLE,
	REWARD,
	TRAP
};

struct mapInfo
{
	/*
	타입 : (일반 전투맵, 보상맵, 함정맵)
	적 정보 (0 ~ 3)
	*/
	TYPE type;
	Enemy enemy[3];
};

struct mapNode
{
	MapNode* curNode;
	/*
	다음 맵 노드를 가지고 있음
	*/
	MapNode* leftNode;
	MapNode* straightNode;
	MapNode* rightNode;

	MapInfo info;
};

int main()
{
	system("mode con:lines=150 cols=50");		// 콘솔창 크기

	MapIndexCreate(mapIndex);
	Temp();

}
