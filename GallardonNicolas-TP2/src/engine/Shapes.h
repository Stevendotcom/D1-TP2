#pragma once
#include "ColorPalette.h"
#include "VectorMath.h"

namespace Shapes
{
    void DrawRect(const VectorMath::Vector2& position, const VectorMath::Vector2& size);
    void DrawRectOutline(const VectorMath::Vector2& position, const VectorMath::Vector2& size);
    void DrawCircle(const VectorMath::Vector2& position, float radius, Color::Color& color, float opacity);
    void DrawCircleOutline(const VectorMath::Vector2& position, float radius, Color::Color& color, float opacity);

};
