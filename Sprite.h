#pragma once
#include <d3d9.h>
#include <d3dx9.h>

class CSprite
{
protected:

	LPDIRECT3DTEXTURE9 m_Image;
	LPD3DXSPRITE m_SpriteHandler;

	int m_Index;								// Current sprite index
	int m_Width;								// Sprite width
	int m_Height;								// Sprite height
	int m_Count;								// Number of sprites
	int m_SpritePerRow;							// Number of sprites per row
public:
	CSprite(LPD3DXSPRITE SpriteHandler, LPWSTR FilePath, int Width, int Height, int Count, int SpritePerRow);
	~CSprite();

	void Next();
	void Reset();

	// Render current sprite at location (X,Y) at the target surface
	void Render(int X, int Y);
	void Render(LPDIRECT3DSURFACE9 Target, int X, int Y);
};

