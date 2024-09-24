#pragma once
namespace Color
{
    struct Color
    {
        float Red;
        float Green;
        float Blue;
    };

    constexpr float MAX = 255;

    constexpr Color WHITE = {255 / MAX, 255 / MAX, 255 / MAX};
    constexpr Color MANTIS = {109 / MAX, 211 / MAX, 112 / MAX};
    constexpr Color FRENCH = {211 / MAX, 205 / MAX, 215 / MAX};
    constexpr Color DIM_GRAY = {108 / MAX, 117 / MAX, 107 / MAX};
    constexpr Color COFFEE = {125 / MAX, 93 / MAX, 76 / MAX};
    constexpr Color BITTERSWEET = {237 / MAX, 106 / MAX, 90 / MAX};

    //Color

    void SetBackColor(const Color &color);
    void SetForeColor(const Color &color, float opacity);
    void SetAdditiveBlend(bool enable);

}

// https://coolors.co/6dd370-d3cdd7-6c756b-7d5d4c-ed6a5a
