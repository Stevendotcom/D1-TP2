#include "ColorPalette.h"

#include <sl.h>

namespace Color
{
    void SetBackColor(const Color &color)
    {
        slSetBackColor(color.Red, color.Green, color.Blue);
    }


    void SetForeColor(const Color &color, const float opacity)
    {
        slSetForeColor(color.Red, color.Green, color.Blue, opacity);
    }


    void SetAdditiveBlend(const bool enable)
    {
        slSetAdditiveBlend(enable);
    }
}
