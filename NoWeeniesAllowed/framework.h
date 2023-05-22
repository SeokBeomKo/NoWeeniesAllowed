// header.h: 표준 시스템 포함 파일
// 또는 프로젝트 특정 포함 파일이 들어 있는 포함 파일입니다.

#pragma once

//========================================
//## 게임 그룹							##
//========================================

typedef struct player Player;

typedef enum move_type MOVE_TYPE;
typedef enum scene_type SCENE_TYPE;

// 열거형
enum move_type
{
	LEFT = 1,
	STRAIGHT,
	RIGHT
};

enum scene_type
{
	MAIN,
	MAP,
	BATTLE,
	REWARD,
	TRAP,
	BOSS,
	
	OPTION
};


// Windows 헤더 파일
#include <windows.h>

// C 런타임 헤더 파일
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Util
#include "struct.h"
#include "WFunc.h"

// Core & Manager
#include "GameManager.h"
#include "MapManager.h"
#include "SceneManager.h"
#include "UIManager.h"







//========================================
//## 함수 정의							##
//========================================

//void ChangeScene(int scene);
//void SetConsoleTextColor(int color_number);