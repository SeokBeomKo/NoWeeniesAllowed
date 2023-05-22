// header.h: ǥ�� �ý��� ���� ����
// �Ǵ� ������Ʈ Ư�� ���� ������ ��� �ִ� ���� �����Դϴ�.

#pragma once

//========================================
//## ���� �׷�							##
//========================================

typedef struct player Player;

typedef enum move_type MOVE_TYPE;

// ������
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