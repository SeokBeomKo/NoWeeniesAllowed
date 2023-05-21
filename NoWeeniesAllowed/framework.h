// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.

#pragma once

//========================================
//## 게임 그룹							##
//========================================

typedef enum move_type MOVE_TYPE;

// 열거형
enum move_type
{
	LEFT = 1,
	STRAIGHT,
	RIGHT
};

enum SCENE_TYPE
{
	MAIN,
	MAP,
	BATTLE,
	REWARD,
	TRAP,
	BOSS
};


// Windows 헤더 파일
#include <windows.h>

// C 런타임 헤더 파일
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Util
#include "struct.h"
#include "WFunc.h"

// Core & Manager
#include "MapManager.h"
#include "SceneManager.h"







//========================================
//## 함수 정의							##
//========================================

//void ChangeScene(int scene);
//void SetConsoleTextColor(int color_number);