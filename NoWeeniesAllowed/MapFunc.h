#pragma once
#include "framework.h"


// 변수

int scanMove;


// 함수

void ChangeScene(int scene);
void Move(int sel);
void MoveFunc(MapNode* node);

void SelectMove()
{
	GotoXY(44, 48);
	printf("1 : ↙\t2 : ↓\t3 : ↘\n");
	GotoXY(45, 51);
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
	ChangeScene(curMapNode->info.type);
}