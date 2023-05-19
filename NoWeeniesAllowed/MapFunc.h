#pragma once
#include "framework.h"

typedef enum move_type MOVE_TYPE;

// ������
enum move_type
{
	LEFT = 1,
	STRAIGHT,
	RIGHT
};


// ����

int scanMove;


// �Լ�

void Move(int sel);
void MoveFunc(MapNode* node);

void SelectMove()
{
	printf("\n");
	printf("1 �� : ����\t2 �� : �߾�\t3 �� : ������\n");
	printf(" �̵��� ��� �Է� : ");
	scanf_s("%d", &scanMove);
	system("cls");
	Move(scanMove);
}

void Move(int sel)
{
	switch (sel)
	{
	case LEFT:
		MoveFunc(curMapNode->leftNode);
		break;
	case STRAIGHT:
		MoveFunc(curMapNode->straightNode);
		break;
	case RIGHT:
		MoveFunc(curMapNode->rightNode);
		break;
	default:
		break;
	}
}

void MoveFunc(MapNode* node)
{
	if (node == NULL)
	{
		printf("!!!! �̵��� �� �����ϴ� !!!\n\n");
		return;
	}
	curMapNode->isStay = 0;
	curMapNode = node;
	curMapNode->isStay = 1;
}