#pragma once
#include <ScreenBuffer.h>
#include <string>
#include <Vec2d.h>

class Stats
{
private:
	Vec2d mPOS{ 20,16 };
	int mLevel{}, mLines{}, mScore{};

public:
	void draw(ScreenBuffer& screen);
	void addScore(int completedLines);
	void restart();
	int getLevel();
};