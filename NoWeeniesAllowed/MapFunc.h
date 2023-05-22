#pragma once
#include "framework.h"


// ����

int scanMove;


// �Լ�

void ChangeScene(int scene);
void Move(int sel);
void MoveFunc(MapNode* node);

void SelectMove()
{
	GotoXY(44, 48);
	printf("1 : ��\t2 : ��\t3 : ��\n");
	GotoXY(45, 51);
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
	ChangeScene(curMapNode->info.type);
}