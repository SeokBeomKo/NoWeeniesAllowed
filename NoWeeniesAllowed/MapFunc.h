#pragma once
#include "framework.h"

typedef enum move_type MOVE_TYPE;

// 열거형
enum move_type
{
	LEFT = 1,
	STRAIGHT,
	RIGHT
};


// 변수

int scanMove;


// 함수

void Move(int sel);
void MoveFunc(MapNode* node);

void SelectMove()
{
	printf("\n");
	printf("1 번 : 왼쪽\t2 번 : 중앙\t3 번 : 오른쪽\n");
	printf(" 이동할 장소 입력 : ");
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
		printf("!!!! 이동할 수 없습니다 !!!\n\n");
		return;
	}
	curMapNode->isStay = 0;
	curMapNode = node;
	curMapNode->isStay = 1;
}