#include "Buttons.h"


void Buttons::RenderButtons(Button buttons[], const int amount)
{
    const int margin = 3;

    Wrapper::ChangeFontSize(buttons[0].Size.Y - margin);
    Wrapper::SetFont(button);
    Wrapper::CenterText();

    for (int i = 0; i < amount; i++)
    {
        Wrapper::LoadSprite(buttons[i].Sprite, buttons[i].Position, buttons[i].Size);

        if (buttons[i].Selected)
        {
            Wrapper::SetForeColor(buttons[i].ColorSelected, 1.0f);
        }
        else
        {
            Wrapper::SetForeColor(buttons[i].Color, 1.0f);
        }

        Wrapper::TextPrint({buttons[i].Position.X, buttons[i].Position.Y + margin}, buttons[i].Text);
    }
}
