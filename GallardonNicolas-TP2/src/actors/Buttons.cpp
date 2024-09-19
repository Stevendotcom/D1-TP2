#include "Buttons.h"
#include "Wrapper.h"


void Buttons::RenderButtons(Button buttons[], const int amount)
{
    const float margin = buttons[0].Size.Y * 0.6;

    Wrapper::ChangeFontSize(buttons[0].Size.Y - margin);
    Wrapper::SetFont(button);
    Wrapper::CenterText();

    for (int i = 0; i < amount; i++)
    {
        Wrapper::LoadSprite(buttons[i].Sprite,
                            {buttons[i].Position.X, buttons[i].Position.Y + (buttons[i].Size.Y / 2.0F) - margin / 2.0F},
                            buttons[i].Size);

        if (buttons[i].Selected)
        {
            Wrapper::SetForeColor(buttons[i].ColorSelected, 1.0F);
        }
        else
        {
            Wrapper::SetForeColor(buttons[i].Color, 1.0F);
        }
        Wrapper::TextPrint({buttons[i].Position.X, buttons[i].Position.Y}, buttons[i].Text);
    }
}
