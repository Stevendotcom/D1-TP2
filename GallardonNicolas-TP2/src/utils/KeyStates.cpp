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
    if (key >= 'a' && key <= 'z')
    {
        return previousKeyStates[key - 'a' + 'Z' - 'A'];
    }
    return false;
}



void KeyStates::TogglePreviousKeyState(int key)
{
    if (key >= '0' && key <= '9')
    {
       previousKeyStates[key - '0'] = !previousKeyStates[key - '0'];
    }
    else if (key >= 'A' && key <= 'Z')
    {
       previousKeyStates[key - 'A' + '9' - '0'] = !previousKeyStates[key - 'A' + '9'];
    }
    else if (key >= 'a' && key <= 'z')
    {
        previousKeyStates[key - 'a' + 'Z' - 'A'] = !previousKeyStates[key - 'a' + 'Z'];
    }
}



void KeyStates::AddKeyToWatch(int key)
{
    activeKeys[amountActive] = key;
    amountActive++;
}



void KeyStates::CheckForKeysInWatch(int active[MAX_ACTIVE_KEYS])
{
    int actualActive = amountActive;

    for (int i = 0; i < amountActive; i++)
    {
        if(!slGetKey(active[i]))
        {
            TogglePreviousKeyState(active[i]);
            actualActive--;
        }
    }

    amountActive = actualActive;
}
