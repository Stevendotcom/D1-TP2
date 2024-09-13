#include "Buttons.h"

extern const std::string assetsDir;
const Wrapper::Font buttonFont = Wrapper::LoadFont(assetsDir + "DirtyHarold_Font/DirtyHarold");
const int margin = 3;

void Buttons::RenderButtons(Button buttons[], const int amount)
{
    for(int i = 0; i < amount; i++)
    {
        Wrapper::LoadSprite(buttons[i].Sprite, buttons[i].Position, buttons[i].Size);

        if(buttons[i].Selected)
        {
            Wrapper::SetForeColor(buttons[i].ColorSelected, 1.0f);
        }
        else
        {
            Wrapper::SetForeColor(buttons[i].Color, 1.0f);
        }

        Wrapper::CenterText();
        Wrapper::ChangeFontSize(buttons[i].Size.Y - margin);
        Wrapper::SetFont(buttonFont);
        Wrapper::TextPrint({buttons[i].Position.X, buttons[i].Position.Y + margin}, buttons[i].Text);
    }
}
