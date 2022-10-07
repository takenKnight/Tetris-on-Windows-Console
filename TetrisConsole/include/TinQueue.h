#pragma once

#include <Tetromino.h>
#include <chrono>
#include <ScreenBuffer.h>

class TinQueue :public Tetromino
{
private:
	std::wstring mFutShape;

public:
	TinQueue();
	void draw(ScreenBuffer& screen);
	std::wstring getCurrShape();
	void randFutShape();
};