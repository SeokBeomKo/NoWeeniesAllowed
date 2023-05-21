// header.h: ǥ�� �ý��� ���� ����
// �Ǵ� ������Ʈ Ư�� ���� ������ ��� �ִ� ���� �����Դϴ�.

#pragma once

//========================================
//## ���� �׷�							##
//========================================

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
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

// Core & Manager
#include "MapManager.h"
#include "SceneManager.h"

// Util
#include "struct.h"
#include "WFunc.h"





//========================================
//## �Լ� ����							##
//========================================

//void ChangeScene(int scene);
//void SetConsoleTextColor(int color_number);