#pragma once

#include "Wrapper.h"

namespace Buttons
{
    struct Button
    {
        VectorMath::Vector2 Position;
        VectorMath::Vector2 Size;
        Wrapper::Texture Sprite;
        Color::Color Color;
        Color::Color ColorSelected;
        std::string Text;
        bool Selected;
    };
    void RenderButtons(Button buttons[], int amount);
};
