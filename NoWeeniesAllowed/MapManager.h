#pragma once
#include "framework.h"
#include "MapGenerator.h"

void MapManagerInit()
{
	MapIndexCreate();

	for (column = 0; column < COLUMN; column++)
	{
		for (row = 0; row < ROW; row++)
		{
			if (mapIndex[column][row] == 1)
			{
				mapList[column][row].isFull = 1;
				mapList[column][row].info.enemyCount = rand() % 3 + 1;
				// �ʿ� ������ �� ��ü ��
				// printf("mapList[%d][%d] : %d\n", column, row, mapList[column][row].info.enemyCount);
				MapNodeAdd(column, row);
			}
		}
	}
}

void MapManagerRender()
{
	EnterRender();
	StageRender();
	ExitRender();
}