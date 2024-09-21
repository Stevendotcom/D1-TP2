﻿#pragma once
namespace Color
{
    struct Color
    {
        float Red;
        float Green;
        float Blue;
    };

    const float MAX = 255;

    const Color white = {255 / MAX, 255 / MAX, 255 / MAX};
    const Color mantis = {109 / MAX, 211 / MAX, 112 / MAX};
    const Color french = {211 / MAX, 205 / MAX, 215 / MAX};
    const Color dimGray = {108 / MAX, 117 / MAX, 107 / MAX};
    const Color coffee = {125 / MAX, 93 / MAX, 76 / MAX};
    const Color bittersweet = {237 / MAX, 106 / MAX, 90 / MAX};

    //Color

    void SetBackColor(const Color &color);
    void SetForeColor(const Color &color, float opacity);
    void SetAdditiveBlend(bool enable);

}

// https://coolors.co/6dd370-d3cdd7-6c756b-7d5d4c-ed6a5a
