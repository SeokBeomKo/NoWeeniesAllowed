// header.h: ǥ�� �ý��� ���� ����
// �Ǵ� ������Ʈ Ư�� ���� ������ ��� �ִ� ���� �����Դϴ�.

#pragma once

//========================================
//## ���� �׷�							##
//========================================

typedef struct player Player;

typedef enum move_type MOVE_TYPE;
typedef enum scene_type SCENE_TYPE;

// ������
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


// Windows ��� ����
#include <windows.h>

// C ��Ÿ�� ��� ����
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
//## �Լ� ����							##
//========================================

//void ChangeScene(int scene);
//void SetConsoleTextColor(int color_number);