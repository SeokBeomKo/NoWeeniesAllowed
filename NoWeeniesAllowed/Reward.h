#pragma once
#include "framework.h"

// ���� �� �Ǵ� ���� �� ���� ��

#define REWARDCOUNT 3

int isRewardSel;

static int code[REWARDCOUNT];
static int grade[REWARDCOUNT];
static int selectReward;
static int number;
static int diffiChance;

static ActiveSkill rewardSkill[REWARDCOUNT];

void EnterReward();
void Reward();
void RewardCreate();
void RewardDraw();
void DeleteSkill();
void RewardSelect();

void EnterReward()
{

}

void Reward()
{
	RewardCreate();

	RewardDraw();
	RewardSelect();
}

void RewardCreate()
{
	for (int i = 0; i < REWARDCOUNT; i++)
	{
		// �ڵ� 0 ~ 9
		code[i] = rand() % 3;
		// ��� 0 ~ 2 , 0 ~ 99
		grade[i] = rand() % 100;

		if (grade[i] < 80 - (difficulty * 20))			grade[i] = 0;
		else if (grade[i] < 90 - (difficulty * 10))		grade[i] = 1;
		else if (grade[i] < 100)						grade[i] = 2;
	}
	
}

void RewardDraw()
{
	printf("���� ��� \n\n");
	for (int i = 0; i < REWARDCOUNT; i++)
	{
		printf("%s\n", activeSkill[grade[i]][code[i]].name);
		rewardSkill[i] = activeSkill[grade[i]][code[i]];
	}
}

void RewardSelect()
{
	while (TRUE)
	{
		printf("���� ����");
		scanf_s("%d", &selectReward);

		if (selectReward < 0 || selectReward > REWARDCOUNT)	printf("�ٽ� ����");
		else break;
	}
	

	// ������ �ִٸ� �ֱ�
	for (int i = 0; i < ACTIVESKILL; i++)
	{
		if (player->askill[i].name == NULL)
		{
			player->askill[i] = rewardSkill[selectReward];
			isRewardSel = 1;
			break;
		}
	}

	if (isRewardSel == 0)
	{
		DeleteSkill();
		isRewardSel = 1;
	}

	printf("[%s] �������", rewardSkill[selectReward].name);
}

void DeleteSkill()
{
	int del = 0;

	printf("��� ��ų ����");
	scanf_s("%d", &del);

	player->askill[del] = rewardSkill[selectReward];
}

