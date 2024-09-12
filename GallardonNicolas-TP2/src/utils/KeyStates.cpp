#include "KeyStates.h"


//Sl defined keys + amount of letters + numbers. First 10 represent numbers, following 26 represent letters, the rest are sl-defined.
const int MAX_KEYS = 105;

bool previousKeyStates[MAX_KEYS] = {false};

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
    if (key >= 'a' && key <= 'z')
    {
        return previousKeyStates[key - 'a' + 'Z' - 'A'];
    }
    return false;
}
