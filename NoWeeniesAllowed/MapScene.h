#pragma once
#include "framework.h"
#include "MapGenerator.h"
#include "MapFunc.h"


void MapSceneUpdate()
{
	EnterRender();
	StageRender();
	ExitRender();

	SelectMove();
}