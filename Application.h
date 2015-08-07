#pragma once
#include <Windows.h>
#include <d3d9.h>
#include "Graphics.h"
#include "Game.h"
//
// Screen resolution
//
#define GAME_SCREEN_RESOLUTION_640_480_24   0
#define GAME_SCREEN_RESOLUTION_800_600_24   1
#define GAME_SCREEN_RESOLUTION_1024_768_24  2

#define GAME_SCREEN_RESOLUTION_640_480_32   10
#define GAME_SCREEN_RESOLUTION_800_600_32   11
#define GAME_SCREEN_RESOLUTION_1024_768_32  12



class CApplication
{
public:
	CApplication();
	~CApplication();

	bool Initialize(HINSTANCE hInstance, int mode, bool isFullScreen);
	bool LoadWindow(LPWSTR windowTitle, int posX, int posY);
	int Run();
	bool Close();
private:
	CGraphics* m_Graphics;
	CGame* m_Game;

	HWND m_windowHandle;
	HINSTANCE m_hInstance;
	LPWSTR m_windowTitle;
	bool m_isFullScreen;
	int m_screenWidth;
	int m_screenHeight;

	

private:
	void SetScreenDimension(int Mode);
	static LRESULT CALLBACK WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	void RenderSence();
};

