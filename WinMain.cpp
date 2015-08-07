#include<d3d9.h>
#include "Game.h"
#include "Application.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstace,	LPSTR lpStrCmdLine,	int nShowCmd)
{	
	CApplication a;
	if (a.Initialize(hInstance, GAME_SCREEN_RESOLUTION_800_600_24, false))
	{
		if (a.LoadWindow(L"Easy Game", 100, 150))
		{
			a.Run();
		}
	}
	return 0;
}