#include "Input.h"

#include <sl.h>


namespace Input
{
    //Sl defined keys + amount of letters + numbers. First 10 represent numbers, following 26 represent letters, the rest are sl-defined.
    const int MAX_KEYS = 105;

    //false if up
    bool previousKeyStates[MAX_KEYS] = {false};

    int amountActive = 0;

    bool GetPreviousKeyState(const int key)
    {
        if (key >= '0' && key <= '9')
        {
            return previousKeyStates[key - '0'];
        }
        if (key >= 'A' && key <= 'Z')
        {
            return previousKeyStates[key - 'A' + '9' - '0'];
        }
        if (key >= SL_KEY_ESCAPE && key <= SL_KEY_RIGHT_SUPER)
        {
            return previousKeyStates[key - SL_KEY_ESCAPE + '9' - '0' + 'Z' - 'A'];
        }
        return false;
    }


    void TogglePreviousKeyState(int key)
    {
        if (key >= '0' && key <= '9')
        {
            previousKeyStates[key - '0'] = !previousKeyStates[key - '0'];
        }
        else if ((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z'))
        {
            previousKeyStates[key - 'A' + '9' - '0'] = !previousKeyStates[key - 'A' + '9' - '0'];
        }
        else
        {
            previousKeyStates[key - SL_KEY_ESCAPE + '9' - '0' + 'Z' - 'A'] =
                !previousKeyStates[key - SL_KEY_ESCAPE + '9' - '0' + 'Z' - 'A'];
        }
    }


    bool IsKeyDown(const int key)
    {
        return slGetKey(key);
    }


    bool IsKeyAboutToPress(const int key)
    {
        return IsKeyDown(key) && !Input::GetPreviousKeyState(key);

    }

    bool IsKeyReleasing(const int key)
    {
        // if key is down
        if (IsKeyDown(key))
        {
            //if it was not down
            if (!Input::GetPreviousKeyState(key))
            {
                Input::TogglePreviousKeyState(key);
            }
        }
        //key is up
        else
        {
            //was down
            if (Input::GetPreviousKeyState(key))
            {
                Input::TogglePreviousKeyState(key);
                return true;
            }
        }
        return false;
    }
}
