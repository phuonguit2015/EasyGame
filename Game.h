#pragma once
class CGame
{
public:
	CGame();
	~CGame();

	void InitGame();										// Khởi tạo các đối tượng của game
	void UpdateGame(float gameTime);						// Cập nhật
	void Render();											// Vẽ các đối tượng game
};

