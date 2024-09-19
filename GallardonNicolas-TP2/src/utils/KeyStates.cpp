#include "KeyStates.h"

#include <sl.h>


//Sl defined keys + amount of letters + numbers. First 10 represent numbers, following 26 represent letters, the rest are sl-defined.
const int MAX_KEYS = 105;

//false if up
bool previousKeyStates[MAX_KEYS] = {false};

int amountActive = 0;

bool KeyStates::GetPreviousKeyState(const int key)
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


void KeyStates::TogglePreviousKeyState(int key)
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
        previousKeyStates[key - SL_KEY_ESCAPE + '9' - '0' + 'Z' - 'A' ] =
            !previousKeyStates[key - SL_KEY_ESCAPE + '9' - '0' + 'Z' - 'A' ];
    }
}
