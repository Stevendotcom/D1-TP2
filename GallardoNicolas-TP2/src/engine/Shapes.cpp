#include "Shapes.h"

#include <sl.h>

void Shapes::DrawRect(const VectorMath::Vector2 &position, const VectorMath::Vector2 &size)
{
    slRectangleFill(position.X, position.Y, size.X, size.Y);
}

void Shapes::DrawRectOutline(const VectorMath::Vector2 &position, const VectorMath::Vector2 &size)
{
    slRectangleOutline(position.X, position.Y, size.X, size.Y);
}

void Shapes::DrawCircle(const VectorMath::Vector2 &position, const float radius, float opacity)
{
    slCircleFill(position.X, position.Y, radius, 64);
}

void Shapes::DrawCircleOutline(const VectorMath::Vector2 &position, const float radius, float opacity)
{
    slCircleOutline(position.X, position.Y, radius, 64);
}
