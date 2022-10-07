#pragma once
#include <Windows.h>

class KeyPressed 
{
private:
    int mKey;
    bool mOn;

public:
    KeyPressed(int key) :mKey(key), mOn(false)
    {

    }

    operator bool() = delete;

    bool trueOnFirstPressed() {
        if (GetAsyncKeyState(mKey) && !mOn)
        {
            mOn = true;
            return true;
        }
        else if(GetAsyncKeyState(mKey) == false)
        {
            mOn = false;
        }
        return false;

    }

    bool trueWhilePressed()
    {
        if (GetAsyncKeyState(mKey)) return true;
        else return false;
    }


};