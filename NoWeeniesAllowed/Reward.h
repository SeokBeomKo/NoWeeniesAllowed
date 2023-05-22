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
void HaveSkillDraw();

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

		if (grade[i] < 90 - (difficulty * 20))			grade[i] = 0;	// 90, 70, 50
		else if (grade[i] < 97 - (difficulty * 10))		grade[i] = 1;	// 7, 17, 27
		else if (grade[i] < 100)						grade[i] = 2;	// 3, 13, 23

		rewardSkill[i] = activeSkill[grade[i]][code[i]];
		rewardSkill[i] = activeSkill[grade[i]][code[i]];
		rewardSkill[i] = activeSkill[grade[i]][code[i]];
	}
	
}

void RewardDraw()
{
	GotoXY(45,5);
	printf("������������ ���� ��� ������������");
	
	GotoXY(26, 10);printf("���������������������������������������������������������������� ���������������������������������������������������������������� ����������������������������������������������������������������");
	GotoXY(26, 11);printf("��\t\t\t\t   �� ��\t\t\t\t    �� ��\t\t\t\t     ��");		//\t 5 �Ҹ� �ڽ�Ʈ
	GotoXY(26, 12);printf("��\t\t\t\t   �� ��\t\t\t\t    �� ��\t\t\t\t     ��");		// �̸�
	GotoXY(26, 13);printf("��\t\t\t\t   �� ��\t\t\t\t    �� ��\t\t\t\t     ��");		// ���� Ÿ��
	GotoXY(26, 14);printf("��\t\t\t\t   �� ��\t\t\t\t    �� ��\t\t\t\t     ��");		
	GotoXY(26, 15);printf("��\t\t\t\t   �� ��\t\t\t\t    �� ��\t\t\t\t     ��");		// ����
	GotoXY(26, 16);printf("��\t\t\t\t   �� ��\t\t\t\t    �� ��\t\t\t\t     ��");		
	GotoXY(26, 17);printf("��\t\t\t\t   �� ��\t\t\t\t    �� ��\t\t\t\t     ��");
	GotoXY(26, 18);printf("�������������������������������� ���������������������������� �������������������������������� ���������������������������� �������������������������� ����������������������������������");

	GotoXY(33, 10);
	printf(" %s ", rewardSkill[0].grade);
	GotoXY(49, 10);
	printf(" %s ", rewardSkill[1].grade);
	GotoXY(65, 10);
	printf(" %s ", rewardSkill[2].grade);

	GotoXY(28, 12);
	printf("%s\n", rewardSkill[0].name);

	GotoXY(45, 12);
	printf("%s\n", rewardSkill[1].name);

	GotoXY(61, 12);
	printf("%s\n", rewardSkill[2].name);

	HaveSkillDraw();
}

void HaveSkillDraw()
{
	GotoXY(44, 30);
	printf("������������ ���� ��ų ��� ������������");

	GotoXY(36, 33);
	for (int i = 0; i < ACTIVESKILL; i++)
	{
		if (player->askill[i].name == NULL)	printf("�� ����\t\t");
		else printf("%s\t\t", player->askill[i].name);
	}
}

void RewardSelect()
{
	GotoXY(48, 20);
	while (TRUE)
	{
		printf("���� ����\n");
		GotoXY(50, 22);
		scanf_s("%d", &selectReward);

		if (selectReward <= 0 || selectReward > REWARDCOUNT)	printf("�ٽ� ����");
		else break;
	}
	
	selectReward++;

	// ������ �ִٸ� �ֱ�
	for (int i = 0; i < ACTIVESKILL; i++)
	{
		if (player->askill[i].name == NULL)
		{
			player->askill[i] = rewardSkill[selectReward - 2];
			isRewardSel = 1;
			break;
		}
	}

	if (isRewardSel == 0)
	{
		DeleteSkill();
		isRewardSel = 1;
	}

	system("cls");

	GotoXY(48, 25);
	printf("[%s]", rewardSkill[selectReward - 2].name);
	GotoXY(48, 26);
	printf("�������");
	_getch();
}

void DeleteSkill()
{
	int del = 0;

	GotoXY(46, 25);
	while (TRUE)
	{
		printf("������ ��ų ����");
		GotoXY(50, 26);
		scanf_s("%d", &del);
		if (del > 0 || del <= ACTIVESKILL) break;
	}

	player->askill[del - 1] = rewardSkill[selectReward - 2];
}

