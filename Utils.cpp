#include "Utils.h"


CUtils::CUtils(LPDIRECT3DDEVICE9 d3ddv)
{
	m_D3DDevice = d3ddv;
}


CUtils::~CUtils()
{
}

IDirect3DSurface9* CUtils::GetSurfaceFromBitmap(std::string filename)
{
	HRESULT hResult;
	IDirect3DSurface9* surface = NULL;
	D3DXIMAGE_INFO imageInfo;

	// Get the width and height info from this bitmap
	hResult = D3DXGetImageInfoFromFile((LPCWSTR)filename.c_str(), &imageInfo);
	if FAILED(hResult)
		return NULL;

	hResult = m_D3DDevice->CreateOffscreenPlainSurface(imageInfo.Width, imageInfo.Height, D3DFMT_A8R8G8B8, D3DPOOL_DEFAULT, &surface, NULL);
	if (FAILED(hResult))
		return NULL;

	hResult = D3DXLoadSurfaceFromFile(surface, NULL, NULL, (LPCWSTR)filename.c_str(), NULL, D3DX_DEFAULT, 0, NULL);
	if (FAILED(hResult))
		return NULL;

	return surface;
}

IDirect3DSurface9* CUtils::GetBackBuffer(void)
{
	IDirect3DSurface9* backbuffer = NULL;

	if (!m_D3DDevice)
		return NULL;

	HRESULT hResult = m_D3DDevice->GetBackBuffer(0, 0, D3DBACKBUFFER_TYPE_MONO, &backbuffer);
	if (FAILED(hResult))
		return NULL;
	else
		return backbuffer;
}

void CUtils::BlitToSurface(IDirect3DSurface9* srcSurface, const RECT *srcRect, const RECT *destRect)
{
	m_D3DDevice->StretchRect(srcSurface, srcRect, GetBackBuffer(), destRect, D3DTEXF_NONE);
}
