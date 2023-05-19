#pragma once
#include "framework.h"

int stop;

void Core_Init()
{
	MapManagerInit();
}

void Core_Update()
{
	while (1)
	{
		MapManagerRender();
		SelectMove();
	}
}