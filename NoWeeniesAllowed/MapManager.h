#pragma once
#include "framework.h"
#include "MapGenerator.h"
#include "MapFunc.h"

void MapManagerInit()
{
	MapIndexCreate();
	MapListCreate();
}

void MapManagerUpdate()
{
	EnterRender();
	StageRender();
	ExitRender();

	SelectMove();
}