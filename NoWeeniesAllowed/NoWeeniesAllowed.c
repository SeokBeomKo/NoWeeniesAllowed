#include "framework.h"
#include "Core.h"


int main()
{
	system("mode con:lines=50 cols=200");		// 콘솔창 크기

	Core_Init();
	Core_Update();
	

	return 0;
}

