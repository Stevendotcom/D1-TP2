#include "VectorMath.h"
#include <cmath>

VectorMath::Vector2 VectorMath::Add(const Vector2 &a, const Vector2 &b)
{
    return {a.X + b.X, a.Y + b.Y};
}

void VectorMath::Normalize(Vector2 &v)
{
    const float length = sqrt(v.X * v.X + v.Y * v.Y);
    v = {v.X / length, v.Y / length};
}
