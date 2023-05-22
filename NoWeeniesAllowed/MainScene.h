#pragma once
#include "framework.h"


void SetConsoleTextColor(int color_number);
void MainLogoRender();

void MainSceneUpdate()
{
	MainLogoRender();

	SetConsoleTextColor(1);
	GotoXY(45, 45); printf("Press Any Button");
	SetConsoleTextColor(15);
	_getch();
	ChangeScene(MAP);
}

void MainLogoRender()
{
	// TODO : 堅纂晦

	GotoXY(25, 5); printf("忙式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式忖\n");
	GotoXY(25, 6); printf("弛.__   __.   ______                                                                            弛\n");
	GotoXY(25, 7); printf("弛|  1 |  |  /  __  1                                                                           弛\n");
	GotoXY(25, 8); printf("弛|   1|  | |  |  |  |  																		弛\n");
	GotoXY(25, 9); printf("弛|  . `  | |  |  |  |                                                                          弛\n");
	GotoXY(25, 10); printf("弛|  |1   | |  `--'  |                                                                          弛\n");
	GotoXY(25, 11); printf("弛|__| 1__|  1______/                                                                           弛\n");
	GotoXY(25, 12); printf("弛																								弛\n");
	GotoXY(25, 13); printf("弛____    __    ____  _______  _______ .__   __.  __   _______      _______.					弛\n");
	GotoXY(25, 14); printf("弛1   1  /  1  /   / |   ____||   ____||  1 |  | |  | |   ____|    /       |                    弛\n");
	GotoXY(25, 15); printf("弛 1   1/    1/   /  |  |__   |  |__   |   1|  | |  | |  |__      |   (----`                    弛\n");
	GotoXY(25, 16); printf("弛  1            /   |   __|  |   __|  |  . `  | |  | |   __|      1   1                        弛\n");
	GotoXY(25, 17); printf("弛   1    /1    /    |  |____ |  |____ |  |1   | |  | |  |____ .----)   |                       弛\n");
	GotoXY(25, 18); printf("弛    1__/  1__/     |_______||_______||__| 1__| |__| |_______||_______/						弛\n");
	GotoXY(25, 19); printf("弛													弛\n");
	GotoXY(25, 20); printf("弛        ___       __       __        ______   ____    __    ____  _______  _______            弛\n");
	GotoXY(25, 21); printf("弛       /   1     |  |     |  |      /  __  1  1   1  /  1  /   / |   ____||       1 			   弛\n");
	GotoXY(25, 22); printf("弛      /  ^  1    |  |     |  |     |  |  |  |  1   1/    1/   /  |  |__   |  .--.  |          弛\n");
	GotoXY(25, 23); printf("弛     /  /_1  1   |  |     |  |     |  |  |  |   1            /   |   __|  |  |  |  |          弛\n");
	GotoXY(25, 24); printf("弛    /  _____  1  |  `----.|  `----.|  `--'  |    1    /1    /    |  |____ |  '--'  |			弛\n");
	GotoXY(25, 25); printf("弛   /__/     1__1 |_______||_______| 1______/      1__/  1__/     |_______||_______/           弛\n");
	GotoXY(25, 26); printf("戌式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式式戎\n");
	printf("\n");
}
