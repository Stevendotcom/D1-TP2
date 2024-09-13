#pragma once

#include "Wrapper.h"

namespace Buttons
{
    struct Button
    {
        Wrapper::Vector2 Position;
        Wrapper::Vector2 Size;
        Wrapper::Texture Sprite;
        Wrapper::Color Color;
        Wrapper::Color ColorSelected;
        std::string Text;
        bool Selected;
    };
    void RenderButtons(Button buttons[], int amount);
};
