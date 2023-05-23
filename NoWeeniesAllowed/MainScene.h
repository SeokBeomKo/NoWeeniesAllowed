#pragma once
#include "framework.h"


void SetConsoleTextColor(int color_number);
void MainLogoRender();

void MainSceneUpdate()
{
	MainLogoRender();

	GotoXY(45, 45); printf("Press Any Button");
	SetConsoleTextColor(15);

	_getch();
	ChangeScene(OPTION);
}

void MainLogoRender()
{
	FilePrintUni(L"Logo.txt", 25, 10);
	
	printf("\n");
}
