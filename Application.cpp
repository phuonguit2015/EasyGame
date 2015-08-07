#include "Application.h"
#include "Trace.h"

CApplication::CApplication()
{
	m_Graphics = NULL;
	m_Game = NULL;
}


CApplication::~CApplication()
{
	if (m_Graphics != NULL){
		delete m_Graphics;
	}
	if (m_Game != NULL){
		delete m_Game;
	}
}

void CApplication::SetScreenDimension(int Mode)
{
	switch (Mode)
	{
	case GAME_SCREEN_RESOLUTION_640_480_24:
		m_screenWidth = 640;
		m_screenHeight = 480;	
		break;

	case GAME_SCREEN_RESOLUTION_800_600_24:
		m_screenWidth = 800;
		m_screenHeight = 600;
		break;

	case GAME_SCREEN_RESOLUTION_1024_768_24:
		m_screenWidth = 1024;
		m_screenHeight = 768;
		break;

	default:
		break;
	}
}


bool CApplication::Initialize(HINSTANCE hInstance, int Mode, bool isFullScreen)
{
	m_hInstance = hInstance;
	m_isFullScreen = isFullScreen;
	SetScreenDimension(Mode);
	return true;
}

bool CApplication::LoadWindow(LPWSTR windowTitle, int posX, int posY)
{
	WNDCLASSEX wc;
	wc.cbSize = sizeof(WNDCLASSEX);

	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.hInstance = m_hInstance;

	wc.lpfnWndProc = (WNDPROC)CApplication::WinProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hIcon = NULL;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = windowTitle;
	wc.hIconSm = NULL;

	RegisterClassEx(&wc);

	DWORD style;
	if (m_isFullScreen)
		style = WS_EX_TOPMOST | WS_VISIBLE | WS_POPUP;
	else
		style = WS_OVERLAPPEDWINDOW;

	m_windowHandle =
		CreateWindow(windowTitle, windowTitle, style, CW_USEDEFAULT, CW_USEDEFAULT,
		m_screenWidth, m_screenHeight, NULL, NULL, m_hInstance, NULL);

	if (!m_windowHandle)
	{
		trace(L"[ERROR] Failed to created window!");
		DWORD ErrCode = GetLastError();
		return false;
	}

	ShowWindow(m_windowHandle, SW_SHOWNORMAL);
	UpdateWindow(m_windowHandle);

	m_Graphics = new CGraphics();
	if (!m_Graphics->InitWithWindowHandle(m_windowHandle)){
		delete m_Graphics;
		return false;
	}

	return true;
}

int CApplication::Run()
{	
	MSG msg;
	ZeroMemory(&msg, sizeof(MSG));

	m_Game->InitGame();

	trace(L">>> Main game loop has been started");
	while (msg.message != WM_QUIT)
	{
		while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}	
		m_Game->UpdateGame(0);
		RenderSence();
		Sleep(0);
	}
	trace(L"Main game loop has ended");
	return 0;
}

bool CApplication::Close()
{
	return true;
}


LRESULT CALLBACK CApplication::WinProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
		//TO DO
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}


void CApplication::RenderSence(){
	m_Graphics->BeginRender();
	m_Game->Render();
	m_Graphics->EndRender();
}