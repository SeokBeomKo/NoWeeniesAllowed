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
	// TODO : °íÄ¡±â

	
	GotoXY(31, 6);  printf(".__   __.   ______                                                                          ");
	GotoXY(31, 7);  printf("|  1 |  |  /  __  1                                                                         ");
	GotoXY(31, 8);  printf("|   1|  | |  |  |  |  																		 ");
	GotoXY(31, 9);  printf("|  . `  | |  |  |  |                                                                        ");
	GotoXY(31, 10); printf("|  |1   | |  `--'  |                                                                       ");
	GotoXY(31, 11); printf("|__| 1__|  1______/                                                                        ");
	GotoXY(31, 12); printf("																							 ");
	GotoXY(31, 13); printf("____    __    ____  _______  _______ .__   __.  __   _______      _______.				 ");
	GotoXY(31, 14); printf("1   1  /  1  /   / |   ____||   ____||  1 |  | |  | |   ____|    /       |                 ");
	GotoXY(31, 15); printf(" 1   1/    1/   /  |  |__   |  |__   |   1|  | |  | |  |__      |   (----`                 ");
	GotoXY(31, 16); printf("  1            /   |   __|  |   __|  |  . `  | |  | |   __|      1   1                     ");
	GotoXY(31, 17); printf("   1    /1    /    |  |____ |  |____ |  |1   | |  | |  |____ .----)   |                    ");
	GotoXY(31, 18); printf("    1__/  1__/     |_______||_______||__| 1__| |__| |_______||_______/					 ");
	GotoXY(30, 20); printf("        ___       __       __        ______   ____    __    ____  _______  _______         ");
	GotoXY(30, 21); printf("       /   1     |  |     |  |      /  __  1  1   1  /  1  /   / |   ____||       1 		 ");
	GotoXY(30, 22); printf("      /  ^  1    |  |     |  |     |  |  |  |  1   1/    1/   /  |  |__   |  .--.  |       ");
	GotoXY(30, 23); printf("     /  /_1  1   |  |     |  |     |  |  |  |   1            /   |   __|  |  |  |  |       ");
	GotoXY(30, 24); printf("    /  _____  1  |  `----.|  `----.|  `--'  |    1    /1    /    |  |____ |  '--'  |		 ");
	GotoXY(30, 25); printf("   /__/     1__1 |_______||_______| 1______/      1__/  1__/     |_______||_______/        ");
	
	printf("\n");
}
