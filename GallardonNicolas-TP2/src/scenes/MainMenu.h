#pragma once
#include "Buttons.h"


namespace MainMenu
{
    void Menu();
    void MakeButtons(Buttons::Button buttons[]);
    void Input(Buttons::Button buttons[], int& selected);
    void Draw(Buttons::Button buttons[]);
}


