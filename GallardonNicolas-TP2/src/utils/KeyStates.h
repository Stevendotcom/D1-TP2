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

    /**
     * @brief adds key to a watchlist, which is used to check if any
     *        key has been released between cycles.
     * @param key key number according to SL
     */
    void AddKeyToWatch(int key);
    /**
     * @brief checks if any key has been released between cycles.
     * @param active array with active keys
     */
    void CheckForKeysInWatch(int active[MAX_ACTIVE_KEYS]);
}
