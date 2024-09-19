#pragma once
const float PI = 3.1416f;

namespace VectorMath
{
    struct Vector2
    {
        float X;
        float Y;
    };

    VectorMath::Vector2 Add(const Vector2 &a, const Vector2 &b);
    void Normalize(Vector2 &v);
};
