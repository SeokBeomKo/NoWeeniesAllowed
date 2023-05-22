#pragma once
#include "framework.h"

//콘솔창 출력색상을 나타내는 함수
void SetConsoleTextColor(int color_number) 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

//콘솔 창의 크기와 제목을 지정하는 함수
void SetConsoleView()
{
    system("mode con:cols=100 lines=25");
    system("NoWeeniesAllowed");
}

//커서의 위치를 x, y로 이동하는 함수
void GotoXY(int x, int y)
{
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void PrintXY(string print,int x, int y)
{
    GotoXY(x, y);
    printf("%s", print);
}

void FilePrint(char * input_str, int x, int y)
{
    char str[100];
    FILE* fp = NULL;
        fopen_s(&fp, input_str, "rt");
    if (fp == NULL) return;
    int i = 0;
    while (1)
    {
        char* pstr = fgets(str, 100, fp);
        if (pstr == NULL) break;
        GotoXY(x, y + i);
        printf("%s",str);
        i++;
    }
    fclose(fp);
}