#pragma once
namespace KeyStates
{
    const int MAX_ACTIVE_KEYS = 26;
    static int activeKeys[MAX_ACTIVE_KEYS];

    /**
     * @brief Checks for the key previous state, stored in previousKeyStates
     * @param key key number according to SL
     * @return true if the key is down, false if up
     */
    bool GetPreviousKeyState(int key);

    /**
     * @brief changes key state stored in previousKeyStates
     * @param key key number according to SL
     */
    void TogglePreviousKeyState(int key);
}
