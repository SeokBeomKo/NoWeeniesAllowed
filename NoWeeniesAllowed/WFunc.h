#pragma once
#include "framework.h"


void SetConsoleTextColor(int color_number) //�ܼ�â ��»����� ��Ÿ���� �Լ�
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}