#include "framework.h"


int main()
{
	system("mode con:lines=150 cols=50");		// 콘솔창 크기

	MapManagerInit();
	MapManagerRender();
	

	return 0;
}

