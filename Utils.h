#pragma once
#include <d3d9.h>
#include <d3dx9tex.h>
#include <string>

class CUtils
{
public:
	CUtils(LPDIRECT3DDEVICE9 d3ddv);
	~CUtils();

	IDirect3DSurface9* GetSurfaceFromBitmap(std::string filename);

	IDirect3DSurface9* GetBackBuffer(void);
	void BlitToSurface(IDirect3DSurface9* srcSurface, const RECT *srcRect, const RECT *destRect);

private:
	LPDIRECT3DDEVICE9 m_D3DDevice;
};

