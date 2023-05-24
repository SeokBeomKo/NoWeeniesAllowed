#pragma once
#include "framework.h"
#include <time.h>			// ����
#include "Enemy.h"


// TODO : �� ���氪�� �°� �ڵ� ����
#define COLUMN		10
#define ROW			3

typedef struct mapInfo MapInfo;
typedef struct mapNode MapNode;

// ����ü

struct mapInfo
{
	/*
	Ÿ�� : (�Ϲ� ������ : 2, ����� : 3, ������ : 4, ������ : 5)
	��ȯ�� �� ���� (0 ~ 3)
	��ȯ�� �� ��ü��
	���� (���)
	*/
	int type;
	Enemy enemy[3];
	int enemyCount;
	int rewards;
};
struct mapNode
{
	int isFull;			// ���� ����ִ��� Ȯ��
	int isStay;			// �÷��̾ ��ġ�ߴ��� Ȯ��
	int isClear;		// Ŭ������ �������
	int isColumn;		// ���° ������

	int step;			// ���� ���� �ܰ� (�ܰ�� ���̵��� ���� ��ȯ�Ǵ� ���� ������ �ٸ�)
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

void MapIndexCreate();
void MapDoubleCheck();

void MapListCreate();
void MapNodeAdd(int column, int row);
void BossNodeAdd(int row);

void StageRender();
void CurRender(MapNode node, int column);
void CurDirRender(int dir, int column);

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
		// ���� ��尡 ���� ��� ���ֱ�
		if (mapIndex[column][0] == 1 && mapIndex[column + 1][0] == 0 && mapIndex[column + 1][1] == 0)
		{
			mapIndex[column + 1][rand() % 2] = 1;
		}
		if (mapIndex[column][2] == 1 && mapIndex[column + 1][1] == 0 && mapIndex[column + 1][2] == 0)
		{
			mapIndex[column + 1][rand() % 2 + 1] = 1;
		}

		// ���� ��尡 ���� ��� ���ֱ�
		if (mapIndex[column + 1][0] == 1 && mapIndex[column][0] == 0 && mapIndex[column][1] == 0)
		{
			mapIndex[column][1] = 1;
		}
		if (mapIndex[column + 1][2] == 1 && mapIndex[column][1] == 0 && mapIndex[column][2] == 0)
		{
			mapIndex[column][1] = 1;
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

	exitMapNode.info.type = (int)BOSS;

	for (column = 0; column < COLUMN; column++)
	{
		for (row = 0; row < ROW; row++)
		{
			if (mapIndex[column][row])
			{
				mapList[column][row].isFull = 1;
				mapList[column][row].isClear = 0;
				mapList[column][row].isColumn = column;
				// �ʳ�� �ܰ� ����		0 0 0 1 1 1 2 2 2 3
				mapList[column][row].step = column / 3;

				// �� Ÿ�� ���� 0 : ����, 1 : ����, 2 : ����
				// ���� 80 ���� 10 ���� 10
				type = rand() % 10;

				// ���� ��
				if (type < 0)		
				{
					mapList[column][row].info.type = (int)BATTLE;
					// �ʿ� ������ �� ��ü ��
					mapList[column][row].info.enemyCount = rand() % 3 + 1;
					for (int i = 0; i < mapList[column][row].info.enemyCount; i++)
					{
						AddEnemy(&mapList[column][row].info.enemy[i], difficulty, rand() % 3 + mapList[column][row].step);
					}
				}
				// ���� ��
				else if (type < 10)
				{
					mapList[column][row].info.type = (int)REWARD;
				}
				// ���� ��
				else if (type < 10)
				{
					mapList[column][row].info.type = (int)TRAP;
				}
				MapNodeAdd(column, row);
				if (column == COLUMN - 1) BossNodeAdd(row);
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

void BossNodeAdd(int row)
{
	switch (row)
	{
	case 0:
		mapList[COLUMN - 1][row].rightNode = &exitMapNode;
		break;
	case 1:
		mapList[COLUMN - 1][row].straightNode = &exitMapNode;
		break;
	case 2:
		mapList[COLUMN - 1][row].leftNode = &exitMapNode;
		break;
	default:
		break;
	}
}

// �� �׸��� ���
void EnterRender()
{
	GotoXY(45,1);
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
	GotoXY(45, 3);
	printf("\t");
	for (row = 0; row < ROW; row++)
	{
		switch (row)
		{
		case 0:
			if (mapList[0][row].isFull)	CurDirRender(LEFT,-1);
			else printf("  ");
			break;
		case 1:
			if (mapList[0][row].isFull)	CurDirRender(STRAIGHT, -1);
			else printf("  ");
			break;
		case 2:
			if (mapList[0][row].isFull)	CurDirRender(RIGHT, -1);
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
	int i = 5;
	// �� �ε��� ���� Ȯ��
	for (column = 0; column < COLUMN; column++)
	{
		// �� ���� ��Ÿ�� ��
		GotoXY(45, i + (column * 4));
		for (row = 0; row < ROW; row++)
		{
			if (mapList[column][row].isFull)
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
		// ���� ���� ������ ��Ÿ�� ��
		// TODO : ù ���۰� ������ ����ó��
		GotoXY(45, i + (column * 4) + 2);
		for (row = 0; row < ROW; row++)
		{
			if (column == COLUMN - 1)
				break;
			if (mapList[column][row].isFull)		// ��尡 �ִٸ�
			{
				if (mapList[column][row].leftNode != NULL)	CurDirRender(LEFT, column);
				else printf(" ");
				if (mapList[column][row].straightNode != NULL)	CurDirRender(STRAIGHT, column);
				else printf("  ");
				if (mapList[column][row].rightNode != NULL)	CurDirRender(RIGHT, column);
				else printf(" ");
			}
			printf("\t");
		}
		printf("\n");
		if (column != COLUMN - 1) printf("\n");
	}
}
void ExitRender()
{
	GotoXY(45, 43);
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
	GotoXY(45, 45);
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
	int clearcolumn = curMapNode->isColumn;

	// ���� �ִ� ���
	if (node.isStay)
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
	else if (node.isColumn <= clearcolumn)
	{
		SetConsoleTextColor(8);
		switch (node.info.type)
		{
		case 3:
			printf("��");
			break;
		case 4:
			printf("��");
			break;
		default:
			printf("��");
			break;
		}
		SetConsoleTextColor(15);
	}

	// ������ ���
	else
	{
		// Ÿ�Կ� ���� �ٸ���
		switch (node.info.type)
		{
		case 2:	// ������
			printf("��");
			break;
		case 3:	// �����
			printf("��");
			break;
		case 4:	// ������ (����� ����)
			printf("��");
			break;
		default:
			break;
		}
	}

}
void CurDirRender(int dir, int column)
{
	int clearcolumn = curMapNode->isColumn;

	if (column < clearcolumn)
	{
		SetConsoleTextColor(8);
	}

	switch (dir)
	{
	case 1:
		printf("��");
		break;
	case 2:
		printf("��");
		break;
	case 3:
		printf("��");
		break;
	default:
		break;
	}
	SetConsoleTextColor(15);
}