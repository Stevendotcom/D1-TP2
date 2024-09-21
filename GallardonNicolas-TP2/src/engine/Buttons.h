#pragma once
#include "ColorPalette.h"
#include "Sprites.h"
#include "VectorMath.h"

namespace Buttons
{
    struct Button
    {
        VectorMath::Vector2 Position;
        VectorMath::Vector2 Size;
        Texture Sprite;
        Color::Color Color;
        Color::Color ColorSelected;
        std::string Text;
        bool Selected;
    };

    void RenderButtons(Button buttons[], int amount);
    void Input(Button buttons[], int &selected, int amount);

};
