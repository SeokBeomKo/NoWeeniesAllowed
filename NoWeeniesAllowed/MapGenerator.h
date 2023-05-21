#pragma once
#include "framework.h"
#include <time.h>			// ����
#include "Enemy.h"


// TODO : �� ���氪�� �°� �ڵ� ����
#define COLUMN		10
#define ROW			3

typedef struct mapInfo MapInfo;
typedef struct mapNode MapNode;
typedef enum map_type MAP_TYPE;

// ������

enum map_type
{
	BATTLE,
	REWARD,
	TRAP
};

// ����ü

struct mapInfo
{
	/*
	Ÿ�� : (�Ϲ� ������, ����Ʈ ������, �����, ������)
	��ȯ�� �� ���� (0 ~ 3)
	��ȯ�� �� ��ü��
	���� (���)
	*/
	Enemy enemy[3];
	int type;
	int enemyCount;
	int rewards;
};
struct mapNode
{
	int isFull;			// ���� ����ִ��� Ȯ��
	int isStay;			// �÷��̾ ��ġ�ߴ��� Ȯ��
	int isClear;		// Ŭ������ �������
	int isColumn;		// ���° ������
	/*
	���� �� ��带 ������ ����
	*/
	MapNode* leftNode;
	MapNode* straightNode;
	MapNode* rightNode;

	MapInfo info;
};

/*
	�� ���� ����

		  ��				�� �� ��
	   ��    ��          ��
	�� �� �� �� �� �� ��	      ��
	   ��    ��	   ��	 ��    ��
		  �� �� ��		    �� �� ��
*/

// ����

int				mapIndex[COLUMN][ROW];
static int		column = 0, row = 0, isFull = 0;
MapNode mapList[COLUMN][ROW] = { 0 };
MapNode enterMapNode;
MapNode exitMapNode;
MapNode *curMapNode;

// �Լ�

void SetConsoleTextColor(int color_number);

void MapDoubleCheck();
void MapNodeAdd(int column, int row);
void CurRender(MapNode node, int column);

// �� ���� ���
void MapIndexCreate()
{
	srand(time(NULL));
	isFull = 0;

	// �� �ε��� ���� (���� �ִ��� �������)
	for (column = 0; column < COLUMN; column++)
	{
		// ���� ����ִ��� Ȯ�� �� �ʱ�ȭ
		isFull = 0;
		for (row = 0; row < ROW; row++)
		{
			mapIndex[column][row] = rand() % 2;

			// ���� : ��� ���� ����ִٸ� �ּ� �Ѱ��� ���� ��� ����
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

	// ���� ���� ����
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

				// �� Ÿ�� ���� 0 : ����, 1 : ����, 2 : ����
				// ���� 60 ���� 20 ���� 20
				type = rand() % 10;

				// ���� ��
				if (type > 6)		
				{
					mapList[column][row].info.type = (int)BATTLE;
					mapList[column][row].info.enemyCount = rand() % 3 + 1;
				}
				// ���� ��
				else if (type > 8)
				{
					mapList[column][row].info.type = (int)REWARD;
				}
				// ���� ��
				else if (type > 10)
				{
					mapList[column][row].info.type = (int)TRAP;
				}
				
				// �ʿ� ������ �� ��ü ��
				// printf("mapList[%d][%d] : %d\n", column, row, mapList[column][row].info.enemyCount);
				MapNodeAdd(column, row);
			}
		}
	}
}

void MapNodeAdd(int column, int row)
{
	// ���� ��� ���� �ֱ�
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


// �� �׸��� ���
void EnterRender()
{
	// ���� ���� ����
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
			if (mapList[0][row].isFull)	printf("��");
			else printf("  ");
			break;
		case 1:
			if (mapList[0][row].isFull)	printf("��");
			else printf("  ");
			break;
		case 2:
			if (mapList[0][row].isFull)	printf("��");
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
	// �� �ε��� ���� Ȯ��
	for (column = 0; column < COLUMN; column++)
	{
		// �� ���� ��Ÿ�� ��
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
		// ���� ���� ������ ��Ÿ�� ��
		// TODO : ù ���۰� ������ ����ó��
		for (row = 0; row < ROW; row++)
		{
			if (column == COLUMN - 1)
				break;
			if (mapList[column][row].isFull)		// ��尡 �ִٸ�
			{
				if (mapList[column][row].leftNode != NULL)	printf("��");
				else printf("  ");
				if (mapList[column][row].straightNode != NULL)	printf("��");
				else printf("  ");
				if (mapList[column][row].rightNode != NULL)	printf("��");
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
			if (mapList[9][row].isFull)	printf("��");
			else printf("  ");
			break;
		case 1:
			if (mapList[9][row].isFull)	printf("��");
			else printf("  ");
			break;
		case 2:
			if (mapList[9][row].isFull)	printf("��");
			else printf("  ");
			break;
		default:
			break;
		}
	}
	printf("\n");
	// ���� ���� ����
	for (row = 0; row < ROW - 2; row++)
	{
		printf("\t  ");
	}
	// TODO : ���� ��ġ�� ���� ��ä����
	printf("��");
	for (row = 0; row < ROW - 2; row++)
	{
		printf("  \t");
	}
	printf("\n");
}

// ���� ��ġ �׸��� ���
void CurRender(MapNode node, int column)
{
	/*
	01. ���� �ִ� ��
	02. ������ ��
	03. ���ư� �� ���� ��
	04. ������ ��
	*/
	int clearcolumn = curMapNode->isColumn;

	// ���� �ִ� ���
	if (node.isStay == 1)
	{
		SetConsoleTextColor(12);
		printf("��");
		SetConsoleTextColor(15);
	}

	// ������ ���
	else if (node.isClear)
	{
		SetConsoleTextColor(4);
		printf("��");
		SetConsoleTextColor(15);
	}

	// ���ư� �� ���� ���
	else if (node.isColumn < clearcolumn)
	{
		SetConsoleTextColor(8);
		printf("��");
		SetConsoleTextColor(15);
	}

	// ������ ���
	else
	{
		printf("��");
	}

}