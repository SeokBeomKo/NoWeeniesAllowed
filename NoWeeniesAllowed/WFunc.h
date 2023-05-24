#pragma once
#include "framework.h"

void SetConsoleTextColor(int color_number);
void SetConsoleView();
void GotoXY(int x, int y);
void PrintXY(string print, int x, int y);
void FilePrint(char* input_str, int x, int y);
void FilePrintUni(wchar_t* input_str, int x, int y);

// 콘솔창 출력색상을 나타내는 함수
void SetConsoleTextColor(int color_number) 
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color_number);
}

// 콘솔 창의 크기와 제목을 지정하는 함수
void SetConsoleView()
{
    system("mode con:cols=100 lines=25");
    system("NoWeeniesAllowed");
}

// 커서의 위치를 x, y로 이동하는 함수
void GotoXY(int x, int y)
{
    COORD Pos;
    Pos.X = 2 * x;
    Pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

// x, y 위치에서 출력
void PrintXY(string print,int x, int y)
{
    GotoXY(x, y);
    printf("%s", print);
}

// 텍스트 파일 출력
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
// 텍스트 파일 출력 (유니코드)
void FilePrintUni(wchar_t* input_str, int x, int y)
{
    _setmode(_fileno(stdout), _O_U16TEXT);

    wchar_t str[100];
    FILE* fp = NULL;
    _wfopen_s(&fp, input_str, L"rt+,ccs=UTF-8");
    if (fp == NULL) return;
    int i = 0;
    while (1)
    {
        wchar_t* pstr = fgetws(str, 100, fp);
        if (pstr == NULL) break;
        GotoXY(x, y + i);
        wprintf(L"%s", str);
        i++;
    }
    fclose(fp);

    _setmode(_fileno(stdout), _O_TEXT);
}