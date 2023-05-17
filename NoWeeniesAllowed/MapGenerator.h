#pragma once
#include "framework.h"
#include <time.h>			// 랜덤


#define COLUMN		10
#define ROW			3

/*
	맵 생성 예시

		  ㅁ				ㅁ → ㅁ
	   ↗    ↘          ↗
	ㅁ → ㅁ → ㅁ → ㅁ	      ㅁ
	   ↘    ↗	   ↗	 ↘    ↗
		  ㅁ → ㅁ		    ㅁ → ㅁ
*/

// 변수

int				mapIndex[COLUMN][ROW];
static int		column = 0, row = 0, isFull = 0;

// 함수

void MapIndexCreate(int index[][ROW])
{
	// TODO : 이전 노드 또는 다음 노드와 2 칸 떨어져 있는 경우
	srand(time(NULL));

	column = 0, row = 0, isFull = 0;

	// 맵 인덱스 생성 (방이 있는지 비었는지)
	for (column = 0; column < 10; column++)
	{
		// 방이 비어있는지 확인 값 초기화
		isFull = 0;
		for (row = 0; row < 3; row++)
		{
			mapIndex[column][row] = rand() % 2;

			// 예외 : 모든 방이 비어있다면 최소 한개의 방을 가운데 생성
			isFull += mapIndex[column][row];
			if (isFull == 0)
			{
				mapIndex[column][(ROW / 2) + 1] = 1;
			}
		}
	}
}


// 임시 테스트

void Temp()
{
	column = 0, row = 0;
	// 맵 인덱스 생성 확인
	for (column = 0; column < 10; column++)
	{
		for (row = 0; row < 3; row++)
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