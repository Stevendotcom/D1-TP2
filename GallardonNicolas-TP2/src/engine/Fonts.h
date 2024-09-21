#pragma once

#include "VectorMath.h"

#include <string>

typedef int Font;

namespace Fonts
{
    static int fontSize = 20;

    struct Fonts
    {
        Font Title;
        Font Body;
    };

    void LoadAllFonts(Fonts &fonts);
    Font LoadFont(const std::string &filename);
    void SetFont(Font font);
    void ChangeFontSize(int size);
    void TextPrint(VectorMath::Vector2 position, const std::string &text);
    VectorMath::Vector2 GetTextSize(const std::string &text);
    void CenterText();
};

extern Fonts::Fonts fonts;
