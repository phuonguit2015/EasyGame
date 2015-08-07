#pragma once
#include <d3d9.h>
#include <d3dx9.h>

class CGraphics
{
public:
	CGraphics();
	~CGraphics();

	bool InitWithWindowHandle(HWND hwnd);
	bool RenderSence();
	void BeginRender();
	void EndRender();

private:
	LPDIRECT3D9 m_D3DObject;							// Direct3D Object. Biến này cần thiết cho việc khởi tạo Device để thao tác vẽ trong Game.
	LPDIRECT3DDEVICE9 m_D3DDevice;					// Biến lưu thông tin của Device sử dụng thao tác vẽ trong chương trình.
	int m_Width;										// Kích thước bộ đệm
	int m_Height;

	bool InitDirect3DObject();
	bool HashHRResult(HRESULT hResult);
};

