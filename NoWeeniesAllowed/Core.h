#pragma once
#include "framework.h"


void Core_Init()
{
	SceneManagerInit();
	MapManagerInit();
}

void Core_Update()
{
	while (TRUE)
	{
		SceneManagerUpdate();
		MapManagerUpdate();
	}
}