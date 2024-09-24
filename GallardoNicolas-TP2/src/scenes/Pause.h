#pragma once
#include "Buttons.h"

namespace Pause
{
    constexpr int MAX_BUTTONS = 3;

    void Pause();
    void MakeButtons(Buttons::Button buttons[MAX_BUTTONS]);
    void Draw(Buttons::Button buttons[MAX_BUTTONS]);
};
