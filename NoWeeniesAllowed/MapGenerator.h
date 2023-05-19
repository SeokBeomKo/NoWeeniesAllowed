#pragma once
#include "framework.h"
#include <time.h>			// ����


#define COLUMN		10
#define ROW			3

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

// �Լ�

void MapIndexCreate()
{
	// TODO : ���� ��� �Ǵ� ���� ���� 2 ĭ ������ �ִ� ���
	srand(time(NULL));

	column = 0, row = 0, isFull = 0;

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
}


// �ӽ� �׽�Ʈ

void Temp()
{
	column = 0, row = 0;
	// �� �ε��� ���� Ȯ��
	for (column = 0; column < COLUMN; column++)
	{
		for (row = 0; row < ROW; row++)
		{
			if (mapIndex[column][row] == 0)
			{
				printf(" \t");
			}
			else
			{
				printf("O\t");
			}
		}
		printf("\n\n");
	}
}