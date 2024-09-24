#pragma once
#include "Buttons.h"

namespace Pause
{
    constexpr int MAX_BUTTONS = 2;

    enum class Selection
    {
        GoToMain,
        Return,
    };

    void Pause(bool &returnMain);
    void MakeButtons(Buttons::Button buttons[MAX_BUTTONS]);
    void Draw(Buttons::Button buttons[MAX_BUTTONS]);
};
