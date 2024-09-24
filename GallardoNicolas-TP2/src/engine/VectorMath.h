#pragma once
#include <string>
constexpr float PI = 3.1416f;

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;
extern const std::string GAME_TITLE;
extern const std::string ASSETS_DIR;

namespace VectorMath
{
    struct Vector2
    {
        float X;
        float Y;
    };

    Vector2 Add(const Vector2 &a, const Vector2 &b);
    void Normalize(Vector2 &v);
};
