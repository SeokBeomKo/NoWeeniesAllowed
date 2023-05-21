#pragma once
#include "framework.h"


void Core_Init()
{
	GameManagerInit();
	SceneManagerInit();
	MapManagerInit();
}

void Core_Update()
{
	while (TRUE)
	{
		GameManagerUpdate();
		SceneManagerUpdate();
		MapManagerUpdate();
	}
}