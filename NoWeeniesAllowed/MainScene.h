#pragma once
#include "framework.h"


void SetConsoleTextColor(int color_number);
void MainLogoRender();

void MainSceneUpdate()
{
	MainLogoRender();

	GotoXY(45, 45); printf("Press Any Button");
	SetConsoleTextColor(15);

	FilePrintUni(L"Enemy\\01.Easy\\Harv.txt", 0, 0);

	_getch();
	ChangeScene(OPTION);
}

void MainLogoRender()
{
	// TODO : °íÄ¡±â

	
	FilePrintUni(L"Logo.txt", 25, 10);
	
	printf("\n");
}
