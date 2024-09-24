#pragma once
#include "Sprites.h"
#include "VectorMath.h"

namespace Structures
{
    enum class SpecialBricks
    {
        RotateScreen,
        InvertControls,
        OneUp,
        FasterPlayer,
        None
    };

    struct Ball
    {
        VectorMath::Vector2 Position;
        VectorMath::Vector2 FuturePosition;
        VectorMath::Vector2 Direction;
        Texture Sprite;
        float Radius;
        float Speed;
    };

    enum class Direction
    {
        Left,
        Right,
        Idle
    };

    struct Player
    {
        VectorMath::Vector2 Position;
        VectorMath::Vector2 FuturePosition;
        Direction Direction;
        Texture Sprite;
        float Width;
        float Height;
        int Speed;
        int Score;
        int Hearts;
        bool Won;
    };

    struct Brick
    {
        SpecialBricks Power;
        bool IsVisible;
        VectorMath::Vector2 Position;
        VectorMath::Vector2 Size;
        Texture Sprite;
    };
}
