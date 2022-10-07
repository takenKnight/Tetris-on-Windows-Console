#pragma once
#include <Vec2d.h>
#include <ScreenBuffer.h>
#include <Tetromino.h>
#include <iostream>
#include <cstdlib>

class InQueue
{
private:
	std::wstring mShape[7], mCurrShape, mFutShape, mNextText{ L"NEXT" };
	Vec2d mPOS{ 20, 4 };

public:
	InQueue()
	{
		mShape[0] = L"...OOOO."; //Z
		mShape[1] = L"..O.OO.O"; //S
		mShape[2] = L"...OOO.O"; //T
		mShape[3] = L"..OOOO.."; //O
		mShape[4] = L".O.O.O.O"; //I
		mShape[5] = L"..O.O.OO"; //L
		mShape[6] = L"...O.OOO"; //J

		srand(time(NULL));
		mFutShape = mShape[rand() % 7];
		mCurrShape = mFutShape;
		mFutShape = mShape[rand() % 7];
	}

	void draw(ScreenBuffer& screen)
	{
		for (size_t i = 0; i < 4; i++)
		{
			screen[i + mPOS.sum(SWIDTH)] = mNextText[i];
		}

		for (int i{}; i < 8; i++)
		{
			if(mFutShape[i] == 'O')
				screen[-i/2 + i%2*SWIDTH +
				mPOS.sum(SWIDTH) + 2*SWIDTH + 5] = mFutShape[i];
		}
	}

	std::wstring* getShape()
	{
		return mShape;
	}

	std::wstring getCurrShape()
	{
		return mCurrShape;
	}

	void randFutShape()
	{
		srand(time(NULL));
		mCurrShape = mFutShape;
		mFutShape = mShape[rand() % 7];
	}
};