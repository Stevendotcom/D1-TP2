#include "Fonts.h"

#include <sl.h>


namespace Fonts
{
    void LoadAllFonts(Fonts &fonts)
    {

        fonts.Title = LoadFont(ASSETS_DIR + "Antiquity-Print/antiquity-print.ttf");
        fonts.Body = LoadFont(ASSETS_DIR + "DirtyHarold_Font/DirtyHarold.ttf");

    }


    Font LoadFont(const std::string &filename)
    {
        return slLoadFont(filename.c_str());
    }


    void SetFont(const Font font)
    {
        slSetFont(font, fontSize);
    }


    void ChangeFontSize(const int size)
    {
        fontSize = size;
        slSetFontSize(fontSize);
    }


    void TextPrint(const VectorMath::Vector2 position, const std::string &text)
    {
        slText(position.X, position.Y, text.c_str());
    }

    VectorMath::Vector2 GetTextSize(const std::string &text)
    {
        return {static_cast<float>(slGetTextWidth(text.c_str())), static_cast<float>(slGetTextHeight(text.c_str()))};
    }

    void CenterText()
    {
        slSetTextAlign(SL_ALIGN_CENTER);
    }

    void TextAlignLeft()
    {
        slSetTextAlign(SL_ALIGN_LEFT);
    }
}
