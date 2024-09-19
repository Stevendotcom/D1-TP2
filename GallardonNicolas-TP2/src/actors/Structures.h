#pragma once
#include "VectorMath.h"
#include "Wrapper.h"

namespace Structures
{
    enum class Powers
    {
        // None = LoadTexture(...);
        None
    };

    struct Ball
    {
        VectorMath::Vector2 Position;
        VectorMath::Vector2 FuturePosition;
        VectorMath::Vector2 Direction;
        Wrapper::Texture Sprite;
        float Radius;
        float Speed;
    };

    struct Key
    {
        int Left;
        int Right;
    };

    struct Player
    {
        VectorMath::Vector2 Position;
        VectorMath::Vector2 FuturePosition;
        Wrapper::Texture Sprite;
        Key Keys;
        float Direction;
        int Width;
        int Height;
        int Speed;
        int Score;
    };

    struct Brick
    {
        Powers Power;
        bool IsVisible;
        VectorMath::Vector2 Position;
        VectorMath::Vector2 Size;
        Wrapper::Texture Sprite = static_cast<Wrapper::Texture>(Power);
    };
}
