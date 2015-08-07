#include "Sprite.h"
#include "Trace.h"

CSprite::CSprite(LPD3DXSPRITE SpriteHandler, LPWSTR FilePath, int Width, int Height, int Count, int SpritePerRow)
{
	D3DXIMAGE_INFO info;
	HRESULT result;

	m_Image = NULL;
	m_SpriteHandler = SpriteHandler;

	m_Width = Width;
	m_Height = Height;
	m_Count = Count;
	m_SpritePerRow = SpritePerRow;
	m_Index = 0;

	result = D3DXGetImageInfoFromFile(FilePath, &info);
	if (result != D3D_OK)
	{
		trace(L"[ERROR] Failed to get information from image file '%s'", FilePath);
		return;
	}

	LPDIRECT3DDEVICE9 d3ddv;
	SpriteHandler->GetDevice(&d3ddv);

	result = D3DXCreateTextureFromFileEx(
		d3ddv,
		FilePath,
		info.Width,
		info.Height,
		1,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		D3DCOLOR_XRGB(0, 0, 0),
		&info,
		NULL,
		&m_Image);

	if (result != D3D_OK)
	{
		trace(L"[ERROR] Failed to create texture from file '%s'", FilePath);
		return;
	}
}

void CSprite::Render(int X, int Y)
{
	this->Render(NULL, X, Y);
}


void CSprite::Render(LPDIRECT3DSURFACE9 Target, int X, int Y)
{
	RECT srect;

	srect.left = (m_Index % m_SpritePerRow)*(m_Width)+1;
	srect.top = (m_Index / m_SpritePerRow)*(m_Height)+1;
	srect.right = srect.left + m_Width;
	srect.bottom = srect.top + m_Height + 1;

	D3DXVECTOR3 position((float)X, (float)Y, 0);

	m_SpriteHandler->Draw(
		m_Image,
		&srect,
		NULL,
		&position,
		D3DCOLOR_XRGB(255, 255, 255)
		);
}

void CSprite::Next()
{
	m_Index = (m_Index + m_Count - 1) % m_Count;
}

void CSprite::Reset()
{
	m_Index = 0;
}

CSprite::~CSprite()
{
	m_Image->Release();
}