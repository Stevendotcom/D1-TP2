#include "Buttons.h"

#include <sl.h>

#include "Fonts.h"
#include "Input.h"


void Buttons::RenderButtons(Button buttons[], const int amount)
{
    const float margin = buttons[0].Size.Y * 0.6;

    Fonts::ChangeFontSize(buttons[0].Size.Y - margin);
    Fonts::SetFont(fonts.Body);
    Fonts::CenterText();

    for (int i = 0; i < amount; i++)
    {
        Sprites::LoadSprite(buttons[i].Sprite,
                            {buttons[i].Position.X, buttons[i].Position.Y + (buttons[i].Size.Y / 2.0F) - margin / 2.0F},
                            buttons[i].Size);

        if (buttons[i].Selected)
        {
            SetForeColor(buttons[i].ColorSelected, 1.0F);
        }
        else
        {
            SetForeColor(buttons[i].Color, 1.0F);
        }
        Fonts::TextPrint({buttons[i].Position.X, buttons[i].Position.Y}, buttons[i].Text);
    }
}


void Buttons::Input(Buttons::Button buttons[], int &selected, const int amount)
{
    buttons[selected].Selected = false;
    if (Input::IsKeyReleasing(SL_KEY_DOWN))
    {
        if (selected == amount - 1)
        {
            selected = 0;
        }
        else
        {
            selected++;
        }
    }
    else if (Input::IsKeyReleasing(SL_KEY_UP))
    {
        if (selected == 0)
        {
            selected = amount - 1;
        }
        else
        {
            selected--;
        }
    }
    buttons[selected].Selected = true;
}