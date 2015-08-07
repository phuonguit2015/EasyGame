#pragma once
#include <d3d9.h>
#include <d3dx9.h>
#include "Sprite.h"

class CFish
{
public:
	CFish();
	~CFish();
	
	LPD3DXSPRITE m_SpriteHandler;

	int m_PositionX;
	int m_PositionY;

	CSprite * kitty_right;
	CSprite * kitty_left;

	void RenderFrame();
};

