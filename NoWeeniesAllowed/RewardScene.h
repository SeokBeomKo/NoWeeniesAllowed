#pragma once
#include "framework.h"
#include "Reward.h"

void RewardSceneUpdate()
{

	while (isRewardSel != 1)
	{
		Reward();
	}
	

	ChangeScene(MAP);
}